#include "framework.h"

float Timer::currTime;
float Timer::prevTime;
float Timer::deltaTime;
float Timer::timeScale;

void Timer::init()
{
	//�ð������ϱ� - GetTickCount�� ��ǻ�Ͱ� ���������� �ð��� ms ������..ī��Ʈ��//
	currTime = GetTickCount() / 1000.0f;
	prevTime = GetTickCount() / 1000.0f;
	deltaTime = 0;
	timeScale = 1;
}

void Timer::update()
{
	//������Ʈ//
	currTime = GetTickCount() / 1000.0f;
	deltaTime = (currTime - prevTime) * timeScale;
	prevTime = currTime;
}