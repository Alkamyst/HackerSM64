#include "src/game/envfx_snow.h"

const GeoLayout tree_door_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_door_Main_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_door_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
