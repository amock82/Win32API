#include "framework.h"

PlayerLaser::PlayerLaser(float px, float py)
		   :Sprite("�÷��̾�", "������", true, px, py)
{
	this->speed    = 400;
	this->lifeTime = 10.0f;
}

PlayerLaser::~PlayerLaser()
{}

void PlayerLaser::start()
{
	setImage("Asset/������.bmp");
	addBoxCollider2D(0, 0, 6, 33);
}

void PlayerLaser::update()
{
	//�̵�//
	float dist = speed * Timer::deltaTime;
	translate(0, -dist);

	//������Ÿ��//
	lifeTime = lifeTime - Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);
	}
}

void PlayerLaser::onTriggerStay(GameObject* other)
{
	string tag  = other->getTag();
	string name = other->getName();

	if (tag == "����")
	{	
		if (name == "�ƾ���" || name == "���ڽ�" || name == "���̴�" || name.compare(0, 4, "����") == 0 || name == "����" || name.compare(0, 6,"������") == 0 || name == "�����緯")
		{
			//������ ��ġ
			float x = getPx();
			float y = getPy();

			//���� ��ü�� Ǯ���� �����ͼ� Ȱ��ȭ ��Ŵ
			GameObject* exp = ObjectPool::pop("����ȿ��", "����������");

			if (exp != nullptr)
			{
				//Ǯ���� ������ ��ü �Ӽ��� �缳��
				exp->setPosition(x - 13, y - 10);
				exp->setActive(true);
			}
			else {
				cout << "������ ���� ��ü�� Ǯ�� ����" << endl;
			}

			//������ ��ü ����
			ObjectManager::destroy(this);
		}
	}
}