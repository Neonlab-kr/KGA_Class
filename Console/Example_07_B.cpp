#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#pragma region �Լ� �����ε�
/*
- �����ε��� ����
	- �Ű������� ������ Ÿ�� �Ǵ� ������ �ٸ���.
	- ��ȯ���� �Լ� �̸��� ����.

- �����ε��� ����
	- ������������ �������� ������
	- �ڵ��� �������� ������
	- �ϳ��� �̸����� ���� �Լ��� ������ �� �ִ�.

*/
#pragma endregion

#pragma region ����Ʈ �Ű�����
/*
- �Ű������� �⺻���� ��������.
- ���޵� ���� ������ ���޵� ���� ���.
- ���ٸ� ����Ʈ ���� ���.
- ���� �����ʺ��� ������ ����߸� ��.

int sum(int a, int b = 3)
{
	return a + b;
}

- �Լ� �����ε��� �Բ� ���ÿ��� �����ؾ���
	- ��ȣ���� �߻��� �� ����.
*/
#pragma endregion

#pragma region inline �Լ�
/*
- ȣ��� �� �Ϲ����� �Լ��� ȣ�� ������ ��ġ�� �ʰ�, �Լ��� ��� �ڵ带 ȣ��� �ڸ��� �ٷ� �����ϴ� ����� �Լ�
- �ڵ尡 �����ϰ� ȣ���� ���� �Լ��� inline�� ���ָ� ����.
- �ֱ��� �����Ϸ��� �˾Ƽ� ���������� �ζ����� ������� �ֱ⵵ �ϴµ� ���� Ȱ���� �ʿ�� ����.
inline void Test(int left, int right) { return left > right ? left : right; }
*/
#pragma endregion

int sum(int a, int b);
int sum(int a, int b,int c);


void main()
{

}


int sum(int a, int b)
{
	return a + b;
}

int sum(int a, int b, int c)
{
	return a + b + c;
}