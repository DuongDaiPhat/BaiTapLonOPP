#include "Map.h"

map_Object::map_Object() {
	img_object = NULL;
	img_rect.x = 0;
	img_rect.y = 0;
	img_rect.w = 0;
	img_rect.h = 0;
}

map_Object::~map_Object() {
	free();
}

bool map_Object::loadMap(const string path, SDL_Renderer* renderer) {
	SDL_Surface *newSurface = SDL_LoadBMP(path.c_str());
	if (newSurface == NULL) {
		return false;
	}
	img_object = SDL_CreateTextureFromSurface(renderer, newSurface);
	if (img_object == NULL) {
		return false;
	}
	SDL_FreeSurface(newSurface);
	return true;
}

void map_Object::readType(const string file_Mapname) {
	ifstream TypeFile(file_Mapname.c_str());
	if (TypeFile.is_open()) {
		for (int y = 0; y < MAX_TILE_Y; y++) {
			for (int x = 0; x < MAX_TILE_X; x++) {
				TypeFile >> type[y][x];
			}
		}
	}
	TypeFile.close();
}

void map_Object::MapRender(SDL_Renderer* renderer, int X_OFFSET) {
	for (int y = 0; y < MAX_TILE_Y; y++) {
		for (int x = 0; x < MAX_TILE_X; x++) {
			tile[y][x + X_OFFSET].x = x * 64;
			tile[y][x + X_OFFSET].y = y * 64;
			tile[y][x + X_OFFSET].w = 64;
			tile[y][x + X_OFFSET].h = 64;
			switch (type[y][x + X_OFFSET]) {
				case 1: {
					mapClip[y][x + X_OFFSET] = {0, 0, 64, 64};
					break;
				}
				case 2: {
					mapClip[y][x + X_OFFSET] = { 64, 0, 64, 64 };
					break;
				}
				case 3: {
					mapClip[y][x + X_OFFSET] = { 0, 64, 64, 64 };
					break;
				}
				case 4: {
					mapClip[y][x + X_OFFSET] = { 64, 64, 64, 64 };
					break;
				}
				default: {
					continue;
				}
			}
			SDL_RenderCopy(renderer, img_object, &mapClip[y][x + X_OFFSET], &tile[y][x + X_OFFSET]);
		}
	}
}

void map_Object::free() {
	if (img_object != NULL) {
		SDL_DestroyTexture(img_object);
		img_object = NULL;
		img_rect.x = 0;
		img_rect.y = 0;
		img_rect.w = 0;
		img_rect.h = 0;
	}
}
