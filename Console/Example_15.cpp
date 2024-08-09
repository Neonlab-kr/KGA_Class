#pragma region template
/*
�� 

*/
#pragma endregion

#pragma region ����Ʈ
/*
�� ����Ʈ(List)
- ��带 ������� �Ǿ�����(���Ϳ��� �������� ������ ��)
- ���� ��ġ�� �ٷ� ������ �Ұ�����(���� ���ٸ� ����)
- Ž���� �־ �ſ� �������� ���԰� ������ �ӵ��� ����
- �����Ϳ� �����Ͱ� �� ��帶�� ���� ������ ���Ϳ� ���� �޸� ��뷮�� ũ��

- ��� �Լ�
	- push_back() : ����Ʈ �� ��� �߰�
	- push_front() : ����Ʈ �� ��� �߰�
	- pop_back() : ����Ʈ �� ��� ����
	- pop_front() : ����Ʈ �� ��� ����
	- insert() : ������ ��ġ�� ��� ����
	- erase() : ������ ��ġ�� ��� ����
	- clear() : ��� ��� ����
	- size() : ����Ʈ ��� ���� ��ȯ
	- front() : ù��° ��� ��ȯ
	- back() : ������ ��� ��ȯ
	- remove() : ������ ���� ������ ��� ��� ����
	- reverse() : ����Ʈ ���� ������
	- sort() : ����
*/
#pragma endregion

#pragma region ��
/*
�� �� (map)
- key�� value�� ��(Pair)���� ������.
- key�� unique��� Ư��
- key�� �ߺ��� ����ϰ� �ʹٸ� multimap�� ����ؾ���
- ���������� ���� �˻� Ʈ���� ������ RBT(Red Black Tree)�� �����Ǿ�����.
- �˻� �ӵ��� �ſ� ����

�� ��(pair)
- �ΰ��� ���� ��� �ϳ��� ��ü�� ����ϴ� ���ø� Ŭ����
- �ΰ��� ���� �ٸ� Ÿ���� ���� �Բ� ��밡��
- ���� �ΰ��� ����� ������ �ִ�.
- first, second

�� �� �߰� ���� ���
	1. value_type�� �̿��� ���
		- �⺻���� Ű-�� �� Ÿ���� ��Ÿ����
		- pair ��ü�� ������ ������ insert�� ����
		- �������� ������
		EX)
			data.insert(map<string,int>::value_type("key1",1));

	2. make_pair�� �̿��� ���
		- pair��ü�� �����ϴ� �Լ� ���ø�
		- std::pair<T,T> ��ü�� �����Ͽ� return����
		- �ڵ����� ���ø� ���ڸ� �߷��Ͽ� ����
		EX)
			data.insert(std::make_pair("key1", 1));

	3. pair�� �̿��� ���
		- Ű�� ���� ���������� �����ؼ� ����
		EX)
			data.insert(std::pair<string, int>("key3", 3));

	4. ��ü�� ���� �����ϴ� ���
		- ������ ������ �и��Ǿ� �ֱ⶧���� ������ ������ �޶��� �� ����
		- �������� ������
		EX)
			std::pair<string, int> pt1("���ѹα�", 10);
			data.insert(pt1);
�� ����Լ�
	- insert() : pair��� ����, ��ȯ���� <iterator,bool>�� pair��. first�� ���Ե� ��ҿ� ���� iterator�̰� second�� ���� ���� ���ο� ���� bool���̴�.
	- find() : �־��� Ű�� �˻��ϰ� iterator�� ��ȯ, Ű�� ������ end()�� ��ȯ
	- count() : �־��� Ű�� ������ ��ȯ
	- clear() : ��� ��Ҹ� ����
	- empty() : ����ִ��� ���θ� Ȯ��
	- size() : ����� ������ ��ȯ
*/
#pragma endregion

/*
���� Ȱ��
���� �÷��̾��� �κ��丮 ���͸� map�� �ְ� key�� �÷��̾��� �̸��� �ִ´ٸ�?
������ �ش� �κ��丮�� ��ȸ�� ����
*/

/*
�ڷ� ���� 1: RBT�� ���ؼ� ����

*/