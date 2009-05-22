/* $Id$ */

/** @file engine_base.h Base class for engines. */

#ifndef ENGINE_BASE_H
#define ENGINE_BASE_H

#include "engine_type.h"
#include "economy_type.h"
#include "core/pool.hpp"
#include "core/smallvec_type.hpp"

typedef Pool<Engine, EngineID, 64, 64000> EnginePool;
extern EnginePool _engine_pool;

struct Engine : EnginePool::PoolItem<&_engine_pool> {
	char *name;         ///< Custom name of engine
	Date intro_date;
	Date age;
	uint16 reliability;
	uint16 reliability_spd_dec;
	uint16 reliability_start, reliability_max, reliability_final;
	uint16 duration_phase_1, duration_phase_2, duration_phase_3;
	byte lifelength;
	byte flags;
	uint8 preview_company_rank;
	byte preview_wait;
	CompanyMask company_avail;
	uint8 image_index; ///< Original vehicle image index
	VehicleType type; ///< type, ie VEH_ROAD, VEH_TRAIN, etc.

	EngineInfo info;

	union {
		RailVehicleInfo rail;
		RoadVehicleInfo road;
		ShipVehicleInfo ship;
		AircraftVehicleInfo air;
	} u;

	/* NewGRF related data */
	const struct GRFFile *grffile;
	const struct SpriteGroup *group[NUM_CARGO + 2];
	uint16 internal_id;                             ///< ID within the GRF file
	uint16 overrides_count;
	struct WagonOverride *overrides;
	uint16 list_position;

	Engine();
	Engine(VehicleType type, EngineID base);
	~Engine();

	CargoID GetDefaultCargoType() const;
	bool CanCarryCargo() const;
	uint GetDisplayDefaultCapacity() const;
	Money GetRunningCost() const;
	Money GetCost() const;
	uint GetDisplayMaxSpeed() const;
	uint GetPower() const;
	uint GetDisplayWeight() const;
	uint GetDisplayMaxTractiveEffort() const;
};

struct EngineIDMapping {
	uint32 grfid;          ///< The GRF ID of the file the entity belongs to
	uint16 internal_id;    ///< The internal ID within the GRF file
	VehicleTypeByte type;  ///< The engine type
	uint8  substitute_id;  ///< The (original) entity ID to use if this GRF is not available (currently not used)
};

/**
 * Stores the mapping of EngineID to the internal id of newgrfs.
 * Note: This is not part of Engine, as the data in the EngineOverrideManager and the engine pool get resetted in different cases.
 */
struct EngineOverrideManager : SmallVector<EngineIDMapping, 256> {
	static const uint NUM_DEFAULT_ENGINES; ///< Number of default entries

	void ResetToDefaultMapping();
	EngineID GetID(VehicleType type, uint16 grf_local_id, uint32 grfid);
};

extern EngineOverrideManager _engine_mngr;

#define FOR_ALL_ENGINES_FROM(var, start) FOR_ALL_ITEMS_FROM(Engine, engine_index, var, start)
#define FOR_ALL_ENGINES(var) FOR_ALL_ENGINES_FROM(var, 0)

#define FOR_ALL_ENGINES_OF_TYPE(e, engine_type) FOR_ALL_ENGINES(e) if (e->type == engine_type)

static inline const EngineInfo *EngInfo(EngineID e)
{
	return &Engine::Get(e)->info;
}

static inline const RailVehicleInfo *RailVehInfo(EngineID e)
{
	return &Engine::Get(e)->u.rail;
}

static inline const RoadVehicleInfo *RoadVehInfo(EngineID e)
{
	return &Engine::Get(e)->u.road;
}

static inline const ShipVehicleInfo *ShipVehInfo(EngineID e)
{
	return &Engine::Get(e)->u.ship;
}

static inline const AircraftVehicleInfo *AircraftVehInfo(EngineID e)
{
	return &Engine::Get(e)->u.air;
}

#endif /* ENGINE_TYPE_H */
