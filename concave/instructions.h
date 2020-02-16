#pragma once
#include "window.h"
#include "button.h"
#include "image.h"

class Instructions : public Window
{
private:

	Texture menuBgTexture;
	SpriteData menuBg;

	Texture insBgTexture;
	SpriteData insBg;

	Texture backBtnTexture;
	Texture backHoverTexture;
	Button back;
	Button backHover;

public:
	Instructions();
	~Instructions();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};