#include "button.h"
Button::Button()
{
	
}

Button::~Button()
{}

void Button::initialize(Graphics* graphics, Input* input, Texture* texture, float x, float y)
{
	Button::graphics = graphics;
	Button::input = input;
	Button::texture = texture;
	Button::x = x;
	Button::y = y;
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
		

		int buttonWidth = x + getSpriteData().width;
		int buttonHeight = y + getSpriteData().height;


		return (mouseX > x && mouseX < buttonWidth &&
			mouseY > y && mouseY < buttonHeight);
	}
}

bool Button::isClicked()
{

	/*if (input->mouseRawIn) return false;*/

	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	if (!input->getMouseLButton())
	{
		return false;
	}
	else
	{
		SpriteData sd = getSpriteData();

		int buttonWidth = x + sd.width;
		int buttonHeight = y + sd.height;


		return (mouseX > x && mouseX < buttonWidth &&
			mouseY > y && mouseY < buttonHeight);
	}

}

int Button::getWidth()
{
	return getSpriteData().width;
}




