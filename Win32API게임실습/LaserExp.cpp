#include "framework.h"

LaserExp::LaserExp(float px, float py) 
	:Animation("����ȿ��", "����������", true, px, py)
{}

LaserExp::~LaserExp()
{}

void LaserExp::start()
{
	//�ִϸ��̼� �߰��ϱ�//
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			addImage("Asset/����������.bmp", 36 * i, 36 * j, 36, 36, 0);
		}
	}	

	//�ִϸ��̼� �÷���
	play(0);

	//�ִϸ��̼� �ӵ�
	setSpeed(5);
}

//�ִ����� �̺� �������̵�//
void LaserExp::animEndEvent()
{
	this->setActive(false);
}