#pragma once

#include "Sprite.h"

class Player : public Sprite
{
private:

	enum class State {showUp, control};

	//���º���
	State state;

	//�̵��ӵ�
	float speed;

	//�߻�Ÿ�̸�//
	float fireTimer;
	float fireDelay;

	//�÷��̾� �̹��� ���� �迭//
	Image images[7];
	int   imageIdx;  

	//�̹��� Ÿ�̸�
	float imageTimer;
	float imageDelay;

	//�ǵ� Ÿ�̸�
	float shieldTimer;

	//�÷��̾� ü��
	//float hp;	//GameManager�� �̵�

	//������ �߻� ����
	int laserCount;

	//��ź ����
	//int bombCount;	//GameManager�� �̵���

public:
	Player(float px, float py);
	virtual ~Player();

	virtual void start();
	virtual void update();

	//�÷��̾� �����Լ�
	void showUp();

	//�̵��Լ�
	void move();

	//�߻��Լ�
	void fire();

	//�÷��̾� �����Լ�
	void shield();

	//�������� Ŭ���� üũ �Լ�
	void stageClear();

	//�浹�̺�Ʈ �������̵�//
	virtual void onTriggerStay(GameObject* other);

	//�÷��̾� �����Լ�
	void explode();
};
