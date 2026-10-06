//
// Created by realg on 07/08/2026.
//
#pragma once

#include <string>

using namespace std;

class player_data {
public:
    static string need_std(const string& name) {
        string data_return = data(name);
        return data_return;
    }

    static int64_t need_int(const string& type, const string& name) {
        int64_t data_return = 0;
        if (type == "pos") {
            data_return = pos(name);
        }
        if (type == "data") {
            data_return = other_data(name);
        }
        return data_return;
    }

private:
    static string data(const string& data_find) {
        string result;
        if (data_find == "name") {
            const string name = "GuestGuestGuestGuestGuestGuestGuestGuestGuest";
            result = name;
        }
        if (data_find == "inv") {
            const string Inventory = "64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,";
            result = Inventory;
        }
        if (data_find == "effects") {
            const string effect = "10:2;Slowness,";
            result = effect;
        }
        return result;
    }

    static int64_t pos(const string& data_find) {
        int64_t result = 0;
        if (data_find == "x") {
            constexpr int64_t x = 999999999999999999;
            result = x;
        }
        if (data_find == "y") {
            constexpr int64_t y = 999999999999999999;
            result = y;
        }
        return result;
    }

    static int16_t other_data(const string& data_find) {
        int16_t result = 0;
        if (data_find == "HP") {
            constexpr int16_t HP = 4000;
            result = HP;
        }
        if (data_find == "Armor") {
            constexpr int16_t Armor = 100;
            result = Armor;
        }
        if (data_find == "Armor_boost") {
            constexpr int16_t Armor_boost = 50;
            result = Armor_boost;
        }
        if (data_find == "Toughness") {
            constexpr int16_t Toughness = 100;
            result = Toughness;
        }
        if (data_find == "Absorption") {
            constexpr int16_t Absorption = 75;
            result = Absorption;
        }
        if (data_find == "Regeneration_Speed") {
            constexpr int16_t Regeneration_Speed = 10;
            result = Regeneration_Speed;
        }
        if (data_find == "Speed") {
            constexpr int16_t Speed = 25;
            result = Speed;
        }
        if (data_find == "Level") {
            constexpr int16_t Level = 100;
            result = Level;
        }
        return result;
    }
};
