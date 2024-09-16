#pragma once
#ifndef MAP
#define MAP
#include "DoiTuongCoSo.h"
#include "HamCoBan.h"

class map_Object: public BaseObj {
protected:
	int type[18][50];
	SDL_Rect tile[18][50];
	SDL_Rect mapClip[18][50];
public:
	map_Object();
	~map_Object();
	bool loadMap(const string path, SDL_Renderer* renderer);
	void readType(const string file_Mapname);
	void MapRender(SDL_Renderer* renderer, int X_OFFSET);
	void free();
};

#endif // 
