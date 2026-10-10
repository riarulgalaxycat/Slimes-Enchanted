//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_REGISTER_H
#define SLIMES_ENCHANTED_REGISTER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <set>

namespace fs = std::filesystem;

inline void register_file(const std::string& folderPath, const std::string& fileName, const std::string& content) {
    try {
        std::ifstream inFile(fileName);
        std::ifstream file(fileName);
        std::set<std::string> existingLines;
        if (!folderPath.empty() && !fs::exists(folderPath)) {
            fs::create_directories(folderPath);
        }

        fs::path fullPath = fs::path(folderPath) / fileName;

        if (!file.is_open()) {
            std::ofstream outFile(fullPath);
            if (outFile.is_open()) {
                std::string line;
                outFile << content;
                outFile.close();
            }
        }

    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
}

#endif //SLIMES_ENCHANTED_REGISTER_H