#include "framework.h"

BTNPause::BTNPause(float px, float py) : Button(px, py)
{

}

BTNPause::~BTNPause(){}

void BTNPause::start()
{
	setImage("Asset/UI/btnPause.bmp");
}

void BTNPause::onClick()
{
	if (GameManager::isPause == false)
	{
		Timer::timeScale = 0.0f;
		GameManager::isPause = true;
		
		GameObject* menu = ObjectManager::find("�޴�");
		
		if (menu != nullptr)
			menu->setActive(true);
		else
			cout << "�޴� ��ü �����Ͱ� nullptr �Դϴ�." << endl;
	}
	else
	{
		Timer::timeScale = 1.0f;
		GameManager::isPause = false;

		GameObject* menu = ObjectManager::find("�޴�");
		
		if (menu != nullptr)
			menu->setActive(false);
		else
			cout << "�޴� ��ü �����Ͱ� nullptr �Դϴ�." << endl;
	}
}