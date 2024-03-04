// metal_box.inc.c

struct ObjectHitbox sMetalBoxHitbox = {
    /* interactType:      */ INTERACT_NONE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 220,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 220,
    /* hurtboxHeight:     */ 300,
};

s32 check_if_moving_over_floor(f32 maxDist, f32 offset) {
    struct Surface *floor;
    f32 xPos = o->oPosX + sins(o->oMoveAngleYaw) * offset;
    f32 zPos = o->oPosZ + coss(o->oMoveAngleYaw) * offset;

    f32 floorHeight = find_floor(xPos, o->oPosY, zPos, &floor);

    return (absf(floorHeight - o->oPosY) < maxDist);
}

void bhv_pushable_loop(void) {
    obj_set_hitbox(o, &sMetalBoxHitbox);
    o->oForwardVel = 0.0f;

    if (obj_check_if_collided_with_object(o, gMarioObject) && gMarioStates[0].flags & MARIO_PUSHING) {
        s16 angleToMario = obj_angle_to_object(o, gMarioObject);
        if (abs_angle_diff(angleToMario, gMarioObject->oMoveAngleYaw) > 0x4000) {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if (check_if_moving_over_floor(8.0f, 150.0f)) {
                o->oForwardVel = 6.0f;
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
            }
        }
    }

    // Ground pound box to break it and make it respawn at its home (in case it gets stuck)
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                spawn_mist_particles();
                spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
                cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
                o->oPosX = o->oHomeX;
                o->oPosY = o->oHomeY;
                o->oPosZ = o->oHomeZ;
                o->oAction = 1;
            } 
            break;

        case 1:
            o->oBreakableBoxSmallFramesSinceReleased++;

            // Begin flashing
            if (o->oBreakableBoxSmallFramesSinceReleased < 90) {
                COND_BIT((o->oBreakableBoxSmallFramesSinceReleased & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
            }

            // Stop flashing
            if (o->oBreakableBoxSmallFramesSinceReleased >= 90) {
                o->oBreakableBoxSmallFramesSinceReleased = 0;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->oAction = 0;
            }
    }

    cur_obj_move_using_fvel_and_gravity();
}
