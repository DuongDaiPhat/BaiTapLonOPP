#include "Map.h"
#include "DoiTuongCoSo.h"
#include "HamCoBan.h"
#include "NhanVat.h"


BaseObj background;
map_Object gameMap;
NhanVatChinh player;


//Thay vì Init từng window, renderer,.. thì dùng chung một hàm InitData()//
//Hàm InitData sẽ khởi tạo tất cả các chức năng trong SDL cần thiết để load ảnh lên màn hình//
//Trả về 0 nếu khởi tạo thất bại//

static bool initData() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Loi mo window\n";
		return false;
	}
	//Tối ưu hóa hình ảnh//
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	
	//Khởi tạo window//
	window = SDL_CreateWindow("BTLOOP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	//Nếu tạo thành công window thì mới tạo tiếp và tương tự//
	if (window == NULL) {
		return false;
		
	}
	else {
		//Tạo render
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL) {
			return false;
		}
		else {
			//Tạo màu mặc định//
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			//Khởi tạo ảnh để sử dụng IMG_Load;
			if (!(IMG_Init(IMG_INIT_JPG) && IMG_INIT_JPG)) {
				return false;
			}
		}
	}
	return 1;
}

//Hàm load back ground trong thư mục assets
static bool loadBackGround() {
	bool check = background.loadImage("C:\\BTL\\BTLOOP\\assets\\background\\background1.jpg", renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (check == false) {
		return false;
	}
	return true;
}

static bool loadMap() {
	bool check = gameMap.loadMap("C:\\BTL\\BTLOOP\\assets\\tileMap\\map.bmp", renderer);
	if (check == false) {
		return false;
	}
	gameMap.readType("C:\\BTL\\BTLOOP\\file\\map.txt");
	return true;
		
}
static bool loadPlayer() {
	bool check = player.loadImage("C:\\BTL\\BTLOOP\\assets\\Character\\CharacterMoveRight.bmp", renderer, 0, 0);
	if (check == false) {
		return false;
	}
	player.setClips();
	return true;
}
//Hàm tắt chương trình.
static void close() {
	background.Free();
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	if (initData() == false) {
		SDL_Quit();
		return false;
	}
	if (loadBackGround() == false) {
		SDL_Quit();
		return false;

	}
	if (loadMap() == false) {
		SDL_Quit();
		return false;

	}
	if (loadPlayer() == false) {
		SDL_Quit();
	}
	const Uint8* pKeys = SDL_GetKeyboardState(NULL);
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
			}
			player.HandleInput(pKeys, renderer);
			static int X_OFFSET = 0;
			if (pKeys[SDL_SCANCODE_A]) {
				X_OFFSET--;
				SDL_Delay(20);
			}
			if (pKeys[SDL_SCANCODE_D]) {
				X_OFFSET++;
				SDL_Delay(20);
			}
			if (X_OFFSET < 0) {
				X_OFFSET = 0;

			}
			else if (X_OFFSET > 50) {
				X_OFFSET = 50;
			}
			SDL_RenderClear(renderer);
			background.render(renderer, NULL);
			gameMap.MapRender(renderer, X_OFFSET);
			player.Show(renderer);
			SDL_RenderPresent(renderer);
		}
	}
	close();
	return 0;
}
