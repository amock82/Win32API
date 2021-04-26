#include "framework.h"

LaserItem::LaserItem(float px, float py) : Sprite("������", "������", true, px, py)
{
	this->lifeTime = 10;
}

LaserItem::~LaserItem(){}

void LaserItem::start()
{
	setImage("Asset/�Ѿ˾�����.bmp");
	addBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::update()
{
	lifeTime -= Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);
	}
}

void LaserItem::onTriggerStay(GameObject* other)
{
	
}