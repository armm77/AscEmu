/*
Copyright (c) 2014-2021 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

#include <cstdint>
#include <utility>

#include "ManagedPacket.h"

namespace AscEmu::Packets
{
    class SmsgSpellFailure : public ManagedPacket
    {
    public:
        WoWGuid casterGuid;
        uint8_t castNumber;
        uint32_t spellId;
        uint8_t result;

        SmsgSpellFailure() : SmsgSpellFailure(WoWGuid(), 0, 0, 0)
        {
        }

        SmsgSpellFailure(WoWGuid casterGuid, uint8_t castNumber, uint32_t spellId, uint8_t result) :
            ManagedPacket(SMSG_SPELL_FAILURE, 8 + 4),
            casterGuid(casterGuid),
            castNumber(castNumber),
            spellId(spellId),
            result(result)
        {
        }

    protected:
        bool internalSerialise(WorldPacket& packet) override
        {
            packet << casterGuid;
#if VERSION_STRING > TBC
            packet << castNumber;
#endif
            packet << spellId << result;

            return true;
        }

        bool internalDeserialise(WorldPacket& /*packet*/) override
        {
            return false;
        }
    };
}
