// ���� �ּ�: �ڵ忡 ������ ���� �ʴ´�.
// ���� �Ǵ� Ÿ���� ���� �޸� ����� ���� �ǹ��Ѵ�.

// ���� ���θ� �ϸ鼭 �ּ��� �ִ��� ���� ����°� ����.
// �� �ּ��� �ȳ���� ������ -> ������ ����

// �ּ��� ������ ��ǻ�Ͱ� �о� ������ �ʴ´� -> �ؼ��� ���� �ʴ´�.

// ��ǻ�ʹ� �⺻������ �ȶ��ϰ� ����Ʈ�� ģ�� -> ��, �������� ����.

// ��ǻ�ʹ� ȿ�����ΰ� �����Ѵ�.

// S / E <- Start, End
/*
���� �ּ�

�ּ��� ������ ��ǻ�Ͱ� �о� ������ �ʴ´� -> �ؼ��� ���� �ʴ´�.

�ּ��� ������ ��ǻ�Ͱ� �о� ������ �ʴ´� -> �ؼ��� ���� �ʴ´�.

��ǻ�ʹ� �⺻������ �ȶ��ϰ� ����Ʈ�� ģ�� -> ��, �������� ����.

��ǻ�ʹ� ȿ�����ΰ� �����Ѵ�.

�۲�(Consolas, Monaco ������ ���)
1iIlL0Oo <- ������ �Ǵ� �۲��� ����� ��
*/

//��ó���� ���ɾ�
// # : ���� ������
// pragma <- �����Ϸ��� ����� �����ϰڴ�
// #pragma once
#pragma region ���α׷��� ���

/*

�� ���α׷����̶�?

- Programming. Program + ing �� �پ����� ���� ���α׷��� �ϰ� �ִ� ��� ������ �� �ִ�.
�� ���� ���α׷��� �ϰ� �ִ� ��� ���� �ᱹ ���α׷��� ����°� -> ������ �ǹ��Ѵ�.

�� ���α׷��� ����?

- ��ǻ�Ϳ� ��ȭ �Ǵ� ������ �� �� �ִ� �Ϸ��� ���ɹ��� �ۼ��� �� �ִ� �� �ǹ��Ѵ�
�� ���α׷��� �� �̿��ϸ� ���α׷��� ����� ���� ����

- ���α׷��� ���� �پ��� �� ���������� ũ�� 2������ �з��� �� �ִ�.
�� 1. Ư�� ��� ������ ����ȭ �� ���
�� 2. ������ ���

C++ <- �޸� ����ȭ ���

�� ���α׷��� �� ��ǻ�Ϳ��� �����ϴ� ���

- C / C++ ���� �ۼ��Ǿ� �ִ� �ڵ�� ��ǻ�Ͱ� ���� �� �� ���� ���ɹ��̱� ������ C / C++ ����
�߰����� �� �ؼ����ִ� ������ ������ �ϴ� ���𰡰� �ʿ��ϴ�

�� �� ����� �����ϴ� ģ���� �ٷ� �����Ϸ�
�� �����Ϸ��� �ش� �ڵ带 ��ǻ�Ͱ� ���� �� �� �ִ� ���� ��ȯ�ϴ� ������ �����Ѵ�.


- �����Ϸ��� ���α׷��� ���� ��ǻ�� ���̿��� �뿪�� ������ ���ֱ� ������ ���α׷��� �� �ۼ��ϴ�
����� ��ǻ���� �� �𸥴ٰ� �ϴ��� ��ǻ�Ϳ��� ���ɹ��� �����°��� �����ϴ�.

- C / C++ ������ ������ ������������ �⺻ ������ ���õǾ� �ִ�.
�� �����Ϸ� != ����������


�� ���α׷��� ��� �� ���
- ���α׷��� ����� ���� ������ ������ �����ε� ������ ����.
�� �پ��� ����� ����� ũ�� 4������ ����ϸ� �ȴ�.


1. ������ ���α׷��� (��������)
�� ���α׷��� �ʱ� �ܰ���� ���� ������� �ڵ��� �帧�� ���� ���α׷��� �ϴ� ���
 �� ����ϸ� ���α׷��� ������� ��������� �帧�� �״�� ���α׷��� �Ѵ�.
�� �̷��� ����� ���α׷��� �帧�� ���󰡱� ������ ���������� ���ϰ� �ڵ尡 �������� ����� �ֱ� ������
���������� ����ٴ� ������ �����Ѵ�.
�� c ��Ÿ��


2. ������ ���α׷���
�� ������ ���α׷����� ������ �����ϱ� ���� ���� ���
 ���������� �������� �ڵ��� ������ ��� ������ ���� ����� ä���Ѵ�.
�� �Լ����� ���α׷����̶���� �θ��� ������ ���α׷��ֺ��ٴ� ���������� �����ϴٴ� ������ �ִ�.

�� �̷��� ��ɵ��� �ѵ� ���� ����̶�� ���·� ����� �ǰ� �̴� ���α׷��� ���̺귯���� ����
�� c ��Ÿ��


3. ��ü���� ���α׷���
�� ���� ����� �� ��İ��� ���� �ٸ� ������� �ڵ��� ������ "��ü" ������ ���� ���α׷��� �ϴ� ���
�� ��� ��󿡴� �Ӽ��� �޼��尡 �ְ� �̸� �ϳ��� ���� ��ü�� ����� ����̸� ���⿡�� ���ϴ� ��󿡴� ���� ������ �ʴ� �͵� ������ �ȴ�.
�� ��ü���� ������� �پ��� ����� ������ �̴� ��ü���� ������ �ٷ��.
�� C++ ��Ÿ�� + C# ��Ÿ��


4. ������Ʈ (���) ���α׷���
�� ���� ��Ÿ�� + �÷��� ��Ÿ��
�� �ڵ��� ������ ������Ʈ ������ ���α׷��� �Ѵ�.
�� ������ ������Ʈ�� ���������� �����̴� ��ǰ�� �����Ƿ� �ٸ��� ���� �������� �ٿ��ָ� �Ȱų� �޸���
���� �����ϰ� �Ǹ� ������ ���� �� �𸮾� ������ �߱��ϴ� ����� �ٷ� ������Ʈ ��� ���α׷�



*/
#pragma endregion ���⵵ ����

