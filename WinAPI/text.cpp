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
API(Application Programming Interface)는 GDI(Graphic Device Interface)중 DC(Device Context)라는 녀석을 사용함.
GDI는 BMP(Bitmap)를 사용한다(픽셀 단위 열화가 없음, 이미지 압축이 X)(강렬한 색상의 전달)
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

    strnlen(),strlen_s()
    - 주어진 문자열의 길이를 최대 maxlen까지 검사.
    - 길이를 계산하지만 문자열이 종료되지 않은 경우 버퍼의 끝까지 진행하지 않음.
    - 알려진 버퍼 크기로 들어오는 신뢰할 수 없는 데이터의 크기를 계산하는 경우 사용.
    - strnlen 및 strnlen_s는 싱글바이트 문자열로 문자열을 해석하므로 문자열에 멀티바이트 문자가 포함되어 있더라도 반환 값은 항상 바이트 수와 동일
    - wcsnlen 및 wcsnlen_s는 각각 strnlen과 strnlen_s의 유니코드(wide character) 버전

    - strnlen, wcsnlen은 해당 매개 변수의 유효성을 검사하지 않음. str이 NULL인 경우 액세스 위반이 발생
    - strnlen_s, wcsnlen_s는 자신의 매개 변수에 대한 유효성을 검사함. str이 NULL인 경우 함수는 0을 반환.
*/
#pragma endregion

#pragma region WinMain, WndProc
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
    LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

- 클라이언트 크기 지정 함수
    void setWindowSize(int x, int y, int width, int height);

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

    static POINT pt = { 0,0 };
    char strPT[128];

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

        wsprintf(strPT, "X: %d       Y: %d", pt.x, pt.y);//숫자를 문자열로 출력할때(변환)
        TextOut(hdc, 10, 10, strPT, strlen(strPT));

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_MOUSEMOVE:
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);

        //#include<windowsx.h>
        //pt.x = GET_X_LPARAM(lParam);
        //pt.y = GET_Y_LPARAM(lParam);

        InvalidateRect(hWnd, NULL, true);
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

void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0,width,height };

    //실제 윈도우 크기 조정
    //AdjustWindowRect(): RECT구조체, 윈도우 스타일, 메뉴 여부
    AdjustWindowRect(&rc, WINSTYLE, false);

    //RECT의 정보로 윈도우 사이즈 세팅
    SetWindowPos(_hWnd, NULL,       //핸들, 부모 윈도우
        x, y,                       //좌표
        (rc.right - rc.left),       //cx
        (rc.bottom - rc.top),       //cy
        SWP_NOZORDER | SWP_NOMOVE); //2D에서 클리핑, 3D에서는 컬링 'ZORDER는 렌더링 우선순위' NO이므로 가려지면 그냥 출력 안하겠다는 의미. NOMOVE는 해상도에 따른 위치변경을 적용하지 않겠다.
}
*/
#pragma endregion

