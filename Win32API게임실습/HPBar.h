#pragma once

#include "GameObject.h"
#include "BMP.h"

class HPBar : public GameObject
{
private:
	Image bg;
	Image bar;

	//ü�¹� fillAmount
	float fillAmount;

public:
	HPBar(float px, float py);
	virtual ~HPBar();

	virtual void start();
	virtual void draw();

	void setFillAmount(float fillAmount);
};