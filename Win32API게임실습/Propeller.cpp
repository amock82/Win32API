#include "framework.h"

Propeller::Propeller(float px, float py) : Animation("����", "�����緯", true, px, py)
{
	this->hp = 100;
}

Propeller::~Propeller(){}

void Propeller::start()
{
	//���ؾ��� �ִϸ��̼�
	addImage("Asset/������.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/������.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//�����ִ� �ִϸ��̼�
	addImage("Asset/������.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/������.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	//�ִϸ��̼� �÷���
	play(0);

	//�ִϸ��̼� �ӵ�
	setSpeed(1.5);

	addBoxCollider2D(5, 0, 21, 12);
}

void Propeller::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "�÷��̾�")
	{
		if (name == "������")
		{
			hp -= 10;

			if (hp < 50)
			{
				play(1);
			}


			if (hp <= 0)
			{
				float x = getPx();
				float y = getPy();

				ObjectManager::instantiate(new BossChildExp(x + 1, y - 9), 3);

				parent->delChildObj(this);
			}
		}
		else if (name == "��ź����")
		{
			float x = getPx();
			float y = getPy();

			ObjectManager::instantiate(new BossChildExp(x + 1, y - 9), 3);

			parent->delChildObj(this);
		}
	}
}