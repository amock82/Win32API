#include "framework.h"

EnemyLaser::EnemyLaser(float px, float py)
	       :Sprite("����", "������", true, px, py)
{
	this->speed = 250;
	this->lifeTime = 10;
}

EnemyLaser::~EnemyLaser()
{}

void EnemyLaser::start()
{
	setImage("Asset/�����Ѿ�1.bmp");

	addBoxCollider2D(1, 0, 15, 15);
}

void EnemyLaser::update()
{
	// �̵�
	float dist = speed * Timer::deltaTime;
	translate(0, dist);

	// ������Ÿ��
	lifeTime -= Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);
	}
}

void EnemyLaser::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "�÷��̾�")
	{
		if (name == "����" || name == "����")
		{
			//������ ��ġ
			float x = getPx();
			float y = getPy();

			//���� ��ü�� Ǯ���� �����ͼ� Ȱ��ȭ ��Ŵ
			GameObject* exp = ObjectPool::pop("����ȿ��", "����������");

			if (exp != nullptr)
			{
				//Ǯ���� ������ ��ü �Ӽ��� �缳��
				exp->setPosition(x - 8, y);
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