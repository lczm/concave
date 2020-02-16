#include "mainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{}



void MainMenu::initialize()
{

	initButtons();

	menuBgTexture.initialize(Window::graphics, MENU_BG);
	menuBgTexture.getSpriteData(menuBg);

	logoTexture.initialize(Window::graphics, LOGO);
	logoTexture.getSpriteData(logo);


}

//SpriteData MainMenu::initBg(const char* file)
//{
//	Texture texture;
//	SpriteData sd;
//
//	texture.initialize(Window::graphics, file);
//	texture.getSpriteData(sd);
//	return sd;
//}

void MainMenu::initButtons()
{
	playbtnTexture.initialize(Window::graphics, PLAY_BTN_TEXTURE);
	insbtnTexture.initialize(Window::graphics, INS_BTN_TEXTURE);
	optbtnTexture.initialize(Window::graphics, OPT_BTN_TEXTURE);
	crbtnTexture.initialize(Window::graphics, CR_BTN_TEXTURE);

	playHoverTexture.initialize(Window::graphics, PLAY_HOVER_TEXTURE);
	insHoverTexture.initialize(Window::graphics, INS_HOVER_TEXTURE);
	optHoverTexture.initialize(Window::graphics, OPT_HOVER_TEXTURE);
	crHoverTexture.initialize(Window::graphics, CR_HOVER_TEXTURE);


	


	playbtn.initialize(Window::graphics, Window::input, &playbtnTexture);
	insbtn.initialize(Window::graphics, Window::input, &insbtnTexture);
	optbtn.initialize(Window::graphics, Window::input, &optbtnTexture);
	crbtn.initialize(Window::graphics, Window::input, &crbtnTexture);

	playHover.initialize(Window::graphics, Window::input, &playHoverTexture);
	insHover.initialize(Window::graphics, Window::input, &insHoverTexture);
	optHover.initialize(Window::graphics, Window::input, &optHoverTexture);
	crHover.initialize(Window::graphics, Window::input, &crHoverTexture);

	

	playbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 375);
	playHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 375);

	insbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 450);
	insHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 450);

	optbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 525);
	optHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 525);

	crbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 600);
	crHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 600);


}



void MainMenu::releaseAll()
{
}

void MainMenu::resetAll()
{}

//void MainMenu::CheckState(Button a, Button a_hover)
//{
//	if (a.isHovered())
//	{
//		a.setActive(false);
//		a_hover.setActive(true);
//	}
//	else
//
//
//}

void MainMenu::update()
{

	if (playbtn.isHovered()) 
	{
		playHover.setActive(true);
		playbtn.setActive(false);
	}
	else if (insbtn.isHovered())
	{
		insHover.setActive(true);
		insbtn.setActive(false);
	}
	else if (optbtn.isHovered())
	{
		optHover.setActive(true);
		optbtn.setActive(false);

		

	}
	else if(crbtn.isHovered())
	{
		crHover.setActive(true);
		crbtn.setActive(false);
	}
	
	else
	{
		playHover.setActive(false);
		insHover.setActive(false);
		optHover.setActive(false);
		crHover.setActive(false);
		

		playbtn.setActive(true);
		insbtn.setActive(true);
		optbtn.setActive(true);
		crbtn.setActive(true);

	}

	if (playbtn.isClicked())
	{
		input->setMouseLButton(false);
		windows.pop_back();
		windows.push_back(&level);
        windows.push_back(&hud);
	}
	
	if (optbtn.isClicked())
	{

		windows.pop_back();
		windows.push_back(&options);

	}

	if (insbtn.isClicked())
	{

		windows.pop_back();
		windows.push_back(&instructions);

	}

	if (crbtn.isClicked())
	{

		windows.pop_back();
		windows.push_back(&credits);

	}

	

}

void MainMenu::render()
{
	graphics->drawSprite(menuBg, 0, 0, 1);

	graphics->drawSprite(logo, 400, 50, 0.5);


	

	playbtn.draw();
	insbtn.draw();
	optbtn.draw();
	crbtn.draw();
	playHover.draw();
	insHover.draw();
	optHover.draw();
	crHover.draw();
	
}