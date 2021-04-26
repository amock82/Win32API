#pragma once

#include "Sprite.h"

class Wing : public Sprite
{
private:
	int imgRect[8][4] = { {298, 425, 30, 18},
						  {329, 426, 32, 16},
						  {364, 426, 32, 16},
						  {399, 426, 32, 16},

						  {404, 406, 28, 15},
						  {369, 406, 32, 16},
						  {334, 406, 32, 16},
						  {299, 406, 32, 16} };

	int colRect[8][4] = { {0, 0, 30, 18},	//������ ù��°
						  {0, 0, 32, 16},	//������ �ι�°
						  {0, 0, 32, 16},	//������ ����°
						  {0, 0, 32, 16},	//������ �׹�°

						  {0, 0, 28, 15},	//���� ù��°
						  {0, 0, 32, 16},	//���� �ι�°
						  {0, 0, 32, 16},	//���� ����°
						  {0, 0, 32, 16} };	//���� �׹�°

	int imgId;
	float hp;

public:
	Wing(float px, float py, int imgId);
	virtual ~Wing();

	virtual void start();
	virtual void onTriggerStay(GameObject* other);
};