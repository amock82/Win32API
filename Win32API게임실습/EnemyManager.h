#pragma once

#include "GameObject.h"

#define MAX_SIZE 15

class EnemyManager : public GameObject
{
private:
	enum class State {ayakoSpawn, stealthSpawn, bossSpawn};

	float spawnTimer;
	float spawnDelay;

	//���� ���� ���Ϲ迭
	//0 = ��������, 1 = ������, 2 = ������ �����ۻ���
	int spawnPat[MAX_SIZE][2] = {
		{1, 0},
		{1, 0},
		{0, 0},
		{0, 1},
		{0, 2},
		
		{1, 0},
		{1, 1},
		{0, 2},
		{1, 1},
		{2, 1},

		{1, 1},
		{0, 1},
		{1, 1},
		{1, 0},
		{1, 1}
	};

	int spawnIdx;

	State state;

	int stealthCount;

public:
	EnemyManager(float px, float py);
	virtual ~EnemyManager();

	virtual void update();

	virtual void onDrawGizmos();
};