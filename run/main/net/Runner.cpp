//
// Created by realg on 06/08/2026.
//

#include <chrono>
#include <iostream>

#include "slimes_enchanted/resources/menu/settings/general.h"
#include "slimes_enchanted/resources/menu/settings/others.h"
#include "slimes_enchanted/resources/menu/settings/Controls/controls.h"
#include "slimes_enchanted/resources/save_data/compress.h"
#include "slimes_enchanted/resources/menu/settings/World/Optimations/Opti.h"
#include "slimes_enchanted/resources/time.h"
#include "slimes_enchanted/game/funtions/functions.h"

using namespace std;
using namespace se_functions;

static bool compress = true;
static bool crashed = false;
static bool debug = false;
static bool override_debug = true;
static bool override_test = true;

int main() {

    if (!no_timer) {
        time(1);
    }

    if (fast_loading and !override_debug) {
        debug = false;
    }
    if (debug_launch or override_debug) {
        debug = true;
    }

    if (load_resources_during_game_load) {

        //This is a example how it works
        if (test_game or override_test and !no_compress_test) {
            compresser("player", "data", compress, "name", "", "", "std", debug, no_compress_result);
            compresser("player", "data", compress, "inv", "", "", "std", debug, no_compress_result);
            compresser("player", "data", compress, "effects", "", "", "std", debug, no_compress_result);
            compresser("player", "pos", compress, "x", "", "", "int", debug, no_compress_result);
            compresser("player", "pos", compress, "y", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "HP", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Armor", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Armor_boost", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Toughness", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Absorption", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Regeneration_Speed", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Speed", "", "", "int", debug, no_compress_result);
            compresser("player", "data", compress, "Level", "", "", "int", debug, no_compress_result);
        }
    }
    if (debug) {
        if (!no_compress_result) {
            cout << "(Compress? 1 = true, 0 = false)\n" << "Debug mode enabled" << endl;
        } else {
            cout << "Debug mode enabled" << endl;
        }
        cout << debug_launch <<
            test_game <<command_button <<chat_button <<player_list <<attack_and_break_button <<place_button <<quick_drop_button <<off_hand_button <<gui_scale <<
                fullscreen <<sync <<blocky_lighting <<pixel_lighting <<fast_particles <<fast_events <<ray_lighting <<fast_loading <<
                    load_resources_during_game_load <<no_timer <<no_exit_Code <<no_compress_test <<no_compress_result <<endl;
        cout << "Overide Debug?: " << override_debug << "\nOverride Test?: " << override_test << endl;
    }

    if (!no_timer) {
        time(2);
    }

    if (!no_timer and debug_launch) {
        cout << "Task took " << added_time(1).count() << " milliseconds." << endl;
    }


    try {}
    catch (const exception& e) {
        cerr << "Fatal Error: " << e.what() << endl;
        crashed = true;
    }

    cout << functions("Creation_Date","Day/Hour.Minute") << endl;

    if (test_game or override_test and !no_exit_Code) {
        if (crashed) {
            cout << "Test exit code: 2.";
        }
        else {
            cout << "Test exit code: 1.";
        }
        cout << "\n" << "Test exit codes: 0=Closed Application, 1=Test Completed, 2=Crashed, 3=Game could not launch, 4=Failed a task(Movement(collision)aka Error: 1, Generation aka Error: 2, Locating Texture aka Error: 3. This is for the game running to aka [Running game error codes:]" << endl;
    }

    if (!no_timer) {
        time(3);
    }

    if (!no_timer) {
        cout << "run time " << added_time(2).count() << " milliseconds." << endl;
    }

    if (crashed) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
