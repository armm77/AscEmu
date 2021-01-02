/*
Copyright (c) 2014-2021 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

enum
{
    //BASE_RESOURCES_GAIN = 10,
    RESOURCES_WARNING_THRESHOLD = 1400,
    RESOURCES_WINVAL = 1600,

    AB_BUFF_RESPAWN_TIME = 90000
};

enum ABBuffs
{
    AB_BUFF_STABLES = 0,
    AB_BUFF_BLACKSMITH = 1,
    AB_BUFF_FARM = 2,
    AB_BUFF_LUMBERMILL = 3,
    AB_BUFF_MINE = 4,
    AB_NUM_BUFFS = 5
};

enum ABControlPoints
{
    AB_CONTROL_POINT_STABLE = 0,
    AB_CONTROL_POINT_FARM = 1,
    AB_CONTROL_POINT_BLACKSMITH = 2,
    AB_CONTROL_POINT_MINE = 3,
    AB_CONTROL_POINT_LUMBERMILL = 4,
    AB_NUM_CONTROL_POINTS = 5
};

enum ABSpawnTypes
{
    AB_SPAWN_TYPE_NEUTRAL = 0,
    AB_SPAWN_TYPE_ALLIANCE_ASSAULT = 1,
    AB_SPAWN_TYPE_HORDE_ASSAULT = 2,
    AB_SPAWN_TYPE_ALLIANCE_CONTROLLED = 3,
    AB_SPAWN_TYPE_HORDE_CONTROLLED = 4,
    AB_NUM_SPAWN_TYPES = 5
};
