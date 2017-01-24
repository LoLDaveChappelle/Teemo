#pragma once

// Include the plugin SDK
#include "PluginSDK.h"

class AlqoholicVayne;

struct SpellMenu
{
	IMenuOption* ComboQ;
	IMenuOption* LastHitQ;
	IMenuOption* ComboE;
	IMenuOption* AutoE;
	IMenuOption* AutoR;
	IMenuOption* AutoREnemies;
	IMenuOption* DrawReady;
	IMenuOption* DrawQ;
	IMenuOption* DrawE;
};

class Plugin
{
public:
	Plugin();
	~Plugin();

	void _OnRender() const;
	void _OnGameUpdate() const;
	void _OnOrbwalkAfterAttack(IUnit* source, IUnit* target) const;

private:
	PLUGIN_EVENT(void) OnRender();
	PLUGIN_EVENT(void) OnGameUpdate();
	PLUGIN_EVENT(void) OnOrbwalkAfterAttack(IUnit* Source, IUnit* Target);

	void LoadMenu();
	static void LoadPluginEvents();
	static void UnloadPluginEvents();

public:
	SpellMenu Menu;
	IMenu* Parent;
	IMenu* QSettings;
	IMenu* WSettings;
	IMenu* ESettings;
	IMenu* RSettings;
	IMenu* Misc;
	IMenu* Drawings;
	AlqoholicVayne* Implementation;
};

extern Plugin* GPluginInstance;