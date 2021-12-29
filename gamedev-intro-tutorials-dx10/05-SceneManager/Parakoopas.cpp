#include "Parakoopas.h"

CParakoopas::CParakoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = PARAKOOPAS_GRAVITY;
	SetState(PARAKOOPAS_STATE_WALKING);
}

void CParakoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == PARAKOOPAS_STATE_SHELL)
	{
		left = x - PARAKOOPAS_BBOX_WIDTH / 2;
		top = y - PARAKOOPAS_BBOX_HEIGHT_DIE / 2;
		right = left + PARAKOOPAS_BBOX_WIDTH;
		bottom = top + PARAKOOPAS_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - PARAKOOPAS_BBOX_WIDTH / 2;
		top = y - PARAKOOPAS_BBOX_HEIGHT / 2;
		right = left + PARAKOOPAS_BBOX_WIDTH;
		bottom = top + PARAKOOPAS_BBOX_HEIGHT;
	}
}

void CParakoopas::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CParakoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CParakoopas*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CParakoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParakoopas::Render()
{
	int aniId = ID_ANI_PARAKOOPAS_WALKING_LEFT;
	if (state == PARAKOOPAS_STATE_SHELL)
	{
		
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CParakoopas::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PARAKOOPAS_STATE_SHELL:
		y += (PARAKOOPAS_BBOX_HEIGHT - PARAKOOPAS_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case PARAKOOPAS_STATE_WALKING:
		vx = -PARAKOOPAS_WALKING_SPEED;
		break;
	}
}
