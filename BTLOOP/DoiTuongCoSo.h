#pragma once
#ifndef DOI_TUONG_CO_SO_H
#define DOI_TUONG_CO_SO_H

#include "HamCoBan.h"
	
using namespace std;

//Đối tượng cơ sở
class BaseObj {
protected:
	//Biến lưu trữ hình ảnh
	SDL_Texture* img_object; //image object
	//Biến lưu trữ kích thước hình ánh
	SDL_Rect img_rect;
public:
	//Hàm mặc định khởi tạo Constructor
	BaseObj();
	//Hàm mặc định giải phóng sau khi kết thúc chương trình Destructor
	~BaseObj();
	//Hàm Set kích thước cho Rect
	void setRect(const int &x, const int &y) {
		img_rect.x = x;
		img_rect.y = y;
	}
	//Hàm lấy Rect//
	SDL_Rect getRect() const{
		return img_rect;
	}
	//Hàm lấy img_object
	SDL_Texture* getObject() const {
		return img_object;
	}
	//Hàm load img trả về true nếu load thành công
	//picType: 0 = picture, 1 = BMP
	virtual bool loadImage(string image_path, SDL_Renderer* screen, int width, int height);
	//Hàm Render ảnh để load lên màn hình
	void render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	//Hàm giải phóng và sẽ được bỏ mặc định vào hàm destructor (~BaseObj)
	void Free();
};
#endif // !DOI_TUONG_CO_SO_H
