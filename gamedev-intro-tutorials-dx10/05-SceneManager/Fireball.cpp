#include "debug.h"
#include "Fireball.h"

CFireball::CFireball(float x, float y) : CGameObject(x, y)
{
	ay = FIREBALL_GRAVITY;
}
void CFireball::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx = FIREBALL_SPEED;
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFireball::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CFireball::OnCollisionWith(LPCOLLISIONEVENT e)
{

}


void CFireball::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FIREBALL)->Render(x, y);

	RenderBoundingBox();


}


void CFireball::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - FIREBALL_BBOX_HEIGHT / 2;
	top = y - FIREBALL_BBOX_WIDTH / 2;
	right = left + FIREBALL_BBOX_HEIGHT;
	bottom = top + FIREBALL_BBOX_WIDTH;
}

