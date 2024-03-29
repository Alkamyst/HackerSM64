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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BOB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_BOB, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x05, LEVEL_BOB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x06, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x07, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x08, LEVEL_WF, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x09, LEVEL_WF, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_WF, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x12, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_JRB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_JRB, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x15, LEVEL_JRB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x16, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x17, LEVEL_CCM, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x18, LEVEL_CCM, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x19, LEVEL_CCM, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_CCM, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CREDITS_BUTTON, 1170, -909, -2546, 0, -180, 0, (0x0B << 16), bhvCreditsButton),
		OBJECT(MODEL_LEVEL_BUTTON, -1000, 600, -2546, 0, -180, 0, (1 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -500, 600, -2546, 0, -180, 0, (2 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 0, 600, -2546, 0, -180, 0, (3 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 500, 600, -2546, 0, -180, 0, (4 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 1000, 600, -2546, 0, -180, 0, (5 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -1000, 200, -2546, 0, -180, 0, (6 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -500, 200, -2546, 0, -180, 0, (7 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 0, 200, -2546, 0, -180, 0, (8 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 500, 200, -2546, 0, -180, 0, (9 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 1000, 200, -2546, 0, -180, 0, (0x10 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -1000, -200, -2546, 0, -180, 0, (0x11 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -500, -200, -2546, 0, -180, 0, (0x12 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 0, -200, -2546, 0, -180, 0, (0x13 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 500, -200, -2546, 0, -180, 0, (0x14 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 1000, -200, -2546, 0, -180, 0, (0x15 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -1000, -600, -2546, 0, -180, 0, (0x16 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, -500, -600, -2546, 0, -180, 0, (0x17 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 0, -600, -2546, 0, -180, 0, (0x18 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 500, -600, -2546, 0, -180, 0, (0x19 << 16), bhvLevelButton),
		OBJECT(MODEL_LEVEL_BUTTON, 1000, -600, -2546, 0, -180, 0, (0x20 << 16), bhvLevelButton),
		OBJECT(MODEL_SELECTOR, 0, 0, -2546, 0, -180, 0, 0x00000000, bhvSelector),
		OBJECT(MODEL_NONE, 0, -1758, -3406, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, -1730, -3398),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BABA_IS_YOU),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, -1730, -3398),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
