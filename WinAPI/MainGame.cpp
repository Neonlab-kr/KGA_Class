#include "Stdafx.h"
#include "MainGame.h"

// 관리자
HRESULT MainGame::init(void)
{
    GameNode::init();

    rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);

    return S_OK;
}

void MainGame::release(void)
{
    GameNode::release();
    // 동적 할당 해제
}

void MainGame::update(void)
{
    GameNode::update();

    if (KEYMANAGER->isStayKeyDown(VK_UP))
    {
        rc.top -= 3;
        rc.bottom -= 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_DOWN))
    {
        rc.top += 3;
        rc.bottom += 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        rc.left -= 3;
        rc.right -= 3;
    }

    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        rc.left += 3;
        rc.right += 3;
    }
}

void MainGame::render(HDC hdc)
{
    if (KEYMANAGER->isToggleKey(VK_F1))
    {
        Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
    }
}
