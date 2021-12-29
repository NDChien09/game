#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define FIREBALL_SPEED 0.05f
#define FIREBALL_GRAVITY 0.001f
#define FIREBALL_BBOX_WIDTH  8
#define FIREBALL_BBOX_HEIGHT 8
#define ID_ANI_FIREBALL 9100

class CFireball : public CGameObject
{
	float ay;

public:
	CFireball(float x, float y);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();

	int IsCollidable()
	{
		return 1;
	}

	int IsBlocking() { return 0; }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};