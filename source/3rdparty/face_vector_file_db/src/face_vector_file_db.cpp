#include "face_vector_file_db.cpp"

int load_feature_file(std::string file_path, std::vector<std::string> &user_list, cv::Mat &feature_mat) {
    std::cout << "load_feature_file at: " << file_path << std::endl;

    std::ifstream input_file(file_path, std::ofstream::app | std::ofstream::out);
    std::string line, word;

    size_t count = 0;
    while (std::getline(input_file, line)) {
        std::istringstream record(line);

        record >> word;
        user_list.push_back(word);

        cv::Mat feature;
        while (record >> word) {
            feature.push_back(std::stof(word));
        }

        if (count == 0) {
            feature_mat = feature;
        } else {
            cv::hconcat(feature_mat, feature, feature_mat);
        }

        count++;
    }

    input_file.close();
    return 0;
}

int write_feature_file(std::string file_path, std::string &user_name, float feature[512]) {
    std::cout << "write_feature_file at: " << file_path << std::endl;

    std::ofstream output_file(file_path, std::ofstream::app | std::ofstream::in);

    output_file << user_name;
    for (size_t i = 0; i < 512; i++) {
        output_file << " " << feature[i];
    }
    output_file << std::endl;
    
    output_file.close();
    return 0;
}
