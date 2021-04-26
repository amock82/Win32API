#pragma once

#include <string>

using namespace std;

#define MAX_KEY 10

struct MousePosition
{
	int x;
	int y;
};

class Input
{
private:

	enum State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 };

	static int key[MAX_KEY];
	static int state[MAX_KEY];
	static string name[MAX_KEY];

public:

	//���콺 ��ǥ ���� ����
	static MousePosition mousePosition;

	static void init();
	static void update();

	//Ű�˻� �Լ�//
	static bool getKey(string keyCode);
	static bool getKeyDown(string keyCode);
	static bool getKeyUp(string keyCode);

	//���콺 ��ư �˻� �Լ�//
	static bool getMouseButton(int button); //	0 = L | 1 = R | 2 = M
	static bool getMouseButtonDown(int button);
	static bool getMouseButtonUp(int button);
};

