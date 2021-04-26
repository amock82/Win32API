#include "framework.h"

Wing::Wing(float px, float py, int imgId) : Sprite("����", "����", true, px, py)
{
	this->imgId = imgId;
	this->hp = 100;
}

Wing::~Wing(){}

void Wing::start()
{
	setImage("Asset/������.bmp", imgRect[imgId][0], imgRect[imgId][1], imgRect[imgId][2], imgRect[imgId][3]);
	addBoxCollider2D(colRect[imgId][0], colRect[imgId][1], colRect[imgId][2], colRect[imgId][3]);
}

void Wing::onTriggerStay(GameObject* other)
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

				ObjectManager::instantiate(new BossChildExp(x - 15 + imgRect[imgId][2] / 2, y - 15 + imgRect[imgId][3] / 2), 3);

				parent->delChildObj(this);
			}
		}
		else if (name == "��ź����")
		{
			float x = getPx();
			float y = getPy();

			ObjectManager::instantiate(new BossChildExp(x - 15 + imgRect[imgId][2] / 2, y - 15 + imgRect[imgId][3] / 2), 3);

			parent->delChildObj(this);
		}
	}
}