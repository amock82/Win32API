#include "framework.h"

Boss::Boss(float px, float py) : Sprite("����", "����", true, px, py)
{
	this->speed = 50;

	this->fireTimer = 0;
	this->fireDelay = 0.8;

	this->fireIndex = 0;

	this->state = State::showUp;
}
	
Boss::~Boss(){}

void Boss::start()
{
	//���ߵ��� ���� ����
	setImage("Asset/������.bmp", 0, 0, 493, 206);

	//�����緯 �ڽ�
	addChildObj(new Propeller(63, 41), 2);
	addChildObj(new Propeller(111, 41), 2);
	addChildObj(new Propeller(159, 41), 2);

	addChildObj(new Propeller(302, 41), 2);
	addChildObj(new Propeller(350, 41), 2);
	addChildObj(new Propeller(398, 41), 2);

	//���� �ڽ� �߰�
	addChildObj(new Wing(256, 97, 0), 2);
	addChildObj(new Wing(302, 94, 1), 2);
	addChildObj(new Wing(350, 90, 2), 2);
	addChildObj(new Wing(405, 84, 3), 2);

	addChildObj(new Wing(206, 98, 4), 2);
	addChildObj(new Wing(158, 94, 5), 2);
	addChildObj(new Wing(110, 90, 6), 2);
	addChildObj(new Wing(62, 85, 7), 2);

	//������ �߰�
	addChildObj(new BossGun(94, 71, "������1"), 2);
	addChildObj(new BossGun(142, 71, "������2"), 2);
	addChildObj(new BossGun(190, 71, "������3"), 2);

	addChildObj(new BossGun(238, 63, "������4"), 2);

	addChildObj(new BossGun(286, 71, "������5"), 2);
	addChildObj(new BossGun(334, 71, "������6"), 2);
	addChildObj(new BossGun(382, 71, "������7"), 2);

	//���� �߰�
	addChildObj(new WingGun(265 + 5, 97 + 10, "����1"), 2);
	addChildObj(new WingGun(206 - 5, 97 + 10, "����2"), 2);

	//���̴� �߰�
	addChildObj(new Radar(241, 105), 2);
	addChildObj(new Radar(241, 117), 2);

	//���� �浹ü �߰�
	addBoxCollider2D(227, 4, 39, 193);
	addBoxCollider2D(7, 60, 478, 32);
	addBoxCollider2D(185, 171, 123, 33);
	addBoxCollider2D(62, 92, 369, 13);
}

void Boss::update()
{
	if (state == State::showUp)
	{
		float dist = speed * Timer::deltaTime;
		translate(0, dist);

		if (getPy() >= 50)
		{
			state = State::moveLeft;
		}
	}
	else if (state == State::moveLeft)
	{
		float dist = speed * Timer::deltaTime;
		translate(-dist, 0);

		if (getPx() <= -106.5)
		{
			state = State::moveRight;
		}
	}
	else if (state == State::moveRight)
	{
		float dist = speed * Timer::deltaTime;
		translate(dist, 0);

		if (getPx() >= 93.5)
		{
			state = State::moveLeft;
		}
	}

	if (state != State::showUp)
	{
		checkDestroy();
		fire();
	}
}

void Boss::explode()
{
	float x = getPx();
	float y = getPy();

	//���� ��ü�� Ǯ���� �����ͼ� Ȱ��ȭ ��Ŵ
	/*GameObject* exp[6] = { ObjectPool::pop("����", "���������"),
						   ObjectPool::pop("����", "���������"),
						   ObjectPool::pop("����", "���������"),
						   ObjectPool::pop("����", "���������"),
						   ObjectPool::pop("����", "���������"),
						   ObjectPool::pop("����", "���������")};*/

	//���� ��ġ ������
	float offX[6] = { 0, 73, 146, 146 , 219 , 293 };
	float offY[6] = { -30, -20, -50 , 80 , -20, -30 };
	
	for (int i = 0; i < 6; i++)
	{
		GameObject* exp = ObjectPool::pop("����", "���������");
		if (exp != nullptr)
		{
			//Ǯ���� ������ ��ü �Ӽ��� �缳��
			exp->setPosition(x + offX[i], y + offY[i]);
			exp->setActive(true);
		}
		else {
			cout << "��ü ���� ��ü�� Ǯ�� ����" << endl;
		}
	}

	//�ƾ��� ����//
	ObjectManager::destroy(this);

	// �ƾ��� ���� ī��Ʈ ����
	GameManager::delAyakoCount();
}

void Boss::checkDestroy()
{
	if (getChildCount() <= 0)
	{
		float x = getPx();
		float y = getPy();

		//����ȿ��
		explode();

		//DeadBoss��ü ����
		ObjectManager::instantiate(new DeadBoss(x + 47, y + 10), 1);

		//�������� Ŭ���� ���� ����
		GameManager::setStageClear(true);

		//Boss��ü ����
		ObjectManager::destroy(this);
	}
}

void Boss::fire()
{
	fireTimer += Timer::deltaTime;

	if (fireTimer >= fireDelay)
	{
		string name[9] = { "������1", "������2", "������3", "������4", "������5", "������6", "������7" ,"����1", "����2" };

		for (int i = 0; i < 9; i++)
		{
			if (firePat[fireIndex][i] == 1)
			{
				//BossGun* gun = (BossGun*)find("������" + to_string(i+1));
				GameObject* gun = find(name[i]);

				if (gun != nullptr)
				{
					if (i < 7)
					{
						((BossGun*)gun)->fire();
					}
					else
					{
						((WingGun*)gun)->fire();
					}
				}
			}
		}

		fireIndex++;
		fireTimer = 0;

		if (fireIndex >= MAX_SIZE)
			fireIndex = 0;
	}
}