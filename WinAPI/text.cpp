#pragma region WinAPI
/*
▶ API(Application Programming Interface)

- 운영체제가 응용프로그램 개발을 위해 제공하는 함수의 집합이라고 할 수 있다.

- 명령어의 집합으로 어플리케이션 프로그램에서 오퍼레이팅 시스템의 기본적인 기능을 사용할 필요가 있을 경우 API에서 명령어 로출이 진행된다.

- 어셈블리어 기반이 아니라 장치관리자 단에서 처리가 되는 녀석
-> 윈도우에게 자원을 사용할 수 있게끔 함수 형태로 달라는 요청을 운영체제에게 보냄

EX)
하드웨어 ----------------- 운영체제(Windows) ----------------- 응용 프로그램
(API 함수)

● 장점
 - 운영체제가 같으면 같은 기능의 집합을 사용하기에 확장성 및 연동성 / 그리고 유지보수에 매우 유리하다.
	- 윈도우즈 != 리눅스

● 단점
- 사용하는 프로그래머의 역량에 따라 플랫폼에 대한 고착화가 발생할 수 있다. (WinAPI)
	- C언어로 개발된 플랫폼의 한계점을 극복하지 못한다는 프로그래머의 모순
	- 이는 대부분 타 라이브러리 확장으로 해결은 되지만, 프로그래머의 역량을 많이 요구하기 때문에 이는 사람 입장에서는 단점이라고 할 수 있다.


▷ API 구조
- 크게 3가지만 기억하면 OK
- 진입점 / 루프 (메세지) / Window Procedure

*/
#pragma endregion

#pragma region tchar
/*
LPSTR   -> char*
LPCSTR  -> const char*
LPCTSTR -> const tchar*

▶ TCHAR
- 이 자료형은 프로젝트 문자셋 설정에 따라 자동적으로 변환을 해주는 중간 매크로 자료형
	- Type Casting을 유발하며 char 또는 wchar_t로 변환한다.

- 멀티와 유니 환경에서 별도의 수정작업 없이 프로그램을 구동하기 위해서는 TCHAR형으로 문자열을 표현하는 것을 권장한다.

- 원도우 어플리케이션을 사용하는 프로그램부터는 응용프로그램에서 문자열 상수를 쓰기 위해서는 중간 설정에 따라 char*-> wchar_t*로 변환을 해주는 _T 매크로도 유효하다.

EX)
LPCSTR script1 = "ABC";
LPCWSTR script2 = L"ABC";//유니코드 문자열이라고 L을 붙혀줌
TCHAR* script2 = _T("ABC");

*/
#pragma endregion

#pragma region 준수 모드
/*
Visual Studio 17에서 추가된 녀석
문자열에서는 확인된 주소에 한해서만 포인터 사용이 가능하다.
사용하지 않고 싶다면 const를 붙혀주면 가능함. 단, API에서는 추가적인 자료형을 붙히는걸 권장하지 않음.

*/
#pragma endregion

#pragma region API와 BMP
/*
★★★★★ 면접질문 ★★★★★
API는 GDI(그래픽 디바이스 인터페이스)중 DC라는 녀석을 사용함.
GDI는 BMP를 사용한다(픽셀 단위 열화가 없음, 이미지 압축이 X)(강렬한 색상의 전달)
그만큼 용량이 커진다.
RGBA에서 A(alpha)가 없다 -> 보간이 안들어간다.(회전이 고통스럽다?)
alpha는 픽셀의 투명도를 의미한다.(0~255)
alpha가 추가된 GDI+가 존재, Direct 2D 등으로 이어진다.
*/
#pragma endregion

#pragma region 문자열 함수
/*
    (멀티바이트)(유니코드)  (자동)
    strlen  -> wcslen -> _tcslen    -> 문자열 길이
    strcpy  -> wcscpy -> _tcscpy    -> 문자열 복사
    strcmp  -> ....                 -> 문자열 비교
    strcat  -> ....                 -> 문자열 합치기
    strtok  -> ....                 -> 문자열 토크나이징(자르기)
    strchr  -> ....                 -> 문자 찾기
    strstr  -> ....                 -> 부분 문자열 찾기

    - strlen() 할당받은 메모리에 바인딩 된 문자열에서 NULL값을 제외한 문자열 길이
*/
#pragma endregion

