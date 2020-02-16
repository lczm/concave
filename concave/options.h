#pragma once
#include "window.h"
#include "button.h"
#include "image.h"

class Options : public Window
{
private:

	Texture menuBgTexture;
	SpriteData menuBg;

	Texture optionBgTexture;
	SpriteData optionBg;

	Texture backBtnTexture;
	Texture backHoverTexture;
	Button back;
	Button backHover;

	Texture scrollBarTexture;
	Texture scrollerTexture;
	Button scrollBar;
	Button scroller;

public:
	Options();
	~Options();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};