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

}
SpriteData Button::getSpriteData() 
{
	SpriteData sd;
    texture->getSpriteData(sd);
	return sd;
}
void Button::draw()
{

	graphics->drawSprite(getSpriteData(), x, y, 1);
	
}

bool Button::isHovered()
{
	
	SpriteData sd = getSpriteData();

	/*if (input->mouseRawIn) return false;*/

	int mouseX = input->getMouseRawX();
	int mouseY = input->getMouseRawY();

	int left = x - sd.width;
	int top = y - sd.height;
	int relX = mouseX - left;
	int relY = mouseY - top;
	return (0 < relX && relX < sd.width &&
		0 < relY && relY < sd.height);
}

