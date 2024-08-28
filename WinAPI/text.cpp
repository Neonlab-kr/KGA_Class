#pragma region WinAPI
/*
�� API(Application Programming Interface)

- �ü���� �������α׷� ������ ���� �����ϴ� �Լ��� �����̶�� �� �� �ִ�.

- ��ɾ��� �������� ���ø����̼� ���α׷����� ���۷����� �ý����� �⺻���� ����� ����� �ʿ䰡 ���� ��� API���� ��ɾ� ������ ����ȴ�.

- ������� ����� �ƴ϶� ��ġ������ �ܿ��� ó���� �Ǵ� �༮
-> �����쿡�� �ڿ��� ����� �� �ְԲ� �Լ� ���·� �޶�� ��û�� �ü������ ����

EX)
�ϵ���� ----------------- �ü��(Windows) ----------------- ���� ���α׷�
(API �Լ�)

�� ����
 - �ü���� ������ ���� ����� ������ ����ϱ⿡ Ȯ�强 �� ������ / �׸��� ���������� �ſ� �����ϴ�.
	- �������� != ������

�� ����
- ����ϴ� ���α׷����� ������ ���� �÷����� ���� ����ȭ�� �߻��� �� �ִ�. (WinAPI)
	- C���� ���ߵ� �÷����� �Ѱ����� �غ����� ���Ѵٴ� ���α׷����� ���
	- �̴� ��κ� Ÿ ���̺귯�� Ȯ������ �ذ��� ������, ���α׷����� ������ ���� �䱸�ϱ� ������ �̴� ��� ���忡���� �����̶�� �� �� �ִ�.


�� API ����
- ũ�� 3������ ����ϸ� OK
- ������ / ���� (�޼���) / Window Procedure

*/
#pragma endregion

#pragma region tchar
/*
LPSTR   -> char*
LPCSTR  -> const char*
LPCTSTR -> const tchar*

�� TCHAR
- �� �ڷ����� ������Ʈ ���ڼ� ������ ���� �ڵ������� ��ȯ�� ���ִ� �߰� ��ũ�� �ڷ���
	- Type Casting�� �����ϸ� char �Ǵ� wchar_t�� ��ȯ�Ѵ�.

- ��Ƽ�� ���� ȯ�濡�� ������ �����۾� ���� ���α׷��� �����ϱ� ���ؼ��� TCHAR������ ���ڿ��� ǥ���ϴ� ���� �����Ѵ�.

- ������ ���ø����̼��� ����ϴ� ���α׷����ʹ� �������α׷����� ���ڿ� ����� ���� ���ؼ��� �߰� ������ ���� char*-> wchar_t*�� ��ȯ�� ���ִ� _T ��ũ�ε� ��ȿ�ϴ�.

EX)
LPCSTR script1 = "ABC";
LPCWSTR script2 = L"ABC";//�����ڵ� ���ڿ��̶�� L�� ������
TCHAR* script2 = _T("ABC");

*/
#pragma endregion

#pragma region �ؼ� ���
/*
Visual Studio 17���� �߰��� �༮
���ڿ������� Ȯ�ε� �ּҿ� ���ؼ��� ������ ����� �����ϴ�.
������� �ʰ� �ʹٸ� const�� �����ָ� ������. ��, API������ �߰����� �ڷ����� �����°� �������� ����.

*/
#pragma endregion

#pragma region API�� BMP
/*
�ڡڡڡڡ� �������� �ڡڡڡڡ�
API�� GDI(�׷��� ����̽� �������̽�)�� DC��� �༮�� �����.
GDI�� BMP�� ����Ѵ�(�ȼ� ���� ��ȭ�� ����, �̹��� ������ X)(������ ������ ����)
�׸�ŭ �뷮�� Ŀ����.
RGBA���� A(alpha)�� ���� -> ������ �ȵ���.(ȸ���� ���뽺����?)
alpha�� �ȼ��� ������ �ǹ��Ѵ�.(0~255)
alpha�� �߰��� GDI+�� ����, Direct 2D ������ �̾�����.
*/
#pragma endregion

