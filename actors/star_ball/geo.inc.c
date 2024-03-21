#include "src/game/envfx_snow.h"

const GeoLayout star_ball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, star_ball_Sphere_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, star_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
