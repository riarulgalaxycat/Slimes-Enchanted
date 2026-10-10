//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_REGISTER_H
#define SLIMES_ENCHANTED_REGISTER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_set>

namespace fs = std::filesystem;

namespace register_file_error {
    inline bool error_ = false;
    inline string reason = "";
    inline string file = "";
    inline string path = "";
    inline int errors;
}

using namespace register_file_error;

inline void register_file(const std::string& folderPath, const std::string& fileName, const std::string& content) {
    try {
        bool edit = false;
        std::string line;
        std::ifstream file(fileName);
        if (!folderPath.empty() && !fs::exists(folderPath)) {
            fs::create_directories(folderPath);
        }

        fs::path fullPath = fs::path(folderPath) / fileName;
        file.open(fullPath.string());
        if (!file.is_open()) {
            if (std::ofstream outFile(fullPath); outFile.is_open()) {
                outFile << content;
                outFile.close();
            }
        } else {
            edit = true;
            if (file.is_open()) {
                unordered_set<std::string> lines;
                while (std::getline(file, line)) {
                    lines.insert(line);
                }
            }
        }

        if (edit) {
            std::unordered_set<std::string> existingLines;

            if (std::ifstream targetIn(folderPath);
                targetIn.is_open()) {
                while (std::getline(targetIn, line)) {
                    existingLines.insert(line);
                }
                targetIn.close();
            }

            std::ofstream targetOut(folderPath, std::ios::app);
            if (!file.is_open()) {
                errors += 1;
                error_ = true;
                reason = "Error: Could not open source file.";
                path = fileName;
            }

            targetOut.open(fullPath.string());
            if (!targetOut.is_open()) {
                errors += 1;
                error_ = true;
                reason = "Error: Could not create/open target file.";
                path = folderPath;
            }

            // 4. Scan source and append unique lines
            int addedCount = 0;
            while (std::getline(file, line)) {
                // If the line doesn't exist in the target file, add it
                if (existingLines.find(line) == existingLines.end()) {
                    targetOut << line << "\n";
                    existingLines.insert(line);
                    addedCount++;
                }
            }

            file.close();
            targetOut.close();


            if (!error_) {
                std::cout << "Sync complete. Added " << addedCount << " new lines to " << folderPath << "\n";
            }
        }

    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
}

#endif //SLIMES_ENCHANTED_REGISTER_H