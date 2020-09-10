/*
 * Copyright (c) 2014-2020 AscEmu Team <http://www.ascemu.org>
 * Copyright (c) 2007-2015 Moon++ Team <http://www.moonplusplus.info>
 * Copyright (C) 2008-2012 ArcEmu Team <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Setup.h"
#include "Management/Item.h"
#include "Management/ItemInterface.h"
#include "Spell/SpellAuras.h"
#include "Server/Script/ScriptMgr.h"
#include "Spell/Definitions/ProcFlags.h"
#include <Spell/Definitions/PowerType.h>

//////////////////////////////////////////////////////////////////////////////////////////
// Spell Defs
bool FlametongueWeaponPassive(uint8_t /*effectIndex*/, Aura* pAura, bool apply)
{
    Unit* target = pAura->getOwner();

    if (apply)
    {
        // target is always a player
        Item* item = static_cast<Player*>(target)->getItemInterface()->GetItemByGUID(pAura->itemCasterGUID);
        target->AddProcTriggerSpell(10444, pAura->getSpellInfo()->getId(), pAura->getCasterGuid(), pAura->getSpellInfo()->getProcChance(), PROC_ON_MELEE_ATTACK, 0, NULL, NULL, item);
    }
    else
        target->RemoveProcTriggerSpell(10444, pAura->getCasterGuid(), pAura->itemCasterGUID);

    return true;
}

bool SkyShatterRegalia(uint8_t /*effectIndex*/, Spell* s)
{
    // Shaman - Skyshatter Regalia - Two Piece Bonus
    // it checks for earth, air, water, fire totems and triggers Totemic Mastery spell 38437.

    if (!s->getPlayerCaster())
        return false;

    if (s->getPlayerCaster()->summonhandler.HasSummonInSlot(0) &&
        s->getPlayerCaster()->summonhandler.HasSummonInSlot(1) &&
        s->getPlayerCaster()->summonhandler.HasSummonInSlot(2) &&
        s->getPlayerCaster()->summonhandler.HasSummonInSlot(3))
    {
        Aura* aur = sSpellMgr.newAura(sSpellMgr.getSpellInfo(38437), 5000, s->getPlayerCaster(), s->getPlayerCaster(), true);

        for (uint8_t j = 0; j < 3; j++)
            aur->addAuraEffect(static_cast<AuraEffect>(aur->getSpellInfo()->getEffectRadiusIndex(j)), aur->getSpellInfo()->getEffectBasePoints(j) + 1, aur->getSpellInfo()->getEffectMiscValue(j), j);

        s->getPlayerCaster()->addAura(aur);
    }

    return true;
}

bool ManaTide(uint8_t /*effectIndex*/, Spell* s)
{
    Unit* unitTarget = s->GetUnitTarget();

    if (unitTarget == NULL || unitTarget->isDead() || unitTarget->getClass() == WARRIOR || unitTarget->getClass() == ROGUE)
        return false;

    uint32_t gain = (uint32_t)(unitTarget->getMaxPower(POWER_TYPE_MANA) * 0.06);
    unitTarget->energize(unitTarget, 16191, gain, POWER_TYPE_MANA);

    return true;
}

bool EarthShieldDummyAura(uint8_t /*effectIndex*/, Aura* pAura, bool apply)
{
    Unit* m_target = pAura->getOwner();

    if (apply)
        m_target->AddProcTriggerSpell(379, pAura->getSpellId(), pAura->getCasterGuid(), pAura->getSpellInfo()->getProcChance(), pAura->getSpellInfo()->getProcFlags() & ~PROC_ON_SPELL_LAND_VICTIM, pAura->getSpellInfo()->getProcCharges(), NULL, NULL);
    else if (m_target->GetAuraStackCount(pAura->getSpellId()) == 1)
        m_target->RemoveProcTriggerSpell(379, pAura->getCasterGuid());

    return true;
}

bool Reincarnation(uint8_t /*effectIndex*/, Aura* a, bool apply)
{
    Unit* u_target = a->getOwner();

    if (!u_target->isPlayer())
        return true;

    Player* p_target = static_cast<Player*>(u_target);

    if (apply)
        p_target->bReincarnation = true;
    else
        p_target->bReincarnation = false;

    return true;
}

void SetupLegacyShamanSpells(ScriptMgr* mgr)
{
    uint32_t FlametongueWeaponPassiveIds[] = { 10400, 15567, 15568, 15569, 16311, 16312, 16313, 58784, 58791, 58792, 0 };
    mgr->register_dummy_aura(FlametongueWeaponPassiveIds, &FlametongueWeaponPassive);

    mgr->register_dummy_spell(38443, &SkyShatterRegalia);

    mgr->register_dummy_spell(39610, &ManaTide);

    uint32_t earthshielddummyauraids[] =
    {
        974,
        32593,
        32594,
        49283,
        49284,
        0
    };
    mgr->register_dummy_aura(earthshielddummyauraids, &EarthShieldDummyAura);

    mgr->register_dummy_aura(20608, &Reincarnation);
}
