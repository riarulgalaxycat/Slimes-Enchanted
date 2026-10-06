//
// Created by realg on 17/09/2026.
//
#pragma once

#include <chrono>

const auto start = std::chrono::high_resolution_clock::now();

inline auto time(const int need) {
        if (need == 1) {return start;}
        if (need == 2) {const auto end = std::chrono::high_resolution_clock::now(); return end;}
        if (need == 3) {const auto run_time = std::chrono::high_resolution_clock::now(); return run_time;}
}

inline auto added_time(const int need) {
        std::chrono::__enable_if_is_duration<std::chrono::milliseconds> duration;
        if (need == 1) {duration = std::chrono::duration_cast<std::chrono::milliseconds>(time(2) - start);}
        if (need == 2) {duration = std::chrono::duration_cast<std::chrono::milliseconds>(time(3) - start);}
        return duration;
}
