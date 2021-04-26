#include "framework.h"

///������, �Ҹ���///
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag    = tag;
	this->name   = name;
	this->active = active;
	this->alive  = true;

	this->px = px;
	this->py = py;
		
	this->parent = nullptr;
}

GameObject::~GameObject()
{
}

//����, ����//
string GameObject::getTag()
{
	return tag;
}

string GameObject::getName()
{
	return name;
}

bool GameObject::getActive()
{
	return active;
}

float GameObject::getPx()
{
	return px;
}

float GameObject::getPy()
{
	return py;
}

void GameObject::getPosition(float& px, float& py)
{
	px = this->px;
	py = this->py;
}

vector<BoxCollider2D> GameObject::getCollider()
{
	return collider;
}

bool GameObject::getAlive()
{
	return alive;
}

void GameObject::setTag(string tag)
{
	this->tag = tag;
}

void GameObject::setName(string name)
{
	this->name = name;
}

void GameObject::setActive(bool active)
{
	this->active = active;

	//�ڽ� ��ü�鵵 ���¸� �����ϱ�
	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->setActive(active);
	}
}

void GameObject::setPx(float px)
{
	float tx = px - this->px;

	//�浹ü �̵���Ű��//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].translate(tx, 0);
	}

	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->translate(tx, 0);
	}

    //���Ӱ�ü ��ġ ����
	this->px = px;
}

void GameObject::setPy(float py)
{
	float ty = py - this->py;

	//�浹ü �̵���Ű��//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].translate(0, ty);
	}

	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->translate(0, ty);
	}

	//���Ӱ�ü ��ġ ����
	this->py = py;
}

void GameObject::setPosition(float px, float py)
{
	setPx(px);
	setPy(py);
}

void GameObject::setAlive(bool alive)
{
	this->alive = alive;

	//�ڽİ�ü�鵵 �����ϰ� alive ���� �����ϱ�
	for (int i = 0; i < childObj.size(); i++)
	{
		childObj[i]->setAlive(alive);
	}
}

void GameObject::translate(float x, float y)
{
	//���Ӱ�ü translate//
	this->px += x;
	this->py += y;

	//�浹ü translate//
	for (int i = 0; i < collider.size(); i++)
	{
		this->collider[i].translate(x, y);
	}

	// �ڽİ�ü translate //
	for (int i = 0; i < childObj.size(); i++)
	{
		this->childObj[i]->translate(x, y);
	}
}

void GameObject::addBoxCollider2D(float x, float y, float width, float height)
{
	this->collider.push_back(BoxCollider2D(x + px, y + py, width, height));
}

void GameObject::addBoxCollider2D(BoxCollider2D collider)
{
	//���Ӱ�ü�� ��������..�����ǥ��..������//
	collider.translate(px, py);
	this->collider.push_back( collider );
}

void GameObject::addChildObj(GameObject* obj, int layer)
{
	//�ڽİ�ü�� �θ�ü ������ ����//
	obj->parent = this;

	//���Ӱ�ü�� ��������..�����ǥ��..������//
	obj->translate(px, py);

	// �ڽİ�ü ���ü �߰��ϱ�
	this->childObj.push_back(obj);

	// �ڽİ�ü�� ������Ʈ�Ŵ����� �߰��ϱ�
	ObjectManager::instantiate(obj, layer);
}

void GameObject::delChildObj(GameObject* obj)
{
	//���Ӱ�ü ��Ͽ��� ����
	ObjectManager::destroy(obj);

	//�ڽİ�ü ��Ͽ��� ����
	for (int i = 0; i < childObj.size(); i++)
	{
		if (childObj[i] == obj)
		{
			childObj.erase(childObj.begin() + i);
			break;
		}
	}
}

GameObject* GameObject::getChild(int index)
{
	if (index < childObj.size())
	{
		return childObj[index];
	}
	
	return nullptr;
}

GameObject* GameObject::find(string name)
{
	for (int i = 0; i < childObj.size(); i++)
	{
		if (childObj[i]->getName() == name)
			return childObj[i];
	}

	return nullptr;
}

int GameObject::getChildCount()
{
	return childObj.size();
}

void GameObject::onDrawGizmos()
{
	if (active == true)
	{
		//�浹ü ����� �׸���//
		float x, y, width, height;

		for (int i = 0; i < collider.size(); i++)
		{
			collider[i].getBoundingBox(x, y, width, height);

			//�簢�� ������
			float x0 = x;
			float y0 = y;
			float x1 = x + width;
			float y1 = y + height;

			drawRect(x0, y0, x1, y1, 0, 255, 0);
		}
	}
}

void GameObject::onTriggerStay(GameObject * other)
{}

void GameObject::start()
{}

void GameObject::update()
{}

void GameObject::draw()
{}