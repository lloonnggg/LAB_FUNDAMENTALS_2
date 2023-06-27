#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<ctime>
#include<Windows.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

static int ScreenWidth = 800;
static int ScreenHeight = 600;
static int BackgroundWidth = 800;
static int BackgroundHeight = ScreenHeight * 2;
static int SCROLL_SPEED = 2;
static int scrollPos = BackgroundHeight - 800;