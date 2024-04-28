#pragma once


// Local library includes
#include "imgui.h"


/***
 * TODO:
 * 	- Check if memory card is in target slot via CARDProbe() (and CARDProbeEX()?)
 * 	- Mount card via CARD_MountAsync()
 * 	- Check card status (custom function?)
 * 	- Read from card via CARD_ReadAsync()
 * 	- Check for free space (custom function)
 * 	- Create a file via CARD_CreateAsync()
 * 	- Add comments, icon, and initialization data via CARD_WriteAsync()
 * 	- Set icon and comment offset via CARD_SetStatusAsync()
 * 	- Update save data (create new file and delete old one afterwards, explore backups)
 * 	- Delete from card via CARD_DeleteAsync()
 * 	- Unmount card via CARD_Unmount() after all read actions are complete
 * 	- Icon (32x32, RGB5A3, 2KB per frame, up to 8 animated frames, can change over time)
 * 	- Banner (96x32, RGB5A3, 6KB, can change over time)
 * 	- Comments (Two lines, Game and File Metadata, 32 bytes per-line)
 * 	- Filename (32 bytes)
 * 	- File Size (blocks, a multiple of 8KB)
 */


namespace memory_cards {


class Manager {
	public:
		Manager();
		void Update();	// Basically just for ImGui-based debugging
};


}	// namespace memory_cards

