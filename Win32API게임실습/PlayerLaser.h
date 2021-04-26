#pragma once

#include "Sprite.h"

class PlayerLaser : public Sprite
{
private:

	float speed;
	float lifeTime;  //��ü�� ����ִ� �ð�

public:
	PlayerLaser(float px, float py);
	virtual ~PlayerLaser();

	virtual void start();
	virtual void update();

	//�浹�̺�Ʈ �������̵�//
	virtual void onTriggerStay(GameObject* other);	
};