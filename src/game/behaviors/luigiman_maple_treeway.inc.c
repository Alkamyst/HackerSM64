// Leaf Pile Behavior

void bhv_luigiman_leaf_pile_init() {
    if (o->oBehParams2ndByte == 0) {
        o->oNumLootCoins = 0;
    }
    if (o->oBehParams2ndByte == 1) {
        o->oNumLootCoins = 3;
    }
    if (o->oBehParams2ndByte == 2) {
        o->oNumLootCoins = 5;
    }
}

// extern const Collision luigiman_rings_collision[];
void bhv_luigiman_leaf_pile_loop(void) {
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        obj_mark_for_deletion(o);
        spawn_mist_particles_variable(0, 0, 46.0f);
        o->oInteractType = INTERACT_COIN;
        // obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
    }
}

// Chestnuts Behavior

static struct ObjectHitbox sChestnutHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_luigiman_chestnut_init(void) {
    // o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
    o->oGravity = -5.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;
    if (o->oBehParams2ndByte == 1) {
        cur_obj_scale(3.5f);
    }
}

void luigiman_chestnut_act_0(void) {
    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = OBJ_MOVE_NONE;
    cur_obj_set_pos_to_home();
    obj_set_hitbox(o, &sChestnutHitbox);
    if (o->oBehParams2ndByte == 0) {
        o->oGraphYOffset = 100.0f;
    }
    if (o->oBehParams2ndByte == 1) {
        o->oGraphYOffset = 250.0f;
    }
    o->oAction = 1;
}

void luigiman_chestnut_act_1(void) {
    if (o->oTimer < 30) {
        if (o->oBehParams2ndByte == 0) {
            o->oForwardVel = 5.0f;
        } else {
            o->oForwardVel = 17.0f;
        }
    } else {
//        if (o->oTimer > 40) {
//            cur_obj_update_floor_and_walls();
//        }

        o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f));
        if (o->oBehParams2ndByte == 0) {
            o->oForwardVel = 15.0f;
        } else {
            o->oForwardVel = 20.0f;
        }

        if (o->oTimer > 30) {
            //object_step_without_floor_orient();
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-70);
            sOrientObjWithFloor = FALSE;
            // o->oMoveAnglePitch -= 0x4F;
            // o->oFaceAngleYaw = o->oMoveAngleYaw;
        }

        if ((o->oMoveFlags & OBJ_MOVE_HIT_WALL)) {
            o->oAction = 0;
            spawn_mist_particles();
        }
    }

    o->parentObj = cur_obj_nearest_object_with_behavior(bhvPushableMetalBox);

    if ((dist_between_objects(o, o->parentObj) < 400.0f) && (o->oBehParams2ndByte == 0)) {
        o->oAction = 0;
        spawn_mist_particles();
    }

    if ((dist_between_objects(o, o->parentObj) < 500.0f) && (o->oBehParams2ndByte == 1)) {
        o->oAction = 0;
        spawn_mist_particles();
    }
}

void luigiman_chestnut_act_2(void) {
    // o->oMoveAngleYaw == 0x0;
    // o->oMoveAngleYaw += 0x9000;
    cur_obj_rotate_yaw_toward(0x0, 0x8000);
    o->oAction = 0;
}

void luigiman_chestnut_act_3(void) {
    spawn_mist_particles();
    o->oAction = 0;
}

ObjActionFunc sluigimanChustnutActions[] = {
    luigiman_chestnut_act_0,
    luigiman_chestnut_act_1,
    luigiman_chestnut_act_2,
    luigiman_chestnut_act_3,
};

void bhv_luigiman_chestnut_loop(void) {
    cur_obj_call_action_function(sluigimanChustnutActions);

    if (o->oDistanceToMario >= 5000.0f) {
        o->oAction = 0;
    }

    if (cur_obj_check_interacted()) {
        o->oAction = 3;
    }
}

// Golden Chestnuts Behavior

void bhv_luigiman_golden_chestnut_init(void) {
    o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
    o->oGravity = 5.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;
}

