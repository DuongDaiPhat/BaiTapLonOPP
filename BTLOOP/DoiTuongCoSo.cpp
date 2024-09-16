#include "DoiTuongCoSo.h"
#include "HamCoBan.h"

BaseObj::BaseObj() {
	img_object = NULL;
	img_rect.x = 0;
	img_rect.y = 0;
	img_rect.w = 0;
	img_rect.h = 0;
}

BaseObj::~BaseObj() {
	Free();
}


bool BaseObj::loadImage(string img_path, SDL_Renderer* screen, int width, int height) {
	//Tạo một texture mới//
	SDL_Texture* newTexture = NULL;
	//Khởi tạo một surface từ img_path;
	SDL_Surface* loadSurface = IMG_Load(img_path.c_str()); //cho img_path trả về const char *
	if (loadSurface != NULL) {
		//cho surface với thông số màu mặc định xem là trong suốt cho nên trong suốt/
		SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, RED_KEY, GREEN_KEY, BLUE_KEY));
		//gán texture mới từ surface mới chỉnh sửa//
		newTexture = SDL_CreateTextureFromSurface(screen, loadSurface);
		if (newTexture != NULL) {
			//lấy giá trị chiều cao, chiều rộng của ảnh trong surface nếu chiều cao chiều rộng không được thiết lập
			if (width == 0 && height == 0) {
				img_rect.w = loadSurface->w;
				img_rect.h = loadSurface->h;
			}
			else {
				img_rect.w = width;
				img_rect.h = height;
			}
		}
		//Surface đã làm xong nhiệm vụ, giải phóng//
		SDL_FreeSurface(loadSurface);
		img_object = newTexture;
		if (img_object == NULL) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

//Hàm render ảnh//
void BaseObj::render(SDL_Renderer* des, const SDL_Rect* clip) {
	//Tạo một biến dstrect để ảnh khi được render lên màn hình đúng kích thước.
	SDL_Rect dstrect = { img_rect.x, img_rect.y, img_rect.w, img_rect.h };
	SDL_RenderCopy(des, img_object, clip, &dstrect);
}

void BaseObj::Free() {
	//Nếu object đã đươc tạo thì giải phóng bộ nhớ đ tạo//
	if (img_object != NULL) {
		SDL_DestroyTexture(img_object);
		img_object = NULL;
		img_rect.x = 0;
		img_rect.y = 0;
		img_rect.w = 0;
		img_rect.h = 0;
	}
}
