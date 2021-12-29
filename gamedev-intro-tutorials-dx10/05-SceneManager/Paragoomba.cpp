#include "Paragoomba.h"
#include "Goomba.h"

CParagoomba::CParagoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = PARAGOOMBA_GRAVITY;
	SetState(PARAGOOMBA_STATE_WALKING);
	timer = 0;
}

void CParagoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - PARAGOOMBA_BBOX_WIDTH / 2;
	top = y - PARAGOOMBA_BBOX_HEIGHT / 2;
	right = left + PARAGOOMBA_BBOX_WIDTH;
	bottom = top + PARAGOOMBA_BBOX_HEIGHT;
}

void CParagoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	SetState(PARAGOOMBA_STATE_JUMP);
};

void CParagoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CParagoomba*>(e->obj)) return;

	if (e->ny < 0)
		SetState(PARAGOOMBA_STATE_WALKING);

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CParagoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if (GetTickCount64() - timer > 2000)
	{
		timer = GetTickCount64();
		vy = -0.3f;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParagoomba::Render()
{
	int aniId = ID_ANI_PARAGOOMBA_WALKING;

	if (state == PARAGOOMBA_STATE_DIE)
	{
		aniId = ID_ANI_GOOMBA_WALKING;
	}
	else if (state == PARAGOOMBA_STATE_JUMP)
	{
		aniId = ID_ANI_PARAGOOMBA_JUMP;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CParagoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GOOMBA_STATE_DIE:
		y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case PARAGOOMBA_STATE_WALKING:
		vx = -PARAGOOMBA_WALKING_SPEED;
		break;
	case PARAGOOMBA_STATE_JUMP:
		vx = -PARAGOOMBA_WALKING_SPEED;
		break;
	}
}