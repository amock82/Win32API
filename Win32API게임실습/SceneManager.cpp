#include "framework.h"

Scene* SceneManager::scene = nullptr;

void SceneManager::init()
{
	scene = new TitleScene();
	scene->load();
}

void SceneManager::run()
{
	scene->run();
}

void SceneManager::loadScene(Scene* nextScene)
{
	delete scene;	//���� �� �����ϱ�

	//���� ��
	scene = nextScene;
	scene->load();
}