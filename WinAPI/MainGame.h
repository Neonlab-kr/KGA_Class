#pragma once
#include "GameNode.h"

class MainGame : public GameNode
{
private:
	//����ȭ�� ��� �̷� ��ü�� ó���� ���� �ȵ�. 
	//�Ŵ��� ��ü�� ��� ó����
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

