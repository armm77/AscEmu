/*
Copyright (c) 2014-2020 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

//////////////////////////////////////////////////////////////////////////////////////////
// Allianze & Horde spawns
struct ICCSpawns
{
    uint32_t entry;
    float x;
    float y;
    float z;
    float o;
    uint32_t faction;
};

const ICCSpawns AllySpawns[13] = {
    // Light's Hammer
    { 37190, -47.59f, 2208.98f, 27.99f, 3.12f, 1732 },      // Commander
    { 37190, -47.93f, 2216.32f, 27.99f, 3.12f, 1732 },      // Commander
    { 37190, -46.08f, 2212.61f, 27.99f, 3.12f, 1732 },      // Commander
    { 37119, -48.92f, 2213.55f, 27.99f, 3.23f, 2073 },      // Highlord Tirion Fordring
    { 37200, -48.81f, 2211.06f, 27.99f, 3.14f, 1732 },      // Muradin Bronzebart
    { 39371, -49.00f, 2219.47f, 27.99f, 3.12f, 1733 },      // King Varian Wrynn <King of Stormwind>
    { 37997, -79.44f, 2269.37f, 30.66f, 5.3f, 1732 },       // Yili <Rogue Armor>
    { 37998, -70.96f, 2269.32f, 30.66f, 4.46f, 1732 },      // Talan Moonstrike <Hunter Armor>
    { 37999, -75.84f, 2270.65f, 30.66f, 4.92f, 1732 },      // Alana Moonstrike <Druid Armor>
    { 38182, -63.37f, 2260.46f, 30.65f, 1.83f, 1732 },      // Niby the Almighty <Warlock Armor>
    { 38283, -75.8f, 2283.46f, 32.87f, 4.69f, 1732 },       // Malfus Grimfrost <Mage Armor>
    { 38840, -67.79f, 2270.71f, 30.65f, 4.91f, 1732 },      // Jedebia <Shaman Armor>
    //Ramparts of Skull
    { 37200, -555.96f, 2211.4f, 539.37f, 6.27f, 1732 },      // Muradin Bronzebart
};

const ICCSpawns HordeSpawns[13] = {
    // Light's Hammer
    { 37189, -47.59f, 2208.98f, 27.99f, 3.12f, 1734 },      // General
    { 37189, -47.93f, 2216.32f, 27.99f, 3.12f, 1734 },      // General
    { 37189, -46.08f, 2212.61f, 27.99f, 3.12f, 1734 },      // General
    { 39372, -49.00f, 2219.47f, 27.99f, 3.12f, 1734 },      // Garosh Hellscream
    { 37187, -48.81f, 2211.06f, 27.99f, 3.14f, 1734 },      // Highlord Overloard Saurfang
    { 37119, -48.92f, 2213.55f, 27.99f, 3.23f, 2073 },      // Highlord Tirion Fordring
    { 37991, -79.42f, 2269.39f, 30.65f, 5.62f, 1734 },      // Ikfirus the Vile <Rogue Armor>
    { 37992, -75.76f, 2270.64f, 30.65f, 4.85f, 1734 },      // Tortunok <Druid Armor>
    { 37993, -70.92f, 2269.2f, 30.65f, 4.45f, 1734 },       // Gerardo the Suave <Hunter Armor>
    { 38181, -63.37f, 2260.46f, 30.65f, 1.83f, 1734 },      // Haragg the Unseen <Warlock Armor>
    { 38284, -75.81f, 2283.34f, 32.87f, 4.74f, 1734 },      // Uvlus Banefire <Mage Armor>
    { 38841, -67.77f, 2270.51f, 30.65f, 4.93f, 1734 },      // Vol'guk <Shaman Armor>
    //Ramparts of Skull
    { 37187, -555.96f, 2211.4f, 539.37f, 6.27f, 1734 },      // Highlord Overloard Saurfang
};

//////////////////////////////////////////////////////////////////////////////////////////
// Misc
enum IceCrownCitadelGOs
{
    //GO_Tele
    GO_TELE_1 = 202242,
    GO_TELE_2 = 202243,
    GO_TELE_3 = 202244,
    GO_TELE_4 = 202245,
    GO_TELE_5 = 202246,

    // Lower Spire Trash
    GO_SPIRIT_ALARM_1 = 201814,
    GO_SPIRIT_ALARM_2 = 201815,
    GO_SPIRIT_ALARM_3 = 201816,
    GO_SPIRIT_ALARM_4 = 201817,

    // Lord Marrogar
    GO_MARROWGAR_ICEWALL_2 = 201910,
    GO_MARROWGAR_ICEWALL_1 = 201911,
    GO_MARROWGAR_DOOR = 201857,

    // Lady Deathwhisper
    GO_ORATORY_OF_THE_DAMNED_ENTRANCE = 201563,
    GO_LADY_DEATHWHISPER_ELEVATOR = 202220,

    // Gunship Gameobjects
    GO_ORGRIM_S_HAMMER_HORDE_ICC = 201812,
    GO_ORGRIM_S_HAMMER_ALLIANCE_ICC = 201581,
    GO_THE_SKYBREAKER_HORDE_ICC = 201811,
    GO_THE_SKYBREAKER_ALLIANCE_ICC = 201580,
    GO_CAPITAN_CHEST_A_10N = 201872,
    GO_CAPITAN_CHEST_A_25N = 201873,
    GO_CAPITAN_CHEST_A_10H = 201874,
    GO_CAPITAN_CHEST_A_25H = 201875,
    GO_CAPITAN_CHEST_H_10N = 202177,
    GO_CAPITAN_CHEST_H_25N = 202178,
    GO_CAPITAN_CHEST_H_10H = 202179,
    GO_CAPITAN_CHEST_H_25H = 202180,

    // Deathbringer Saurfang
    GO_SAURFANG_S_DOOR = 201825,
    GO_DEATHBRINGER_S_CACHE_10N = 202239,
    GO_DEATHBRINGER_S_CACHE_25N = 202240,
    GO_DEATHBRINGER_S_CACHE_10H = 202238,
    GO_DEATHBRINGER_S_CACHE_25H = 202241,
    GO_SCOURGE_TRANSPORTER_SAURFANG = 202244,

    // Professor Putricide
    GO_ORANGE_PLAGUE_MONSTER_ENTRANCE = 201371,
    GO_GREEN_PLAGUE_MONSTER_ENTRANCE = 201370,
    GO_SCIENTIST_AIRLOCK_DOOR_COLLISION = 201612,
    GO_SCIENTIST_AIRLOCK_DOOR_ORANGE = 201613,
    GO_SCIENTIST_AIRLOCK_DOOR_GREEN = 201614,
    GO_DOODAD_ICECROWN_ORANGETUBES02 = 201617,
    GO_DOODAD_ICECROWN_GREENTUBES02 = 201618,
    GO_SCIENTIST_ENTRANCE = 201372,
    GO_DRINK_ME = 201584,
    GO_PLAGUE_SIGIL = 202182,

    // Blood Prince Council
    GO_CRIMSON_HALL_DOOR = 201376,
    GO_BLOOD_ELF_COUNCIL_DOOR = 201378,
    GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT = 201377,

    // Blood-Queen Lana'thel
    GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01 = 201746,
    GO_DOODAD_ICECROWN_GRATE_01 = 201755,
    GO_BLOODWING_SIGIL = 202183,

    // Valithria Dreamwalker
    GO_GREEN_DRAGON_BOSS_ENTRANCE = 201375,
    GO_GREEN_DRAGON_BOSS_EXIT = 201374,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_01 = 201380,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_02 = 201381,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_03 = 201382,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_04 = 201383,
    GO_CACHE_OF_THE_DREAMWALKER_10N = 201959,
    GO_CACHE_OF_THE_DREAMWALKER_25N = 202339,
    GO_CACHE_OF_THE_DREAMWALKER_10H = 202338,
    GO_CACHE_OF_THE_DREAMWALKER_25H = 202340,

    // Sindragosa
    GO_SINDRAGOSA_ENTRANCE_DOOR = 201373,
    GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR = 201369,
    GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR = 201379,
    GO_ICE_WALL = 202396,
    GO_ICE_BLOCK = 201722,
    GO_SIGIL_OF_THE_FROSTWING = 202181,

    // The Lich King
    GO_SCOURGE_TRANSPORTER_LK = 202223,
    GO_ARTHAS_PLATFORM = 202161,
    GO_ARTHAS_PRECIPICE = 202078,
    GO_DOODAD_ICECROWN_THRONEFROSTYWIND01 = 202188,
    GO_DOODAD_ICECROWN_THRONEFROSTYEDGE01 = 202189,
    GO_DOODAD_ICESHARD_STANDING02 = 202141,
    GO_DOODAD_ICESHARD_STANDING01 = 202142,
    GO_DOODAD_ICESHARD_STANDING03 = 202143,
    GO_DOODAD_ICESHARD_STANDING04 = 202144,
    GO_DOODAD_ICECROWN_SNOWEDGEWARNING01 = 202190,
    GO_FROZEN_LAVAMAN = 202436,
    GO_LAVAMAN_PILLARS_CHAINED = 202437,
    GO_LAVAMAN_PILLARS_UNCHAINED = 202438,
};

enum IceCrownCitadelNpcEntrys
{
    // Gunship
    NPC_GB_SKYBREAKER = 37540,
    NPC_GB_ORGRIMS_HAMMER = 37215,
    NPC_GB_HIGH_OVERLORD_SAURFANG = 36939,
    NPC_GB_MURADIN_BRONZEBEARD = 36948,
    NPC_GB_HIHG_CAPTAIN_JUSTIN_BARTLETT = 37182,
    NPC_GB_HIGH_OVERLORD_SAURFANG_NOT_VISUAL = 50004,
    NPC_GB_MURADIN_BRONZEBEARD_NOT_VISUAL = 50006,
    NPC_GB_SKYBREAKER_SORCERER = 37026,
    NPC_GB_SKYBREAKER_SORCERERS = 37116,
    NPC_GB_KORKRON_REAVER = 37920,
    NPC_GB_KORKRON_REAVERS = 36957,
    NPC_GB_KORKRON_SERGANTE = 36960,
    NPC_GB_SKYBREAKER_SERGANTE = 36961,
    NPC_GB_KORKRON_BATTLE_MAGE = 37117,
    NPC_GB_SKYBREAKER_MARINE = 36950,
    NPC_GB_KORKRON_ROCKETEER = 36982,
    NPC_GB_SKYBREAKER_MORTAR_SOLDIER = 36978,
    NPC_GB_KORKRON_AXETHROWER = 36968,
    NPC_GB_SKYBREAKER_RIFLEMAN = 36969,
    NPC_GB_SKYBREAKER_DECKHAND = 36970,
    NPC_GB_ZAFOD_BOOMBOX = 37184,
    NPC_GB_ALLIANCE_CANON = 36838,
    NPC_GB_HORDE_CANON = 36839,
    NPC_GB_INVISIBLE_STALKER = 32780,
    NPC_GB_PORTAL = 37227,
    NPC_GB_GUNSHIP_HULL = 37547,

    NPC_KORKRON_INVOKER = 37033,
    NPC_SPIRE_FROSTWYRM = 37230,
    NPC_SKYBREAKER_SORCERER = 37026,
};

enum IceCrownCitadelCNentry
{
   CN_LORD_MARROWGAR        = 36612,
   CN_COLDFLAME             = 36672,
   CN_BONE_SPIKE            = 36619,
   CN_LADY_DEATHWHISPER     = 36855,
   CN_VALITHRIA_DREAMWALKER = 36789,
};

static Movement::Location Doors[] =
{
    { -407.35f, 2147.88f, 42.85f, 0 },       //IceWall1
    { -412.97f, 2285.24f, 42.01f, 0 },       //IceWall2
    { -520.44f, 2211.47f, 63.14f, 0 },       //Door behinde ice problem with viewing distance....
};

// Teleport coords for Gossip
static float ICCTeleCoords[6][5] =
{    // moving this to a clean mysql table with all teleports in it... maybe as spell or event?
    { MAP_ICECROWNCITADEL, -17.856115f, 2211.640137f, 30.115812f, 0.0f },     //1   Teleport to Light's Hammer 
    { MAP_ICECROWNCITADEL, -503.632599f, 2211.219971f, 62.823246f, 0.0f },    //2   Teleport to Oratory of The Damned
    { MAP_ICECROWNCITADEL, -615.098267f, 2211.509766f, 199.973083f, 0.0f },   //3   Teleport to Rampart of Skulls 
    { MAP_ICECROWNCITADEL, -549.151001f, 2211.463967f, 539.290222f, 0.0f },   //4   Teleport to Deathbringer's Rise 
    { MAP_ICECROWNCITADEL, 4356.780273f, 2863.636230f, 349.337982f, 0.0f },   //5   Teleport to the Upper Spire.
    { MAP_ICECROWNCITADEL, 4453.248535f, 2769.325684f, 349.347473f, 0.0f }    //6   Teleport to Sindragosa's Lair
};

enum Spells
{
    SPELL_ALLIANCE_PHASE = 55774,
    SPELL_HORDE_PHASE = 55773,

    // Lord Marrowgar
    SPELL_BONE_SLICE = 69055,
    SPELL_BONE_STORM = 69076,
    SPELL_BONE_SPIKE_GRAVEYARD = 69057,
    SPELL_COLDFLAME_NORMAL = 69140,
    SPELL_COLDFLAME_BONE_STORM = 72705,

    // Bone Spike
    SPELL_IMPALED = 69065,
    SPELL_RIDE_VEHICLE = 46598,

    // Coldflame
    SPELL_COLDFLAME_PASSIVE = 69145,
    SPELL_COLDFLAME_SUMMON = 69147,

    // Rotting Frost Giant
    SPELL_DEATH_PLAGUE = 72879,
    SPELL_DEATH_PLAGUE_AURA = 72865,
    SPELL_RECENTLY_INFECTED = 72884,
    SPELL_DEATH_PLAGUE_KILL = 72867,
    SPELL_STOMP = 64652,
    SPELL_ARCTIC_BREATH = 72848,

    // Frost Freeze Trap
    SPELL_COLDFLAME_JETS = 70460,

    // Alchemist Adrianna
    SPELL_HARVEST_BLIGHT_SPECIMEN = 72155,
    SPELL_HARVEST_BLIGHT_SPECIMEN25 = 72162,

    // Crok Scourgebane
    SPELL_ICEBOUND_ARMOR = 70714,
    SPELL_SCOURGE_STRIKE = 71488,
    SPELL_DEATH_STRIKE = 71489,

    // Sister Svalna
    SPELL_CARESS_OF_DEATH = 70078,
    SPELL_IMPALING_SPEAR_KILL = 70196,
    SPELL_REVIVE_CHAMPION = 70053,
    SPELL_UNDEATH = 70089,
    SPELL_IMPALING_SPEAR = 71443,
    SPELL_AETHER_SHIELD = 71463,
    SPELL_HURL_SPEAR = 71466,

    // Captain Arnath
    SPELL_DOMINATE_MIND = 14515,
    SPELL_FLASH_HEAL_NORMAL = 71595,
    SPELL_POWER_WORD_SHIELD_NORMAL = 71548,
    SPELL_SMITE_NORMAL = 71546,
    SPELL_FLASH_HEAL_UNDEAD = 71782,
    SPELL_POWER_WORD_SHIELD_UNDEAD = 71780,
    SPELL_SMITE_UNDEAD = 71778,

    // Captain Brandon
    SPELL_CRUSADER_STRIKE = 71549,
    SPELL_DIVINE_SHIELD = 71550,
    SPELL_JUDGEMENT_OF_COMMAND = 71551,
    SPELL_HAMMER_OF_BETRAYAL = 71784,

    // Captain Grondel
    SPELL_CHARGE = 71553,
    SPELL_MORTAL_STRIKE = 71552,
    SPELL_SUNDER_ARMOR = 71554,
    SPELL_CONFLAGRATION = 71785,

    // Captain Rupert
    SPELL_FEL_IRON_BOMB_NORMAL = 71592,
    SPELL_MACHINE_GUN_NORMAL = 71594,
    SPELL_ROCKET_LAUNCH_NORMAL = 71590,
    SPELL_FEL_IRON_BOMB_UNDEAD = 71787,
    SPELL_MACHINE_GUN_UNDEAD = 71788,
    SPELL_ROCKET_LAUNCH_UNDEAD = 71786,

    // Invisible Stalker (Float, Uninteractible, LargeAOI)
    SPELL_SOUL_MISSILE = 72585,
};

void SetupICC(ScriptMgr* mgr);
