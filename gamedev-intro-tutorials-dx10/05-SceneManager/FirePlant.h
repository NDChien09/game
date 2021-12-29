#pragma once
#include "GameObject.h"


#define FIREPLANT_BBOX_WIDTH 16
#define FIREPLANT_BBOX_HEIGHT 32

#define ID_ANI_FIREPLANT_MOVELEFT 9000

class CFirePlant : public CGameObject
{
protected:

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

public:
	CFirePlant(float x, float y);
	virtual void SetState(int state);
};