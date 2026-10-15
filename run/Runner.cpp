//
// Created by realg on 06/08/2026.
//

#include <chrono>
#include <iostream>

#include "main/net/slimes_enchanted/api/core.h"
#include "main/net/slimes_enchanted/game/functions/functions.h"
#include "main/net/slimes_enchanted/resources/time.h"
#include "main/net/slimes_enchanted/resources/menu/settings/others.h"
#include "main/net/slimes_enchanted/resources/menu/settings/World/Optimations/Opti.h"

static bool crashed = false;
static bool debug = false;
static bool override_debug = true;
static bool override_test = true;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (!no_timer) {
        se_timer::time(1);
    }

    se_core_API::get_register("../run/main/net/slimes_enchanted/api/player_data","player_data.yml", "../run/main/net/slimes_enchanted/api/player/player_data.yml");

    if (fast_loading and !override_debug and !debug_launch) {
        debug = false;
    } else {
        debug = true;
    }

    if (debug) {
        std::cout << "Debug mode enabled" << '\n';
        
        //this is a example, so disable this two during testing.
        std::cout << se_functions::functions_string("Creation_Date","Day/Hour.Minute") << '\n';
        std::cout << se_functions::functions_int("Creation_Date",63452) << '\n';
        //

        std::cout << "Override Debug?: " << override_debug << "\nOverride Test?: " << override_test << '\n';
    }

    if (!no_timer) {
        se_timer::time(2);
        if (debug) {
            std::cout << "Task took " << se_timer::added_time(1).count() << " milliseconds." << '\n';
        }
    }


    try {

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << '\n';
        crashed = true;
    }

    if (test_game or override_test and !no_exit_Code) {
        if (crashed) {
            std::cerr << "Test exit code: 2.";
        }
        else {
            if (se_core_elements::_error_task) {
                std::cerr << "Test exit code: " << 4 << '\n';
                std::cerr << "error count: " << se_core_elements::_error_count << '\n' << se_core_elements::_reason << '\n';
                if (!se_core_elements::_path.empty()) {
                    std::cerr << "path: " << se_core_elements::_path << "\n";
                }
                if (!se_core_elements::_file.empty()) {
                    std::cerr << "file: " << se_core_elements::_file << '\n';
                }
            } else {
                std::cout << "Test exit code: 1.\n";
            }
        }
        std::cout << "Test exit codes: 0=Closed Application, 1=Test Completed, 2=Crashed, 3=Game could not launch, 4=Failed a task(Movement(collision) Error: 1, Generation Error: 2, Locating Texture Error: 3. This is for the game running to aka [Running game error codes:]" << '\n';
    }

    if (!no_timer) {
        se_timer::time(3);
        std::cout << "run time " << se_timer::added_time(2).count() << " milliseconds." << std::endl;
    }

    if (crashed) {
        return EXIT_FAILURE;
    } {
        return EXIT_SUCCESS;
    }
}
