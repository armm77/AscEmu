/*
Copyright (c) 2014-2017 AscEmu Team <http://www.ascemu.org/>
This file is released under the MIT license. See README-MIT for more information.
*/

#include "Setup.h"
#include "ZulFarrak.h"


class ZulFarrak : public InstanceScript
{
public:

    ZulFarrak(MapMgr* pMapMgr) : InstanceScript(pMapMgr)
    {
        generateBossDataState();
    }

    static InstanceScript* Create(MapMgr* pMapMgr) { return new ZulFarrak(pMapMgr); }

    void OnCreatureDeath(Creature* pCreature, Unit* pUnit)
    {
        setData(pCreature->GetEntry(), Finished);
    }
};


void ZulFarrakScripts(ScriptMgr* scriptMgr)
{
    scriptMgr->register_instance_script(209, &ZulFarrak::Create);
}

