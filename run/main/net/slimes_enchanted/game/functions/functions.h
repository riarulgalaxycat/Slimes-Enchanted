//
// Created by realg on 06/08/2026.
//
#pragma once

#include <iostream>
#include <string>

#include "functions_list.h"

namespace functions {
    static string functions_string(const string &need, const string& put) {
        functions_list MCF;
        const string Function = need;
        const string Type = MCF.Functions = put;

        string output =  Function + ":" + Type;
        return output;
    }
    static string functions_int(const string &need, const int64_t put) {
        functions_list MCF;
        const string Function = need;
        const string Type = MCF.Functions = to_string(put);

        string output =  Function + ":" + Type;
        return output;
    }
}