/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file newgrf_airport.h NewGRF handling of airports. */

#ifndef NEWGRF_AIRPORT_H
#define NEWGRF_AIRPORT_H

#include "date_type.h"
#include "map_type.h"

/* Copy from station_map.h */
typedef byte StationGfx;

struct AirportTileTable {
	TileIndexDiffC ti;
	StationGfx gfx;
};

/** TTDP airport types. Used to map our types to TTDPatch's */
enum TTDPAirportType {
	ATP_TTDP_SMALL,    ///< Same as AT_SMALL
	ATP_TTDP_LARGE,    ///< Same as AT_LARGE
	ATP_TTDP_HELIPORT, ///< Same as AT_HELIPORT
	ATP_TTDP_OILRIG,   ///< Same as AT_OILRIG
};

/**
 * Defines the data structure for an airport.
 */
struct AirportSpec {
	const AirportTileTable * const *table; ///< list of the tiles composing the airport
	const TileIndexDiffC *depot_table;     ///< gives the position of the depots on the airports
	byte nof_depots;                       ///< the number of depots in this airport
	byte size_x;                           ///< size of airport in x direction
	byte size_y;                           ///< size of airport in y direction
	byte noise_level;                      ///< noise that this airport generates
	byte catchment;                        ///< catchment area of this airport
	Year min_year;                         ///< first year the airport is available
	Year max_year;                         ///< last year the airport is available
	TTDPAirportType ttd_airport_type;      ///< ttdpatch airport type (Small/Large/Helipad/Oilrig)

	static const AirportSpec *Get(byte type);
	static AirportSpec *GetWithoutOverride(byte type);

	bool IsAvailable() const;

	static void ResetAirports();

	static AirportSpec dummy;
	static AirportSpec oilrig;

private:
	static AirportSpec specs[NUM_AIRPORTS];
};


#endif /* NEWGRF_AIRPORT_H */
