#include "framework.h"

GameOver::GameOver(float px, float py) : Sprite("UI", "���ӿ���", true, px, py)
{

}

GameOver::~GameOver(){}

void GameOver::start()
{
	setImage("Asset/���ӿ���.bmp");
}