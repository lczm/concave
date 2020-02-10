#include "button.h"
Button::Button()
{
	x = 0;
	y = 0;
}

Button::~Button()
{}

void Button::initialize(Graphics* graphics, Input* input, Texture* texture)
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

	graphics->drawSprite(getSpriteData(), x, y, NULL);
	
}

