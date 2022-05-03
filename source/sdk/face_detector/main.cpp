#include <iostream>
#include "UltraFace.hpp"

int main() {
    std::cout << "Testing face detector" << std::endl; 

    // Init inference engine
    std::string mnn_path = "/home/rock/ai_vision_model_rockchip_deploy/source/model/facedetect/RFB-320.mnn";
    UltraFace face_detector = UltraFace(mnn_path, 240, 240, 2, false, 0.65); // CPU mode

    // Load image for testing
    std::string test_img_path1_1 = "/home/rock/ai_vision_model_rockchip_deploy/test_data/face_640_480.jpeg";
    cv::Mat test_img1_1 = cv::imread(test_img_path1_1, cv::IMREAD_COLOR);

    // Face detect
    std::vector<FaceInfo> face_info;
    face_detector.detect(test_img1_1, face_info);
    if (face_info.size() > 0) {
        std::cout << "Face detect " << face_info.size() << " faces" << std::endl;

        // Only draw bounding box if have face
        for (size_t face_num = 0; face_num < face_info.size(); face_num++) {
            cv::Point pt1(face_info[face_num].x1, face_info[face_num].y1);
            cv::Point pt2(face_info[face_num].x2, face_info[face_num].y2);
            cv::rectangle(test_img1_1, pt1, pt2, cv::Scalar(0, 255, 0), 2);
        }

        std::string result_file_name = "result.jpeg";
        cv::imwrite(result_file_name, test_img1_1);
    }

    return 0;
}