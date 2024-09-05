#include "Stdafx.h"
#include "MainGame.h"

// 관리자
HRESULT MainGame::init(void)
{
    GameNode::init();

    _bgImage = new GImage();
    _bgImage->init("Resource/Images/BackGround/EnderLiliesBG.bmp", WINSIZE_X, WINSIZE_Y);

    _plImage = new GImage();
    _plImage->init("Resource/Images/Object/Lily.bmp", 445/2 , 508/2 , true, RGB(255, 0, 255));

    _rc = RectMakeCenter(WINSIZE_X / 2 - 500, WINSIZE_Y / 2 + 200, 445/2, 508/2);

    //ShowCursor();

    _countA = _countB = 0;
    _alphaA = _alphaB = 0;

    _isAlphaIncrease = false;

    _nine = new GImage();
    _nine->init
    (
        "Resource/Images/Object/Nine.bmp",
        WINSIZE_X / 2 - 200,
        WINSIZE_Y / 2 - 200,
        3940, 586, // 전체 이미지 크기
        10, 2,// 이미지 가로,세로 개수
        true, RGB(255, 0, 255)
    );

    _isLeft = false;
    _count = _index = 0;

    return S_OK;
}

void MainGame::release(void)
{
    GameNode::release();

    SAFE_DELETE(_bgImage);
    SAFE_DELETE(_plImage);
    SAFE_DELETE(_nine);
}

void MainGame::update(void)
{
    GameNode::update();

    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        _isLeft = true;
        _nine->setX(_nine->getX() + 8.0f);
    }

    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        _isLeft = false;
        _nine->setX(_nine->getX() + 8.0f);
    }

    if (_isLeft)
    {
        _count++;
        _nine->setFrameY(1);
        if (_count % 3 == 0)
        {
            _index--;
            if (_index < 0)
            {
                _index = 10;
            }
            _nine->setFrameX(_index);
        }
    }
    else
    {
        _count++;
        _nine->setFrameY(0);
        if (_count % 3 == 0)
        {
            _index++;
            if (_index > 10)
            {
                _index = 0;
            }
            _nine->setFrameX(_index);
        }
    }

    if (KEYMANAGER->isStayKeyDown(VK_UP))
    {
        _rc.top -= 3;
        _rc.bottom -= 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_DOWN))
    {
        _rc.top += 3;
        _rc.bottom += 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        _rc.left -= 3;
        _rc.right -= 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        _rc.left += 3;
        _rc.right += 3;
    }

    //if (PtInRect())
    //{

    //}
    //if (IntersectRect())
    //{

    //}

    _countA++;
    if (_countA % 3 == 0)
    {
        _alphaA++;
        if (_alphaA >= 255) _alphaA = 0;
        //if (_alphaA >= 255) _alphaA = _alphaA * -1;
    }

    _countB++;
    if (_countB % 3 == 0)
    {
        _alphaB+=5;
        if (_alphaB >= 255) _alphaB = 0;
    }
}

void MainGame::render(HDC hdc)
{
    // 백버퍼 가져오기
    HDC memDC = this->getBackBuffer()->getMemDC();

    // 검은색 비트맵 (빈)
    PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
    //====================================================================

    //_bgImage->render(memDC, 0, 0);
    //_bgImage->alphaRender(memDC, _alphaA);

    //if (KEYMANAGER->isToggleKey(VK_F1))
    //{
    //    Rectangle(memDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
    //}

    //_plImage->render(memDC, _rc.left, _rc.top);
    //_plImage->alphaRender(memDC, _rc.left, _rc.top, _alphaB);

    //클리핑
    //_bgImage->render(memDC, _rc.left, _rc.top, 500, 500, 300, 300);

    _nine->frameRender(memDC, _nine->getX(), _nine->getY());

    //====================================================================
    //this->getBackBuffer()->render(hdc, 0, 0);
    this->getBackBuffer()->render(hdc);
}
