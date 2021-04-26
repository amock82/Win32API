#pragma once

#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	//��������Ʈ �̹��� ����ü//
	Image image;
public:
	Sprite(string tag, string name, bool active, float px, float py);
	virtual ~Sprite();

	//�̹��� ����ü �ε��Լ�//
	void setImage(string  fileName);
	void setImage(string  fileName,int x, int y, int width, int height);
	void setImage(Image  &image);
	void resetImage();

	//�����Լ� �������̵�//
	virtual void draw();

	//�̹��� ����ü ���� ����
	int getImageWidth();
	int getImageHeight();
	void getImageRect(int& width, int& height);
};