#pragma region GetMessage vs PeekMessage
/*
GetMessage : 메시지를 꺼내올 수 있을때까지 대기
    - 메세지 큐로부터 하나의 메세지를 가져오는 역할을 수행한다.
    - 다만, 메세지 큐가 비어있을 경우 메세지가 들어올때까지 대기

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

    WM_MOUSEMOVE
    - 마우스가 움직일때 발생하는 메세지

    WM_LBUTTONDOWN
    - 좌클릭시 발생하는 메세지

    WM_RBUTTONDOWN
    - 우클릭시 발생하는 메세지

    WM_KEYDOWN
    - 키보드 입력시 발생하는 메세지
    - wParam에 문자 코드가 아닌 가상 키코드라는 것을 전달
    - 가상키코드(Virtual Key Code)란 시스템에 장착된 키보드의 종류에 상관없이 키를 입력받기 위해 만들어진 코드값
    - 숫자 및 영문자의 가상 키코드는 아스키 코드와 동일
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

호 그리기
Arc(hdc, 200, 100, 600, 700, 230, 200, 570, 200);//경계 사각형의 left,top,right,bottom 호의 시작점 x,y 끝점 x,y

사각형 그리기
Rectangle(hdc, 100, 100, 200, 200);
Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

다각형,삼각형 그리기
POINT num[3] = { (100,100),(50,50),(300,300) };
Polygon(hdc, num, 3);

문자열 출력
SetTextColor(hdc, RGB(255, 0, 0));//RGB는 컬러 레퍼런스
TextOut(hdc, 300, 400, "더 많은 과제가 필요하다", strlen("더 많은 과제가 필요하다"));

선 그리기
MoveToEx(hdc, 400, 400, NULL);
LineTo(hdc, 200, 400);

여러개의 베지어 곡선 그리기
POINT BezierLine[4] = {{ 100,100 },{ 150,50 },{ 200,50 },{ 250,100 }};//시작점, 조절점1, 조절점2, 끝점
PolyBezier(hdc, BezierLine, 4);// n개의 곡선을 그리기 위해서는 1 + 3*n 개의 점이 필요(두번째 부터는 이전 곡선의 끝점이 곧 시작점)
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

#pragma region UpdateWindow / InvalidateRect
/*
InvalidateRect는 무효화 영역을 설정하여 화면을 갱신하는 WM_PAINT를 발생시키는 함수
UpdateWindow는 갱신할 영역이 있으면 시스템의 상태와 상관없이 즉각 갱신하는 함수(즉, WM_PAINT를 즉각 처리하는 함수)
UpdateWindow는 WM_PAINT를 발생시키는 것이 아님에 주의. 시스템 부하의 경우 WM_PAINT의 처리가 늦어질 수 있는데, 이와 무관하게 갱신하기 위함
단, 당연히 너무 자주 사용시 시스템에 부담을 주게 됨.

EX)
InvalidateRect(_hWnd, NULL, true);//갱신할 창의 핸들, 갱신할 RECT(NULL의 경우 화면 전체), 화면을 지우고 갱신할 것인지 여부
UpdateWindow(_hWnd);// WM_PAINT 즉각 처리
*/
#pragma endregion

#pragma region PCH
/*
- 설계의 영역
- C/C++에서는 필수적 but 언리얼에서는 사용하지 않음(가능은 하나 매우 까다로움)
- C++ 은 컴파일이 매우 느린데, 이걸 완화해 주는것이 pch임.
- 언리얼의 경우 언리얼의 코어,모듈에 대해서 많이 알고 깊은 이해가 필요함.
- 미리 컴파일된 헤더파일 -> 메모리를 차지하고 시작하므로 메모리를 죽이고 편의성을 챙긴다!
- 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSence 성능에도 영향을 미침.
*/
#pragma endregion

#pragma region 디버그 모드
/*
VS의 디버그 모드는 정상 작동은 하지만 논리적으로 뭔가 오류가 있을 경우에 사용하는 것.
또한 최소한 CPU 레지스터 등을 볼 수 있어야 활용이 가능하다는 것.
값의 확인을 위해서는 변수와 출력문 등을 쓸것.
언리얼의 경우에는 매우 불편함(다 끄고 디버깅 모드로 다시 켜야함.)

디버그 모드로 실행시 디버깅 심볼을 위해 전처리기가 처리해야할 부분을 컴파일러가 처리하기 시작.
*/
#pragma endregion 

#pragma region malloc VS new
/*
둘다 메모리 동적 할당이지만 클래스 인스턴스의 생성자 호출여부가 가장 큰 차이일것.

malloc 함수
- 정해진 메모리 크기만큼의 공간을 할당받을 뿐 용도는 정해지지 않음(void*반환)
- 할당과 동시에 초기값을 지정해줄 수 없음.
- POD가 아닌 경우에 대한 사용은 정의되지 않은 동작임.
- realloc을 통해 재할당이 가능 즉 ,POD이면서 재할당이 빈번한 경우라면 malloc과 free가 더 좋은 경우가 됨.

new 연산자
- 알아서 할당할 타입과 같은 타입의 포인터로 반환되며, 생성자를 자동으로 호출.
- 할당과 동시에 초기화가 가능.
- 재할당 함수가 없으므로 할당 -> 복사 -> 해제의 과정을 거쳐야함.
- 객체의 경우 반드시 new와 delete를 사용해서 할당 및 해제를 해주어야함.(생성자와 소멸자 호출)
*/
#pragma endregion

