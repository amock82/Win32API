#include "framework.h"

WingGun::WingGun(float px, float py, string name) : Sprite("����", name, true, px, py)
{
	this->hp = 100;
}

WingGun::~WingGun(){}

void WingGun::start()
{
	setImage("Asset/������.bmp", 357, 262, 21, 22);

	addBoxCollider2D(0, 0, 21, 22);
}

void WingGun::fire()
{
	float x = getPx();
	float y = getPy();

	ObjectManager::instantiate(new EnemyLaser(x + 2, y + 5), 1);
}

void WingGun::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "�÷��̾�")
	{
		if (name == "������")
		{
			hp -= 10;

			if (hp <= 0)
			{
				float x = getPx();
				float y = getPy();

				ObjectManager::instantiate(new BossChildExp(x - 4.5, y - 6), 3);

				parent->delChildObj(this);
			}
		}
		else if (name == "��ź����")
		{
			float x = getPx();
			float y = getPy();

			ObjectManager::instantiate(new BossChildExp(x - 4.5, y - 6), 3);

			parent->delChildObj(this);
		}
	}
}