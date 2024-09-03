﻿//File chứa tất cả hàm cơ bản, thư viện cơ bản và thông số cơ bản dùng chung cho cả dự án//

#ifndef HAM_CO_BAN_H
#define HAM_CO_BAN_H

//thư viện cơ bản
#include <iostream>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

//Init Các biến SDL cơ bản//
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Event event;

//Thông số màn hình của game//
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BBP = 32; //32 bits per pixel;

//Thông số màu RGB trong suốt dùng để xóa background ảnh//

const int RED_KEY = 167;
const int BLUE_KEY = 175;
const int GREEN_KEY = 180;
#endif
