#include "mainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{}

void MainMenu::initialize()
{	
	playbtnTexture.initialize(Window::graphics, PLAY_BTN_TEXTURE);
	playbtn.initialize(Window::graphics, Window::input, &playbtnTexture, 0, 0);
	playbtnGM.initialize(0, 0, 351, 138, 0, 0, 0, 0);
}



void MainMenu::releaseAll()
{}

void MainMenu::resetAll()
{}

void MainMenu::update()
{}

void MainMenu::render()
{
	playbtn.draw();
}