#pragma region ���ڿ� �Լ�
/*
    (��Ƽ����Ʈ)(�����ڵ�)  (�ڵ�)
    strlen  -> wcslen -> _tcslen    -> ���ڿ� ����
    strcpy  -> wcscpy -> _tcscpy    -> ���ڿ� ����
    strcmp  -> ....                 -> ���ڿ� ��
    strcat  -> ....                 -> ���ڿ� ��ġ��
    strtok  -> ....                 -> ���ڿ� ��ũ����¡(�ڸ���)
    strchr  -> ....                 -> ���� ã��
    strstr  -> ....                 -> �κ� ���ڿ� ã��

    - strlen() �Ҵ���� �޸𸮿� ���ε� �� ���ڿ����� NULL���� ������ ���ڿ� ����
*/
#pragma endregion

#pragma region Windowâ
/*
 [���� ����]
- �ν��Ͻ�
    - ������ OS�� ���� ����ǰ� �ִ� ���α׷��� Ȯ���ϱ� ���� ��
    - ���� ���α׷��̸� �Ϲ������� ���� �ν��Ͻ� ���� ������.
    - Ŭ������ �޸𸮿� ������ ������ ��ü
    - ����ǰ� �ִ� ������ ���α׷���
    EX) HINSTANCE _hInstance;

- �ڵ� : ������ â
    EX) HWND _hWnd;

- ������ Ÿ��Ʋ
    EX) LPTSTR _lpszClass = TEXT("Windows API");

- �ݹ� �Լ�(WndProc)
    ?

[������(WinMain)]
    hInstance : ���α׷� �ν��Ͻ� �ڵ�
    hPrevInstance : ������ ����� �ν��Ͻ� �ڵ�
    lpszCmdParam :��������� ���޵� ���α׷� ���� ��
    nCmdShow : ���α׷��� ���۵� ���� (�ּ�ȭ / ���� ũ�� ���,,)

    _twWinMain <- ��ũ�η� �ڵ�ó��

    int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)

    1. ������â ����ü ���� �� �ʱ�ȭ
    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;//Class�� ���� ���� �޸�
    wndClass.cbWndExtra = 0;//Window�� ���� ���� �޸�
    wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH)); //�ڵ� ����̽� ���ؽ�Ʈ�� ���� �귯��(���� ����)
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ�� �ҷ�����(Ŀ�� ������ ����)
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);// MAKEINTRESOURCE <- �ܺο��� �������ڴ�. â ���� ����� ������
    wndClass.hInstance = hInstance;//������ �ĺ��� ����
    wndClass.lpfnWndProc = (WNDPROC)WndProc;//long pointer functional number�̰� ���ν����� �ϳ���� 0������ �ڵ� mapping //������ ���ν���
    wndClass.lpszClassName = _lpszClass;//Ŭ���� �̸�
    wndClass.lpszMenuName = NULL;//�޴� �̸�
    wndClass.style = CS_HREDRAW | CS_VREDRAW;//�޴�����(�ּ�ȭ, �Ϲ�ũ��, ����) / ������ ��Ÿ��

    2. ������ Ŭ���� ���
    RegisterClass(&wndClass);

    3. ȭ�鿡 ������ ������â ����
    _hWnd = CreateWindow
    (
        _lpszClass,//������ Ŭ���� �ĺ���
        _lpszClass,//������ Ÿ��Ʋ �� �̸�
        WS_OVERLAPPEDWINDOW,//������ ��Ÿ��
        400,//������ ȭ�� x��ǥ
        100,//������ ȭ�� y��ǥ
        800,//â ����ũ��
        800,//â ����ũ��
        NULL,//�θ� ������ -> â�� ������ �Ѵ� ��� ���ʿ� �θ� ��� �༮, �ڽ� ������� �̾��� �ڽ� �����쿡 �ν��Ͻ��� �־��ָ� ���� / NULL, GetDesktopWindow() ��
        (HMENU)NULL,//�޴� �ڵ�
        hInstance,//�ν��Ͻ� ����
        NULL//�������� �ڽ� �����츦 �����ϸ� ���� / NULL
    );

    4. ȭ�鿡 ������â�� nCmdShow�� �����ؼ� ����
    ShowWindow(_hWnd, nCmdShow);
    UpdateWindow(_hWnd);

    �ڡڡڡڡ� �������� �ڡڡڡڡ�
    5. �⺻ �޽��� ����
    TranslateMessage : Ű������ �Է� �޼��� ó���� ����Ѵ�. �Էµ� Ű�� ���� Ű���� Ȯ���ϰ� �빮�� Ȥ�� �ҹ���, �ѱ�, ���������� ���� WM_CHAR �޽����� �߻���Ų��.
    DispatchMessage : ������ ���ν������� ���޵� �޼����� ���� ������� �����Ѵ�.

    EX)
    MSG message;
    ZeroMemory(&message, sizeof(message)); //�޼��� �ʱ�ȭ

    while (GetMessage(&message, 0, 0, 0))
    {
        //if (!TranslateAccelerator(message.hwnd, hAccelTable, &message))//�õ��ڵ�, ���ø����̼��� ��쿡�� �ʿ���
        //{
        TranslateMessage(&message);
        DispatchMessage(&message);
        //}
    }

[������ ���ν���(WndProc)]
hWnd : ��� �����쿡�� �߻��� �޼������� �����ϴ� �뵵
iMessage : �޼��� ���� ��ȣ
wParam : unsigned int ���콺 ��ư ���� / Ű���� ����Ű�� ���� ����
lParam : unsigned long ���콺 Ŭ�� ��ǥ�� ����


Window Procedure

- �޼����� �ü���� ���� -> �ü���� ������ ȣ���� �ȴ�.
    - WinMain�� �ƴ� �ü���� ���� ȣ���� �Ǵ� �ݹ� �Լ���� �� �� �ִ�.
    - �����츦 �����Ҷ��� �ݵ�� ������ ���־�� �Ѵ�.

- ������ ���ν��� ���ο����� �����쿡�� �߻��� ��� �޼����� ó���ϴ� ���� �ƴ϶�, Ư�� �޼������� ó���ϰ� ������ �޼����� DefWindowProc �Լ��� ó���ϵ��� ������ �����ϴ°��� �Ϲ���

EX)
    LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    char str[] = "������";

    //�������̸� RECT �������̸� FAR *LPRECT; 
    //������ SX,SY(L,T) / ���� EX,EY(R,B)�� �����Ѵ�.
    RECT rc = { 100,100,200,200 };

    switch (iMessage)
    {
    case WM_CREATE:
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        //Paint things

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_LBUTTONDOWN:
        break;

    case WM_RBUTTONDOWN:
        break;

    case WM_KEYDOWN:
        break;

    case WM_DESTROY:
        //PostQuitMessage : �޼��� ť�� QUIT �޼����� ������ ������ ����
        //Quit �޼����� �����ϴ� ���� GetMessage�� FALSE�� ��ȯ�ϹǷ� �޼��� ������ ����ȴ�.
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
*/
#pragma endregion

