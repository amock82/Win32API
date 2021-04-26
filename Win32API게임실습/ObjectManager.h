#pragma once

#include <vector>
#include "GameObject.h"

using namespace std;

#define MAX_LAYER 8

class ObjectManager
{
private:	
	static vector<GameObject*> gameObject[MAX_LAYER];
	static bool isShowGizmo;

public:
	//���ӿ�����Ʈ �߰�, ���� �ϱ�//
	static GameObject* instantiate(GameObject* obj, int layer = 0);
	static void destroy(GameObject* obj);

	//���ӿ�����Ʈ ������Ʈ
	static void update();

	//���ӿ�����Ʈ �浹�˻�
	static void checkCollision();

	//������� ��ü��..��� �����ϱ�
	static void clearDeadObj();

	//���ӿ�����Ʈ �׸���
	static void draw();

	//���ӿ������� ��� �����ϱ�
	static void exit();

	//��ü ã�ƿ���
	static GameObject* find(string name);
};
