//
// Created by realg on 07/08/2026.
//
#pragma once

#include "Level/players/compress_player_cpp.h"


inline std::string compresser(const std::string& type, const std::string& need, const bool un_or_compress, const std::string& name, const std::string& replace, const std::string& replace_with, const std::string& int_or_std, const bool debug, const bool send_compress) {
    std::string compressed;
    if (type == "player") {
        compressed = compress_player_cpp(need, un_or_compress, name, replace, replace_with, int_or_std, debug, send_compress);
    }
    return compressed;
}