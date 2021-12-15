//  Created by Linzaer on 2019/11/15.
//  Copyright © 2019 Linzaer. All rights reserved.

#include "UltraFace.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 2) {
        fprintf(stderr, "Usage: %s <mnn .mnn> [image files...]\n", argv[0]);
        return 1;
    }

    string mnn_path = argv[1];
    // UltraFace ultraface(mnn_path, 320, 240, 4, false, 0.65); // cpu

    UltraFace ultraface(mnn_path, 320, 240, 1, true, 0.65); // gpu

    for (int i = 2; i < argc; i++) {
        string image_file = argv[i];
        cout << "Processing " << image_file << endl;

        cv::Mat frame = cv::imread(image_file);

        vector<FaceInfo> face_info;
        for (int j = 0; j < 200; j++) {
            auto start = chrono::steady_clock::now();
            ultraface.detect(frame, face_info);

            auto end = chrono::steady_clock::now();
            chrono::duration<double> elapsed = end - start;
            cout << "all time: " << elapsed.count() << " s" << endl;
        }

        for (auto face : face_info) {
            cv::Point pt1(face.x1, face.y1);
            cv::Point pt2(face.x2, face.y2);
            cv::rectangle(frame, pt1, pt2, cv::Scalar(0, 255, 0), 2);
        }

        cv::imshow("UltraFace", frame);
        cv::waitKey();
        string result_name = "result" + to_string(i) + ".jpg";
        cv::imwrite(result_name, frame);
    }
    return 0;
}
