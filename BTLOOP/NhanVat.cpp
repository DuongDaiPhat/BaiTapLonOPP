#include "NhanVat.h"

NhanVatChinh::NhanVatChinh() {
	frameNum = 0;
	xPosition = 896;
	yPosition = 836;
	charSpeed = 32;
	jumpPower = 0;
	width_frame = 0;
	height_frame = 0;
	charStatus = WALK_RIGHT;
}

NhanVatChinh::~NhanVatChinh() {

}

bool NhanVatChinh::loadImage(const string path, SDL_Renderer* renderer, int width, int height) {
	bool check = BaseObj::loadImage(path, renderer, width, height);
	if (check == true) {
		width_frame = img_rect.w/10;
		height_frame = img_rect.h;
	}
	return check;
}
void NhanVatChinh::setClips() {
	if (width_frame > 0 && height_frame > 0) {
		for (int i = 0; i < 10; ++i) {
			walkFrameClip[i].x = i * width_frame;
			walkFrameClip[i].y = 0;
			walkFrameClip[i].w = width_frame;
			walkFrameClip[i].h = height_frame;
		}
	}
}

void NhanVatChinh::Show(SDL_Renderer* renderer) {
	if (input_type.goLeft == 1 || input_type.goRight == 1) {
		frameNum++;
		SDL_Delay(20);
	}
	else {
		frameNum = 0;
	}

	if (frameNum >= 10) {
		frameNum = 0;
	}

	img_rect.x = xPosition;
	img_rect.y = yPosition;

	SDL_Rect* current_clip = &walkFrameClip[frameNum];
	SDL_Rect renderQuad = {img_rect.x, img_rect.y, width_frame, height_frame};
	if (charStatus == WALK_LEFT) {
		SDL_RenderCopyEx(renderer, img_object, current_clip, &renderQuad, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
	else {
		SDL_RenderCopy(renderer, img_object, current_clip, &renderQuad);
	}
}

void NhanVatChinh::HandleInput(const Uint8* pkeys, SDL_Renderer* renderer) {
	if (pkeys[SDL_SCANCODE_A]) {
		if (charStatus != WALK_LEFT) {
			loadImage("C:\\BTL\\BTLOOP\\assets\\haracter\\CharacterMoveRight.bmp", renderer, 0, 0);
		}
		charStatus = WALK_LEFT;
		input_type.goLeft = 1;
	}
	if (pkeys[SDL_SCANCODE_D]) {
		if (charStatus != WALK_RIGHT) {
			loadImage("C:\\BTL\\BTLOOP\\assets\\haracter\\CharacterMoveRight.bmp", renderer, 0, 0);
		}
		charStatus = WALK_RIGHT;
		input_type.goRight = 1;
	}
	if (!pkeys[SDL_SCANCODE_A]) {
		input_type.goLeft = 0;
	}
	if (!pkeys[SDL_SCANCODE_D]) {
		input_type.goRight = 0;
	}
}