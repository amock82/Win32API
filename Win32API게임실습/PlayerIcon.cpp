#include "framework.h"

PlayerIcon::PlayerIcon(float px, float py) : Sprite("UI", "�÷��̾������", true, px, py)
{

}

PlayerIcon::~PlayerIcon(){}

void PlayerIcon::start()
{
	setImage("Asset/UI/�����̹���.bmp");
}