//
// Created by realg on 06/08/2026.
//
#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <charconv>
#include <windows.h>
#include <psapi.h>
#include "player_data.h"

inline std::string compressString(std::string_view sv) {
    if (sv.empty()) return "";
    std::string result;
    result.reserve(sv.size() / 2);
    char last_char = '\0';
    int64_t char_count = 0;
    auto flush_chars = [&]() {
        if (char_count == 0) return;
        if (char_count > 3) {
        result += last_char;
        result += '~';
            char* buf = new char[32];
            auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), char_count);
        result.append(buf, ptr - buf); result += '!';
            delete[] buf;
        } else {
            result.append(char_count, last_char);
        }
        char_count = 0;
    };
    auto emit_char = [&](char c) {
        if (char_count > 0 && c == last_char) {
            char_count++;
        } else {
            flush_chars(); last_char = c; char_count = 1;
        }
    }; auto emit_string = [&](std::string_view s) {
        for (char c : s) emit_char(c);
    };
    int64_t n = sv.size();
    int64_t i = 0;
    const int64_t MAX_PATTERN_LEN = 200;
    bool macro_compressed = false;
    for (int64_t check_i = 0; check_i < n; check_i++) {
        int64_t max_search_len = std::min((n - check_i) / 2, MAX_PATTERN_LEN);
        for (int64_t len = 1; len <= max_search_len; len++) {
            std::string_view pattern = sv.substr(check_i, len);
            if (check_i + len * 2 <= n && sv.substr(check_i + len, len) == pattern) {
                macro_compressed = true;
                break;
            }
        }
        if (macro_compressed) break;
    }
    if (!macro_compressed) {
            emit_string(sv);
            flush_chars();
            return result;
        }
    while (i < n) {
        int64_t best_len = 0;
        int64_t best_count = 0;
        int64_t max_search_len = std::min((n - i) / 2, MAX_PATTERN_LEN);
        for (int64_t len = 1; len <= max_search_len; len++) {
            std::string_view pattern = sv.substr(i, len);
            int64_t count = 1;
            while (i + (count * len) + len <= n && sv.substr(i + (count * len), len) == pattern) {
                count++;
            }
            if (count >= 2 && (len * count > best_len * best_count)) {
                best_len = len; best_count = count;
            }
        }

        if (best_count >= 2) {
            emit_string(sv.substr(i, best_len));
            emit_char('=');

            char* buf = new char[32];
            auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), best_count);

            emit_string(std::string_view(buf, ptr - buf)); emit_char('+');
            i += (best_len * best_count);
            delete[] buf;
        } else {
            int64_t start_uncompressed = i; while (i < n) {
                bool pattern_starts = false;
                int64_t next_max_search = std::min((n - i) / 2, MAX_PATTERN_LEN);
                for (int64_t len = 1; len <= next_max_search; len++) {
                    std::string_view pattern = sv.substr(i, len);
                    int64_t count = 1;
                    while (i + (count * len) + len <= n && sv.substr(i + (count * len), len) == pattern) {
                        count++;
                    }
                    if (count >= 2) {
                        pattern_starts = true;
                        break;
                    }
                } if (pattern_starts) break;
                i++;
            } if (i > start_uncompressed) {
                emit_string(sv.substr(start_uncompressed, i - start_uncompressed));
                emit_char('+');
            }
        }
    }
    flush_chars();
    return result;
}

inline std::string decompressString(std::string_view str) {
    std::string final_result;
    final_result.reserve(str.size() * 2);
    int64_t i = 0;
    char current_char = '\0';
    int64_t repeat_count = 0;
    auto get_next_char = [&]() -> bool {
        if (repeat_count > 0) {
            repeat_count--;
            return true;
        } if (i >= str.size())
            return false;
        if (i + 1 < str.size() && str[i + 1] == '~') {

            current_char = str[i]; i += 2; int64_t count = 0;
            while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i]))) {
                count = count * 10 + (str[i] - '0'); i++;
            }
            if (i < str.size()) i++; if (count > 0) {
                repeat_count = count - 1;
            }
            return true;
        } else {
            current_char = str[i++];
            return true;
        }
    };

    std::string segment;
    segment.reserve(256);
    bool in_uncompressed_stream = false;

    while (get_next_char()) {
        if (current_char == '+') {
            if (in_uncompressed_stream) {
                in_uncompressed_stream = false;
    } else {
        int64_t equal_pos = segment.find('=');
        if (equal_pos != std::string::npos) {

                    std::string_view pattern = std::string_view(segment).substr(0, equal_pos);
                    std::string_view count_str = std::string_view(segment).substr(equal_pos + 1); int64_t count = 0;
                    std::from_chars(count_str.data(), count_str.data() + count_str.size(), count);

                    for (int64_t c = 0; c < count; c++) {
                        final_result.append(pattern);
                    }
                } else {
                        final_result.append(segment);
                    }
        segment.clear();
    }
        } else {
            if
            (in_uncompressed_stream) {
                final_result += current_char;
            } else {
                segment += current_char;
            if (segment.size() > 250 && segment.find('=') == std::string::npos) {
                final_result.append(segment);
                segment.clear();
                in_uncompressed_stream = true;
            }}}
    }
    if (!segment.empty()) {
        if (const int64_t equal_pos = segment.find('='); equal_pos != std::string::npos) {
            const std::string_view pattern = std::string_view(segment).substr(0, equal_pos);
            const std::string_view count_str = std::string_view(segment).substr(equal_pos + 1); int64_t count = 0;
            std::from_chars(count_str.data(), count_str.data() + count_str.size(), count);
            for (int64_t c = 0; c < count; c++) {
                final_result.append(pattern);
            }
        } else {
            final_result.append(segment);
        }
    }
    return final_result;
}

inline std::string compress_player_cpp(
    const std::string& need,
    const bool un_or_compress,
    const std::string& name,
    const std::string& replace,
    const std::string& replace_with,
    const std::string& int_or_std,
    const bool debug,
    const bool send_compress
    ) {

    PROCESS_MEMORY_COUNTERS pmc;

    std::string input_2;
    std::string input_3;

    std::string input;

    if (int_or_std == "int") {
        const int64_t put = player_data::need_int(need, name);
        const std::string input_1 = std::to_string(put);
        input_3 = input_1;

    } if (int_or_std == "std") {
        const std::string put = player_data::need_std(name);
        input_2 = put;
    }
    if (int_or_std == "int") {
        input = input_3;
    }

    else if (int_or_std == "std") {
        input = input_2;
    }

    std::string result;

    if (un_or_compress) {
        const std::string compressed = compressString(input);
        result.append(compressed);}
    else {
        const std::string compressed = decompressString(input);
        result.append(compressed);
    }

    if (debug and !send_compress) {
        std::cout << "debug: "
        << need
        << " : "
        <<  "Compress? > " << un_or_compress
        << " | "
        << name
        << " = "
        << result
        << " |Replace: "
        << replace
        << " > "
        << replace_with
        << " | "
        << int_or_std;
        if (
            GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))
            ) {
            std::cout << " | RAM Used: " << pmc.WorkingSetSize / 1000 << " KB" << std::endl;
        }
    } else if(send_compress) {
        std::cout << result << std::endl;
    }
    return result;
}