//
// Created by realg on 06/08/2026.
//
#pragma once

#include <cstdint>

class functions_list {
    public:
        // Custom&Natural Functions
        // std
            //Item
        std::string Enchantments;
        std::string Creator;
                //Natural (1 Line)
        std::string Creation_Date;
            //All
        std::string Functions;

        // int
            //Entity
        int64_t HP;
        int64_t Toughness;
        int64_t Absorption;
        int64_t Regeneration_Speed;
        int64_t Speed;

            //Block
        int64_t Face_North;
        int64_t Face_East;
        int64_t Face_South;
        int64_t Face_West;
        int64_t Powered;

            //Item
        int64_t Durability;
        int64_t Unbreakable;
                //Natural (Rest of the lines)
            //Entity
        int64_t Boss;
        int64_t Size;
        int64_t Level;

            //Block
        int64_t Break_Time;
        int64_t Block_Upgrade_Level;
        int64_t Durability_To_Explosions;
};