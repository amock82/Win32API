#include "framework.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
	     :Sprite(tag, name, active, px, py)
{
	this->imageIdx   = 0;
	this->imageTimer = 0;
	this->imageDelay = 0.1f;
	this->animClip   = 0;
	this->animSpeed  = 1.0f;
}

Animation::~Animation()
{
	for (int clip = 0; clip < 10; clip++)
	{
		for (int i = 0; i < images[0].size(); i++)
		{
			delete[] images[clip][i].data;
		}

		images[clip].clear();
	}

	resetImage(); //�θ� Ŭ���� Sprite�� ������ ����
}

void Animation::draw()
{
	if (getActive() == true)
	{
		//��������Ʈ �θ�Ŭ���� draw ȣ���ϱ�//
		Sprite::draw();

		//�ִϸ��̼� ��� ���ö���Ʈ �����ϱ�//
		imageTimer = imageTimer + Timer::deltaTime;

		if (imageTimer >= imageDelay / animSpeed)
		{
			imageIdx++;

			if (imageIdx >= images[animClip].size())
			{
				//�ִϸ޴ϼ� 1ȸ ���� �̺�Ʈ//
				animEndEvent();

				imageIdx = 0;
			}

			setImage(images[animClip][imageIdx]);
			imageTimer = 0;
		}
	}
}

void Animation::addImage(string fileName, int x, int y, int width, int height, int animClip)
{
	Image img;
	
	readBMP(fileName.data(), x, y, width, height, &img);
	images[animClip].push_back(img);
}

void Animation::addImage(string fileName, int animClip)
{
	Image img;

	readBMP(fileName.data(), &img);
	images[animClip].push_back(img);
}

void Animation::play(int animClip)
{
	setImage(images[animClip][imageIdx]);
	this->animClip = animClip;
}

void Animation::setSpeed(float speed)  //1.0f�� ����ӵ���
{
	animSpeed = speed;
}

void Animation::animEndEvent()
{}