// slide.inc.c

#define ANALOG_AMOUNT 162144 / 315
#define RATE (ANALOG_AMOUNT * ((gPlayer1Controller->stickX / 64.0f) * (gPlayer1Controller->stickX / 64.0f)) * 1.0f)

void bhv_tilt_platform(void) {

    // Tilts the platform based on the left joystick
    if (gPlayer1Controller->rawStickX > 0) {
        o->oFaceAngleRoll += RATE;
    } else if (gPlayer1Controller->rawStickX < 0) {
        o->oFaceAngleRoll += RATE * -1.0;
    }

    // Makes it so the platform doesn't rotate past 45 degrees
    if (o->oFaceAngleRoll > 0x2000) {
        o->oFaceAngleRoll = 0x2000;
    }

    if (o->oFaceAngleRoll < -0x2000) {
        o->oFaceAngleRoll = -0x2000;
    }
    
}

void bhv_tilt_box(void) {

    // Tilts the platform based on the left joystick
    if (gPlayer1Controller->rawStickX > 0) {
        o->oFaceAngleRoll += RATE * -1.0;
    } else if (gPlayer1Controller->rawStickX < 0) {
        o->oFaceAngleRoll += RATE;
    }
    
}

void bhv_slide_platform_hori(void) {

    // Left joystick makes the platform move left/right
    if (gPlayer1Controller->rawStickX > 0) {
        o->oPosX += RATE / 13;
    } else if (gPlayer1Controller->rawStickX < 0) {
        o->oPosX += RATE / 13 * -1.0;
    }

    f32 limitRight = GET_BPARAM1(o->oBehParams);
    f32 limitLeft = GET_BPARAM3(o->oBehParams);

    // Flips the limit if the next BPARAM is not 0
    if (GET_BPARAM2(o->oBehParams) > 0) {
        limitRight = (GET_BPARAM1(o->oBehParams) * -1.0);
    }

    if (GET_BPARAM4(o->oBehParams) > 0) {
        limitLeft = (GET_BPARAM3(o->oBehParams) * -1.0);
    }

    // Limits the platform to be in between BPARAM2 and BPARAM 3 divided by 10
    if (o->oPosX > limitRight * 10.0) {
        o->oPosX = limitRight * 10.0;
    }

    if (o->oPosX < limitLeft * -10.0) {
        o->oPosX = limitLeft * -10.0;
    }

}

void bhv_slide_platform_vert(void) {

    // Left joystick makes the platform move up/down
    if (gPlayer1Controller->rawStickX > 0) {
        o->oPosY += RATE / 10;
    } else if (gPlayer1Controller->rawStickX < 0) {
        o->oPosY += RATE / 10 * -1.0;
    }

    // Limits the platform to be in between BPARAM2 and BPARAM 3 divided by 10
    if (o->oPosX > GET_BPARAM2(o->oBehParams) * 10.0) {
        o->oPosX = GET_BPARAM2(o->oBehParams) * 10.0;
    }

    if (o->oPosX < (GET_BPARAM3(o->oBehParams) * -10.0)) {
        o->oPosX = (GET_BPARAM3(o->oBehParams) * -10.0);
    }

}