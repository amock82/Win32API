#pragma once

#include "Button.h"

//////////////////////////////
//		���� ��ư Ŭ����		//
//////////////////////////////
class BtnStart : public Button
{
private:

public:
	BtnStart(float px, float py);
	virtual ~BtnStart();

	virtual void start();
	virtual void onClick();
};


//////////////////////////////
//		��� ��ư Ŭ����		//
//////////////////////////////
class BtnMode : public Button
{
private:

public:
	BtnMode(float px, float py);
	virtual ~BtnMode();

	virtual void start();
	virtual void onClick();
};


//////////////////////////////
//		�ɼ� ��ư Ŭ����		//
//////////////////////////////
class BtnOption : public Button
{
private:

public:
	BtnOption(float px, float py);
	virtual ~BtnOption();

	virtual void start();
	virtual void onClick();
};


//////////////////////////////
//		���� ��ư Ŭ����		//
//////////////////////////////
class BtnQuit : public Button
{
private:

public:
	BtnQuit(float px, float py);
	virtual ~BtnQuit();

	virtual void start();
	virtual void onClick();
};