//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_CORE_H
#define SLIMES_ENCHANTED_CORE_H

#include "auth/register.h"
#include "auth/login.h"
#include <filesystem>

namespace fs = std::filesystem;

namespace se_core_elements {
    inline bool _error_task = false;
    inline std::string _reason = "";
    inline std::string _path = "";
    inline std::string _file = "";
    inline int _error_count = 0;
}

namespace se_core_API {

    inline void get_register(const std::string& folderPath, const std::string& fileName, const std::string& content) {
        std::string PathName = folderPath + "/" + fileName;
        std::cout << PathName << std::endl;
        if (fs::path pathfile = PathName; !fs::exists(pathfile)) {
        } else {
            std::cout << "creating file " << folderPath << " | " << fileName << "\n";
            register_file(folderPath,fileName, content);
            std::cout << "created " << PathName << "\n";
            se_core_elements::_error_task = error_;
            se_core_elements::_error_count = errors;
            se_core_elements::_reason = reason;
            se_core_elements::_path = path;
            se_core_elements::_file = file;
        }
    }

    inline void get_login() {

    }

    inline void update_file() {

    }
}

#endif //SLIMES_ENCHANTED_CORE_H
