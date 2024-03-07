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