//
// Created by realg on 10/10/2026.
//

#ifndef SLIMES_ENCHANTED_CORE_H
#define SLIMES_ENCHANTED_CORE_H

#include "auth/register.h"
#include "auth/login.h"

namespace core_API {
    inline void get_register(const std::string& folderPath, const std::string& fileName, const std::string& content) {
        register_file(folderPath,fileName, content);
    }

    inline void get_login() {

    }

    inline void get_profile() {

    }
}

#endif //SLIMES_ENCHANTED_CORE_H
