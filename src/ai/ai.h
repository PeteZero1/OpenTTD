/* $Id$ */

/** @file ai.h Base functions for all AIs. */

#ifndef AI_H
#define AI_H

#include "../network/network.h"
#include "../command_type.h"
#include "../core/random_func.hpp"
#include "../settings_type.h"

/* How DoCommands look like for an AI */
struct AICommand {
	uint32 tile;
	uint32 p1;
	uint32 p2;
	uint32 procc;
	CommandCallback *callback;

	char *text;
	uint uid;

	AICommand *next;
};

/* The struct for an AIScript Company */
struct AICompany {
	bool active;            ///< Is this AI active?
	AICommand *queue;       ///< The commands that he has in his queue
	AICommand *queue_tail;  ///< The tail of this queue
};

/* The struct to keep some data about the AI in general */
struct AIStruct {
	/* General */
	bool enabled;           ///< Is AI enabled?
	uint tick;              ///< The current tick (something like _frame_counter, only for AIs)
};

extern AIStruct _ai;
extern AICompany _ai_company[MAX_COMPANIES];

// ai.c
void AI_StartNewAI(CompanyID company);
void AI_CompanyDied(CompanyID company);
void AI_RunGameLoop();
void AI_Initialize();
void AI_Uninitialize();
CommandCost AI_DoCommand(TileIndex tile, uint32 p1, uint32 p2, uint32 flags, uint procc);
CommandCost AI_DoCommandCc(TileIndex tile, uint32 p1, uint32 p2, uint32 flags, uint procc, CommandCallback* callback);

/** Is it allowed to start a new AI.
 * This function checks some boundries to see if we should launch a new AI.
 * @return True if we can start a new AI.
 */
static inline bool AI_AllowNewAI()
{
	/* If disabled, no AI */
	if (!_ai.enabled)
		return false;

	/* If in network, but no server, no AI */
	if (_networking && !_network_server)
		return false;

	/* If in network, and server, possible AI */
	if (_networking && _network_server) {
		/* Do we want AIs in multiplayer? */
		if (!_settings_game.ai.ai_in_multiplayer)
			return false;

		/* Only the NewAI is allowed... sadly enough the old AI just doesn't support this
		 *  system, because all commands are delayed by at least 1 tick, which causes
		 *  a big problem, because it uses variables that are only set AFTER the command
		 *  is really executed... */
		if (!_settings_game.ai.ainew_active)
			return false;
	}

	return true;
}

#define AI_CHANCE16(a, b)    ((uint16)     AI_Random()  <= (uint16)((65536 * a) / b))
#define AI_CHANCE16R(a, b, r) ((uint16)(r = AI_Random()) <= (uint16)((65536 * a) / b))

/**
 * The random-function that should be used by ALL AIs.
 */
static inline uint AI_RandomRange(uint max)
{
	/* We pick RandomRange if we are in SP (so when saved, we do the same over and over)
	 *   but we pick InteractiveRandomRange if we are a network_server or network-client.
	 */
	if (_networking)
		return InteractiveRandomRange(max);
	else
		return RandomRange(max);
}

/**
 * The random-function that should be used by ALL AIs.
 */
static inline uint32 AI_Random()
{
/* We pick RandomRange if we are in SP (so when saved, we do the same over and over)
	 *   but we pick InteractiveRandomRange if we are a network_server or network-client.
	 */
	if (_networking)
		return InteractiveRandom();
	else
		return Random();
}

#endif /* AI_H */
