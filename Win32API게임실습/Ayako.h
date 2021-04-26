#pragma once

#include "Animation.h"

class Ayako : public Animation
{
private:
	enum class State
	{
		moveDown,
		moveLeft,
		moveRight,
		fall
	};

	float speed;
	float fallFactor;
	float hp;

	float fireTimer;
	float fireDelay;

	float lifeTime;
	float moveDownRange;

	State state;	

	bool dropItem;

public:
	Ayako(float px, float py, bool dropItem);
	~Ayako();

	virtual void start();
	virtual void update();

	//�浹 �̺�Ʈ �Լ� �������̵�//
	virtual void onTriggerStay(GameObject* other);

	//�ƾ��� ���� �Լ�
	void explode();

	// ���� �����Լ�
	void moveDown();
	void moveLeft();
	void moveRight();
	void fall();
};
