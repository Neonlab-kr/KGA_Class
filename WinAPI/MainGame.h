#pragma once
#include "GameNode.h"

class MainGame : public GameNode
{
private:
	//정형화된 경우 이런 객체나 처리는 말이 안됨. 
	//매니저 개체가 없어서 처리중
	GImage* _bgImage;
	GImage* _plImage;
	GImage* _nine;

	RECT _rc;

	int _countA, _countB;
	int _alphaA, _alphaB;

	bool _isAlphaIncrease;

	int _count;
	int _index;
	bool _isLeft;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC);

	MainGame() {}
	~MainGame() {}
};

