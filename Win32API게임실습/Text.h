#pragma once

// freetype ���
#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include "GameObject.h"

using namespace std;

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face    face;

	wstring text;
	int fontSize;

	// ��Ʈ����
	unsigned char r;
	unsigned char g;
	unsigned char b;

public:
	Text(wstring text, int fontSize, unsigned char r, unsigned char g, unsigned char b, float px, float py);
	Text(wstring text, float px, float py);
	virtual ~Text();

	virtual void start();
	virtual void update();
	virtual void draw();
	void setText(wstring text);
};