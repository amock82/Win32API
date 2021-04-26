#pragma once

#include "Sprite.h"

class Button : public Sprite
{
private:
	enum class State { normal, hover, press, release, click};

	State state;

	bool isUsed;

public:
	Button(float px, float py);
	virtual ~Button();

	virtual void update();

	//���콺 �����Ͱ� ��ư �̹��� �����ȿ� �ִ��� �˻��ϴ� �Լ�
	bool mouseInButton();
	void checkClick();
	virtual void onClick();
};