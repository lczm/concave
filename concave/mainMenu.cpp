#include "mainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{}

void MainMenu::initBg(Graphics* graphics)
{
	menuBg.initialize(graphics, MENU_BG);
}

void MainMenu::initialize()
{
	initBg(Window::graphics);

	playbtnTexture.initialize(Window::graphics, PLAY_BTN_TEXTURE);
	insbtnTexture.initialize(Window::graphics, INS_BTN_TEXTURE);
	optbtnTexture.initialize(Window::graphics, OPT_BTN_TEXTURE);
	crbtnTexture.initialize(Window::graphics, CR_BTN_TEXTURE);

	playHoverTexture.initialize(Window::graphics, PLAY_HOVER_TEXTURE);
	insHoverTexture.initialize(Window::graphics, INS_HOVER_TEXTURE);
	optHoverTexture.initialize(Window::graphics, OPT_HOVER_TEXTURE);
	crHoverTexture.initialize(Window::graphics, CR_HOVER_TEXTURE);


	scrbarTexture.initialize(Window::graphics, SCROLLBAR);
	scrollerTexture.initialize(Window::graphics, SCOLLER);


	playbtn.initialize(Window::graphics, Window::input, &playbtnTexture);
	insbtn.initialize(Window::graphics, Window::input, &insbtnTexture);
	optbtn.initialize(Window::graphics, Window::input, &optbtnTexture);
	crbtn.initialize(Window::graphics, Window::input, &crbtnTexture);

	playHover.initialize(Window::graphics, Window::input, &playHoverTexture);
	insHover.initialize(Window::graphics, Window::input, &insHoverTexture);
	optHover.initialize(Window::graphics, Window::input, &optHoverTexture);
	crHover.initialize(Window::graphics, Window::input, &crHoverTexture);

	scrbar.initialize(Window::graphics, Window::input, &scrbarTexture);
	scroller.initialize(Window::graphics, Window::input, &scrollerTexture);

	
	playbtn.setPos(GAME_WIDTH/2 - playbtn.getWidth() / 2, 275);
	insbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 300);
	optbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 375 );
	crbtn.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 450);


	scrbar.setPos(0, GAME_HEIGHT / 2);
	scroller.setPos(GAME_WIDTH / 2, GAME_HEIGHT / 2);
	

	//playbtnGM.initialize(0, 0, 350, 56, 0, 0, 0, 0);
}



void MainMenu::releaseAll()
{
}

void MainMenu::resetAll()
{}

void MainMenu::update()
{
	if (playbtn.isHovered()) 
	{
		playHover.setActive(true);
		playHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, GAME_HEIGHT / 4);
		playbtn.setActive(false);
	}
	else if (insbtn.isHovered())
	{
		insHover.setActive(true);
		insHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, GAME_HEIGHT / 3);
		insbtn.setActive(false);
	}
	else if (optbtn.isHovered())
	{
		optHover.setActive(true);
		optHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 375);
		optbtn.setActive(false);
	}
	else if(crbtn.isHovered())
	{
		crHover.setActive(true);
		crHover.setPos(GAME_WIDTH / 2 - playbtn.getWidth() / 2, 450);
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

	int mouseX = input->getMouseX();

	if (scrbar.isClicked())
	{
		scroller.setPos(mouseX, GAME_HEIGHT / 2);

	}

}

void MainMenu::render()
{
	
	
	playbtn.draw();
	insbtn.draw();
	optbtn.draw();
	crbtn.draw();
	playHover.draw();
	insHover.draw();
	optHover.draw();
	crHover.draw();
	/*scrbar.draw();
	scroller.draw();*/
}