#pragma region GetMessage vs PeekMessage
/*
GetMessage : �޽����� ������ �� ���������� ���
    - �޼��� ť�κ��� �ϳ��� �޼����� �������� ������ �����Ѵ�.
    - �ٸ�, �޼��� ť�� ������� ��� �޼����� ���ö����� ���

    EX)
        if (!TranslateAccelerator(message.hwnd, hAccelTable, &message))//�õ��ڵ�, ���ø����̼��� ��쿡�� �ʿ���
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

PeekMessage : �޽����� ������ ��ȯ�� �ȴ�.
    - ���ػ� ������ ������ �ʿ���.
    - API ���� �����ϱ� ���� �����ؾ��ϴ°�. �������� ������ �Ǿ��ִ�.
    - ���� timer�� update�� ���ؼ� �������־����. �𸮾󿡼��� tick���� �����Ǿ�����.

    EX)
        while (true)
        {
            if (PeekMessage(&message,NULL,0,0,PM_REMOVE))
            {
                if (message.message == WM_QUIT) break;
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
        }
*/
#pragma endregion

#pragma region ������ �޼���
/*
    WM_CREATE
    - �������� ����
    
    WM_PAINT
    - �����츦 �ٽ� �׷��� �Ҷ� �߻��ϴ� �޼���
        - �����찡 ó�� ���������
        - ������ ũ�⸦ �����Ҷ�
        - �����찡 �ٸ� �����쿡 �������ٰ� �ٽ� ���϶�
        - ���� �Լ��� ȣ��ɶ�
    - ��¿� ���� ������ ����Ѵ�. (����, �׸�, ���� ��� ȭ�鿡 ���̴� ����)

    WM_LBUTTONDOWN
    - ��Ŭ���� �߻��ϴ� �޼���

    WM_RBUTTONDOWN
    - ��Ŭ���� �߻��ϴ� �޼���

    WM_KEYDOWN
    - Ű���� �Է½� �߻��ϴ� �޼���
    EX)
        switch (wParam)
        {
        case VK_LEFT://���� ����Ű
            break;
        case VK_RIGHT://������ ����Ű
            break;
        case VK_ESCAPE://ESCŰ
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }

    WM_DESTROY
    - ���Ḧ ���� �߻��ϴ� �޼���
    - PostQuitMessage : �޼��� ť�� QUIT �޼����� ������ ������ ����
    - Quit �޼����� �����ϴ� ���� GetMessage�� FALSE�� ��ȯ�ϹǷ� �޼��� ������ ����ȴ�.
*/
#pragma endregion

