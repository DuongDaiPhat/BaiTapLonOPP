#ifndef MAP

#define MAP
#include "DoiTuongCoSo.h"

class map_Object: public BaseObj {
protected:
	int type[20][30];
	SDL_Rect tile[20][30];
public:
	map_Object();
	~map_Object();
	bool loadMap(const string path, SDL_Renderer* renderer);
	void readType(const string file_Mapname);
	void MapRender(SDL_Renderer* renderer);
	void free();
};

#endif // 