void luigiman_golden_chestnut_act_0(void) {
    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = OBJ_MOVE_NONE;
    cur_obj_set_pos_to_home();
    obj_set_hitbox(o, &sChestnutHitbox);
    o->oGraphYOffset = 100.0f;
    o->oAction = 1;
}

void luigiman_golden_chestnut_act_1(void) {
    struct Object *sparkleObj = spawn_object(o, MODEL_SPARKLES_ANIMATION, bhvSparkle);
    obj_translate_xyz_random(sparkleObj, 270.0f);
    obj_scale_random(sparkleObj, 2.0f, 0.0f);

    cur_obj_update_floor_and_walls();

    o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f));
    o->oForwardVel = 10.0f;
    o->oAngleToMario = cur_obj_angle_to_home();
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);

    object_step_without_floor_orient();

    o->parentObj = cur_obj_nearest_object_with_behavior(bhvPushableMetalBox);

    if (dist_between_objects(o, o->parentObj) < 400.0f) {
        spawn_mist_particles();
        obj_mark_for_deletion(o);
        spawn_default_star(7852.0f, 4006.0f, -9493.0f);
    }
}

ObjActionFunc sluigimanGoldenChustnutActions[] = {
    luigiman_golden_chestnut_act_0,
    luigiman_golden_chestnut_act_1,
};

void bhv_luigiman_golden_chestnut_loop(void) {
    cur_obj_call_action_function(sluigimanGoldenChustnutActions);
    if (cur_obj_check_interacted()) {
        obj_set_hitbox(o, &sChestnutHitbox);
    }
}

void bhv_ground_pound_switch(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN);
                o->oVelY = -20.0f;
                o->oAction = 1;
            } 
            break;

        case 1:
            if (o->oTimer > 3) {
                o->oVelY = 0.0f;
            } else {
                cur_obj_move_using_fvel_and_gravity();
            }
            break;
    }
}

void bhv_tree_door(void) {
    o->parentObj = cur_obj_nearest_object_with_behavior(bhvGroundPoundSwitch);

    if (o->parentObj->oAction == 1) {
        play_puzzle_jingle();
        spawn_mist_particles();
        spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
        cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
        obj_mark_for_deletion(o);
    }
}

struct ObjectHitbox sFlyBugHurt = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 5,
    /* radius:            */ 250,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_flybug(void) {
    f32 floor = find_floor_height(o->oPosX, o->oPosY + 200.0f, o->oPosZ);
    f32 targetY;

    // Handles hurting Mario interaction
    obj_set_hitbox(o, &sFlyBugHurt);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    // Changes action based on distance to Mario
    if (o->oDistanceToMario > 1000.0f) {
        o->oAction = 0;
    } else {
        cur_obj_init_animation(1);
        o->oAction = 1;
    }

    o->oAngleToHome = cur_obj_angle_to_home();

    switch (o->oAction) {
        case 0: // Idle
            // Return to Home
            if ((cur_obj_lateral_dist_to_home() > 100.0f) && (o->oPosY < (o->oHomeY + 50)) ) {
                o->oPosY = approach_s16_symmetric(o->oPosY, (o->oHomeY + 50), 10);
            } else if (cur_obj_lateral_dist_to_home() > 100.0f) {
                cur_obj_rotate_yaw_toward(o->oAngleToHome, 0x300);
                cur_obj_forward_vel_approach_upward(5.0f, 0.8f);
            // Drop to floor 
            } else {
                if (o->oPosY <= floor) {
                    cur_obj_init_animation(0);
                        if (o->oDistanceToMario < 3000.0f) {
                            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x100);
                        }
                } else {
                    o->oPosY = approach_s16_symmetric(o->oPosY, floor, 10);
                }
                cur_obj_forward_vel_approach_upward(0, 0.8f);
                targetY = floor;
            }
            break;

        case 1: // Move
            if (floor > (o->oPosY-100)) {
                targetY = floor;
                if ((targetY - o->oPosY) < 50) {
                    o->oPosY = approach_s16_symmetric(o->oPosY, (targetY+100), 5);
                } else {
                    o->oMoveAngleYaw += 0x8000;
                }
            }

            // Change velocity and rotation speed based on Mario's distance
            // If Mario is closer, they are slower
            if (lateral_dist_between_objects(o, gMarioObject) > 100.0f) {
                cur_obj_forward_vel_approach_upward(16.0f, 0.8f);
                cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x300);
            } else {
                cur_obj_forward_vel_approach_upward(2.5f, 0.8f);
                cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);
                targetY = floor;
                o->oPosY = approach_s16_symmetric(o->oPosY, (targetY+100), 5);
            }
            break;
    }

    // Ground Pound Enemy to Kill
    if (cur_obj_is_mario_ground_pounding_platform()) {
        spawn_mist_particles();
        cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SKEETER_DEATH);
        cur_obj_spawn_loot_blue_coin();
        obj_mark_for_deletion(o);
    } 

    cur_obj_update_floor_and_walls();
}

