#include <iostream>
#include "InsightFace.hpp"

int main() {
    std::cout << "Testing face vectorizer" << std::endl; 

    // Init inference engine
    std::string mnn_path = "/home/rock/ai_vision_model_rockchip_deploy/source/model/facevectorize/w600k_mbf.mnn";
    InsightFace face_vectorizer = InsightFace(mnn_path, 4, false); // CPU mode

    // Load image for testing
    std::string test_img_path1 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/croped_face1.png";
    std::string test_img_path1_1 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/croped_face1_1.png";
    std::string test_img_path2 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/croped_face2.png";

    cv::Mat test_img1 = cv::imread(test_img_path1, cv::IMREAD_COLOR);
    cv::Mat test_img1_1 = cv::imread(test_img_path1_1, cv::IMREAD_COLOR);
    cv::Mat test_img2 = cv::imread(test_img_path2, cv::IMREAD_COLOR);

    // Extract face vector
    float face_vector1[512] = {0};
    float face_vector1_1[512] = {0};
    float face_vector2[512] = {0};
    face_vectorizer.vectorize(test_img1, face_vector1);
    face_vectorizer.vectorize(test_img1_1, face_vector1_1);
    face_vectorizer.vectorize(test_img2, face_vector2);
    cv::Mat face_vector_mat1 = cv::Mat(1, 512, CV_32F, face_vector1);
    cv::Mat face_vector_mat1_1 = cv::Mat(1, 512, CV_32F, face_vector1_1);
    cv::Mat face_vector_mat2 = cv::Mat(1, 512, CV_32F, face_vector2);

    // Compare same face
    cv::Mat face_score1 = face_vector_mat1 * face_vector_mat1_1.t();
    std::cout << "Same face face_score1: " << face_score1 << std::endl;

    // Compare different face
    cv::Mat face_score2 = face_vector_mat1 * face_vector_mat2.t();
    std::cout << "Different face face_score2: " << face_score2 << std::endl;

    return 0;
}