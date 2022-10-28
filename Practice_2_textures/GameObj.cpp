#include <d3dx10.h>

#include "Debug.h"
#include "Games.h"
#include "GameObj.h"

/*
	Initialize game object
*/
CGameObj::CGameObj(float x, float y, LPTEXTURE tex)
{
	this->x = x;
	this->y = y;
	this->texture = tex;
}

void CGameObj::Render() {
	CGame::GetInstance()->Draw(x, y, texture);
}