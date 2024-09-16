#pragma once
#ifndef NHAN_VAT_H
#define NHAN_VAT_H

#include "DoiTuongCoSo.h"
#include "HamCoBan.h"

class NhanVatChinh : public BaseObj {
private:
	float charSpeed;
	float jumpPower;
	//Vi tri show cua nhan vat
	float xPosition;
	float yPosition;
	int width_frame;
	int height_frame;
	SDL_Rect walkFrameClip[10];
	Input input_type;
	int frameNum;
	walkType charStatus;
public:
	NhanVatChinh();
	~NhanVatChinh();
	bool loadImage(const string path, SDL_Renderer* renderer, int width, int height);
	//Ham show animation//
	void Show(SDL_Renderer* renderer);
	//Ham xu ly su kien//
	void HandleInput(const Uint8* pkeys, SDL_Renderer* renderer);
	void setClips();
};

#endif // !NHAN_VAT_H
