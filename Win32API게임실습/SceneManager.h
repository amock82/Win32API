#pragma once

#include "Scene.h"

class SceneManager
{
private:
	static Scene* scene;

public:
	static void init();
	static void run();

	//����ȯ �Լ�
	static void loadScene(Scene*);	//�Լ� ����(����)���� �Ű����� �̸��� ���ȵ�
									//��, ���ʿ��� �� ��ü�� �ּ� 1���� �Ű������� ���޵ȴ�
};