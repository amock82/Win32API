#include "framework.h"

BossChildExp::BossChildExp(float px, float py) : Animation("����", "�ڽ�����", true, px, py)
{

}

BossChildExp::~BossChildExp(){}

void BossChildExp::start()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			addImage("Asset/��Ÿ����.bmp", 30 * j, 30 * i, 30, 30, 0);
		}
	}

	play(0);

	setSpeed(5);
}


void BossChildExp::animEndEvent()
{
	ObjectManager::destroy(this);
}