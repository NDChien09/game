#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_QUESTIONBLOCK 12000
#define ID_ANI_QUESTIONBLOCK_CLAIMED 12001

#define	QUESTIONBLOCK_WIDTH 16
#define QUESTIONBLOCK_BBOX_WIDTH 16
#define QUESTIONBLOCK_BBOX_HEIGHT 16

enum class Item
{
	Coin,
	Mushroom,
};

class CQuestionBlock : public CGameObject 
{
	bool isClaimed = false;
	Item qbItem;
public:
	CQuestionBlock(float x, float y);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	void SetItem(string item);
	void SpawnItem();
	void OnCollisionWith(LPCOLLISIONEVENT e);
};