#pragma once

#include <vector>
#include <string>

#include "GameObject.h"

using namespace std;

class ObjectPool
{
private:
	static vector<GameObject*> pool;

public:

	// ObjectPool �ʱ�ȭ
	static void init();

	// Ǯ�� ��ü �߰��ϱ�
	static void push(GameObject* o);
	
	// Ǯ���� ��ü ��������
	static GameObject* pop(string tag, string name);
};