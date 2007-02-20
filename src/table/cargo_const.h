/* $Id$ */

/* Table of all default cargo types */

#define MK(bt, label, c, e, f, g, h, fr, ks1, ks2, ks3, ks4, ks5, l, m) \
          {bt, label, 0, c, c, e, f, {g, h}, fr, 0, 0, 0, ks1, ks2, ks3, ks4, ks5, l, m}
static const CargoSpec _default_cargo[] = {
	MK(  0, 'PASS', 152,  1, 3185,  0,  24, false,
		STR_000F_PASSENGERS,     STR_002F_PASSENGER,      STR_PASSENGERS, STR_QUANTITY_PASSENGERS,   STR_ABBREV_PASSENGERS,
		SPR_CARGO_PASSENGER,     CC_PASSENGERS  ),

	MK(  1, 'COAL',  32, 16, 5916,  7, 255, true,
		STR_0010_COAL,           STR_0030_COAL,           STR_TONS,       STR_QUANTITY_COAL,         STR_ABBREV_COAL,
		SPR_CARGO_COAL,          CC_BULK        ),

	MK(  2, 'MAIL',  15,  4, 4550, 20,  90, false,
		STR_0011_MAIL,           STR_0031_MAIL,           STR_BAGS,       STR_QUANTITY_MAIL,         STR_ABBREV_MAIL,
		SPR_CARGO_MAIL,          CC_MAIL        ),

	MK(  3, 'OIL_', 174, 16, 4437, 25, 255, true,
		STR_0012_OIL,            STR_0032_OIL,            STR_LITERS,     STR_QUANTITY_OIL,          STR_ABBREV_OIL,
		SPR_CARGO_OIL,           CC_LIQUID      ),

	MK(  4, 'LVST', 208,  3, 4322,  4,  18, true,
		STR_0013_LIVESTOCK,      STR_0033_LIVESTOCK,      STR_ITEMS,      STR_QUANTITY_LIVESTOCK,    STR_ABBREV_LIVESTOCK,
		SPR_CARGO_LIVESTOCK,     CC_PIECE_GOODS ),

	MK(  5, 'GOOD', 194,  8, 6144,  5,  28, true,
		STR_0014_GOODS,          STR_0034_GOODS,          STR_CRATES,     STR_QUANTITY_GOODS,        STR_ABBREV_GOODS,
		SPR_CARGO_GOODS,         CC_EXPRESS     ),

	MK(  6, 'GRAI', 191, 16, 4778,  4,  40, true,
		STR_0015_GRAIN,          STR_0035_GRAIN,          STR_TONS,       STR_QUANTITY_GRAIN,        STR_ABBREV_GRAIN,
		SPR_CARGO_GRAIN,         CC_BULK        ),

	MK(  6, 'WHEA', 191, 16, 4778,  4,  40, true,
		STR_0022_WHEAT,          STR_0042_WHEAT,          STR_TONS,       STR_QUANTITY_WHEAT,        STR_ABBREV_WHEAT,
		SPR_CARGO_GRAIN,         CC_BULK        ),

	MK(  6, 'MAIZ', 191,  6, 4778,  4,  40, true,
		STR_001B_MAIZE,          STR_003B_MAIZE,          STR_TONS,       STR_QUANTITY_MAIZE,        STR_ABBREV_MAIZE,
		SPR_CARGO_GRAIN,         CC_BULK        ),

	MK(  7, 'WOOD',  84, 16, 5005, 15, 255, true,
		STR_0016_WOOD,           STR_0036_WOOD,           STR_TONS,       STR_QUANTITY_WOOD,         STR_ABBREV_WOOD,
		SPR_CARGO_WOOD,          CC_PIECE_GOODS ),

	MK(  8, 'IORE', 184, 16, 5120,  9, 255, true,
		STR_0017_IRON_ORE,       STR_0037_IRON_ORE,       STR_TONS,       STR_QUANTITY_IRON_ORE,     STR_ABBREV_IRON_ORE,
		SPR_CARGO_IRON_ORE,      CC_BULK        ),

	MK(  9, 'STEL',  10, 16, 5688,  7, 255, true,
		STR_0018_STEEL,          STR_0038_STEEL,          STR_TONS,       STR_QUANTITY_STEEL,        STR_ABBREV_STEEL,
		SPR_CARGO_STEEL,         CC_PIECE_GOODS ),

	MK( 10, 'VALU', 202,  2, 7509,  1,  32, true,
		STR_0019_VALUABLES,      STR_0039_VALUABLES,      STR_BAGS,       STR_QUANTITY_VALUABLES,    STR_ABBREV_VALUABLES,
		SPR_CARGO_VALUES_GOLD,   CC_ARMOURED    ),

	MK( 10, 'GOLD', 202,  8, 7509, 10,  40, true,
		STR_0020_GOLD,           STR_0040_GOLD,           STR_BAGS,       STR_QUANTITY_GOLD,         STR_ABBREV_GOLD,
		SPR_CARGO_VALUES_GOLD,   CC_ARMOURED    ),

	MK( 10, 'DIAM', 202,  2, 7509, 10, 255, true,
		STR_001D_DIAMONDS,       STR_003D_DIAMOND,        STR_BAGS,       STR_QUANTITY_DIAMONDS,     STR_ABBREV_DIAMONDS,
		SPR_CARGO_DIAMONDS,      CC_ARMOURED    ),

	MK( 11, 'PAPR',  10, 16, 5688,  7,  60, true,
		STR_001F_PAPER,          STR_003F_PAPER,          STR_TONS,       STR_QUANTITY_PAPER,        STR_ABBREV_PAPER,
		SPR_CARGO_PAPER,         CC_PIECE_GOODS ),

	MK( 12, 'FOOD',  48, 16, 5688,  0,  30, true,
		STR_001E_FOOD,           STR_003E_FOOD,           STR_TONS,       STR_QUANTITY_FOOD,         STR_ABBREV_FOOD,
		SPR_CARGO_FOOD,          CC_EXPRESS     | CC_REFRIGERATED),

	MK( 13, 'FRUT', 208,  6, 4322,  0,  15, true,
		STR_001C_FRUIT,          STR_003C_FRUIT,          STR_TONS,       STR_QUANTITY_FRUIT,        STR_ABBREV_FRUIT,
		SPR_CARGO_FRUIT,         CC_BULK        | CC_REFRIGERATED),

	MK( 14, 'CORE', 184,  6, 5120, 12, 255, true,
		STR_001A_COPPER_ORE,     STR_003A_COPPER_ORE,     STR_TONS,       STR_QUANTITY_COPPER_ORE,   STR_ABBREV_COPPER_ORE,
		SPR_CARGO_COPPER_ORE,    CC_BULK        ),

	MK( 15, 'WATR',  10,  6, 5688, 20,  80, true,
		STR_0021_WATER,          STR_0041_WATER,          STR_LITERS,     STR_QUANTITY_WATER,        STR_ABBREV_WATER,
		SPR_CARGO_WATERCOLA,     CC_LIQUID      ),

	MK( 16, 'RUBR',  32,  6, 5916,  2,  20, true,
		STR_0023_RUBBER,         STR_0043_RUBBER,         STR_LITERS,     STR_QUANTITY_RUBBER,       STR_ABBREV_RUBBER,
		SPR_CARGO_RUBBER,        CC_LIQUID      ),

	MK( 17, 'SUGR',  32, 16, 5916, 20, 255, true,
		STR_0024_SUGAR,          STR_0044_SUGAR,          STR_TONS,       STR_QUANTITY_SUGAR,        STR_ABBREV_SUGAR,
		SPR_CARGO_SUGAR,         CC_BULK        ),

	MK( 18, 'TOYS', 174,  2, 4437, 25, 255, true,
		STR_0025_TOYS,           STR_0045_TOY,            STR_NOTHING,    STR_QUANTITY_TOYS,         STR_ABBREV_TOYS,
		SPR_CARGO_TOYS,          CC_PIECE_GOODS ),

	MK( 19, 'BATT', 208,  4, 4322,  2,  30, true,
		STR_002B_BATTERIES,      STR_004B_BATTERY,        STR_NOTHING,    STR_QUANTITY_BATTERIES,    STR_ABBREV_BATTERIES,
		SPR_CARGO_BATTERIES,     CC_PIECE_GOODS ),

	MK( 20, 'SWET', 194,  5, 6144,  8,  40, true,
		STR_0026_CANDY,          STR_0046_CANDY,          STR_TONS,       STR_QUANTITY_SWEETS,       STR_ABBREV_SWEETS,
		SPR_CARGO_CANDY,         CC_EXPRESS     ),

	MK( 21, 'TOFF', 191, 16, 4778, 14,  60, true,
		STR_002A_TOFFEE,         STR_004A_TOFFEE,         STR_TONS,       STR_QUANTITY_TOFFEE,       STR_ABBREV_TOFFEE,
		SPR_CARGO_TOFFEE,        CC_BULK        ),

	MK( 22, 'COLA',  84, 16, 5005,  5,  75, true,
		STR_0027_COLA,           STR_0047_COLA,           STR_LITERS,     STR_QUANTITY_COLA,         STR_ABBREV_COLA,
		SPR_CARGO_WATERCOLA,     CC_LIQUID      ),

	MK( 23, 'CTCD', 184, 16, 5120, 10,  25, true,
		STR_0028_COTTON_CANDY,   STR_0048_COTTON_CANDY,   STR_TONS,       STR_QUANTITY_CANDYFLOSS,   STR_ABBREV_CANDYFLOSS,
		SPR_CARGO_COTTONCANDY,   CC_BULK        ),

	MK( 24, 'BUBL',  10,  1, 5688, 20,  80, true,
		STR_0029_BUBBLES,        STR_0049_BUBBLE,         STR_NOTHING,    STR_QUANTITY_BUBBLES,      STR_ABBREV_BUBBLES,
		SPR_CARGO_BUBBLES,       CC_PIECE_GOODS ),

	MK( 25, 'PLST', 202, 16, 7509, 30, 255, true,
		STR_002C_PLASTIC,        STR_004C_PLASTIC,        STR_LITERS,     STR_QUANTITY_PLASTIC,      STR_ABBREV_PLASTIC,
		SPR_CARGO_PLASTIC,       CC_LIQUID      ),

	MK( 26, 'FZDR',  48,  2, 5688, 30,  50, true,
		STR_002D_FIZZY_DRINKS,   STR_004D_FIZZY_DRINK,    STR_NOTHING,    STR_QUANTITY_FIZZY_DRINKS, STR_ABBREV_FIZZY_DRINKS,
		SPR_CARGO_FIZZYDRINK,    CC_PIECE_GOODS ),

};


/* Table of which cargo types are available in each climate, by default */
static const CargoLabel _default_climate_cargo[NUM_LANDSCAPE][12] = {
	{ 'PASS', 'COAL', 'MAIL', 'OIL_', 'LVST', 'GOOD', 'GRAI', 'WOOD', 'IORE', 'STEL', 'VALU', 'VOID', },
	{ 'PASS', 'COAL', 'MAIL', 'OIL_', 'LVST', 'GOOD', 'WHEA', 'WOOD', 'VOID', 'PAPR', 'GOLD', 'FOOD', },
	{ 'PASS', 'RUBR', 'MAIL', 'OIL_', 'FRUT', 'GOOD', 'MAIZ', 'WOOD', 'CORE', 'WATR', 'DIAM', 'FOOD', },
	{ 'PASS', 'SUGR', 'MAIL', 'TOYS', 'BATT', 'SWET', 'TOFF', 'COLA', 'CTCD', 'BUBL', 'PLST', 'FZDR', },
};

