#include <CoalaMod.h>
#pragma comment(lib, "CoalaMOD.lib")
#include <stdio.h>

int main() {

	BlockID stone = createBlock(BLOCK_STONE);
	WoolID wool1 = createWool(BlockColor (COLOR_WHITE));
	WoolID wool2 = createWool(BlockColor (COLOR_RED));

	int sx, sy, sz, ex, ey, ez;												//입력받을 좌표
	int x, y, z;															//설치를 시작할 기준 좌표
	scanf_s("%d, %d, %d, %d, %d, %d", &sx, &sy, &sz, &ex, &ey, &ez);
	int dx = sx - ex, dy = sy - ey, dz = sz - ez;							//건물의 길이들

	if (dx < 0) {
		dx = -dx;
	}

	if (dy < 0) {
		dy = -dy;
	}
	if (dz < 0) {
		dz = -dz;
	}

	// 길이는 양수

	if (sx < ex) {
		x = sx;
	}
	else x = ex;

	if (sy < ey) {
		y = sy;
	}
	else y = ey;

	if (sz < ez) {
		z = sz;
	}
	else z = ez;

	// 기준좌표 설정

	for (int i = 0; i <= dy;i= i+2) {
		for (int j = 0; j <= dz; j=j+2) {
			for (int k = 0; k <= dx; k=k+2) {
			
				locateBlock(wool1, x + k, y + i, z + j);
			}
		}
	}
	for (int i = 1; i <= dy; i = i + 2) {
		for (int j = 1; j <= dz; j = j + 2) {
			for (int k = 1; k <= dx; k = k + 2) {

				locateBlock(wool2, x + k, y + i, z + j);
			}
		}
	} 

	//건물생성~!
}