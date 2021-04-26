#pragma once

#include <vector>
#include "Sprite.h"

using namespace std;

class Animation : public Sprite
{
private:
		
	vector<Image> images[10];
	
	int imageIdx;
	int animClip;

	//�̹��� Ÿ�̸�
	float imageTimer;
	float imageDelay;

	//�ִϸ��̼Ǽӵ�
	float animSpeed;

public:

	Animation(string tag, string name, bool active, float px, float py);
	virtual ~Animation();
	
	virtual void draw();

	//�ִϸ��̼� �̹����� �߰��ϱ�//
	void addImage(string fileName, int x, int y, int width, int height, int animClip);
	void addImage(string fileName, int animClip);

	//�ִϸ��̼� �÷����Լ�
	void play(int animClip);

	//�ִϸ��̼� �ӵ� �Լ�//
	void setSpeed(float speed);  //1.0f�� ����ӵ���

	//�ִϸ޼� ���� �̺�Ʈ//
	virtual void animEndEvent();
};
