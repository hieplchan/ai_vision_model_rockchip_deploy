#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <array>
#include <opencv2/opencv.hpp>

#define FACE_VECTOR_LENGTH 512

int load_feature_file(std::string file_path, std::vector<std::string> &user_list, cv::Mat &feature_mat);

int write_feature_file(std::string file_path, std::string &user_name, float feature[FACE_VECTOR_LENGTH]);
