#include "HamCoBan.h"
#include "DoiTuongCoSo.h"

BaseObj background;

//Thay vì Init từng window, renderer,.. thì dùng chung một hàm InitData()//
//Hàm InitData sẽ khởi tạo tất cả các chức năng trong SDL cần thiết để load ảnh lên màn hình//
//Trả về 0 nếu khởi tạo thất bại//

bool initData() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Loi mo window\n";
		return false;
	}
	//Tối ưu hóa hình ảnh//
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	
	//Khởi tạo window//
	window = SDL_CreateWindow("BTLOOP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
bool loadBackGround() {
	bool check = background.loadImage("C:\\BTL\\BTLOOP\\assets\\background1.jpg", renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (check == false) {
		return false;
	}
	return true;
}

//Hàm tắt chương trình.
void close() {
	background.Free();
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	if (initData() == false)
		return false;
	if (loadBackGround() == false) {
		return false;
	}

	bool running = true;
	while (running) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			running = false;
		}
		SDL_RenderClear(renderer);
		background.render(renderer, NULL);
		SDL_RenderPresent(renderer);
	}
	close();
	return 0;
}
