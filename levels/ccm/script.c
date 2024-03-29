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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FAN, -799, -778, -3491, -90, 0, 0, (2 << 24) | (80 << 16), bhvFan),
		OBJECT(MODEL_GATE, 0, 790, -3491, -180, 0, 90, 0x00000000, bhvGate),
		OBJECT(MODEL_SLIDE_PLATFORM_SMALL, -1100, 552, -3491, 0, -180, 0, (110 << 24) | (110 << 8), bhvSlidePlatformHori),
		OBJECT(MODEL_STAR, -799, 30, -3491, 0, -180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_TILT_PLATFORM, 757, -313, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -1100, 580, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_PINBALL, 493, -836, -3491, 0, 0, 0, 0x00000000, bhvPinball),
		OBJECT(MODEL_PINBALL, -546, -836, -3491, 0, -180, 0, 0x00000000, bhvPinball),
		OBJECT(MODEL_STAR, 0, 273, -3491, 0, -180, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, 1027, -418, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_2_collision),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ccm_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FAN, 1042, -630, -3491, 0, -90, 0, (2 << 24) | (200 << 16), bhvFan),
		OBJECT(MODEL_FAN, -987, -630, -3491, 0, 90, 0, (1 << 24) | (200 << 16), bhvFan),
		OBJECT(MODEL_GATE, -400, 688, -3491, -180, 0, 90, (1 << 24), bhvGate),
		OBJECT(MODEL_GATE, 0, 688, -3491, -180, 0, 90, 0x00000000, bhvGate),
		OBJECT(MODEL_GATE, 400, 688, -3491, -180, 0, 90, (1 << 24), bhvGate),
		OBJECT(MODEL_GATE, 800, 688, -3491, -180, 0, 90, 0x00000000, bhvGate),
		OBJECT(MODEL_GATE, 1200, 688, -3491, -180, 0, 90, (1 << 24), bhvGate),
		OBJECT(MODEL_GATE, -800, 688, -3491, -180, 0, 90, 0x00000000, bhvGate),
		OBJECT(MODEL_SLIDE_PLATFORM_SMALL, -1000, -166, -3491, 0, -180, 0, (150 << 24) | (100 << 8), bhvSlidePlatformHori),
		OBJECT(MODEL_SLIDE_PLATFORM_SMALL, -1200, 455, -3491, 0, -180, 0, (130 << 24) | (120 << 8), bhvSlidePlatformHori),
		OBJECT(MODEL_STAR_BALL, -1200, 550, -3491, 0, -180, 0, (2 << 24), bhvBreakableBoxSmall),
		OBJECT(MODEL_NONE, -473, -862, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_3_collision),
		MACRO_OBJECTS(ccm_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, ccm_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 1019, -1112, -3491, 0, -180, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_TILT_PLATFORM, 0, 834, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, 0, 848, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_4_collision),
		MACRO_OBJECTS(ccm_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BOX_HAS_KEY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, ccm_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FAN, 900, -1000, -3491, -90, 0, 0, (1 << 24) | (200 << 16), bhvFan),
		OBJECT(MODEL_GATE, -773, 1033, -3491, -180, 0, 90, 0x00000000, bhvGate),
		OBJECT(MODEL_SLIDE_PLATFORM_SMALL, 900, -253, -3491, -180, 0, 90, (55 << 24) | (60 << 8), bhvSlidePlatformVert),
		OBJECT(MODEL_SLIDE_PLATFORM_SMALL, -1100, 800, -3491, 0, -180, 0, (65 << 24) | (110 << 8), bhvSlidePlatformHori),
		OBJECT(MODEL_STAR_BALL, -1100, 895, -3491, 0, -180, 0, (4 << 24), bhvBreakableBoxSmall),
		OBJECT(MODEL_TILT_PLATFORM, -643, -436, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -899, -386, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_5_collision),
		MACRO_OBJECTS(ccm_area_5_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
