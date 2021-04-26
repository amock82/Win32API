#pragma once

#include "Sprite.h"
#include "Button.h"

//////////////////////////
//		�޴� Ŭ����		//
//////////////////////////
class Menu : public Sprite
{
private:

public:
	Menu(float px, float py);
	virtual ~Menu();

	virtual void start();
};

//////////////////////////////////
//		�̾��ϱ� ��ư Ŭ����		//
//////////////////////////////////
class ItemResume : public Button
{
private:

public:
	ItemResume(float px, float py);
	virtual ~ItemResume();

	virtual void start();
	virtual void onClick();
};

//////////////////////////////////
//		�ٽ��ϱ� ��ư Ŭ����		//
//////////////////////////////////
class ItemRestart : public Button
{
private:

public:
	ItemRestart(float px, float py);
	virtual ~ItemRestart();

	virtual void start();
	virtual void onClick();
};

//////////////////////////////////
//		�������� ��ư Ŭ����		//
//////////////////////////////////
class ItemMain : public Button
{
private:

public:
	ItemMain(float px, float py);
	virtual ~ItemMain();

	virtual void start();
	virtual void onClick();
};

//////////////////////////////////
//		�������� ��ư Ŭ����		//
//////////////////////////////////
class ItemExit : public Button
{
private:

public:
	ItemExit(float px, float py);
	virtual ~ItemExit();

	virtual void start();
	virtual void onClick();
};