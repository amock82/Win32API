#include "framework.h"

EnemyManager::EnemyManager(float px, float py)
			:GameObject("", "", true, px, py)
{
	this->spawnTimer = 4.0f;
	this->spawnDelay = 5.0f;

	this->spawnIdx = 0;

	this->state = State::ayakoSpawn;
	this->stealthCount = 3;
}

EnemyManager::~EnemyManager(){}

void EnemyManager::update()
{
	if (state == State::ayakoSpawn)
	{
		spawnTimer += Timer::deltaTime;

		if (spawnTimer >= spawnDelay)
		{
			float x = getPx();
			float y = getPy();

			// ���� ȭ����� �ƾ��� ���� 
			int ayakoCount = GameManager::getAyakoCount();

			if (ayakoCount < 5)
			{
				//���ʽ���
				if (spawnPat[spawnIdx][0] == 1)
				{
					ObjectManager::instantiate(new Ayako(x - 95 - 100, y - 137, false), 1);
					// �ƾ��� ���� ī���� ������Ű��
					GameManager::addAyakoCount();
				}
				//���ʽ��� + �����ۻ���
				if (spawnPat[spawnIdx][0] == 2)
				{
					ObjectManager::instantiate(new Ayako(x - 95 - 100, y - 137, true), 1);
					// �ƾ��� ���� ī���� ������Ű��
					GameManager::addAyakoCount();
				}
				//�����ʽ���
				if (spawnPat[spawnIdx][1] == 1)
				{
					ObjectManager::instantiate(new Ayako(x - 95 + 100, y - 137, false), 1);
					// �ƾ��� ���� ī���� ������Ű��
					GameManager::addAyakoCount();
				}
				//�����ʽ��� + �����ۻ���
				if (spawnPat[spawnIdx][1] == 2)
				{
					ObjectManager::instantiate(new Ayako(x - 95 + 100, y - 137, true), 1);
					// �ƾ��� ���� ī���� ������Ű��
					GameManager::addAyakoCount();
				}

				spawnTimer = 0;
				spawnDelay = Random::range(3.0f, 5.0f);

				spawnIdx++;

				if (spawnIdx >= MAX_SIZE)
				{
					state = State::stealthSpawn;	//���ڽ� ���� ���� ����(transition)
				}
			}
		}
	}
	else if (state == State::stealthSpawn)
	{
		if (GameManager::getStealthCount() <= 0)	//���ӿ� ���ڽ� ���Ⱑ ���� ��
		{
			if (stealthCount > 0)
			{
				float x = getPx();
				float y = getPy();

				ObjectManager::instantiate(new Stealth(x - 60, y - 200), 1);
				GameManager::addStealthCount();	//������� �����ؼ� ���ӿ� �߰��� ���ڽ� ����

				stealthCount--;	//���� �������� ����
			}
			else
			{
				state = State::bossSpawn;
			}
		}
	}
	else if (state == State::bossSpawn)
	{
		float x = getPx();
		float y = getPy();

		ObjectManager::instantiate(new Boss(x - WIDTH/2 -6, y -250), 0);

		//���׹� �Ŵ��� ����
		ObjectManager::destroy(this);
	}
}

void EnemyManager::onDrawGizmos()
{
	float x = getPx();
	float y = getPy();
	 
	drawLine(x - 20, y, x + 20, y, 100, 250, 250);
	drawLine(x, y - 20, x, y + 20, 100, 250, 250);
}