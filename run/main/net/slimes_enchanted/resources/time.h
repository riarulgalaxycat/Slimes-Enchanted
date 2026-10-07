//
// Created by realg on 17/09/2026.
//
#pragma once

#include <chrono>

using namespace std::chrono;

const auto start = high_resolution_clock::now();

inline auto time(const int need) {
        if (need == 1) {
                return start;
        }
        if (need == 2) {
                const auto end = high_resolution_clock::now();
                return end;
        }
        if (need == 3) {
                const auto run_time = high_resolution_clock::now();
                return run_time;
        }
}

inline auto added_time(const int need) {
        __enable_if_is_duration<milliseconds> duration;
        if (need == 1) {
                duration = duration_cast<milliseconds>(time(2) - start);
        }
        if (need == 2) {
                duration = duration_cast<milliseconds>(time(3) - start);
        }
        return duration;
}
