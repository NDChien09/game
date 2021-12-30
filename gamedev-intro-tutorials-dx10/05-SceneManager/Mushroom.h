#pragma once
#include "GameObject.h"

#define MUSHROOM_SPEED  0.1f
#define MUSHROOM_GRAVITY  0.0015f

#define MUSHROOM_WIDTH 48
#define MUSHROOM_HEIGHT 48

#define ANI_ID_MUSHROOM	0;
class CMushroom : public CGameObject
{
	int state;
	bool isOut;
	float distance;
	float velocity;
	bool SetVx;
public:
	CMushroom();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};