#pragma region Window창
/*
 [전역 변수]
- 인스턴스
    - 윈도우 OS가 현재 실행되고 있는 프로그램을 확인하기 위한 값
    - 같은 프로그램이면 일반적으로 같은 인스턴스 값을 가진다.
    - 클래스가 메모리에 실제로 구현된 실체
    - 실행되고 있는 각각의 프로그램들
    EX) HINSTANCE _hInstance;

- 핸들 : 윈도우 창
    EX) HWND _hWnd;

- 윈도우 타이틀
    EX) LPTSTR _lpszClass = TEXT("Windows API");

- 콜백 함수(WndProc)
    ?

[진입점(WinMain)]
    hInstance : 프로그램 인스턴스 핸들
    hPrevInstance : 이전에 실행된 인스턴스 핸들
    lpszCmdParam :명령형으로 전달된 프로그램 인자 수
    nCmdShow : 프로그램이 시작될 형태 (최소화 / 보통 크기 등등,,)

    _twWinMain <- 매크로로 자동처리

    int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)

    1. 윈도우창 구조체 선언 및 초기화
    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;//Class에 대한 여분 메모리
    wndClass.cbWndExtra = 0;//Window에 대한 여분 메모리
    wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH)); //핸들 디바이스 컨텍스트에 대한 브러쉬(배경색 지정)
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//커서 불러오기(커서 아이콘 변경)
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);// MAKEINTRESOURCE <- 외부에서 가져오겠다. 창 좌측 상단의 아이콘
    wndClass.hInstance = hInstance;//소유한 식별자 정보
    wndClass.lpfnWndProc = (WNDPROC)WndProc;//long pointer functional number이고 프로시저가 하나라면 0번으로 자동 mapping //윈도우 프로시저
    wndClass.lpszClassName = _lpszClass;//클래스 이름
    wndClass.lpszMenuName = NULL;//메뉴 이름
    wndClass.style = CS_HREDRAW | CS_VREDRAW;//메뉴상자(최소화, 일반크기, 종료) / 윈도우 스타일

    2. 윈도우 클래스 등록
    RegisterClass(&wndClass);

    3. 화면에 보여줄 윈도우창 생성
    _hWnd = CreateWindow
    (
        _lpszClass,//윈도우 클래스 식별자
        _lpszClass,//윈도우 타이틀 바 이름
        WS_OVERLAPPEDWINDOW,//윈도우 스타일
        400,//윈도우 화면 x좌표
        100,//윈도우 화면 y좌표
        800,//창 가로크기
        800,//창 세로크기
        NULL,//부모 윈도우 -> 창을 여러개 켜는 경우 최초에 부모를 잡는 녀석, 자식 윈도우와 이어짐 자식 윈도우에 인스턴스를 넣어주면 동작 / NULL, GetDesktopWindow() 등
        (HMENU)NULL,//메뉴 핸들
        hInstance,//인스턴스 지정
        NULL//윈도우의 자식 윈도우를 생성하면 지정 / NULL
    );

    4. 화면에 윈도우창을 nCmdShow와 연동해서 띄우기
    ShowWindow(_hWnd, nCmdShow);
    UpdateWindow(_hWnd);

    ★★★★★ 면접질문 ★★★★★
    5. 기본 메시지 루프
    TranslateMessage : 키보드의 입력 메세지 처리를 담당한다. 입력된 키가 문자 키인지 확인하고 대문자 혹은 소문자, 한글, 영문인지에 대한 WM_CHAR 메시지를 발생시킨다.
    DispatchMessage : 윈도우 프로시저에서 전달된 메세지를 실제 윈도우로 전달한다.

    EX)
    MSG message;
    ZeroMemory(&message, sizeof(message)); //메세지 초기화

    while (GetMessage(&message, 0, 0, 0))
    {
        //if (!TranslateAccelerator(message.hwnd, hAccelTable, &message))//시동코드, 어플리케이션의 경우에는 필요함
        //{
        TranslateMessage(&message);
        DispatchMessage(&message);
        //}
    }

[윈도우 프로시저(WndProc)]
hWnd : 어느 윈도우에서 발생한 메세지인지 구분하는 용도
iMessage : 메세지 구분 번호
wParam : unsigned int 마우스 버튼 상태 / 키보드 조합키의 상태 전달
lParam : unsigned long 마우스 클릭 좌표를 전달


Window Procedure

- 메세지를 운영체제에 전달 -> 운영체제는 강제로 호출이 된다.
    - WinMain이 아닌 운영체제에 의해 호출이 되는 콜백 함수라고 할 수 있다.
    - 윈도우를 생성할때는 반드시 지정을 해주어야 한다.

- 윈도우 프로시저 내부에서는 윈도우에서 발생한 모든 메세지를 처리하는 것이 아니라, 특정 메세지만을 처리하고 나머지 메세지는 DefWindowProc 함수가 처리하도록 로직을 설계하는것이 일반적

EX)
    LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    char str[] = "오케이";

    //고정적이면 RECT 가변적이면 FAR *LPRECT; 
    //시작점 SX,SY(L,T) / 끝점 EX,EY(R,B)가 존재한다.
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
        //PostQuitMessage : 메세지 큐에 QUIT 메세지를 보내는 역할을 수행
        //Quit 메세지를 수신하는 순간 GetMessage가 FALSE를 반환하므로 메세지 루프는 종료된다.
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
*/
#pragma endregion

