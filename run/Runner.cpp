//
// Created by realg on 06/08/2026.
//

#include <chrono>
#include <iostream>

#include "main/net/slimes_enchanted/resources/menu/settings/others.h"
#include "main/net/slimes_enchanted/resources/menu/settings/World/Optimations/Opti.h"
#include "main/net/slimes_enchanted/se.h"

using namespace se::game_core;

static bool crashed = false;
static bool debug = false;
static bool override_debug = true;
static bool override_test = true;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!no_timer) {
        time(1);
    }

    get_register("../run/main/net/slimes_enchanted/player_data","player_data.yml",
        "Username:\nPassword:\nNickname:");

    if (fast_loading and !override_debug) {
        debug = false;
    }
    if (debug_launch or override_debug) {
        debug = true;
    }

    if (debug) {
        cout << "Debug mode enabled" << '\n';
        
        //this is a example, so disable this two during testing.
        cout << functions_string("Creation_Date","Day/Hour.Minute") << '\n';
        cout << functions_int("Creation_Date",63452) << '\n';
        //

        cout << "Override Debug?: " << override_debug << "\nOverride Test?: " << override_test << '\n';
    }

    if (!no_timer) {
        time(2);
    }

    if (!no_timer and debug_launch) {
        cout << "Task took " << added_time(1).count() << " milliseconds." << '\n';
    }


    try {

    }
    catch (const exception& e) {
        cerr << "Fatal Error: " << e.what() << '\n';
        crashed = true;
    }

    if (test_game or override_test and !no_exit_Code) {
        if (crashed) {
            cout << "Test exit code: 2.";
        }
        else {
            if (_error_task) {
                cerr << "Test exit code: " << 4 << '\n';
                cerr << "error count: " << _error_count << '\n' << _reason << '\n';
                if (!_path.empty()) {
                    cerr << "path: " << _path << "\n";
                }
                if (!_file.empty()) {
                    cerr << "file: " << _file << '\n';
                }
            } else {
                cout << "Test exit code: 1.\n";
            }
        }
        cout << "Test exit codes: 0=Closed Application, 1=Test Completed, 2=Crashed, 3=Game could not launch, 4=Failed a task(Movement(collision)aka Error: 1, Generation aka Error: 2, Locating Texture aka Error: 3. This is for the game running to aka [Running game error codes:]" << '\n';
    }

    if (!no_timer) {
        time(3);
    }

    if (!no_timer) {
        cout << "run time " << added_time(2).count() << " milliseconds." << endl;
    }

    if (crashed) {
        return EXIT_FAILURE;
    } {
        return EXIT_SUCCESS;
    }
}
