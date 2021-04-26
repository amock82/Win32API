#include "framework.h"

GameScene::GameScene(){}

GameScene::~GameScene(){}

void GameScene::load()
{
    GameManager::init();
    ObjectPool::init();

    //���Ӱ�ü �ε��ϱ�//
    ObjectManager::instantiate(new GameBG(0, 0));

    // EnemyManager �߰� //
    ObjectManager::instantiate(new EnemyManager(WIDTH / 2, 0), 0);

    // �����,������ ���� [������Ʈ Ǯ] �׽�Ʈ //
    for (int i = 0; i < 10; i++)
    {
        GameObject* obj = ObjectManager::instantiate(new ShipExp(0, 0), 3);

        obj->setActive(false);
        ObjectPool::push(obj);
    }

    for (int i = 0; i < 200; i++)
    {
        GameObject* obj = ObjectManager::instantiate(new LaserExp(0, 0), 3);

        obj->setActive(false);
        ObjectPool::push(obj);
    }

    GameManager::restartPlayer();
}
