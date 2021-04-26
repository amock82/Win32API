#include "framework.h"

Ayako::Ayako(float px, float py, bool dropItem)
	  :Animation("����", "�ƾ���", true, px, py)
{
	this->speed = 70;
	this->fallFactor = 1.5f;
	this->hp    = 100;

	this->fireTimer = 0;
	this->fireDelay = 1.0f;

	this->lifeTime = 10;

	this->state = State::moveDown;

	this->dropItem = dropItem;
}

Ayako::~Ayako()
{}

void Ayako::start()
{
	//�ִϸ��̼� �̹����ε�(���ؾ��� �ִϸ��̼� Ŭ��) : 0 ��//
	addImage("Asset/����1.bmp", 1,   281, 190, 137,   0);
	addImage("Asset/����1.bmp", 201, 281, 190, 137,   0);

	//�ִϸ޴ϼ� �̹����ε�(�߰����� �ִϸ��̼� Ŭ��) : 1 ��//
	addImage("Asset/����1.bmp", 1 + 200 * 0, 141, 190, 137,  1);
	addImage("Asset/����1.bmp", 1 + 200 * 1, 141, 190, 137,  1);
	addImage("Asset/����1.bmp", 1 + 200 * 2, 141, 190, 137,  1);
	addImage("Asset/����1.bmp", 1 + 200 * 3, 141, 190, 137,  1);

	//�ִϸ޴ϼ� �̹����ε�(�������� �ִϸ��̼� Ŭ��) : 2 ��//
	addImage("Asset/����1.bmp", 1 + 200 * 0, 1, 190, 137, 2);
	addImage("Asset/����1.bmp", 1 + 200 * 1, 1, 190, 137, 2);
	addImage("Asset/����1.bmp", 1 + 200 * 2, 1, 190, 137, 2);
	addImage("Asset/����1.bmp", 1 + 200 * 3, 1, 190, 137, 2);

	//�浹ü �߰��ϱ�
	addBoxCollider2D(64, 10, 62,  14);
	addBoxCollider2D(87, 24, 16,  113);
	addBoxCollider2D(1,  88, 189, 17);

	//�ִϸ��̼� �÷��� ����//
	play(0);
	setSpeed(2);

	// �¿� �̵� ������ȯ ���� ���� ���� ����
	moveDownRange = Random::range(-100.0f, 100.0f);
}

void Ayako::update()
{
	// �ൿ ������Ʈ �ӽ�
	switch (state)
	{
	case State::moveDown:
		moveDown();
		break;
	case State::moveLeft:
		moveLeft();
		break;
	case State::moveRight:
		moveRight();
		break;
	case State::fall:			
		fall();
		break;
	}

	// �߻�
	fireTimer = fireTimer + Timer::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float x = getPx();
		float y = getPy();

		ObjectManager::instantiate(new EnemyLaser(x + 86.5, y + 137));

		fireTimer = 0;
	}
}

void Ayako::explode()
{
	float x = getPx();
	float y = getPy();

	//���� ��ü�� Ǯ���� �����ͼ� Ȱ��ȭ ��Ŵ
	GameObject* exp = ObjectPool::pop("����", "���������");

	if (exp != nullptr)
	{
		//Ǯ���� ������ ��ü �Ӽ��� �缳��
		exp->setPosition(x - 5, y);
		exp->setActive(true);
	}
	else {
		cout << "��ü ���� ��ü�� Ǯ�� ����" << endl;
	}

	//�ƾ��� ����//
	ObjectManager::destroy(this);

	// �ƾ��� ���� ī��Ʈ ����
	GameManager::delAyakoCount();

	//������ ������ �����ϱ�
	//if(Random::range(0.0f, 1.0f) <= 0.5f)
	if(dropItem == true)
		ObjectManager::instantiate(new LaserItem(x + 95 - 11, y + 63), 1);
}

void Ayako::onTriggerStay(GameObject* other)
{
	if (getAlive() == true)
	{

		string tag = other->getTag();
		string name = other->getName();

		if (tag == "�÷��̾�")
		{
			if (name == "����")
			{
				explode();
			}

			else if (name == "������")
			{
				//ü�¿�...���������ϱ�//
				hp = hp - 10;

				//�ƾ��� ���� �ִϸ��̼� �����ϱ�
				if (70 <= hp && hp <= 100)
					play(0);
				else if (40 <= hp && hp < 70)
					play(1);
				else
				{
					play(2);
					state = State::fall;
				}

				if (hp <= 0)
					explode();
			}

			else if (name == "��ź����")
			{
				// ��ź�� ���� ������� ���Ⱑ ���ߵ�
				explode();
			}
		}
	}
}

void Ayako::moveDown()
{
	float dist = speed * Timer::deltaTime;
	translate(0, dist);

	if (getPy() >= 200 + moveDownRange)
	{
		float r = Random::range(0, 2);

		if (r == 0)
			state = State::moveLeft;
		else
			state = State::moveRight;
	}
}

void Ayako::moveLeft()
{
	float dist = speed * Timer::deltaTime;
	translate(-dist, 0);

	if (getPx() <= 20)
	{
		state = State::moveRight;
	}
}

void Ayako::moveRight()
{
	float dist = speed * Timer::deltaTime;
	translate(dist, 0);

	if (getPx() >= WIDTH - 190 - 20)
	{
		state = State::moveLeft;
	}
}

void Ayako::fall()
{
	float dist = fallFactor * speed * Timer::deltaTime;
	translate(0, dist);

	lifeTime -= Timer::deltaTime;

	if (lifeTime <= 0)
	{
		ObjectManager::destroy(this);

		// �ƾ��� ���� ī��Ʈ ����
		GameManager::delAyakoCount();
	}
}