#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#pragma region ���׿����� �̷�
/*
�����׿�����
- ���ǽ� ? ���϶��ǹ�ȯ�� : �����϶��ǹ�ȯ��
- �ڵ��� ������ ���̰� ������ ������ ǥ���ϴµ� �����ϰ� ����
- ��, ���ǽ��� �ʹ� ������ ��쿡�� �б⹮���� ó���ϴ����� ����
*/
#pragma endregion

#pragma region ���ڿ��� ���� �̷�
/*
�� char�� ���Ͽ�,,,
- char Ÿ���� ������ ���� �� �ִ�.
- 'a'�� 97�̶�� �ƽ�Ű�ڵ� ���� ����.
- �ѱ��� 1����Ʈ�� �ѱ�� ������ ����� �ʴ´�.(UTF-8�� ��� ���� 1����Ʈ �ѱ� 3����Ʈ UTF-16�� ���� 2����Ʈ �ѱ� 2����Ʈ)

�� ''�� ""�� ����?
- '' �� ���ڰ� ""�� ���ڿ��̴�.
- ���ڿ��� ���������� '\0'�� ���ԵǾ� �ִ�.

�� C��Ÿ�� ���ڿ��� �پ��� �Լ���...
1. strcpy_s(str1,str2);
2. strlen(str);
3. strcat_s(str1,str2);
4. strcmp(str1,str2);

��String Class
- C++�� ���ڿ� Ŭ����
- string�� ������ '\0'�� ���� �ʴ´�.

��String Class�� �޼ҵ��
1. length()
2. size()
3. +,=
4. ==,>,<
5. substr()
6. replace()
7. erase()

*/
#pragma endregion

void main()
{
#pragma region ���׿����� �ǽ�
	int num1 = 2;
	int num2 = 3;

	int result;

	result = (num1 > num2) ? num1 : num2;

	cout << result << endl;
#pragma endregion

#pragma region ���ڿ� �ǽ�
	char c = 'a';

	char str[] = "Hello World";
	cout << str << endl;
	cout << sizeof(str) << endl;

	//���ڿ� ����
	char str1[50];
	strcpy_s(str1, "Hello World");
	cout << str1 << endl;

	//���ڿ� ���� ���
	cout << strlen(str1) << endl;

	//���� ���� ����
	char str2[] = "Hello";
	for (int i = 0; i < strlen(str2); i++)
	{
		cout << "����" << i << " : " << str2[i] << endl;
	}
	cout << '\n';
	for (int i = 0; str2[i] != '\0'; i++)
	{
		cout << "����" << i << " : " << str2[i] << endl;
	}
	cout << '\n';

	//���ڿ� �����ϱ�(strcat_s)
	char str3[50] = "Hello, ";
	char str4[50] = "World";
	strcat_s(str3, str4);
	cout << str3 << endl;
	cout << '\n';

	//���ڿ� ��(strcmp)
	char str5[] = "Hello";
	char str6[] = "Hello";
	char str7[] = "World";
	char str8[] = "Gorld";

	int result1 = strcmp(str5, str6);
	int result2 = strcmp(str5, str7);
	int result3 = strcmp(str5, str8);

	cout <<"str5, str6 ��� : " << result1 << endl; // 0, ����
	cout <<"str5, str7 ��� : " << result2 << endl; // -1, �տ��� ���� ���ؼ� ���ڿ��� ���� ������ ������ ù���ڿ��� ���ڰ� �ι�° ���ڿ��� ���ں��� �ƽ�Ű ���� ũ�ų� ������ ����
	cout <<"str5, str8 ��� : " << result3 << endl; // 1, �տ��� ���� ���ؼ� ���ڿ��� ���� ������ ������ ù���ڿ��� ���ڰ� �ι�° ���ڿ��� ���ں��� �ƽ�Ű ���� ������ ���
	cout << '\n';
#pragma endregion

#pragma region String Ŭ������ �޼ҵ�
	string str9 = "Hello World";

	cout << "���ڿ��� ���� : " << str9.length() << endl;
	cout << '\n';

	cout << "���ڿ��� ũ�� : " << str9.size() << endl;
	cout << '\n';

	string str10 = str9;
	cout << "����� ���ڿ�" << str10 << endl;
	cout << '\n';


	string str11 = "Hello, ";
	string str12 = "World";
	str11 += str12;//stringŬ���� ���ο��� +�����ڰ� �����ε� �Ǿ�����.
	cout << "����� ���ڿ�" << str11 << endl;
	cout << '\n';


	string str13 = "Hello";
	string str14 = "Hello";
	string str15 = "World";
	string str16 = "Gorld";
	cout << "���ڿ� �� " << (str13 == str14) << endl;
	cout << "���ڿ� �� " << (str13 < str15) << endl;
	cout << "���ڿ� �� " << (str13 > str16) << endl;
	cout << '\n';

	string str17 = "Hello, World";
	cout << "���ڿ� �ɰ��� : " << str17.substr(7, 5) << endl;
	cout << '\n';

	cout << "���ڿ� ��ü : " << str17.replace(7,5,"C++") << endl;
	cout << '\n';

	cout << "���ڿ� ����� : " << str17.erase(5,7) << endl;
	cout << '\n';
#pragma endregion
}

/*
����1. �Լ� �����ε��� Ȱ���� ĳ���� ��ų �����
- ����
	- ��ų �̸��� �Է¹޾� ����ϴ� �Լ�
	- ��ų �̸��� ���������� �Է¹޾� ����ϴ� �Լ�
	- ��ų �̸�, ������, ũ��Ƽ�� Ȯ���� �Է¹޾� ����ϴ� �Լ�
	- ��ų �̸�, ������, ũ��Ƽ�� Ȯ��, ��Ÿ��� �Է¹޾� ����ϴ� �Լ�

����2. ����ڰ� �Է��� ���� ������, �� �ڸ����� ���� ���ϴ� ������ �����ض�.
- ����
	- 18324 -> 1+8+3+2+4 = 18
	- 3849 -> 3+8+4+9 = 24

*/