#include "FirePlant.h"

CFirePlant::CFirePlant(float x, float y) :CGameObject(x, y)
{
	
}

void CFirePlant::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - FIREPLANT_BBOX_WIDTH / 2;
	top = y - FIREPLANT_BBOX_HEIGHT / 2;
	right = left + FIREPLANT_BBOX_WIDTH;
	bottom = top + FIREPLANT_BBOX_HEIGHT;
}



void CFirePlant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CFirePlant::Render()
{
	int aniId = ID_ANI_FIREPLANT_MOVELEFT;
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CFirePlant::SetState(int state)
{

}
