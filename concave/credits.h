#pragma once
#include "window.h"

class Credits : public Window
{
private:
	Texture menuBgTexture;
	SpriteData menuBg;

	Texture crBgTexture;
	SpriteData crBg;

	Texture backBtnTexture;
	Texture backHoverTexture;
	Button back;
	Button backHover;


public:
	Credits();
	~Credits();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};