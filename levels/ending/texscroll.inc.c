void scroll_ending_dl_Cube_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ending_dl_Cube_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(0.30000001192092896 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_ending_dl_black() {
	Gfx *mat = segmented_to_virtual(mat_ending_dl_black);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
};

void scroll_ending_dl_Cube_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 15;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ending_dl_Cube_mesh_layer_6_vtx_0);

	deltaX = (int)(-0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sts_mat_ending_dl_stars() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ending_dl_stars);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 2));
		shift_t_down(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_ending_dl_Cube_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 32;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ending_dl_Cube_mesh_layer_5_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_ending() {
	scroll_ending_dl_Cube_mesh_layer_1_vtx_0();
	scroll_sts_mat_ending_dl_black();
	scroll_ending_dl_Cube_mesh_layer_6_vtx_0();
	scroll_sts_mat_ending_dl_stars();
	scroll_ending_dl_Cube_mesh_layer_5_vtx_0();
}
