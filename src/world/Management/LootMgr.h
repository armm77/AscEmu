/*
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (c) 2014-2019 AscEmu Team <http://www.ascemu.org>
 * Copyright (C) 2008-2012 ArcEmu Team <http://www.ArcEmu.org/>
 * Copyright (C) 2005-2007 Ascent Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOOTMGR_H
#define LOOTMGR_H

#include "Server/EventableObject.h"
#include "Storage/DBC/DBCStructures.hpp"
#if VERSION_STRING >= Cata
    #include "Storage/DB2/DB2Structures.h"
#endif

#include <map>
#include <vector>
#include <set>

enum LOOTTYPE
{
    LOOT_NORMAL10,      // normal dungeon / old raid (10/25/40 men) / normal 10 raid
    LOOT_NORMAL25,      // heroic dungeon / normal 25 raid
    LOOT_HEROIC10,      // heroic 10 men raid
    LOOT_HEROIC25,      // heroic 25 men raid
    NUM_LOOT_TYPES
};

struct ItemProperties;
class MapMgr;
class Player;

class LootRoll : public EventableObject
{
    public:

        LootRoll(uint32 timer, uint32 groupcount, uint64 guid, uint32 slotid, uint32 itemid, uint32 itemunk1, uint32 itemunk2, MapMgr* mgr);
        ~LootRoll();

        void PlayerRolled(Player* player, uint8 choice);
        void Finalize();
        int32 event_GetInstanceID();

    private:

        std::map<uint32, uint32> m_NeedRolls;
        std::map<uint32, uint32> m_GreedRolls;
        std::set<uint32> m_passRolls;
        uint32 _groupcount;
        uint32 _slotid;
        uint32 _itemid;
        uint32 _randomsuffixid;
        uint32 _randompropertyid;
        uint32 _remaining;
        uint64 _guid;
        MapMgr* _mgr;
};

typedef std::vector<std::pair<DBC::Structures::ItemRandomPropertiesEntry const*, float>> RandomPropertyVector;
typedef std::vector<std::pair<DBC::Structures::ItemRandomSuffixEntry const*, float>> RandomSuffixVector;

struct _LootItem
{
    ItemProperties const* itemproto;
    uint32 displayid;
};

typedef std::set<uint32> LooterSet;

struct __LootItem
{
    _LootItem item;
    uint32 iItemsCount;
    DBC::Structures::ItemRandomPropertiesEntry const* iRandomProperty;
    DBC::Structures::ItemRandomSuffixEntry const* iRandomSuffix;
    LootRoll* roll;
    bool passed;
    LooterSet has_looted;
    uint32 ffa_loot;
    bool looted;

    __LootItem()
    {
        looted = false;
        item.itemproto = nullptr;
        item.displayid = 0;
        iItemsCount = 0;
        iRandomProperty = nullptr;
        iRandomSuffix = nullptr;
        roll = nullptr;
        passed = false;
        ffa_loot = 0;
    }
};


class ItemIsLooted
{
    public:

        bool operator()(const __LootItem &item)
        {
            if (item.looted)
                return true;
            else
                return false;
        }
};


class ItemIsNotLooted
{
    public:

        bool operator()(const __LootItem &item)
        {
            if (!item.looted)
                return true;
            else
                return false;
        }
};

struct StoreLootItem
{
    _LootItem item;     /// the item that drops
    float chance;       /// normal dungeon / normal 10men raid / old raid (10,25, or 40 men)
    float chance2;      /// heroic dungeon / normal 25men raid
    float chance3;      /// heroic 10men raid
    float chance4;      /// heroic 25men raid
    uint32 mincount;    /// minimum quantity to drop
    uint32 maxcount;    /// maximum quantity to drop
    uint32 ffa_loot;    /// can everyone from the group loot the item?
};

struct StoreLootList
{
    uint32 count;
    StoreLootItem* items;
};

struct Loot
{
    std::vector<__LootItem> items;
    uint32 gold;
    LooterSet looters;

    Loot()
    {
        gold = 0;
    }

    bool HasRoll()
    {
        for (std::vector<__LootItem>::iterator itr = items.begin(); itr != items.end(); ++itr)
        {
            if (itr->roll != NULL)
                return true;
        }
        return false;
    }

    bool any() const;
};

struct tempy
{
    uint32 itemid;
    float chance;
    float chance_2;
    float chance3;
    float chance4;
    uint32 mincount;
    uint32 maxcount;
};

typedef std::map<uint32, StoreLootList> LootStore;

#define PARTY_LOOT_FFA 0
#define PARTY_LOOT_MASTER 2
#define PARTY_LOOT_RR 1
#define PARTY_LOOT_NBG 4
#define PARTY_LOOT_GROUP 3


class SERVER_DECL LootMgr
{
    private:

        LootMgr() = default;
        ~LootMgr() = default;

    public:

        static LootMgr& getInstance();
        void initialize();
        void finalize();

        LootMgr(LootMgr&&) = delete;
        LootMgr(LootMgr const&) = delete;
        LootMgr& operator=(LootMgr&&) = delete;
        LootMgr& operator=(LootMgr const&) = delete;

        void AddLoot(Loot* loot, uint32 itemid, uint32 mincount, uint32 maxcount);


        //////////////////////////////////////////////////////////////////////////////////////////
        /// bool HasLootForCreature(uint32 loot_id)
        /// Tells if there's loot cached for the specified creature.
        ///
        /// \param uint32 loot_id - The identifier of the creature
        ///
        /// \return true if there's loot for this creature, false otherwise.
        ///
        //////////////////////////////////////////////////////////////////////////////////////////
        bool HasLootForCreature(uint32 loot_id);

        void FillCreatureLoot(Loot* loot, uint32 loot_id, uint8 type);
        void FillGOLoot(Loot* loot, uint32 loot_id, uint8 type);
        void FillItemLoot(Loot* loot, uint32 loot_id);
        void FillFishingLoot(Loot* loot, uint32 loot_id);
        void FillSkinningLoot(Loot* loot, uint32 loot_id);
        void FillPickpocketingLoot(Loot* loot, uint32 loot_id);
        bool CanGODrop(uint32 LootId, uint32 itemid);
        bool IsPickpocketable(uint32 creatureId);
        bool IsSkinnable(uint32 creatureId);
        bool IsFishable(uint32 zoneid);

        void LoadLoot();
        void LoadLootProp();

        LootStore CreatureLoot;
        LootStore FishingLoot;
        LootStore SkinningLoot;
        LootStore GOLoot;
        LootStore ItemLoot;
        LootStore PickpocketingLoot;

        std::map<uint32, std::set<uint32>> quest_loot_go;

        DBC::Structures::ItemRandomPropertiesEntry const* GetRandomProperties(ItemProperties const* proto);
        DBC::Structures::ItemRandomSuffixEntry const* GetRandomSuffix(ItemProperties const* proto);

        bool is_loading;

    private:

        void LoadLootTables(const char* szTableName, LootStore* LootTable);
        void PushLoot(StoreLootList* list, Loot* loot, uint8 type);
        std::map<uint32, RandomPropertyVector> _randomprops;
        std::map<uint32, RandomSuffixVector> _randomsuffix;
};

#define sLootMgr LootMgr::getInstance()

#endif // LOOTMGR_H
