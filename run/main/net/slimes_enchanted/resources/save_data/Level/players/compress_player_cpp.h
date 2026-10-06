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

inline string compressString(string_view sv) {
    if (sv.empty()) return "";
    string result;
    result.reserve(sv.size() / 2);
    char last_char = '\0';
    int64_t char_count = 0;
    auto flush_chars = [&]() {
        if (char_count == 0) return;
        if (char_count > 3) {
        result += last_char;
        result += '~';
            const auto buf = new char[32];
            auto [ptr, ec] = to_chars(buf, buf + sizeof(buf), char_count);
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
    }; auto emit_string = [&](const string_view s) {
        for (const char c : s) emit_char(c);
    };
    const int64_t n = sv.size();
    int64_t i = 0;
    constexpr int64_t MAX_PATTERN_LEN = 200;
    bool macro_compressed = false;
    for (int64_t check_i = 0; check_i < n; check_i++) {
        const int64_t max_search_len = min((n - check_i) / 2, MAX_PATTERN_LEN);
        for (int64_t len = 1; len <= max_search_len; len++) {
            if (const string_view pattern = sv.substr(check_i, len); check_i + len * 2 <= n && sv.substr(check_i + len, len) == pattern) {
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
        const int64_t max_search_len = min((n - i) / 2, MAX_PATTERN_LEN);
        for (int64_t len = 1; len <= max_search_len; len++) {
            const string_view pattern = sv.substr(i, len);
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

            const auto buf = new char[32];
            auto [ptr, ec] = to_chars(buf, buf + sizeof(buf), best_count);

            emit_string(string_view(buf, ptr - buf)); emit_char('+');
            i += (best_len * best_count);
            delete[] buf;
        } else {
            const int64_t start_uncompressed = i; while (i < n) {
                bool pattern_starts = false;
                const int64_t next_max_search = min((n - i) / 2, MAX_PATTERN_LEN);
                for (int64_t len = 1; len <= next_max_search; len++) {
                    const string_view pattern = sv.substr(i, len);
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

inline string decompressString(string_view str) {
    string final_result;
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
            while (i < str.size() && isdigit(static_cast<unsigned char>(str[i]))) {
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

    string segment;
    segment.reserve(256);
    bool in_uncompressed_stream = false;

    while (get_next_char()) {
        if (current_char == '+') {
            if (in_uncompressed_stream) {
                in_uncompressed_stream = false;
    } else {
                if (const int64_t equal_pos = segment.find('='); equal_pos != string::npos) {

                    string_view pattern = string_view(segment).substr(0, equal_pos);
                    string_view count_str = string_view(segment).substr(equal_pos + 1); int64_t count = 0;
                    from_chars(count_str.data(), count_str.data() + count_str.size(), count);

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
            if (segment.size() > 250 && segment.find('=') == string::npos) {
                final_result.append(segment);
                segment.clear();
                in_uncompressed_stream = true;
            }}}
    }
    if (!segment.empty()) {
        if (const int64_t equal_pos = segment.find('='); equal_pos != string::npos) {
            const string_view pattern = string_view(segment).substr(0, equal_pos);
            const string_view count_str = string_view(segment).substr(equal_pos + 1); int64_t count = 0;
            from_chars(count_str.data(), count_str.data() + count_str.size(), count);
            for (int64_t c = 0; c < count; c++) {
                final_result.append(pattern);
            }
        } else {
            final_result.append(segment);
        }
    }
    return final_result;
}

inline string compress_player_cpp(
    const string& need,
    const bool un_or_compress,
    const string& name,
    const string& replace,
    const string& replace_with,
    const string& int_or_std,
    const bool debug,
    const bool send_compress
    ) {

    PROCESS_MEMORY_COUNTERS pmc;

    string input;

    if (int_or_std == "int") {
        const int64_t put = player_data::need_int(need, name);
        const string covert = to_string(put);
        input = covert;

    } if (int_or_std == "std") {
        const string put = player_data::need_std(name);
        input = put;
    }

    string result;

    if (un_or_compress) {
        const string compressed = compressString(input);
        result.append(compressed);
    }
    else {
        const string compressed = decompressString(input);
        result.append(compressed);
    }

    if (debug and !send_compress) {
        cout << "debug: "
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
            cout << " | RAM Used: " << pmc.WorkingSetSize / 1000 << " KB" << endl;
        }
    } else if(send_compress) {
        cout << result << endl;
    }
    return result;
}