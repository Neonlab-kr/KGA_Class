#include <iostream>

using std::cout;
using std::endl;

#pragma region 조건문
/*

▶ 조건문

- 조건문은 필수인가? -> 필수다!

- 프로그램이 실행되는 동안 정해져 있는 경우에 수에 맞춰서 서로 다른 결과를 도출하기 위한 문법을 의미한다.

- 조건문을 이용하면 다양한 결과를 출력하는 프로그램을 작성하는 것이 가능하다.

ㆍ C / C++ 언어 조건문의 종류

- if ~ else 조건문
ㄴ for

★ bool 과의 조합에 주의해야 한다. -> 남발


- switch ~ case 조건문
ㄴ while

▷ if ~ else문

- 조건적 실행 (조건에 따라 실행 유무)

- 조건을 만족하는 if문을 발견하면 나머지 if문을 건너 뛴다.

- 또한 if와 else가 만나서 이루는 문장의 수는 둘이 아니라 1개이다.

- if ~ else문에서 조건의 만족 여부 검사는 위에서 아래로 절차지향적으로 진행

- 조건이 만족되어 해당 블록을 실행하고 나면 마지막 else까지도 건너뛴다.

- 조건이 성립되지 않을시 마지막의 else문을 실행한다.

- else문의 설계에 집중할 것.


EX)
if (조건1)
{
    // 조건1이 참일 때 실행할 코드
}
else if (조건2)
{
    // 조건2가 참일 때 실행할 코드
}
else
{
    // 모든 조건이 거짓일 때 실행할 코드
}

▷ switch문

- 스위치 문을 사용하는 경우는 일일이 조건별로 세팅을 해주기가 용이하기 때문에 상태 변화, 조건이 많은 경우에 사용하면 좋은 효율을 낼 수 있는 문법이다.

- 그리고 if문과 매우 흡사하다는 특징이 있으며 switch문으로 작성이 되는 로직은 전부 if문으로 대체가 가능하다.
(단, 코드량이 엄청나게 길어질 수 있으니 주의해야 한다.)

EX)
- 데이터 타입에는 int + char형이 올 수 있다.
ㄴ 하지만 일반적으로 int형을 사용해 주는게 유리하다.
switch (Data Type)
{
    case 값1:

    case 값2:

    .
    .
    .

    default:
}

- 스위치문은 인자 값에 따라서 실행할 영역을 결정한다.
    ㄴ EX : 들어오는 값이 1이면 case 1:이 실행이 되고 들어오는 값이 2라면 case 2:가 실행된다.

- 스위치 ~ 케이스 조건문의 디폴트는 if ~ else 조건문의 else문에 해당하는 역할을 수행한다.

★★★ 면접 질문 ★★★
※ 스위치 ~ 케이스 조건문은 if ~ else 조건문과는 달리 범위에 해당하는 조건을 줄 수 없을뿐더러 조건문을 사용 될 수 있는 자료형은 정수형에 한정된다.
- 정수 이외의 값을 조건으로 줄 경우 올바른 결과를 출력할 수 없다.(데이터 손실)

▶ C / C++ 언어 제어문의 종류

1. return
ㄴ 조건문 일때는 다시 돌려 보낸다. / 함수에서는 값을 반환하고 초기화


2. continue
ㄴ 조건문 일때는 연산을 하지 않고 건너 뛴다. / while문에서는 바로 이전 문항으로

3. break
ㄴ 만나면 멈춘다. / while문 같은 경우는 while문을 빠져 나간다.
ㄴ break 문은 반복문을 탈출하는 용도로 많이 사용이 되는데 break문의 유무에 따라서 결과 값이 완전히 바뀔 수 있으니 주의해야 한다.

4. goto
ㄴ 보통 "점프문"이라고 불리며 goto에 라벨을 지정하면 중간에 있는 코드를 무시하고 해당 라벨로 이동한다.
ㄴ do ~ while 처럼 특정 상황에서 아주 강력함.
ㄴ 가독성이 매우 매우 떨어짐.
ㄴ 단, 남발시 매우 위험하고 남발의 한정된 수가 매우 적다.(일주일 내내 프로젝트 했다고 가정하고 2개정도,,,)








*/
#pragma endregion


