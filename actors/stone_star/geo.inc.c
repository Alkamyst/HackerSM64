#include "src/game/envfx_snow.h"

const GeoLayout stone_star_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stone_star_skinned_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stone_star_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
