#include "credits.h"

Credits::Credits()
{}

Credits::~Credits()
{}

void Credits::initialize()
{
	menuBgTexture.initialize(Window::graphics, MENU_BG);
	menuBgTexture.getSpriteData(menuBg);


	crBgTexture.initialize(Window::graphics, CR_BG);
	crBgTexture.getSpriteData(crBg);

	backBtnTexture.initialize(Window::graphics, BACK_BTN_TEXTURE);
	backHoverTexture.initialize(Window::graphics, BACK_HOVER_TEXTURE);
	back.initialize(Window::graphics, Window::input, &backBtnTexture);
	backHover.initialize(Window::graphics, Window::input, &backHoverTexture);
}

void Credits::releaseAll()
{}

void Credits::resetAll()
{}

void Credits::update()
{
	if (back.isHovered())
	{
		backHover.setActive(true);
		back.setActive(false);
	}
	else
	{
		back.setActive(true);
		backHover.setActive(false);
	}

	if (back.isClicked())
	{
		windows.pop_back();
		windows.push_back(&mainMenu);
	}
}


void Credits::render()
{
	graphics->drawSprite(menuBg, 0, 0, 1);

	graphics->drawSprite(crBg, GAME_WIDTH / 2 - crBg.width / 2, GAME_HEIGHT / 2 - crBg.height / 2, 1);
	back.draw();
	backHover.draw();
}