#pragma region POD(Plain Old Data)
/*
- 연속된 메모리를 가진 자료형
- C와 호환이 가능한 타입
- char, int float, double등의 value타입과 배열 및 포인터 등등
- 변수로만 이루어진 구조체나 클래스의 경우에는 POD타입.(trivial객체인 경우)
※ 트리비얼(trivial) : 사용자가 정의하지 않은 경우의 기본 동작
※ 트리비얼 객체 : 생성자, 소멸자, 복사 생성자, 이동 생성자, 복사 대입 연산자, 이동 대입 연산자와 같은 특수 멤버 함수가 자동으로 생성된 객체(사용자 정의 X)
EX)
    MyClass() { 생성자 코드 } // default 생성자(매개변수가 없는 생성자)
    MyClass() = default;  // trivial 생성자
*/
#pragma endregion

#pragma region static / extern
/*
▶ static / extern
- 저장 클래스(저장 지시자)
    ▷ [static]
        - 전역 변수에 사용될 때 -> 해당 파일 내에서만 접근 가능. 즉, 접근 범위가 파일 범위로 제한.
        - 지역 변수에 사용될 때 -> 함수 호출 간에도 값을 유지. 즉, 호출될 때마다 변수를 초기화하지 않고 이전 값을 유지.
        - 함수에 사용될 때 -> 정의된 파일 내에서만 호출 가능.

    ▷ [extern]
        - 전역 변수에 사용될 때 -> 변수가 다른 파일에서 정의되었음을 명시.
        - 함수에 사용될 때 -> 함수가 다른 파일에서 정의되었음 명시. 함수 선언은 기본적으로 extern임.

    ※ static의 경우 선언에 사용되고 extern의 경우 정의가 다른 파일에 있음을 명시하는데에 사용. extern은 참조만 제공.
*/
#pragma endregion

#pragma region define / constexpr / const
/*
▶ define / constexpr / const
    ▷ #define (매크로)
        - 전처리기 단계에서 텍스트 치환으로 처리.
        - 타입 검사가 없음.

    ▷ constexpr (컴파일타임 상수)
        - constant expression의 약자
        - 컴파일 타임 상수,함수 정의.
        - 컴파일 타임에 상수 값을 계산할 수 있는 변수를 선언하거나 함수의 결과를 컴파일 타임에 계산할 때 사용
        - 타입 검사 수행

    ▷ const (런타임 상수)
        - constant의 약자
        - 런타임 상수 정의.
        - 컴파일 타임 상수로 사용될 수 있는 경우도 있지만, 명시적으로 컴파일 타임 상수를 보장하지는 않음.
        - 값이 변경되지 않는 변수를 선언할 때 사용
        - 런타임에 초기화 될 수 있음.
*/
#pragma endregion

#pragma region 숫자 -> 문자열 변환(sprintf, itoa)
/*
▷ sprintf
    EX)
        sprintf(buffer, "Integer: %d", number);

▷ itoa
    - 비표준 함수
    EX)
        itoa(number, buffer, 10);//10진수로 변환
        itoa(number, buffer, 16);//16진수로 변환
*/
#pragma endregion

#pragma region char[]와 char*
/*
char str[] = "Test";
char *str = "Test"; //C++11부터 const char *str = "Test";로 사용해야함.

▷ str[]
- 배열의 크기는 문자열 리터럴의 길이에 따라 자동으로 결정
- 배열의 각 요소를 직접 수정 가능.(자신의 내용을 소유)
- 배열의 크기는 정의된 시점에서 고정
- sizeof(str)을 통해 배열의 전체 크기를 알 수 있음

▷ *str
- 상수 문자열에 대한 포인터
- 포인터가 가리키는 문자열은 데이터 영역의 읽기 전용 영역에 저장됨. (문자열의 내용을 참조, 수정 불가)
- 문자열의 크기를 알 수 없으므로, strlen과 같은 함수를 사용하여 동적으로 측정해야함.
*/
#pragma endregion 

