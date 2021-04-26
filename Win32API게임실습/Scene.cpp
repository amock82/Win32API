#include "framework.h"

Scene::Scene(){}

Scene::~Scene()
{
    //ObjectManager�� ��� ��ü �����ϱ�
    ObjectManager::exit();
}

void Scene::load()
{
    
}

void Scene::run()
{
    ObjectManager::update();
    ObjectManager::checkCollision();
    ObjectManager::clearDeadObj();
    ObjectManager::draw();
}