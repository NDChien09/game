#include "GameObject.h"

#define PARAKOOPAS_GRAVITY 0.002f
#define PARAKOOPAS_WALKING_SPEED 0.05f


#define PARAKOOPAS_BBOX_WIDTH 16
#define PARAKOOPAS_BBOX_HEIGHT 26
#define PARAKOOPAS_BBOX_HEIGHT_DIE 16

#define PARAKOOPAS_DIE_TIMEOUT 500

#define PARAKOOPAS_STATE_WALKING 100
#define PARAKOOPAS_STATE_SHELL 200

#define ID_ANI_PARAKOOPAS_WALKING_LEFT 6300

class CParakoopas : public CGameObject
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
	CParakoopas(float x, float y);
	virtual void SetState(int state);
};