#pragma region RedBlackTree(map)
/*
▶ RedBlackTree
    - 자가 균형 이진 탐색 트리

    ▷ 주요 규칙
        - 모든 노드는 빨간색 혹은 검은색이다.
        - 루트 노드는 검은색이다.
        - 모든 리프노드(NIL)은 검은색이다. (NIL : null leaf)
        - 빨간색 노드의 자식은 검은색이다. (No Double Red)
        - 모든 리프노드에서 Black Depth는 같다. (리프노드에서 루트노드까지의 경로중 검은색 노드의 수는 항상 동일)

    ▷ 삽입 연산
        1. 새로운 노드는 항상 빨간색 노드이다.
        2. 삽입 후 Double Red 발생시 삼촌노드가 검은색이면 Restructuring, 빨간색이면 Recoloring으로 처리한다.

    ▷ 삭제 연산
        1. 자식 노드가 하나인 경우에는 해당 노드로 대체한다.
        2. 둘인 경우에는 삭제할 노드의 오른쪽 서브트리에서 가장 작은 노드를 찾아 해당 노드로 삭제할 노드를 대체한다.
        3. Double Red 발생시 삼촌노드가 검은색이면 Restructuring, 빨간색이면 Recoloring으로 처리한다.

    ▷ Restructuring
        1. 새로운 노드(N), 부모노드(P), 조상노드(G)를 오름차순 정렬
        2. 셋 중 중간값을 부모로 만들고 나머지 둘을 자식노드로 한다.
        3. 새로운 부모가 빨간색, 나머지 자식노드는 검은색이 된다.

    ▷ Recoloring
        1. 새로운 노드(N)의 부모(P)와 삼촌(U)을 검은색으로, 조상(G)를 빨간색으로 바꾼다
        2. G가 루트 노드라면 검은색으로 바꾼다
        3. G를 빨간색으로 바꾸었을때 DoubleRed가 다시 발생하면 Restructuring과 Recoloring을 반복한다.
*/
#pragma endregion

#pragma region 해시 자료구조(unordered map)
/*
- 해시 함수를 통해 키의 해시값을 계산하여 해당 값을 해시 테이블의 인덱스로 사용.
- 해시 테이블은 여러개의 버킷으로 구성된 배열을 사용.
- 버킷은 원소를 저장할 수 있는 연결리스트를 포함.
- 해시 충돌 발생시 해당 버킷의 리스트에 추가됨.(체이닝 방식)
- 이후 접근 시도시 해당 버킷의 리스트를 순회하며 키를 확인하고 끝까지 탐색했는데 찾지 못했으면 없는것으로 간주
*/
#pragma endregion

#pragma region 선형과 비선형 자료구조
/*
▶ 선형 자료구조
    ▷ 장점
        - 구현이 간단함.
        - 배열기반의 자료구조의 경우 인덱스를 통한 빠른 접근이 가능.
        - 정렬 및 검색이 간단.
        - 구조가 단순.

    ▷ 단점
        - 배열 기반의 자료구조의 경우 삽입과 삭제가 비효율적
        - 연결 리스트의 경우 노드를 사용하기 때문에 메모리 오버헤드가 발생
        - 복잡한 데이터 관계 표현이 불가능 ☆

▶ 비선형 자료구조
    ▷ 장점
        - 복잡한 관계 표현이 가능 ☆
        - 탐색 및 검색이 효율적

    ▷ 단점
        - 구현이 복잡함.
        - 노드로 인한 메모리 오버헤드 발생 ☆
        - 검색이 비효율적(검색을 위한 별도의 알고리즘 필요)
        - 관리가 어려움(삽입, 삭제, 수정시 구조 수정이 되는 경우가 많음)

※ 선형 자료구조는 데이터가 순차적으로 배치되고 단순한 연산이 필요한 경우 유용.
※ 비선형 자료구조는 데이터 간의 복잡한 관계를 처리해야 하는 경우 유용.

*/
#pragma endregion

#pragma region 매니저 클래스
/*
▶ 매니저 클래스
    - 특정 기능이나 리소스를 관리하는 역할을 맡은 클래스
    - 시스템의 다른 부분과 상호작용하며, 객체의 생명주기 관리, 상태 유지, 자원 할당 및 해제 등을 담당

    ▷ 수행 기능
        - 자원 관리 : 데이터베이스 연결, 파일 핸들, 네트워크 소켓 등의 자원을 관리
        - 객체 생성 및 관리 : 객체의 생성, 초기화, 소멸 등을 관리
        - 상태 관리 : 프로그램의 상태나 설정을 유지하고 업데이트
        - 프로세스 관리 : 여러 개의 작업이나 프로세스를 관리하고 조율

    ▷ 장점
        - 구조화 : 코드를 더 모듈화하고 유지보수하기 쉽게 만듦.
        - 재사용성 : 동일한 관리 로직을 여러 곳에서 재사용 가능.
        - 캡슐화 : 자원 관리의 세부 사항을 숨기고, 외부에서는 필요한 인터페이스만 제공하여 코드의 복잡성 감소.

    ▷ 매니저 클래스의 단점
        - 복잡성 증가 : 매니저 클래스를 너무 많이 사용하면 프로그램 구조가 복잡해질 수 있음.
        - 의존성 : 매니저 클래스에 의존하게 되면, 그 클래스를 변경할 때 다른 부분에 영향을 줄 수 있음.
*/
#pragma endregion

