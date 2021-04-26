#include "framework.h"

//////////////////////////
//		�޴� Ŭ����		//
//////////////////////////
Menu::Menu(float px, float py) : Sprite("UI", "�޴�", true, px, py)
{

}

Menu::~Menu(){}

void Menu::start()
{
	setImage("Asset/UI/menu.bmp");

	addChildObj(new ItemResume(16, 19), 6);
	addChildObj(new ItemRestart(16, 19 + 38), 6);
	addChildObj(new ItemMain(16, 19 + 76), 6);
	addChildObj(new ItemExit(16, 19 + 114), 6);
	
	this->setActive(false);
}


//////////////////////////////////
//		�̾��ϱ� ��ư Ŭ����		//
//////////////////////////////////
ItemResume::ItemResume(float px, float py) : Button(px, py)
{

}

ItemResume::~ItemResume(){}

void ItemResume::start()
{
	setImage("Asset/UI/itemResume.bmp");
}

void ItemResume::onClick()
{
	Timer::timeScale = 1.0f;		//��������
	GameManager::isPause = false;	//�������� ����
	
	parent->setActive(false);		//�޴�����
}

//////////////////////////////////
//		�ٽ��ϱ� ��ư Ŭ����		//
//////////////////////////////////
ItemRestart::ItemRestart(float px, float py) : Button(px, py)
{

}

ItemRestart::~ItemRestart() {}

void ItemRestart::start()
{
	setImage("Asset/UI/ItemRestart.bmp");
}

void ItemRestart::onClick()
{
	SceneManager::loadScene(new GameScene());
}

//////////////////////////////////
//		�������� ��ư Ŭ����		//
//////////////////////////////////
ItemMain::ItemMain(float px, float py) : Button(px, py)
{

}

ItemMain::~ItemMain() {}

void ItemMain::start()
{
	setImage("Asset/UI/ItemMain.bmp");
}

void ItemMain::onClick()
{
	SceneManager::loadScene(new TitleScene());
}

//////////////////////////////////
//		�������� ��ư Ŭ����		//
//////////////////////////////////
ItemExit::ItemExit(float px, float py) : Button(px, py)
{

}

ItemExit::~ItemExit() {}

void ItemExit::start()
{
	setImage("Asset/UI/ItemExit.bmp");
}

void ItemExit::onClick()
{
	Application::quit();
}