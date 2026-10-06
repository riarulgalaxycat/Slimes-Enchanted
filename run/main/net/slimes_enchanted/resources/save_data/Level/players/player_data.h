//
// Created by realg on 07/08/2026.
//
#pragma once

#include <string>


class player_data {
public:
    static std::string need_std(const std::string& name) {
        std::string data_return = data(name);
        return data_return;
    }

    static int64_t need_int(const std::string& type, const std::string& name) {
        int64_t data_return = 0;
        if (type == "pos") {
            data_return = pos(name);
        }
        if (type == "data") {
            data_return = otherdata(name);
        }
        return data_return;
    }

private:
    static std::string data(const std::string& datafind) {
        std::string result;
        if (datafind == "name") {
            const std::string name = "GuestGuestGuestGuestGuestGuestGuestGuestGuest";
            result = name;
        }
        if (datafind == "inv") {
            const std::string Inventory = "64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,64Oak_Log,";
            result = Inventory;
        }
        if (datafind == "effects") {
            const std::string effect = "10:2;Slowness,";
            result = effect;
        }
        return result;
    }

    static int64_t pos(const std::string& datafind) {
        int64_t result = 0;
        if (datafind == "x") {
            constexpr int64_t x = 999999999999999999;
            result = x;
        }
        if (datafind == "y") {
            constexpr int64_t y = 999999999999999999;
            result = y;
        }
        return result;
    }

    static int16_t otherdata(const std::string& datafind) {
        int16_t result = 0;
        if (datafind == "HP") {
            constexpr int16_t HP = 4000;
            result = HP;
        }
        if (datafind == "Armor") {
            constexpr int16_t Armor = 100;
            result = Armor;
        }
        if (datafind == "Armor_boost") {
            constexpr int16_t Armor_boost = 50;
            result = Armor_boost;
        }
        if (datafind == "Toughness") {
            constexpr int16_t Toughness = 100;
            result = Toughness;
        }
        if (datafind == "Absorption") {
            constexpr int16_t Absorption = 75;
            result = Absorption;
        }
        if (datafind == "Regeneration_Speed") {
            constexpr int16_t Regeneration_Speed = 10;
            result = Regeneration_Speed;
        }
        if (datafind == "Speed") {
            constexpr int16_t Speed = 25;
            result = Speed;
        }
        if (datafind == "Level") {
            constexpr int16_t Level = 100;
            result = Level;
        }
        return result;
    }
};
