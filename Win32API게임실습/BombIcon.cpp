#include "framework.h"

BombIcon::BombIcon(float px, float py) : Sprite("UI", "��ź������", true, px, py)
{

}

BombIcon::~BombIcon(){}

void BombIcon::start()
{
	setImage("Asset/UI/��ź������.bmp");
}