/*
�� ���� �Լ�  -> EP(Entry Point, ������)

- ���� �Լ��� 1���� �����ؾ� �Ѵ�.
�� C / C++ ���� �ۼ��Ǿ� �ִ� ���α׷��� ó�� ����Ǵ� �κ�

- C / C++ ���� ���α׷��� ó�� ����Ǳ� ���ؼ� �ݵ�� main �Լ��� �����ϰ� �־�� �Ѵ�.
�� ���� main �Լ��� �����ϰ� ���� �ʴٸ� ���� ��ü�� �ȵȴ�.

- C / C++ �� ���α׷����� ��ȯ�Ǳ� ���ؼ� ��ġ�� ū �ܰ�

1. ��ó���� �ܰ�
2. ������ �ܰ�
3. ��ũ �ܰ�

*/
// mutational �Լ�



// ��� ���� (ǥ��)
//C++ �ھ� ���
#include <iostream>
/*
�� iostream: ��, ����� ����ϴ� C++ ǥ�� ���̺귯��

- include�� �ش� ��ο� �ִ� ������ ������ �ܼ��ϰ� �����Ѵ�.

- iostream�� ����Ǿ� �ִ� cout / cin / endl

*/

#include <Windows.h>

// ���� / ��� ���
//#include "Debug\Console.tlog\"

// ���α׷��� ����
//#include "MainGame.h"

using namespace std;

void main()
{
	/*
	�� �ڵ� �ۼ��� �⺻
	�� ���� ������ ���� �ȴٸ�...

	1. ��Ÿüũ
	2. ��, �ڸ� üũ�Ұ�
	3. �����ݷ��� üũ�Ѵ�. (;)
	4. ���������� ������ �Ǵ��� Ȯ���Ѵ�.

	�� �ϴ� ;�� �ڵ��� ��ħǥ -> �ݵ�� ������ �Ѵ�.
	*/
	//cout : ����ض�
	//endl : ���� �ٲ۴�.
	// << : ��� ������ -> cout (C��� -> printf())
	// >> : �Է� ������ -> cin (C��� -> scanf())

	// :: -> ���� ������
	// ��κ��� ������ ���α׷��Ӱ� �������� ȿ�����̴�.
	// �� �� �������� Ǯ���ִ� ���� ���α׷����� ����
	// 1. 2��
	std::cout << "������ �°� ȯ���� ����" << std::endl;
	// 2. std�� ���Ե� ��� ���(�޸�) �߻�
	cout << "������ �°� ȯ���� ����" << endl;

	cout << "���� ���: " << "�׳� �ֵ���ǥ �ȿ� ������ �ȴ�" << endl;
	cout << "���� ���: " << 12345 << "�׳� ���� ������ �ȴ�" << endl;
	
	cout << "��" << endl;
	cout << "��" << endl;

}


/*
01. ����� ���ؼ� ���ݺ��� �����ϴ� ������ ���̸� ���� ����.
�� a. ������� + �̷�
�� b. ������ ���� ����

�� �� ������ �����ϴ� ���񿡰� ���ϴ� ��
�� 1. ���⼺�� �� ����´�.
�� 2. ���θ� ���� ������ �Ѵ�.
�� 3. ���� ��ǥ�� ����� �����ؾ� �Ѵ�.
 v �� a. ���� ��� ����
 v �� b. �߷�
 �� 	c. ����
 �� 	d. ������ ��ĥ �� �ֳ� / ����?


 ����1. �����ϴ� ĳ���� ���

 - ĳ���� ����� ����

 - �ּ� ������ 40 x 40 ��ų��

 �� ���������� �ļ� x

 ����2. �ڱ� �Ұ� ���
 - �̸�, ����, ����ó, �ּ�, �̸���, ����, ���� ���� ȸ��, ����� ���� ����, ���
 - �������� ������ �Ǵ��Ͽ� �� ����� �´�.

 ���� ����1. �ڱ� �Ұ� ���
 - �̸�, ����, ����ó, �ּ�, �̸���, ����, ���� ���� ȸ��, ����� ���� ����, ���
 - �׸��� ����
 - ��, �Է��� ������ ���� ���� ����� �ƴ� Ȯ������ ������ ���� �� ���ȭ�� ���ѿ� ��
 �� ��ü (�߻� Ŭ����/ �������̽�) / ������Ʈ (������ ����) �� 1
*/