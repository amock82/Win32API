#include "framework.h"

Shield::Shield(float px, float py) : Animation("�÷��̾�", "����", true, px, py)
{

}

Shield::~Shield(){}

void Shield::start()
{
	addImage("Asset/��ȣ����1.bmp", 0);
	addImage("Asset/��ȣ����2.bmp", 0);
	addImage("Asset/��ȣ����3.bmp", 0);

	play(0);

	setSpeed(1.0f);

	// �浹ü �߰��ϱ�
	addBoxCollider2D(5, 5, 80, 80);
}

void Shield::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "����")
	{
		if (name == "�ƾ���" || name == "���ڽ�" ||name == "����")
		{
			parent->delChildObj(this);
		}
	}
}