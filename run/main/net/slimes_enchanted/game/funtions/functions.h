//
// Created by realg on 06/08/2026.
//
#pragma once

#include <iostream>
#include <string>

#include "functions_list.h"

namespace se_functions {
    static string functions(const string &need, const string &put) {
        functions_list MCF;
        const string Function = need;
        const string Type = MCF.Functions = put;

        string output =  Function + ":" + Type;
        return output;
    }
}