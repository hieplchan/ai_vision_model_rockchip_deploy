//  Created by Linzaer on 2019/11/15.
//  Copyright © 2019 Linzaer. All rights reserved.

#ifndef InsightFace_hpp
#define InsightFace_hpp

#pragma once

#include "Interpreter.hpp"

#include "MNNDefine.h"
#include "Tensor.hpp"
#include "ImageProcess.hpp"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>

#define FACE_VECTOR_LENGTH 512

class InsightFace {
public:
    InsightFace(const std::string &mnn_path, int num_thread_ = 4, bool is_open_cl = false);

    ~InsightFace();

    int vectorize(cv::Mat &img, float *face_vector);

private:
    std::shared_ptr<MNN::Interpreter> insightface_interpreter;
    MNN::Session *insightface_session = nullptr;
    MNN::Tensor *input_tensor = nullptr;

    int num_thread;

    const float mean_vals[3] = {127, 127, 127};
    const float norm_vals[3] = {1.0 / 128, 1.0 / 128, 1.0 / 128};
    const int INPUT_W = 112;
    const int INPUT_H = 112;
};

#endif /* InsightFace_hpp */
