#include "framework.h"

Stealth::Stealth(float px, float py) : Sprite("����", "���ڽ�", true, px, py)
{
	this->hp = 100;
	this->speed = 70;
	this->attackPos = 150;

	this->state = State::showUp;
}

Stealth::~Stealth(){}

void Stealth::start()
{
	setImage("Asset/����2.bmp");

	addBoxCollider2D(46, 0, 36, 188);
	addBoxCollider2D(4, 29, 42, 65);
	addBoxCollider2D(82, 29, 42, 65);
	addBoxCollider2D(24, 94, 22, 54);
	addBoxCollider2D(82, 94, 22, 54);
}

void Stealth::update()
{
	//������Ʈ�ӽ�(FSM - Finite State Machine)
	if (state == State::showUp)
	{
		float dist = speed * Timer::deltaTime;

		translate(0, dist);

		if (getPy() >= attackPos)
		{
			state = State::addShooter;
		}
	}
	else if (state == State::addShooter)
	{
		//���� �ڽİ�ü �߰�
		addChildObj(new Shooter(58, 94), 1);
		state = State::attack;
	}
	else if (state == State::attack)
	{
		//�ʿ�� ������ �ൿ����
	}
}

void Stealth::explode()
{
	float x = getPx();
	float y = getPy();

	//���� ��ü�� Ǯ���� �����ͼ� Ȱ��ȭ ��Ŵ
	GameObject* exp = ObjectPool::pop("����", "���������");

	if (exp != nullptr)
	{
		//Ǯ���� ������ ��ü �Ӽ��� �缳��
		exp->setPosition(x - 40, y);
		exp->setActive(true);
	}
	else {
		cout << "��ü ���� ��ü�� Ǯ�� ����" << endl;
	}

	//���ڽ� ����//
	ObjectManager::destroy(this);

	//���ڽ� ���� ī��Ʈ ����
	GameManager::delStealthCount();

	//��ź ������ �����ϱ�
	ObjectManager::instantiate(new BombItem(x + 53, y + 74), 1);
}

void Stealth::onTriggerStay(GameObject* other)
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
				hp = hp - 5;

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