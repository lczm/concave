#include "mainMenu.h"

MainMenu::MainMenu()
{}

MainMenu::~MainMenu()
{}

void MainMenu::initialize(Graphics* graphics, Input* input)
{	
	playbtnTexture.initialize(MainMenu::graphics, PLAY_BTN_TEXTURE);
	playbtn.initialize(graphics, input, &playbtnTexture);
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