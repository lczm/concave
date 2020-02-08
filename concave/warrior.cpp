#include "warrior.h"

Warrior::Warrior()
{
	direction = DIRECTION8::NORTH;
	stateManager = new WarriorStateManager();
}

Warrior::~Warrior()
{
}

void Warrior::initialize(Graphics* graphics, Input* input, Component::Position* positionComponent)
{
	Warrior::graphics = graphics;
	Warrior::input = input;
	Warrior::positionComponent = positionComponent;
	stateManager->setPositionComponent(positionComponent);
	unitTexture.initialize(Warrior::graphics, IMAGE_UNIT_WARRIOR);
	// TODO : unitGetHitGridMask
	unitAttackGridMask.initialize(0, 7, 128, 128, 0, 1, 58, 114);
	unitDieGridMask.initialize(2049, 7, 128, 95, 0, 1, 59, 71);
	unitIdleGridMask.initialize(0, 1046, 96, 94, 0, 1, 43, 81);
	unitWalkGridMask.initialize(2882, 1045, 96, 96, 0, 1, 44, 80);
	vector<GridMask> unitGridMasks = {
		unitAttackGridMask,
		unitDieGridMask,
		unitIdleGridMask,
		unitWalkGridMask
	};
	vector<int> unitEndFrames = { 16, 21, 10, 8 };
	unitImage.initialize(&unitTexture, unitGridMasks, unitEndFrames);
}

void Warrior::update(float frameTime)
{
	stateManager->update(input, frameTime);
}

SpriteData Warrior::getSpriteData()
{
	SpriteData sd;
	unitImage.getSpriteData(sd, stateManager->getState(), direction, stateManager->getFrameNo());
	return sd;
}

void Warrior::onLostDevice()
{
	unitTexture.onLostDevice();
}

void Warrior::onResetDevice()
{
	unitTexture.onResetDevice(graphics);
}
