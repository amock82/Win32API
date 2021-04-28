#include "framework.h"

HPBar::HPBar(float px, float py) : GameObject("UI", "ü�¹�", true, px, py)
{
	this->fillAmount = 1;
}

HPBar::~HPBar(){}

void HPBar::start()
{
	//���, ���� �̹��� �ε�
	readBMP("Asset/UI/HP_BG.bmp", &bg);
	readBMP("Asset/UI/HP.bmp", &bar);

	addChildObj(new Text(L"HP:100", 10, 18), 5);
}

void HPBar::draw()
{
	float x = getPx();
	float y = getPy();

	drawBMP(x + 2, y + 3, &bar, fillAmount);
	drawBMP(x, y, &bg);
}

void HPBar::setFillAmount(float fillAmount)
{
	this->fillAmount = fillAmount;
}

void HPBar::setValue(int value)
{
	Text* text = (Text*)getChild(0);

	//������ ���ڿ��� ��ȯ�ϱ� (wsprintf)
	//WCHAR buffer[30];
	//wsprintf(buffer, L"%d", value);

	//text->setText(buffer);

	text->setText(L"HP:" + to_wstring(value));
}