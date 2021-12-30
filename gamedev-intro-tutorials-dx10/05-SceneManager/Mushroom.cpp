#include "Mushroom.h"
#include "Game.h"
#include "Collision.h"

CMushroom::CMushroom()
{
	isOut = false;
	velocity = 0;
	SetVx = false;
}

void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (distance >= MUSHROOM_HEIGHT)
		isOut = true;

	if (isOut)
	{
		if (!SetVx)
		{
			velocity = MUSHROOM_SPEED;
			SetVx = true;
		}
		vy += MUSHROOM_GRAVITY * dt;
	}
}

void CMushroom::Render()
{
	int aniId = ANI_ID_MUSHROOM;
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CMushroom::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + MUSHROOM_WIDTH;
	bottom = top + MUSHROOM_HEIGHT;
}

