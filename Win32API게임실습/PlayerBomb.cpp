#include "framework.h"

PlayerBomb::PlayerBomb(float px, float py)
	      :Animation("�÷��̾�", "��ź", true, px, py)
{
	this->speed = 80;
}

PlayerBomb::~PlayerBomb()
{}

void PlayerBomb::start()
{
	for (int i = 0; i < 8; i++)
	{
		addImage("Asset/������ź2.bmp", i * 34, 0, 32, 32, 0);
	}

	//�ִϸ��̼� �ӵ�//
	setSpeed(0.5);
}

void PlayerBomb::update()
{
	float dist = speed * Timer::deltaTime;
	translate(0, -dist);
}

void PlayerBomb::animEndEvent()
{
	//��ź ���� ȿ��
	float x = getPx();
	float y = getPy();

	ObjectManager::instantiate(new BombExp(x - 48, y - 48));

	//��ź ��ü ����
	ObjectManager::destroy(this);
}