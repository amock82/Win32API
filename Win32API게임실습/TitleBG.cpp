#include "framework.h"

TitleBG::TitleBG(float px, float py) : Sprite("���", "Ÿ��Ʋ���", true, px, py)
{}

TitleBG::~TitleBG(){}

void TitleBG::start()
{
	setImage("Asset/Ÿ��Ʋ���2.bmp");
}