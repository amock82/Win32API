#include "framework.h"

TitleScene::TitleScene(){}
TitleScene::~TitleScene(){}

void TitleScene::load()
{
    ObjectManager::instantiate(new TitleBG(0, 0), 0);

    ObjectManager::instantiate(new BtnStart(250, 500), 5);
    ObjectManager::instantiate(new BtnMode(250, 560), 5);
    ObjectManager::instantiate(new BtnOption(250, 620), 5);
    ObjectManager::instantiate(new BtnQuit(250, 680), 5);
    
    // ���� Ÿ��Ʋ ����ϱ�
    ObjectManager::instantiate(new Text(L"2D ���ð��� �ǽ�", 58, 255, 255, 255, 10, 100), 5);

    // ���� �ϼ� ��¥, ����
    ObjectManager::instantiate(new Text(L"Date : 2021-04-28", 280, 760), 5);
    ObjectManager::instantiate(new Text(L"Version : 1.0.0", 280, 780), 5);

    // ��Ʈ �׽�Ʈ�ϱ�
    //ObjectManager::instantiate(new Text(L"ABC", 32, 200, 200, 0, 100, 100), 5);
    //ObjectManager::instantiate(new Text(L"�׽�Ʈ", 64, 0, 200, 200, 100, 64), 5);
}
