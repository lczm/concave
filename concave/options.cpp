#include "options.h"

Options::Options()
{}

Options::~Options()
{}

void Options::initialize()
{

	menuBgTexture.initialize(Window::graphics, MENU_BG);
	menuBgTexture.getSpriteData(menuBg);

	optionBgTexture.initialize(Window::graphics, OPTIONS_BG);
	optionBgTexture.getSpriteData(optionBg);

	backBtnTexture.initialize(Window::graphics, BACK_BTN_TEXTURE);
	backHoverTexture.initialize(Window::graphics, BACK_HOVER_TEXTURE);
	back.initialize(Window::graphics, Window::input, &backBtnTexture);
	backHover.initialize(Window::graphics, Window::input, &backHoverTexture);



	scrollBarTexture.initialize(Window::graphics, SCROLLBAR);
	scrollerTexture.initialize(Window::graphics, SCOLLER);

	scrollBar.initialize(Window::graphics, Window::input, &scrollBarTexture);
	scroller.initialize(Window::graphics, Window::input, &scrollerTexture);

	back.setPos(0, 0);
	backHover.setPos(0, 0);

	scrollBar.setPos(GAME_WIDTH / 2 - scrollBar.getWidth()/ 2, GAME_HEIGHT / 2 - scrollBar.getHeight() / 2);
	scroller.setPos(GAME_WIDTH / 2 - scrollBar.getWidth() / 2, GAME_HEIGHT / 2 - scrollBar.getHeight() / 1.7);

}

void Options::releaseAll()
{}

void Options::resetAll()
{}

void Options::update()
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


	int mouseX = input->getMouseX();

	if (scrollBar.isClicked())
	{
	
		scroller.setPos(mouseX, GAME_HEIGHT / 2 - scrollBar.getHeight() / 1.7);

	}
}

void Options::render()
{
	graphics->drawSprite(menuBg, 0, 0, 1);
	graphics->drawSprite(optionBg, GAME_WIDTH/2 - optionBg.width/2, GAME_HEIGHT/2 - optionBg.height/2, 1);

	back.draw();
	backHover.draw();
	scrollBar.draw();
	scroller.draw();
}
