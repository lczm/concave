#include "mainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{}

void MainMenu::initialize()
{	
	playbtnTexture.initialize(Window::graphics, PLAY_BTN_TEXTURE);
	playHoverTexture.initialize(Window::graphics, PLAY_HOVER_TEXTURE);

	insbtnTexture.initialize(Window::graphics, INS_BTN_TEXTURE);
	optbtnTexture.initialize(Window::graphics, OPT_BTN_TEXTURE);
	crbtnTexture.initialize(Window::graphics, CR_BTN_TEXTURE);


	playbtn.initialize(Window::graphics, Window::input, &playbtnTexture, 0, 0);
	playHoverbtn.initialize(Window::graphics, Window::input, &playHoverTexture, 0, 0);

	insbtn.initialize(Window::graphics, Window::input, &insbtnTexture, 0, 56);
	optbtn.initialize(Window::graphics, Window::input, &optbtnTexture, 0, 56+56);
	crbtn.initialize(Window::graphics, Window::input, &crbtnTexture, 0, 56+56+56);
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
		
	}
}

void MainMenu::render()
{
	playbtn.draw();
	insbtn.draw();
	optbtn.draw();
	crbtn.draw();
}