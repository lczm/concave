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
	Button::x = x;
	Button::y = y;

}
void Button::draw()
{

	graphics->drawSprite();
	
}

