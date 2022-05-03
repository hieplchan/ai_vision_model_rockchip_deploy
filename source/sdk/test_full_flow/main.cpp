#include <iostream>
#include "UltraFace.hpp"
#include "InsightFace.hpp"

int main() {
    std::cout << "Testing face detector" << std::endl; 

    // Init inference engine face detect
    std::string mnn_path_face_detect = "/home/rock/ai_vision_model_rockchip_deploy/source/model/facedetect/RFB-320.mnn";
    UltraFace face_detector = UltraFace(mnn_path_face_detect, 240, 240, 2, false, 0.65); // CPU mode

    // Init inference engine face vectorize
    std::string mnn_path_face_vectorize = "/home/rock/ai_vision_model_rockchip_deploy/source/model/facevectorize/w600k_mbf.mnn";
    InsightFace face_vectorizer = InsightFace(mnn_path_face_vectorize, 4, false); // CPU mode

    // Load image for testing
    std::string test_img_path1 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/face_1_crop.jpeg";
    std::string test_img_path1_1 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/face_1_full.jpeg";
    std::string test_img_path2 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/croped_face2.png";
    cv::Mat test_img1 = cv::imread(test_img_path1, cv::IMREAD_COLOR);
    cv::Mat test_img1_1 = cv::imread(test_img_path1_1, cv::IMREAD_COLOR);
    cv::Mat test_img2 = cv::imread(test_img_path2, cv::IMREAD_COLOR);

    // Extract face vector
    float face_vector1[512] = {0};
    float face_vector2[512] = {0};
    face_vectorizer.vectorize(test_img1, face_vector1);
    face_vectorizer.vectorize(test_img2, face_vector2);
    cv::Mat face_vector_mat1 = cv::Mat(1, 512, CV_32F, face_vector1);
    cv::Mat face_vector_mat2 = cv::Mat(1, 512, CV_32F, face_vector2);

    // Face detect
    std::vector<FaceInfo> face_info;
    face_detector.detect(test_img1_1, face_info);
    if (face_info.size() > 0) {
        std::cout << "Face detect " << face_info.size() << " faces" << std::endl;

        // Crop face
        cv::Rect croped_rectangle(face_info[0].x1, face_info[0].y1, face_info[0].x2 - face_info[0].x1, face_info[0].y2 - face_info[0].y1);
        cv::Mat crop_face = test_img1_1(croped_rectangle);
        cv::imwrite("croped.jpeg", crop_face);

        // Vectorize and compare face
        float face_vector1_1[512] = {0};
        face_vectorizer.vectorize(crop_face, face_vector1_1);
        cv::Mat face_vector_mat1_1 = cv::Mat(1, 512, CV_32F, face_vector1_1);

        // Compare same face
        cv::Mat face_score1 = face_vector_mat1 * face_vector_mat1_1.t();
        std::cout << "Same face face_score1: " << face_score1 << std::endl;

        // Compare different face
        cv::Mat face_score2 = face_vector_mat1 * face_vector_mat2.t();
        std::cout << "Different face face_score2: " << face_score2 << std::endl;

        // Only draw bounding box if have face
        for (size_t face_num = 0; face_num < face_info.size(); face_num++) {
            cv::Point pt1(face_info[face_num].x1, face_info[face_num].y1);
            cv::Point pt2(face_info[face_num].x2, face_info[face_num].y2);
            cv::rectangle(test_img1_1, pt1, pt2, cv::Scalar(0, 255, 0), 2);
        }
        cv::imwrite("result.jpeg", test_img1_1);

    }

    return 0;
}