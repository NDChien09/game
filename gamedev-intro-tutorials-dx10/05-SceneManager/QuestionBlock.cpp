#include "QuestionBlock.h"
#include "Coin.h"
#include "Mushroom.h"

CQuestionBlock::CQuestionBlock(float x, float y) : CGameObject(x, y)
{
	isClaimed = false;
}

void CQuestionBlock::Render()
{
	int aniID = ID_ANI_QUESTIONBLOCK;
	if (isClaimed)
		 aniID = ID_ANI_QUESTIONBLOCK_CLAIMED;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_QUESTIONBLOCK)->Render(x, y);
	RenderBoundingBox();
}

void CQuestionBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - QUESTIONBLOCK_BBOX_WIDTH / 2;
	t = y - QUESTIONBLOCK_BBOX_HEIGHT / 2;
	r = l + QUESTIONBLOCK_BBOX_WIDTH;
	b = t + QUESTIONBLOCK_BBOX_HEIGHT;
}

void CQuestionBlock::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!isClaimed)
	{
		isClaimed = true;
	}
}

void CQuestionBlock::SetItem(string item)
{
	if (item == "coin")
		qbItem = Item::Coin;
	else if (item == "mushroom")
		qbItem = Item::Mushroom;
}

void CQuestionBlock::SpawnItem()
{
	switch (qbItem)
	{
	case Item::Mushroom:
		{
			CMushroom* mushroom = new CMushroom();
			mushroom->SetPosition(x, y);
			break;
		}
	}
}