#pragma region 구조화(OOP)
/*
- CallBack 함수인 WinProc의 경우 오류 발생시 운영체제에도 오류를 일으킬 수 있음.
- 이에 따라 이를 해결하기 위해 중간 관리자를 생성하여 프로그램 내적으로 처리가 가능하도록 클래스를 추가
- 프로시저 -> 코어(플랫폼) -> 콜백 -> 중간관리자 <- OS
*/
#pragma endregion

#pragma region 객체지향
/*
▶ 객체지향 프로그래밍 (OOP, Object Oriented Programming)
    - 기본적으로 코드의 재사용성이 높고 코드의 관리가 용이할 때가 많다.
    - 신뢰성이 높은 프로그래밍을 가능하게 하는 경우 또한 많다.

▷ 객체 지향 4대 특징
    1. 캡슐화
        - 객체의 속성을 보호하기 위해 사용

    2. 상속
        - 객체지향에서의 상속은 하위로 내려 갈수록 구체화 되는 것을 의미한다.
        - 일반적인 상속은 재사용성과 확장성이 보장되는 경우가 많기 때문에 사용 빈도가 높다.
        - 프로그램 구조에 대한 이해도를 향상시킬 수 있다.

    3. 다형성
        - 하나의 객체가 여러 형태로 변화하는 것을 의미한다.
        - 오버라이딩


    ★★
    4. 추상화
        - 공통적인 부분과 특정 특성을 분리 / 추출해 재조합과 재구성을 하는 행위를 뜻한다.
        (설계 기반인데다 상속과 다형성을 포함해야 한다)

★★★★★ 면접 질문 ★★★★★
▷ 객체 지향 5대 원칙(SOLID 원칙)
    1. Single Responsibility Principle (SRP): 단일 책임 원칙
        - 클래스는 하나의 책임만 가져야 하며, 그 책임을 완전히 캡슐화해야 한다.
        - 즉, 클래스는 하나의 기능만 수행하고, 그 기능에 대한 책임만을 가져야 한다.
        - 결합도는 낮추고 응집도는 높아지게 된다.
            - 결합도
                - 모듈간의 상호 의존 정도를 나타내는 지표라고 이해하면 좋다.
                - 결합도가 낮으면 상호 의존성이 줄어 재사용 및 유지보수에 유리하다.
            - 응집도
                - 하나의 모듈 내부에 존재하는 구성 요소들의 기능적 관련성이라고 얘기할 수 있다.
                - 응집도가 높은 모듈은 하나의 책임에 집중할 수 있고 독립성이 높아지기 때문에 재사용 및 유지보수에 유리

        ※ 상속 + 오버라이딩을 사용하면 평균이상은 간다

    2. Open/Closed Principle (OCP): 개방-폐쇄 원칙
        - 소프트웨어 모듈(클래스, 함수 등)은 확장에는 열려 있어야 하고, 수정에는 닫혀 있어야 한다.
        - 즉, 기존 코드를 수정하지 않고도 새로운 기능을 추가할 수 있어야 한다.
        - 상위 클래스 또는 인터페이스를 중간에 두어 자신의 변화에 대해서는 폐쇄하고 인터페이스는 외부의 변화에 대해 확장성을 개방한다.

    3. Liskov Substitution Principle (LSP): 리스코프 치환 원칙
        - 자식 클래스는 부모 클래스의 대체 가능해야 한다.(업 캐스팅)
        - 즉, 자식 클래스의 객체가 부모 클래스 객체를 대체해도 프로그램의 정확성이 유지되어야 한다.
        - 이는 상속 관계를 올바르게 사용하고 자식 클래스가 부모 클래스의 계약을 준수해야 함을 의미.

    4. Interface Segregation Principle (ISP): 인터페이스 분리 원칙
        - 클라이언트는 자신이 사용하지 않는 인터페이스에 의존하지 않아야 한다.
        - 즉, 하나의 커다란 인터페이스보다는 여러 개의 작은 인터페이스를 사용하는 것이 좋다.
        - 이렇게 하면 각 클라이언트가 필요한 메소드 만을 구현하고 의존하게 되어, 변경의 영향을 최소화할 수 있다.
        - 만드는 프로젝트 요구사항과 설계에 따라서 SRP / ISP 중 1개를 선택해야 하는 경우가 많이 발생한다.

    5. Dependency Inversion Principle (DIP): 의존성 역전 원칙
        - 고수준 모듈이 저수준 모듈에 의존해서는 안 되며, 두 모듈 모두 추상화에 의존해야 한다.
        - 즉, 구체적인 클래스보다 추상화된 인터페이스나 추상 클래스에 의존하도록 설계해야 한다.


*/
#pragma endregion

