//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_CORE_H
#define SLIMES_ENCHANTED_CORE_H

#include "auth/register.h"
#include "auth/login.h"


namespace se_core_elements {
    inline bool _error_task = false;
    inline std::string _reason = "";
    inline std::string _path = "";
    inline std::string _file = "";
    inline int _error_count = 0;
}

namespace se_core_API {

    inline void get_register(const std::string& folderPath, const std::string& fileName, const std::string& content) {
        register_file(folderPath,fileName, content);
        se_core_elements::_error_task = error_;
        se_core_elements::_error_count = errors;
        se_core_elements::_reason = reason;
        se_core_elements::_path = path;
        se_core_elements::_file = file;
    }

    inline void get_login() {

    }

    inline void get_profile() {

    }
}

#endif //SLIMES_ENCHANTED_CORE_H
