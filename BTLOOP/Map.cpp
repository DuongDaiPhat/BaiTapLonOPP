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
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j < 30; j++) {
				TypeFile >> type[i][j];
			}
		}
	}
	TypeFile.close();
}

void map_Object::MapRender(SDL_Renderer* renderer) {
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 30; j++) {
			tile[i][j].x = j * 64;
			tile[i][j].y = i * 64;
			tile[i][j].w = 64;
			tile[i][j].h = 64;
			SDL_Rect clip;
			switch (type[i][j]) {
				case 1: {
					clip = { 0, 0, 64, 64 };
					break;
				}
				case 2: {
					clip = { 64, 0, 64, 64 };
					break;
				}
				case 3: {
					clip = { 0, 64, 64, 64 };
					break;
				}
				case 4: {
					clip = { 64, 64, 64, 64 };
					break;
				}
				default: {
					continue;
				}
			}
			SDL_RenderCopy(renderer, img_object, &clip, &tile[i][j]);
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
