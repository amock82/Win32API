#include "framework.h"

GameBG::GameBG(float px, float py) 
	   : Sprite("���", "���ӹ��", true, px, py)
{}

GameBG::~GameBG()
{}

void GameBG::start()
{
	//���ö���Ʈ �̹��� �ε�//
	setImage("Asset/���1.bmp");
}