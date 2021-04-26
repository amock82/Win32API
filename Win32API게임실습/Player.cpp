#include "framework.h"

Player::Player(float px, float py)
	  :Sprite("�÷��̾�", "����", true, px, py)
{
	this->state = State::showUp;
	this->speed = 300;

	this->fireTimer = 0;
	this->fireDelay = 0.15f;

	this->imageIdx   = 3;
	this->imageTimer = 0;
	this->imageDelay = 0.1f;

	this->shieldTimer = 2;

	this->laserCount = 1;
}

Player::~Player()
{
	//�÷��̾� �̹��� �迭..�����޸� ����//
	for (int i = 0; i < 7; i++)
	{
		delete[] images[i].data;
	}
	
	resetImage();
}

void Player::start()
{
	//�÷��̾� �̹����� �ε��ϱ�//
	readBMP("Asset/�����̵�2.bmp", 64 * 0, 82, 62, 80, &images[0]);
	readBMP("Asset/�����̵�2.bmp", 64 * 1, 82, 62, 80, &images[1]);
	readBMP("Asset/�����̵�2.bmp", 64 * 2, 82, 62, 80, &images[2]);
	readBMP("Asset/�����̵�2.bmp", 64 * 3, 82, 62, 80, &images[3]);
	readBMP("Asset/�����̵�2.bmp", 64 * 4, 82, 62, 80, &images[4]);
	readBMP("Asset/�����̵�2.bmp", 64 * 5, 82, 62, 80, &images[5]);
	readBMP("Asset/�����̵�2.bmp", 64 * 6, 82, 62, 80, &images[6]);

	setImage(images[imageIdx]);

	//�÷��̾� �浹ü �߰��ϱ�//	
	addBoxCollider2D(25, 7, 12, 66);	
	addBoxCollider2D(9, 41, 44, 14);
	
	//���� �ڽİ�ü �߰��ϱ�//
	addChildObj(new Shield(-14, -5), 1);
}

void Player::update()
{
	if (GameManager::isPause == false)
	{
		if (state == State::showUp)
		{
			showUp();
		}
		else if (state == State::control)
		{
			move();
			fire();
			shield();
			stageClear();
		}
	}
}

void Player::showUp()
{
	float dist = speed / 1.5f * Timer::deltaTime;
	translate(0, -dist);

	if (getPy() <= HEIGHT - 200)
	{
		state = State::control;
	}
}

