#pragma once

#include "Animation.h"

class LaserExp : public Animation
{
private:
public:

	LaserExp(float px, float py);
	virtual ~LaserExp();

	virtual void start();

	//�ִ����� �̺� �������̵�//
	virtual void animEndEvent();
};