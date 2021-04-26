#include "framework.h"

BombItem::BombItem(float px, float py) : Sprite("������", "��ź", true, px, py)
{
	this->speed = 100;
	this->lifeTime = 10;
}

BombItem::~BombItem(){}

void BombItem::start()
{
	setImage("Asset/��ź������.bmp");
	addBoxCollider2D(0, 0, 22, 42);
}

void BombItem::update()
{
	float dist = speed * Timer::deltaTime;
	translate(0, dist);

	lifeTime -= Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);
	}
}