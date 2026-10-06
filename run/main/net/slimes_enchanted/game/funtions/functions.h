//
// Created by realg on 06/08/2026.
//
#pragma once

#include <iostream>
#include <string>

#include "functions_list.h"

namespace se_functions {
    static void functions(const std::string &need, const std::string &put) {
        functions_list MCF;
        const std::string Function = need;
        const std::string Type = MCF.Functions = put;

        std::cout << Function <<":" << Type;
    }
}