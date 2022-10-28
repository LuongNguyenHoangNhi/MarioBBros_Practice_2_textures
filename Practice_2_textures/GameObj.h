#pragma once
#include "Texture.h"

#include <Windows.h>
#include <d3d10.h>

class CGameObj
{
protected:
	float x;
	float y;

	//only a pointer to a single texture without sound/graphic/audio
	LPTEXTURE texture;
public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }

	CGameObj(float x = 0.0f, float y = 0.0f, LPTEXTURE texture = NULL);

	virtual void Update(DWORD dt) = 0;
	virtual void Render();

	~CGameObj();
};
typedef CGameObj* LPGAMEOBJECT;

class CBrick : public CGameObj
{
	float vx;
	float vy;
public:
	CBrick(float x, float y, float vx, float vy, LPTEXTURE texture) :CGameObj(x, y, texture)
	{
		this->vx = vx;
		this->vy = vy;
	};
	void Update(DWORD dt);
};

class CChicken : public CGameObj
{
	float vx;
	float vy;
public:
	CChicken(float x, float y, float vx, float vy, LPTEXTURE texture) :CGameObj(x, y, texture)
	{
		this->vx = vx;
		this->vy = vy;
	};
	void Update(DWORD dt);
};
