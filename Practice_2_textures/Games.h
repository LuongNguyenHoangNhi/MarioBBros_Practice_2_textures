#pragma once
#include <Windows.h>
#include <d3d10.h>
#include <d3dx10.h>

#include "Texture.h"

#define MAX_FRAME_RATE 100
	


class CGame
{
	static CGame * __instance;
	HWND hWnd;									// Window handle

	// Backbuffer width & height, will be set during Direct3D initialization
	int BackBufferWidth;
	int BackBufferHeight;

	ID3D10Device* pD3DDevice = NULL;
	IDXGISwapChain* pSwapChain = NULL;
	ID3D10RenderTargetView* pRenderTargetView = NULL;
	//ID3D10BlendState* pBlendStateAlpha = NULL;			// To store alpha blending state

	ID3DX10Sprite* spriteObject = NULL;				// Sprite handling object 
public:
	// Init DirectX, Sprite Handler
	void InitDirectX(HWND hWnd);

	void Draw(float x, float y, LPTEXTURE tex, RECT* rect = NULL, int sprite_width = 0, int sprite_height = 0);
	void Draw(float x, float y, LPTEXTURE tex, int l, int t, int r, int b, int sprite_width = 0, int sprite_height = 0)
	{
		RECT rect;
		rect.left = l;
		rect.top = t;
		rect.right = r;
		rect.bottom = b;
		this->Draw(x, y, tex, &rect, sprite_width, sprite_height);
	}

	LPTEXTURE LoadTexture(LPCWSTR texturePath);

	ID3D10Device* GetDirect3DDevice() { return this->pD3DDevice; }
	IDXGISwapChain* GetSwapChain() { return this->pSwapChain; }
	ID3D10RenderTargetView* GetRenderTargetView() { return this->pRenderTargetView; }
	ID3DX10Sprite* GetSpriteHandler() { return this->spriteObject; }
	//ID3D10BlendState* GetAlphaBlending() { return pBlendStateAlpha; };

	int GetBackBufferWidth() { return BackBufferWidth; }
	int GetBackBufferHeight() { return BackBufferHeight; }

	static CGame* GetInstance();

	~CGame();
};