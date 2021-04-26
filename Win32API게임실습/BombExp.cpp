#include "framework.h"

BombExp::BombExp(float px, float py)
	   :Animation("�÷��̾�", "��ź����", true, px, py)
{}

BombExp::~BombExp()
{}

void BombExp::start()
{
	//�ִϸ��̼� �̹��� �߰�//
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			addImage("Asset/������ź����.bmp", i * 130, j * 130, 128, 128, 0);
		}
	}

	//�ִϸ޴ϼ� ���
	play(0);	

	//�ִϸ��̼� �ӵ�
	setSpeed(2);

	// �浹ü �߰��ϱ�
	addBoxCollider2D(10, 10, 108, 108);
}

void BombExp::animEndEvent()
{
	ObjectManager::destroy(this);
}