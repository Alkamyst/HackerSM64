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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR_BALL, 800, 127, -3491, 0, -180, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_TILT_PLATFORM, 800, -13, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, -800, -13, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -800, 0, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -800, 85, -3491),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_WATER_IS_SINK),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR_BALL, -400, 482, -3491, 0, -180, 0, (1 << 24), bhvBreakableBoxSmall),
		OBJECT(MODEL_SLIDE_PLATFORM_SMALL, -400, 428, -3491, 0, -180, 0, (40 << 24) | (40 << 8), bhvSlidePlatformHori),
		OBJECT(MODEL_TILT_PLATFORM, 0, -480, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, 0, -467, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_WATER_IS_SINK),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, jrb_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FAN, 916, -625, -3491, 0, -90, 0, (0 << 24) | (200 << 16), bhvFan),
		OBJECT(MODEL_STAR_BALL, 700, 383, -3491, 0, -180, 0, (2 << 24), bhvBreakableBoxSmall),
		OBJECT(MODEL_TILT_PLATFORM, -1100, 242, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, 1200, 242, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -700, 255, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_3_collision),
		MACRO_OBJECTS(jrb_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_WATER_IS_SINK),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, jrb_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x04, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR_BALL, 0, 392, -3491, 0, -180, 0, (3 << 24), bhvBreakableBoxSmall),
		OBJECT(MODEL_TILT_PLATFORM, 0, 300, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, 0, -300, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, 0, -255, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_4_collision),
		MACRO_OBJECTS(jrb_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_WATER_IS_SINK),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, jrb_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FAN, 0, -1156, -3491, -90, 0, 0, (0 << 24) | (200 << 16), bhvFan),
		OBJECT(MODEL_STAR_BALL, 700, 889, -3491, 0, -180, 0, (4 << 24), bhvBreakableBoxSmall),
		OBJECT(MODEL_TILT_PLATFORM, -1200, -865, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_TILT_PLATFORM, 1200, 748, -3491, 0, -180, 0, 0x00000000, bhvTiltPlatform),
		OBJECT(MODEL_NONE, -1462, -851, -3500, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_5_collision),
		MACRO_OBJECTS(jrb_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_WATER_IS_SINK),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -800, 85, -3491),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
