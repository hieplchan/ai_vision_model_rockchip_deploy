//  Created by Linzaer on 2019/11/15.
//  Copyright © 2019 Linzaer. All rights reserved.

#define clip(x, y) (x < 0 ? 0 : (x > y ? y : x))

#include "InsightFace.hpp"

using namespace std;

InsightFace::InsightFace(const std::string &mnn_path, int num_thread_, bool is_open_cl) {
    num_thread = num_thread_;

    insightface_interpreter = std::shared_ptr<MNN::Interpreter>(MNN::Interpreter::createFromFile(mnn_path.c_str()));
    MNN::ScheduleConfig config;
    if (is_open_cl) {
        config.type = MNN_FORWARD_OPENCL;
    }
    config.numThread = num_thread;
    
    MNN::BackendConfig backendConfig;    
    backendConfig.precision = (MNN::BackendConfig::PrecisionMode) 2;
    config.backendConfig = &backendConfig;

    insightface_session = insightface_interpreter->createSession(config);

    input_tensor = insightface_interpreter->getSessionInput(insightface_session, nullptr);
}

InsightFace::~InsightFace() {
    insightface_interpreter->releaseModel();
    insightface_interpreter->releaseSession(insightface_session);
}

int InsightFace::vectorize(cv::Mat &raw_image, float *face_vector) {
    if (raw_image.empty()) {
        std::cout << "image is empty ,please check!" << std::endl;
        return -1;
    }

    cv::Mat image;
    cv::resize(raw_image, image, cv::Size(InsightFace::INPUT_W, InsightFace::INPUT_H));

    insightface_interpreter->resizeTensor(input_tensor, {1, 3, InsightFace::INPUT_H, InsightFace::INPUT_W});
    insightface_interpreter->resizeSession(insightface_session);
    std::shared_ptr<MNN::CV::ImageProcess> pretreat(
            MNN::CV::ImageProcess::create(MNN::CV::BGR, MNN::CV::RGB, mean_vals, 3,
                                          norm_vals, 3));
    pretreat->convert(image.data, InsightFace::INPUT_W, InsightFace::INPUT_H, image.step[0], input_tensor);

    auto start = chrono::steady_clock::now();

    // run network
    insightface_interpreter->runSession(insightface_session);

    // get output data

    string output_name = "516";
    MNN::Tensor *tensor_vector = insightface_interpreter->getSessionOutput(insightface_session, output_name.c_str());

    MNN::Tensor tensor_vector_host(tensor_vector, tensor_vector->getDimensionType());

    tensor_vector->copyToHostTensor(&tensor_vector_host);

    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "inference vectorizer time:" << elapsed.count() << " s" << endl;

    std::cout << "[Debug] Insightface tensor_vector_host.host<float>()[0]: " << tensor_vector_host.host<float>()[0] << std::endl;

    for (size_t i = 0; i < FACE_VECTOR_LENGTH; i++) {
        face_vector[i] = tensor_vector_host.host<float>()[i];
    }

    // Normalize vector
    cv::Mat vector = cv::Mat(1, FACE_VECTOR_LENGTH, CV_32F, face_vector);
    cv::normalize(vector, vector);

    std::cout << "[Debug] Insightface face_vector[0]: " << face_vector[0] << std::endl;

    return 0;
}