#pragma region 순수 가상 함수, 추상 클래스, 인터페이스, 가상 소멸자
/*
▶ 순수 가상 함수
    - 함수의 구현부가 없고 선언부가 = 0 으로 끝나는 가상함수를 의미한다.
    - 부모 클래스에서 순수 가상함수를 선언하면 자식 클래스에서는 반드시 재정의한 함수를 멤버로 가져와야 한다.

▷ 선언 예시
    - virtual void IFunctionA() = 0;
    - virtual void IFunctionB() = NULL;
    - virtual void IFunctionC() PURE;
    - virtual void IFunctionD() abstract;

▶ 추상 클래스
    - 순수 가상함수를 하나 이상 포함하고 있는 클래스를 의미한다.

▷ 선언 예시
    - C++ -> class A abstract
    - C# -> abstract class A

▷ 특징
    - 객체를 생성할 수 없다.
    - 포인터 변수는 만들 수 있다.
    - 추상 클래스로 지정한 객체는 인스턴스를 만들 수 없다.
    - 추상 클래스의 자식 클래스를 통해 인스턴스를 생성할 수 있다.
    - 키워드는 abstract 멤버 변수 또는 일반 멤버 함수가 포함된 여부와 상관없이 순수 가상함수를 1개 이상 가지고 있는 클래스는 추상 클래스라고 할 수 있다.

▶ 인터페이스
    - 순수 가상함수로만 이루어진 클래스 -> 인터페이스
    - 인터페이스의 개념은 하위 클래스에서 반드시 정의해야 할 함수를 정해주는 클래스라고 할 수 있다.
    - C++에서는 인터페이스라는 개념을 공식적인 키워드로 지원하지 않는다.
    - 표기법 : 파스칼 케이스

▷ 선언 예시
    __interface IGameClass
    {
	    virtual void idle() PURE;
	    virtual void attack() PURE;
    };

    class IGameClass
    {
        virtual void idle() PURE;
        virtual void attack() PURE;
    };

▷ 특징
    - 멤버 변수 / 함수를 포함시킬 수 없다.(정적 함수도 포함)
    - 한정자를 사용할 수 없다.
    - 기본 클래스를 상속 받을 수 없다.
    - trivial 객체이다.
    - public 속성을 가지고 있어야 한다.
    - 인터페이스의 상속은 인터페이스가 자식클래스를 따른다고 표현(따르게 했다.)

▷ 장점
    - 다중 상속이 가능하다.(다이아몬드 상속 문제가 발생하지 않음)
    - 다형성

▷ 단점
    - 가독성의 감소
    - C++ 기준으로 강제성이 없기 때문에 프로그래머에 의한 실수가 발생할 여지가 아주 많다.(순수가상함수가 아니라 다른걸 넣어도 오류는 안뜸)


※ 인터페이스(순수 가상함수 설계) -> (상속) -> 추상클래스 -> (상속) -> 기본 클래스

★★★
▶ 가상 소멸자
    - 퍼포먼스 이슈를 많이 가지고 있으므로 남발하지 말것.(회사에서 질문이 많은 이유는 신입이 아무데나 갈기기 말았으면 한다.)
    - 가상함수를 포함한 클래스의 경우 소멸자도 가상으로 처리할것.
    - 인터페이스, 추상클래스, 가상함수 등등에서 동적 할당된 클래스를 메모리 해제하면 자식 클래스의 소멸자를 호출해야 하는데 부모 클래스의 소멸자만 호출이 되는 문제를 해결할 수 있다.
    - 호출 순서에 의한 문제를 해결하기 위해 가상 소멸자를 사용해야 한다.
    - 이는 메모리 순환 및 잠재적인 오류에 대한 문제점을 방지할 수 있다.
    - 다만 클래스 링크 / 호출 절차에 의한 속도 및 퍼포먼스 이슈가 발생할 여지가 생기니 사용할때는 주의를 해주면 좋다

*/
#pragma endregion