void main()
{
    int nOperator;
    cout << "내가 입력한 숫자 = ";
    std::cin >> nOperator;

    if (nOperator == 0)
    {
        cout << "첫번째 게임";
    }
    else if (nOperator == 1)
    {
        cout << "두번째 게임";
    }
    else
    {
        cout << "나머지 게임";
    }

    cout << '\n';


    int inputNumber;
    cout << "0번, 1번, 2번중 하나를 선택해라." << endl;
    cout << "inputNumber = ";

    std::cin >> inputNumber;

    // 단일 사용은 그렇게 권장 X
    // ㄴ 짝궁이 있다. -> 열거형
    // 
    switch(inputNumber)
    {
    case 0:
        cout << "0번 입력시 내가 출력된다." << endl;
        break;

    case 1:
        cout << "1번 입력시 내가 출력된다." << endl;
        break;

    case 2:
        cout << "2번 입력시 내가 출력된다." << endl;
        break;

    default:
        cout << "그 외 번호를 입력했다." << endl;
        break;
    }

    cout << '\n';

    /*
    ㆍ C / C++ 언어 증 / 감 연산자 종류

    - 전위 증/감 연산자
    - 후위 증/감 연산자
    
    - 전위 증/감 연산자는 해당 변수의 값을 증/감 시킨 후 연산에 활용하고 후위 증/감 연산자는 연산에 활용이 된 후 해당 변수의 값이 변경이 된다. (보통 개행을 기반으로 발생하며 우선 순위 연산을 따른다.)
    */

    int nValue = 10;

    cout << "증 / 감 에 대한 연산 결과" << endl;

    cout << ++nValue << endl; //11
    cout << --nValue << endl; //10
    cout << nValue++ << endl; //10
    cout << nValue-- << endl; //11

    cout << "nValue 값: " << nValue << endl; //10

    cout << '\n';

    int nValueA, nValueB, nValueC, nValueD;
    nValueA = nValueB = nValueC = nValueD = 10;


    if ((nValueA == nValueB++) && (nValueC++ < ++nValueD))
    {
        cout << nValueA << endl;//10
        cout << nValueB << endl;//11
        cout << nValueC << endl;//11
        cout << nValueD << endl;//11
    }

    cout << '\n';

    /*
    - goto
    ㄴ 사용할 때 주의가 필요한 문법
     ㄴ 가독성을 떨어뜨리고 스파게티 코드를 완성시키는데 일조하기 때문에
      ㄴ 사용하기 전에 "정말 여기서 goto문이 필요할까?" 라는 생각을 먼저 해보고 사용하자.


     EX:
     goto 레이블 :

     레이블 :

    */

    for (int i = 2; i < 10; i += 1)
    {
        for (int j = 1; j < 10; j += 1)
        {
            if (i % 2 == 0)
            {
                goto EXIT_1;
            }
            if (i % 5 == 0)
            {
                goto EXIT_2;
            }

            cout << i << "x" << j << "=" << i * j << endl << endl;
        }
    EXIT_1:
        cout << "i 단을 출력 후 실행" << i << endl << endl;
        
    }
EXIT_2:
    cout << "반복문 나와 버렷네?" << endl;

}


/*
과제1. 가위바위보 게임

- if문을 사용해서 만든다.
ㄴ 스위치문은 사용 금지

- 게임의 진행 횟수는 총 5판
ㄴ 이후는 게임 종료

- 필수: 치트

※ 팁을 주자면 코드를 최대한 간결하게 해온게 좋을것이다.


과제2. 일수 출력기

- if문과 switch문 중에 본인이 판단해 효율적인것을 선택해서 만든다.

- 시작하면 사용자의 입력을 받고 입력한 숫자에 따라 ??일 인지 출력

EX) 4를 입력시 -> 4월을 30일까지 있습니다. -> 다시 입력 커맨트 활성화

- 1월 12월까지 확인이 가능해야 하고 이외의 숫자는 예외처리를 진행한다.

- 총 5번을 입력하면 프로그램 종료



도전 과제1. 함수와 포인터를 활용한 가위바위보

void* Function(int* a, int** b, int*** c)
{
    //내용 작성
}

void main()
{
    // 이외에 코드가 있으면 안된다.
    Function(a, b, c);
}

한줄 조사. 함수

- 노트에 적어온다.

- 비유할 것 생각해 온다. (EX: 함수는 OOO이다.)

*/