void bhv_tree_floor(void) {
    o->parentObj = cur_obj_nearest_object_with_behavior(bhvGroundPoundSwitch);

    if (o->parentObj->oAction == 1) {
        spawn_mist_particles();
        spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
        cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
        obj_mark_for_deletion(o);
    }
}

struct ObjectHitbox sBugaboomHurt = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 250,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_bugaboom(void) {
    s16 startYaw = o->oMoveAngleYaw;
    o->oAngleToHome = cur_obj_angle_to_home();
    f32 distToHome = cur_obj_lateral_dist_to_home();
    s32 speed = 0x90;

    // Speed up in later phases
    if (o->oHealth <= 2) {
        speed = 0x100;
    }

    // Handles hurting Mario interaction
    obj_set_hitbox(o, &sBugaboomHurt);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

    // Slow down if Mario is near
    if (lateral_dist_between_objects(o, gMarioObject) < 300.0f) {
        speed = 0x50;
    }

    cur_obj_init_animation(1);

    o->oBugAngle += speed;

    // Reset oBugAngle if it gets to high to maybe prevent overflow?
    if (o->oBugAngle >= 0xFFFF) {
        o->oBugAngle = 0x0000;
    }

    s16 circularTurn = o->oBugAngle - atan2s(1000.0f, distToHome - 1000.0f);

    o->oPosX = o->oHomeX + coss(circularTurn)*1250; // Last number is distance away
    o->oPosZ = o->oHomeZ + sins(circularTurn)*1250;

    o->oMoveAngleYaw = -circularTurn;

    // Ground Pound to Hurt Boss
    if ((cur_obj_is_mario_ground_pounding_platform()) && (!(o->oBugFlashing))) {
        cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SKEETER_DEATH);
        o->oHealth--;
        // Don't fling Mario if dead
        if (o->oHealth > 0) {
            gMarioState->faceAngle[1] = 0x4000 - circularTurn;
            gMarioState->action = ACT_BACKWARD_AIR_KB;
            gMarioStates[0].vel[1] = 65.0f;
            gMarioStates[0].forwardVel = -60.0f;
            o->oBugFlashing = TRUE;
        }
    } 

    // Kill if no health
    if (o->oHealth <= 0) {
        spawn_mist_particles();
        obj_mark_for_deletion(o);
    }

    // Handle Flashing
    if (o->oBugFlashing) {
        o->oBugInvisibleFrames++;

        // Begin flashing
        if (o->oBugInvisibleFrames < 45) {
            COND_BIT((o->oBugInvisibleFrames & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
        }

        // Stop flashing
        if (o->oBugInvisibleFrames >= 45) {
            o->oBugInvisibleFrames = 0;
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            o->oBugFlashing = FALSE;
        }
    }

    if (o->oHealth == 1) {
        o->oPosY = approach_s16_symmetric(o->oPosY, 300, 10);
    }

}