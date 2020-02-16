#include "instructions.h"

Instructions::Instructions()
{}

Instructions::~Instructions()
{}

void Instructions::initialize()
{
	menuBgTexture.initialize(Window::graphics, MENU_BG);
	menuBgTexture.getSpriteData(menuBg);


	insBgTexture.initialize(Window::graphics, INS_BG);
	insBgTexture.getSpriteData(insBg);

	backBtnTexture.initialize(Window::graphics, BACK_BTN_TEXTURE);
	backHoverTexture.initialize(Window::graphics, BACK_HOVER_TEXTURE);
	back.initialize(Window::graphics, Window::input, &backBtnTexture);
	backHover.initialize(Window::graphics, Window::input, &backHoverTexture);


}

void Instructions::releaseAll()
{}

void Instructions::resetAll()
{}

void Instructions::update()
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

void Instructions::render()
{
	graphics->drawSprite(menuBg, 0, 0, 1);

	graphics->drawSprite(insBg, GAME_WIDTH / 2 - insBg.width / 2, GAME_HEIGHT / 2 - insBg.height / 2, 1);
	back.draw();
	backHover.draw();
}
