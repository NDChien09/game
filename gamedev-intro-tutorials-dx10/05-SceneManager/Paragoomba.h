#pragma once
#include "GameObject.h"

#define PARAGOOMBA_GRAVITY 0.002f
#define PARAGOOMBA_WALKING_SPEED 0.05f


#define PARAGOOMBA_BBOX_WIDTH 16
#define PARAGOOMBA_BBOX_HEIGHT 14

#define PARAGOOMBA_STATE_WALKING 100
#define PARAGOOMBA_STATE_DIE 200

#define ID_ANI_PARAGOOMBA_WALKING 5002

class CParagoomba : public CGameObject
{
protected:
	float ax;
	float ay;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CParagoomba(float x, float y);
	virtual void SetState(int state);
};