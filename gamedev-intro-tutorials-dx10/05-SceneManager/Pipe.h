#pragma once

#include "GameObject.h"

class CPipe : public CGameObject
{
protected:
	int length;
	int height;					// Unit: cell 
	float cellWidth;
	float cellHeight;

public:
	CPipe(float x, float y,
		float cell_width, float cell_height, int length, int height) :CGameObject(x, y)
	{
		this->length = length;
		this->height = height;
		this->cellWidth = cell_width;
		this->cellHeight = cell_height;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void RenderBoundingBox();
};

typedef CPipe* LPPIPE;