#include "framework.h"

GuidLaser::GuidLaser(float px, float py, float angle) : Sprite("����", "����������", true, px, py)
{
	this->speed = 200;
	this->radian = angle * M_PI / 180;

	this->lifeTime = 3.5;
}

GuidLaser::~GuidLaser(){}

void GuidLaser::start()
{
	setImage("Asset/�����Ѿ�2.bmp");

	addBoxCollider2D(0, 0, 17, 17);
}

void GuidLaser::update()
{
	lifeTime -= Timer::deltaTime;

	//���� ��ġ���� Ÿ�� ���� ���ϱ�
	GameObject* target = ObjectManager::find("����");
	float tx, ty;

	if (target != nullptr)
	{
		tx = target->getPx() + 31 - this->getPx();
		ty = target->getPy() + 40 - this->getPy();
	}
	else
	{
		tx = WIDTH / 2 - this->getPx();
		ty = HEIGHT * 1.2 - this->getPy();
	}

	//������ ����(����)���� ���ϱ�
	float nx = cos(radian);
	float ny = sin(radian);

	//(tx, ty)�� (nx, ny) ���Ͱ��� ���հ� ���ϱ�
	float dot = tx * nx + ty * ny;
	float lnxy = 1; //sqrt(nx * nx + ny * ny);	// �׻�1
	float ltxy = sqrt(tx * tx + ty * ty);

	float theta = acos(dot / (lnxy * ltxy));	//�� ������ ���հ�

	//�������� Ÿ�ٹ��� ���ϱ�
	float cross = nx * ty - ny * tx;

	if (cross < 0)
	{
		theta *= -1;
	}

	//���ο� ���� ���� ���ϱ�
	radian = radian + theta * 0.02;

	//�������� radian �������� �̵���Ű��
	float dx = cos(radian) * speed * Timer::deltaTime;
	float dy = sin(radian) * speed * Timer::deltaTime;

	translate(dx, dy);

	//printf("%f  %f\n", this->getPx(), this->getPy());

	if (lifeTime <= 0)
	{
		explode();
	}
}

void GuidLaser::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();
	string name = other->getName();

	if (tag == "�÷��̾�")
	{
		if (name == "����" || name == "����")
		{
			explode();
		}
	}
}

void GuidLaser::explode()
{
	//Ǯ���� ����ȿ�� �����ͼ� ����ȿ��
	float x = getPx();
	float y = getPy();

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