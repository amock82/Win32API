#include "framework.h"

//////////////////////////////
//		���� ��ư Ŭ����		//
//////////////////////////////
BtnStart::BtnStart(float px, float py) : Button(px, py)
{

}

BtnStart::~BtnStart(){}

void BtnStart::start()
{
	setImage("Asset/UI/���۹�ư.bmp");
}

void BtnStart::onClick()
{
	SceneManager::loadScene(new GameScene());
}


//////////////////////////////
//		��� ��ư Ŭ����		//
//////////////////////////////
BtnMode::BtnMode(float px, float py) : Button(px, py)
{

}

BtnMode::~BtnMode() {}

void BtnMode::start()
{
	setImage("Asset/UI/��弱��.bmp");
}

void BtnMode::onClick()
{
	cout << "��弱�� ��ư" << endl;
}


//////////////////////////////
//		�ɼ� ��ư Ŭ����		//
//////////////////////////////
BtnOption::BtnOption(float px, float py) : Button(px, py)
{

}

BtnOption::~BtnOption() {}

void BtnOption::start()
{
	setImage("Asset/UI/�ɼǼ���.bmp");
}

void BtnOption::onClick()
{
	cout << "�ɼ� ��ư" << endl;
}



//////////////////////////////
//		���� ��ư Ŭ����		//
//////////////////////////////
BtnQuit::BtnQuit(float px, float py) : Button(px, py)
{

}

BtnQuit::~BtnQuit() {}

void BtnQuit::start()
{
	setImage("Asset/UI/������.bmp");
}

void BtnQuit::onClick()
{
	Application::quit();
}