void Player::move()
{
	//�÷��̾� �̵�//
	float dist = speed * Timer::deltaTime;

	if (Input::getKey("left") == true)
	{
		translate(-dist, 0);

		if (getPx() < 0)
		{
			setPx(0);
		}

		//�̹��� �����ϱ�//
		if (imageIdx > 0)
		{
			imageTimer = imageTimer + Timer::deltaTime;

			if (imageTimer >= imageDelay)
			{
				imageIdx--;
				setImage(images[imageIdx]);

				imageTimer = 0;
			}
		}
	}

	if (Input::getKey("right") == true)
	{
		translate(dist, 0);

		if (getPx() > WIDTH - 62)
		{
			setPx(WIDTH - 62);
		}

		//�̹��� �����ϱ�
		if (imageIdx < 6)
		{
			imageTimer = imageTimer + Timer::deltaTime;

			if (imageTimer >= imageDelay)
			{
				imageIdx++;
				setImage(images[imageIdx]);

				imageTimer = 0;
			}
		}
	}

	if (Input::getKey("up") == true)
	{
		translate(0, -dist);

		if (getPy() < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey("down") == true)
	{
		translate(0, dist);

		if (getPy() > HEIGHT - 86)
		{
			setPy(HEIGHT - 86);
		}
	}

	//�÷��̾ �¿��̵��� �ƴѰ��
	if (Input::getKey("left") == false && Input::getKey("right") == false)
	{
		if (imageIdx != 3)
		{
			imageTimer = imageTimer + Timer::deltaTime;

			if (imageTimer >= imageDelay)
			{
				if (imageIdx < 3)
				{
					imageIdx++;
				}
				else {
					imageIdx--;
				}

				setImage(images[imageIdx]);
				imageTimer = 0;
			}
		}
	}
}

void Player::fire()
{
	//������ �߻�//
	if (GetAsyncKeyState(VK_SPACE) != 0)
	{
		//�߻�ð������ϱ�
		fireTimer = fireTimer + Timer::deltaTime;

		if (fireTimer >= fireDelay)
		{
			//�߻���ġ
			//float x = getPx();
			//float y = getPy();

			float x, y;
			getPosition(x, y);

			//������ �߻�//
			if (laserCount == 1)
			{
				ObjectManager::instantiate(new PlayerLaser(x + 29, y - 25));
			}
			else if(laserCount == 2)
			{
				ObjectManager::instantiate(new PlayerLaser(x + 19, y - 25));
				ObjectManager::instantiate(new PlayerLaser(x + 39, y - 25));
			}
			else if (laserCount == 3)
			{
				ObjectManager::instantiate(new PlayerLaser(x + 9, y - 25));
				ObjectManager::instantiate(new PlayerLaser(x + 29, y - 45));
				ObjectManager::instantiate(new PlayerLaser(x + 49, y - 25));
			}

			//Ÿ�̸� �����ϱ�
			fireTimer = 0;
		}
	}

	//��ź �߻��ϱ�//
	if (Input::getKeyDown("z")==true)
	{
		if (GameManager::getBombCount() > 0)
		{
			float x, y;
			getPosition(x, y);

			//��ź �߻�//
			ObjectManager::instantiate(new PlayerBomb(x + 15, y - 2));

			GameManager::subBombCount();
		}
		else
			cout << "�����ִ� ��ź�� ����" << endl;
	}
}

void Player::shield()
{
	//�ǵ� Ÿ�̸� 
	shieldTimer -= Timer::deltaTime;

	if (shieldTimer <= 0)
	{
		//�����
		//getChild(0)->setActive(false);
		//find("����")->setActive(false);

		//���� �����ϱ�
		GameObject* obj = getChild(0);

		if (obj != nullptr)
		{
			delChildObj(obj);
		}
	}
}

void Player::stageClear()
{
	if (GameManager::getStageClear() == true)
	{
		float x = getPx();
		float y = getPy();

		ObjectManager::instantiate(new ReturnPlayer(x, y), 3);

		ObjectManager::destroy(this);
	}
}

void Player::explode()
{
	if (getAlive() == true)
	{
		// �÷��̾� ����ȿ��
		GameObject* exp = ObjectPool::pop("����", "���������");

		if (exp != nullptr)
		{
			float x = getPx();
			float y = getPy();

			exp->setPosition(x - 60, y - 50);
			exp->setActive(true);
		}
		else {
			cout << "��ü ���� ��ü�� Ǯ�� ����" << endl;
		}

		// �÷��̾� ����
		ObjectManager::destroy(this);

		//�÷��̾� ������
		GameManager::restartPlayer();
	}
}

void Player::onTriggerStay(GameObject* other)
{
	string tag  = other->getTag();
	string name = other->getName();

	if (tag == "����")
	{
		if (getAlive() == true)
		{
			if (name == "�ƾ���" || name == "���ڽ�" || name == "����")
			{
				explode();
			}
			else if (name == "������")
			{
				GameManager::damagePlayer(20);
			}
			else if (name == "����������")
			{
				GameManager::damagePlayer(2);
			}
		}
	}

	if (tag == "������")
	{
		if (name == "������")
		{
			if (other->getAlive() == true)
			{
				laserCount++;

				if (laserCount > 3)
				{
					laserCount = 3;
				}

				ObjectManager::destroy(other);
			}
		}
		else if (name == "��ź")
		{
			if (other->getAlive() == true)
			{
				GameManager::addBombCount();

				ObjectManager::destroy(other);
			}
		}
	}
}