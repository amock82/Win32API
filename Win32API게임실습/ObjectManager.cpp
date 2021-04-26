#include "framework.h"

vector<GameObject*> ObjectManager::gameObject[MAX_LAYER];
bool ObjectManager::isShowGizmo = true;

GameObject* ObjectManager::instantiate(GameObject* obj, int layer)
{
	gameObject[layer].push_back(obj);
	obj->start();

	return obj;
}

void ObjectManager::destroy(GameObject* obj)
{
	obj->setAlive(false);

	/** �Ǵ� 
	for (int i = 0; i < gameObject.size(); i++)
	{
		if (gameObject[i] == obj)
		{
			obj->setAlive(false);
			break; //���� ��... �ݺ��� ����
		}
	}
	**/
}

void ObjectManager::update()
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			GameObject* o = gameObject[layer].at(i);
			o->update();
		}
	}
}

void ObjectManager::checkCollision()
{
	// �浹�˻縦 ���ؼ� ��� ���̾��� ��ü�� 1���� �迭�� ����
	vector<GameObject*> tempObject;
	
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			tempObject.push_back(gameObject[layer][i]);
		}
	}

	for (int j = 0; j < tempObject.size(); j++)
	{
		for (int i = 0; i < tempObject.size(); i++)
		{
			if (i > j)
			{
				GameObject* objJ = tempObject[j];  //�׽�Ʈ���� �÷��̾� ��ü
				GameObject* objI = tempObject[i];  //�׽�Ʈ���� �ƾ��� ��ü

				if (objJ->getActive() == true && objI->getActive() == true)
				{
					//�浹�˻� ��ü�ֿ��� �浹ü ��������//
					vector<BoxCollider2D> colJ = objJ->getCollider();
					vector<BoxCollider2D> colI = objI->getCollider();

					for (int jj = 0; jj < colJ.size(); jj++)
					{
						for (int ii = 0; ii < colI.size(); ii++)
						{
							//�浹ü �簢�� �ٿ�� �ڽ�..��ǥ ��������
							float x, y, width, height;
							float x0j, y0j, x1j, y1j;  //colJ�� �簢�� ��ǥ
							float x0i, y0i, x1i, y1i;  //colI�� �簢�� ��ǥ

							colJ[jj].getBoundingBox(x, y, width, height);

							x0j = x;
							y0j = y;
							x1j = x + width;
							y1j = y + height;

							colI[ii].getBoundingBox(x, y, width, height);

							x0i = x;
							y0i = y;
							x1i = x + width;
							y1i = y + height;

							if (y1i > y0j && y1j > y0i && x1j > x0i && x1i > x0j)
							{
								objJ->onTriggerStay(objI);  //�浹�̺�Ʈ �߻���Ŵ
								objI->onTriggerStay(objJ);  //�浹�̺�Ʈ �߻���Ŵ
							}
						}
					}
				}
			}
		}
	}
	
	// tempObject Ŭ����
	tempObject.clear();
}

void ObjectManager::clearDeadObj()
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getAlive() == false)
			{
				GameObject* obj = gameObject[layer][i];

				gameObject[layer].erase(gameObject[layer].begin() + i);
				delete obj;

				i--;
			}
		}
	}
}

void ObjectManager::draw()
{
	//����� ��� Ű ���(toggle) �Է� �ޱ�//
	if (Input::getKeyDown("F1") == true)
	{
		if (isShowGizmo == true)
		{
			isShowGizmo = false;
		}
		else {
			isShowGizmo = true;
		}
	}

	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			//���� �̹���(���ö���Ʈ) �׸���
			GameObject* o = gameObject[layer][i];
			
			if (o->getActive() == true)
			{
				o->draw();

				if (isShowGizmo == true)
				{
					//���� �����(�浹ü) �׸���
					o->onDrawGizmos();
				}
			}
		}
	}
}

void ObjectManager::exit()
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			GameObject* o = gameObject[layer].at(i);
			delete o;
		}

		gameObject[layer].clear();
	}
}

GameObject* ObjectManager::find(string name)
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getName() == name)
				return gameObject[layer][i];
		}
	}

	return nullptr;
}