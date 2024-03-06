// slide.inc.c

#define ANALOG_AMOUNT 162144 / 315
const int rate = 300;

void bhv_tilt_platform(void) {

    if (gPlayer1Controller->rawStickX > 0) {
        o->oFaceAngleRoll += ANALOG_AMOUNT * ((gPlayer1Controller->stickX / 64.0f) * (gPlayer1Controller->stickX / 64.0f)) * 1.0f;
    } else if (gPlayer1Controller->rawStickX < 0) {
        o->oFaceAngleRoll += ANALOG_AMOUNT * ((gPlayer1Controller->stickX / 64.0f) * (gPlayer1Controller->stickX / 64.0f)) * -1.0f;
    }
    //if (gPlayer1Controller->rawStickX > 60) o->oFaceAngleRoll += rate;
    //if (gPlayer1Controller->rawStickX < -60) o->oFaceAngleRoll -= rate;
}