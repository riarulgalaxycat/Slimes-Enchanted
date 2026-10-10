//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_REGISTER_H
#define SLIMES_ENCHANTED_REGISTER_H

#include <string>
#include <fstream>
#include <iostream>

inline void createNewFile(const std::string& filename, const std::string& content) {

    if (std::ofstream out_file(filename); out_file.is_open()) {
        out_file << content << "\n";
        out_file.close();
        std::cout << "File '" << filename << "' created successfully!\n";
    } else {
        std::cerr << "Error: Could not create the file.\n";
    }
}

#endif //SLIMES_ENCHANTED_REGISTER_H