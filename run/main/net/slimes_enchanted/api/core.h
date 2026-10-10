//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_CORE_H
#define SLIMES_ENCHANTED_CORE_H

#include "auth/register.h"
#include "auth/login.h"


namespace core_elements {
    inline bool _error_task = false;
    inline string _reason = "";
    inline string _path = "";
    inline string _file = "";
    inline int _error_count = 0;
}

namespace core_API {

    inline void get_register(const std::string& folderPath, const std::string& fileName, const std::string& content) {
        register_file(folderPath,fileName, content);
        core_elements::_error_task = error_;
        core_elements::_error_count = errors;
        core_elements::_reason = reason;
        core_elements::_path = path;
        core_elements::_file = file;
    }

    inline void get_login() {

    }

    inline void get_profile() {

    }
}

#endif //SLIMES_ENCHANTED_CORE_H
