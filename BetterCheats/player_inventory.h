#pragma once

#include "plugin_interface.h"

namespace BetterCheats::Panels::Inventory
{
	// Registers the console command — call once during plugin init.
	void Initialize();

	// Unregisters the console command — call once during plugin shutdown.
	void Shutdown();

	// Polls Tab/E on the game thread. While a maintain burst is active, applies
	// the queued resize and re-asserts slot scale every tick. Otherwise only
	// refreshes the panel snapshot.
	void Tick(float deltaSeconds);

	void RenderImGui(IModLoaderImGui* imgui);

	// Restores the target slot count persisted in the active session's JSON
	// config (see session_config.h). Only queues the wanted grid — apply it by
	// pressing Tab or E. Call on the game thread after SessionConfig::Reload().
	void ApplySavedConfig();
}