#pragma region GetMessage vs PeekMessage
/*
GetMessage : 메시지를 꺼내올 수 있을때까지 대기
    - 메세지 큐로부터 하나의 메세지를 가져오는 역할을 수행한다.
    - 다만, 메세지 큐가 비어있을 경우 메세지가 들어올때까지 대시

    EX)
        if (!TranslateAccelerator(message.hwnd, hAccelTable, &message))//시동코드, 어플리케이션의 경우에는 필요함
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

PeekMessage : 메시지가 없더라도 반환이 된다.
    - 고해상도 진동의 개념이 필요함.
    - API 에는 없으니까 직접 구현해야하는것. 엔진에는 구현이 되어있다.
    - 고성능 timer와 update를 통해서 연결해주어야함. 언리얼에서는 tick으로 구현되어있음.

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

#pragma region 윈도우 메세지
/*
    WM_CREATE
    - 생성자의 개념
    
    WM_PAINT
    - 윈도우를 다시 그려야 할때 발생하는 메세지
        - 윈도우가 처음 만들어질때
        - 윈도우 크기를 조절할때
        - 윈도우가 다른 윈도우에 가려졌다가 다시 보일때
        - 관련 함수가 호출될때
    - 출력에 관한 모든것을 담당한다. (문자, 그림, 도형 등등 화면에 보이는 모든것)

    WM_LBUTTONDOWN
    - 좌클릭시 발생하는 메세지

    WM_RBUTTONDOWN
    - 우클릭시 발생하는 메세지

    WM_KEYDOWN
    - 키보드 입력시 발생하는 메세지
    EX)
        switch (wParam)
        {
        case VK_LEFT://왼쪽 방향키
            break;
        case VK_RIGHT://오른쪽 방향키
            break;
        case VK_ESCAPE://ESC키
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }

    WM_DESTROY
    - 종료를 위해 발생하는 메세지
    - PostQuitMessage : 메세지 큐에 QUIT 메세지를 보내는 역할을 수행
    - Quit 메세지를 수신하는 순간 GetMessage가 FALSE를 반환하므로 메세지 루프는 종료된다.
*/
#pragma endregion

#pragma region API그리기 함수
/*
SetPixel(hdc, 300, 200, RGB(255, 0, 0));

원 그리기
Ellipse(hdc, 300, 100, 200, 200);

사각형 그리기
Rectangle(hdc, 100, 100, 200, 200);
Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

다각형,삼각형 그리기
POINT num[3] = { (100,100),(50,50),(300,300) };
Polygon(hdc, num, 3);

문자열 출력
SetTextColor(hdc, RGB(255, 0, 0));//RGB는 컬러 레퍼런스
TextOut(hdc, 300, 400, "더 많은 과제가 필요하다", strlen("더 많은 과제가 필요하다"));

선그리기
MoveToEx(hdc, 400, 400, NULL);
LineTo(hdc, 200, 400);
*/
#pragma endregion

#pragma region WinAPI 구조체
/*
[RECT 구조체]
고정적이면 RECT 가변적이면 FAR *LPRECT;
시작점 SX,SY(L,T) / 끝점 EX,EY(R,B)가 존재한다.

[MSG 구조체]
운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
*/
#pragma endregion

#pragma region UpdateWindow
/*
기억해둘것
UpdateWindow(_hWnd);
*/
#pragma endregion

#pragma region 08/28 과제
/*
타임어택. 윈도우 창 만들기
- 시간은 10분

한줄 조사.
- 노트에 적어올것(+ 공부)
- CALLBACK Function, DC, GetDC / ReleaseDC, BeginPaint / EndPaint, WM_PAINT, PAINTSTRUCT에 대해 조사
*/
#pragma endregion

#pragma region 08/29 과제
/*
개인 조사.
- strnlen(),strlen_s() -> ?
- 4대문자열 + 1
- char[]와 char*의 차이
- 좌표방식(WinAPI 좌상단, DX 좌하단, MAX/Maya 우상단, OpenGL/Vulkan 우하단) -> 언급이 없다면 보통 좌상단(윈도우 좌표계). 수학적 좌표계는 데카르트좌표계

한줄 조사.
- SetTimer / KillTimer
- InvalidateRect

과제1. WinAPI 출력

- MoveToEX() + LineTo()를 이용할것
- 자기이름 출력(한글로) + UnrealEngine (영문)
    -크기는 800 X 800기준 화면에 절반을 채우는 크기로 양분할것
- 마우스 왼쪽을 누르면 한글자씩 출력이 되고 클릭을 하면 한글자씩 지워진다.(이름에만 적용)
- 도형관련 함수 사용 금지


과제2. 구구단
- 예외처리 필수
    - 구구단의 본질(1단이하 X / 9단 이상 x);
- 마우스 왼쪽 클릭을 했을시 1단씩 출력이 되고 우클릭을 하면 1단씩 지워진다.
- 그리고 3단계 마다 개행을 한다.


(금요일까지)과제3. 애플 로고 출력
- SetPixel()을 이용해서 만든다.
- 근성 OK, 반복문 OK, 꼼수 X
*/
#pragma endregion 