#pragma region API�׸��� �Լ�
/*
SetPixel(hdc, 300, 200, RGB(255, 0, 0));

�� �׸���
Ellipse(hdc, 300, 100, 200, 200);

�簢�� �׸���
Rectangle(hdc, 100, 100, 200, 200);
Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

�ٰ���,�ﰢ�� �׸���
POINT num[3] = { (100,100),(50,50),(300,300) };
Polygon(hdc, num, 3);

���ڿ� ���
SetTextColor(hdc, RGB(255, 0, 0));//RGB�� �÷� ���۷���
TextOut(hdc, 300, 400, "�� ���� ������ �ʿ��ϴ�", strlen("�� ���� ������ �ʿ��ϴ�"));

���׸���
MoveToEx(hdc, 400, 400, NULL);
LineTo(hdc, 200, 400);
*/
#pragma endregion

#pragma region WinAPI ����ü
/*
[RECT ����ü]
�������̸� RECT �������̸� FAR *LPRECT;
������ SX,SY(L,T) / ���� EX,EY(R,B)�� �����Ѵ�.

[MSG ����ü]
�ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
*/
#pragma endregion

#pragma region UpdateWindow
/*
����صѰ�
UpdateWindow(_hWnd);
*/
#pragma endregion

#pragma region 08/28 ����
/*
Ÿ�Ӿ���. ������ â �����
- �ð��� 10��

���� ����.
- ��Ʈ�� ����ð�(+ ����)
- CALLBACK Function, DC, GetDC / ReleaseDC, BeginPaint / EndPaint, WM_PAINT, PAINTSTRUCT�� ���� ����
*/
#pragma endregion

#pragma region 08/29 ����
/*
���� ����.
- strnlen(),strlen_s() -> ?
- 4�빮�ڿ� + 1
- char[]�� char*�� ����
- ��ǥ���(WinAPI �»��, DX ���ϴ�, MAX/Maya ����, OpenGL/Vulkan ���ϴ�) -> ����� ���ٸ� ���� �»��(������ ��ǥ��). ������ ��ǥ��� ��ī��Ʈ��ǥ��

���� ����.
- SetTimer / KillTimer
- InvalidateRect

����1. WinAPI ���

- MoveToEX() + LineTo()�� �̿��Ұ�
- �ڱ��̸� ���(�ѱ۷�) + UnrealEngine (����)
    -ũ��� 800 X 800���� ȭ�鿡 ������ ä��� ũ��� ����Ұ�
- ���콺 ������ ������ �ѱ��ھ� ����� �ǰ� Ŭ���� �ϸ� �ѱ��ھ� ��������.(�̸����� ����)
- �������� �Լ� ��� ����


����2. ������
- ����ó�� �ʼ�
    - �������� ����(1������ X / 9�� �̻� x);
- ���콺 ���� Ŭ���� ������ 1�ܾ� ����� �ǰ� ��Ŭ���� �ϸ� 1�ܾ� ��������.
- �׸��� 3�ܰ� ���� ������ �Ѵ�.


(�ݿ��ϱ���)����3. ���� �ΰ� ���
- SetPixel()�� �̿��ؼ� �����.
- �ټ� OK, �ݺ��� OK, �ļ� X
*/
#pragma endregion 