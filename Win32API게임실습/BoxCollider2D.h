#pragma once

class BoxCollider2D
{
private:
	float x, y;          //�簢�� �浹ü ���� ��� ������
	float width, height; //�簢�� ����/���� ����

public:
	BoxCollider2D();
	BoxCollider2D(float x, float y, float width, float height);
	
	virtual ~BoxCollider2D();

	void getBoundingBox(float& x, float& y, float& width, float& height);
	void translate(float tx, float ty);
};