//
#pragma region bitset
/*
- 비트 연산을 좀 더 사람 친화적 / 함수화 시켜놓은 STL
- 메모리 사용량이 STL보다 매우 적으므로 비트 연산 사용시 가져다 쓰자.
- reset()
- set()
- flip()
- all()
- size()
- any()
*/
#pragma endregion

#pragma region 과제0827
/*
타임어택. 윈도우 창 만들기
- 시간은 10분

한줄 조사.
- 노트에 적어올것(+ 공부)
- CALLBACK Function, DC, GetDC / ReleaseDC, BeginPaint / EndPaint, WM_PAINT, PAINTSTRUCT에 대해 조사
*/
#pragma endregion

#pragma region 과제0828
/*
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

#pragma region 과제0829
/*
과제1. 오망성출력
- 오망성을 마법진처럼 출력
- 양식 및 사용 문법은 본인 자유지만 삼각함수 X

과제2. 사각형 2개 움직이기
- 총 사각형 갯수 : 2개
- 하나는 움직일 수 있는 사각형 / 다른 하나는 움직일 수 없는 사각형
- 움직일 수 없는 사각형을 움직일 수 있는 사각형이 밀어낼 수 있으면 된다.
- 예외처리
    - 2개의 사각형은 화면 밖으로 나갈 수 없다.
    - 2개의 사각형을 초기 위치로 돌리는 기능도 추가한다.
※ 별다른 언급을 하기 전에는 충돌 함수를 사용하지 말것

과제3. 사각형 영혼 밀어넣기 (월요일까지)
- 시작은 큰 사각형 2개와 작은 사각형 1개
- 내가 움직일 수 있는 사각형 안에는 작은 사각형이 있다.
- 사각형을 움직이면 작은 사각형 역시 움직이거나 / 큰 사각형에 끌려가야한다.
    - 끌려가는것 추천
- 예외처리
    - 작은 사각형은 큰 사각형을 벗어날 수 없다.
- 큰 사각형끼리 충돌이 되면 작은 사각형은 충돌이 된 반대편 사각형으로 이동한다.
※ 이때 움직일 수 있는 주도권은 작은 사각형을 소유하고 있는 큰 사각형
※ 모서리에 대한 예외처리 수행할 것

*/
#pragma endregion

#pragma region 과제0830
/*
개인 연습.
    - 싱글톤 -> 손코딩

한줄 조사.
    - GetAsyncKeyState
    - 상태 값 4가지
    - &(비트 연산자)

과제1. 사각형 4단 밀기
- 사각형의 갯수는 총 4개
- 마우스로 화면에 그려진 4개의 사각형중 아무거나 선택해 자유롭게 움직일 수 있어야 한다.
    - 좌클릭으로 누른채로 이동.
    - 크기 조절은 마우스의 한쪽을 찍고 움직이면 늘어나는 형태
- 움직임도 가능하고 크기 또한 조절이 가능해야 함.
    - 마우스 왼 / 오
- 마우스로 움직이고 있는 사각형이 다른 사각형과 충돌되면 충돌된 사각형은 자연스럽게 밀려난다.(타이머 사용)

※ 충돌 함수 사용 금지

과제2. 마우스로 무작위 도형 출력
- 마우스로 클릭한 좌표에 무작위 도형을 출력한다.
- 도형의 크기, 모양, 종류 모두 무작위로 설정
- 도형의 종류는 사각형 / 원 / 삼각형 / 다각형

- 삼각형 / 다각형 -> Polygon()

과제3. 내 얼굴 그려오기 (다음주 화요일까지)

- 도형을 통해 과제를 해올 것
- 쓸수 있는건 다써봐

도전과제1. 도형 회전
- 사각형을 회전 시킨다.
- 외부 라이버러리 X / 외부 문법 x / 순수 WinAPI로만 구현할것
- hdc를 반드시 사용해야 하고 Rectangle()을 꼭 사용해야 한다.
- 회전축이 바뀐 상태면 상대 좌표로 이동하게 구현을 해오면 깔끔
*/
#pragma endregion

#pragma region 과제0902
/*
과제. 미비된 과제를 최대한 해올 것

타임 어택. API 프레임워크 구축
- 가상함수를 통해 메인 게임이 만들어졌고 이후 키매니저까지
- 싱글톤, 랜덤까지는 있는 상태에서 지금 상태로
- 시간은 1시간
*/
#pragma endregion