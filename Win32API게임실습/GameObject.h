#pragma once

#include <string>
#include <vector>

#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//�⺻ �Ӽ�//
	string tag;
	string name;
	bool active;
	bool alive;  //��ü�� ����ִ����� ǥ���ϴ� ���� 

	//Transform �Ӽ�//
	float px, py;

	//���ӿ�����Ʈ �浹ü//
	vector<BoxCollider2D> collider;

	//�ڽ� ���� ������Ʈ//
	vector<GameObject*> childObj;

public:
	//�θ� ���� ������Ʈ//
	GameObject* parent;

	///������, �Ҹ���///
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//����, ����//
	string getTag();
	string getName();
	bool   getActive();

	float getPx();
	float getPy();
	void  getPosition(float& px, float& py);
	bool  getAlive();

	vector<BoxCollider2D> getCollider();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);

	void setPx(float px);
	void setPy(float py);
	void setPosition(float px, float py);

	void setAlive(bool alive);

	//�⺻ �����Լ�//
	virtual void start();
	virtual void update();
	virtual void draw();

	//�̵��Լ�//
	void translate(float x, float y);

	//�浹ü �߰��Լ�
	void addBoxCollider2D(float x, float y, float width, float height);
	void addBoxCollider2D(BoxCollider2D collider);

	//�ڽİ�ü �߰�, �����ϱ�
	void addChildObj(GameObject* obj, int layer = 0);
	void delChildObj(GameObject* obj);

	//�ڽİ�ü ã�ƿ���
	GameObject* getChild(int index);
	GameObject* find(string name);

	//�ڽİ�ü ���� ���ϱ�
	int getChildCount();

	//�浹ü ����� �׸����Լ�//
	virtual void onDrawGizmos();

	//�浹 �̺�Ʈ ó���Լ� //
	virtual void onTriggerStay(GameObject * other);
};