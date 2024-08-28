#include <Windows.h>
#include <tchar.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdParam,int nCmdShow)
{
    _hInstance = hInstance;

    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = (WNDPROC)WndProc;
    wndClass.lpszClassName = _lpszClass;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    
    RegisterClass(&wndClass);
    _hWnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 400, 100, 800, 800, NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(_hWnd, nCmdShow);

    MSG message;
    while (GetMessage(&message, 0, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    char str[] = "오케이";

    RECT rc = { 100,100,200,200 };

    switch (iMessage)
    {
    case WM_CREATE:
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        SetPixel(hdc, 300, 200, RGB(255, 0, 0));

        for (int i = 0; i < 10000 ; i++)
        {
            SetPixel(hdc, rand() % 800, rand() % 800, RGB(rand() % 255, rand() % 255, rand() % 255));
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                SetPixel(hdc, 400 + i, 300 + j, RGB(255, i * 2, j * 2));
            }
        }

        Ellipse(hdc, 300, 100, 200, 200);

        Rectangle(hdc, 100, 100, 200, 200);
        //Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

        POINT num[3] = { (100,100),(50,50),(300,300) };
        Polygon(hdc, num, 3);

        TextOut(hdc, 300, 300, "과제가 너무 재밌다^^", strlen("과제가 너무 재밌다^^"));

        SetTextColor(hdc, RGB(255, 0, 0));
        TextOut(hdc, 300, 400, "더 많은 과제가 필요하다", strlen("더 많은 과제가 필요하다"));

        MoveToEx(hdc, 400, 400, NULL);
        LineTo(hdc, 200, 400);

        MoveToEx(hdc, 400, 400, NULL);
        LineTo(hdc, 200, 200);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_LBUTTONDOWN:
        hdc = GetDC(hWnd);

        SetTextColor(hdc, RGB(0, 0, 255));
        TextOut(hdc, 350, 500, str, strlen(str));
        
        ReleaseDC(hWnd, hdc);
        break;

    case WM_RBUTTONDOWN:
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
            case VK_LEFT:
                break;
            case VK_RIGHT:
                break;
            case VK_ESCAPE:
                PostMessage(hWnd, WM_DESTROY, 0, 0);
                break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}