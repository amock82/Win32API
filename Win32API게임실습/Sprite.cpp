#include "framework.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py)
	  :GameObject(tag, name, active, px, py)
{
	//�̹��� �ε� ����ü..�ʱ�ȭ//
	image.width   = 0;
	image.height  = 0;
	image.data    = nullptr;
}

Sprite::~Sprite()
{
	if (image.data != nullptr)
	{		
		delete[] image.data; //�̹��� ����ü..�����޸�..����//
	}
}

void Sprite::setImage(string fileName)
{
	//��������Ʈ �̹��� �ε��ϱ�//
	readBMP(fileName.data(), &image);
}

void Sprite::setImage(string fileName, int x, int y, int width, int height)
{
	//��������Ʈ �̹��� �ε��ϱ�//
	readBMP(fileName.data(), x, y, width, height, &image);
}

void Sprite::setImage(Image& image)
{
	this->image = image;
}

void Sprite::resetImage()
{
	this->image.data = nullptr;
	
	this->image.width  = 0;
	this->image.height = 0;
}

void Sprite::draw()
{
	//ĳ���� �̹��� �׸���//
	float px = getPx();
	float py = getPy();

	drawBMP(px, py, &image);
}

int Sprite::getImageWidth()
{
	return image.width;
}

int Sprite::getImageHeight()
{
	return image.height;
}

void Sprite::getImageRect(int& width, int& height)
{
	width = image.width;
	height = image.height;
}