#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 821, -7, -3491, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_TILT_PLATFORM_WIDE, 7, -145, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatformWide),
		OBJECT(MODEL_NONE, -821, 261, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -821, 0, -3491),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 821, -7, -3491, 0, -180, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_TILT_PLATFORM, -410, -145, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -821, 261, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, -526, -706, -3491, 0, -180, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_TILT_PLATFORM, -820, -84, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, 807, -84, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -1399, 398, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bob_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_RED_COIN, 0, 647, -3500, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 0, -383, -3500, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 0, -906, -3491, 0, -180, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_TILT_PLATFORM, -820, 378, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, 807, 378, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, 807, -383, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, -820, -383, -3500, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -1399, 1121, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_4_collision),
		MACRO_OBJECTS(bob_area_4_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, bob_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 0, -315, -3491, 0, -180, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_TILT_BOX, 0, 0, -3491, 0, 0, 0, 0x00000000, bhvTiltBox),
		OBJECT(MODEL_NONE, 0, -800, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_5_collision),
		MACRO_OBJECTS(bob_area_5_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -821, 0, -3491),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
