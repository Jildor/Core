#include "ScriptPCH.h"

const uint32 SPELL_DEMENTIA = 41406;

class AntiDrawSystem : public PlayerScript
{
public:
	AntiDrawSystem() : PlayerScript("AntiDrawSystem") {}
	
	void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
	{
		// Remove Dementia on updating zone
		if (player->HasAura(SPELL_DEMENTIA))
			player->RemoveAura(SPELL_DEMENTIA);
	}

	void OnLogin(Player* player)
	{
		// Remove Dementia on player login
		if (player->HasAura(SPELL_DEMENTIA))
			player->RemoveAura(SPELL_DEMENTIA);
	}
	
};

void AddSC_Arena_AntiDraw()
{
	new AntiDrawSystem();
}