#include "button.h"
Button::Button()
{
	
}

Button::~Button()
{}

void Button::initialize(Graphics* graphics, Input* input, Texture* texture)
{
	Button::graphics = graphics;
	Button::input = input;
	Button::texture = texture;
	active = true;

}
SpriteData Button::getSpriteData() 
{
	SpriteData sd;
    texture->getSpriteData(sd);
	return sd;
}

void Button::setActive(bool a)
{
	active = a;
}

void Button::draw()
{

	if(active)
		graphics->drawSprite(getSpriteData(), x, y, 1);
	
}

bool Button::isHovered()
{
	
	
	/*if (input->mouseRawIn) return false;*/
	
	
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();


	if (!mouseX && !mouseY)
	{
		return false;
	}
	else
	{
		

		float buttonWidth = x + getSpriteData().width;
		float buttonHeight = y + getSpriteData().height;


		return (mouseX > x && mouseX < buttonWidth &&
			mouseY > y && mouseY < buttonHeight);
	}
}

bool Button::isClicked()
{

	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	if (!input->getMouseLButton())
	{
		return false;
	}
	else
	{

		float buttonWidth = x + getSpriteData().width;
		float buttonHeight = y + getSpriteData().height;


		return (mouseX > x && mouseX < buttonWidth &&
			mouseY > y && mouseY < buttonHeight);
	}

}

int Button::getWidth()
{
	return  getSpriteData().width;
}

int Button::getHeight()
{
	return getSpriteData().height;
}

void Button::setPos(float posX, float posY)
{
	x = posX;
	y = posY;
}




