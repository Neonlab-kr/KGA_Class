#pragma region �� ĳ���� / �ٿ� ĳ����
/*
�� �� ĳ����(Up Casting)
- �ڽ� Ŭ������ ��ü�� �θ� Ŭ���� Ÿ������ ��ȯ
- ������� Ÿ�� ��ȯ�� �ʿ� ����

�� �ٿ� ĳ����(Down Casting)
- �θ� Ŭ������ ��ü�� �ڽ� Ŭ���� Ÿ������ ��ȯ
- dynamic_cast<�ٲٷ��� ���ο� Ÿ��>(���)
*/
#pragma endregion

#pragma region ���ø�
/*
�� ���ø�(Template)
- template <typename T>
- ���� �������� ���� Ÿ�Կ� ���ؼ� Ŭ������ �Լ��� ������ �� �ִ�!(���׸� ���α׷���)
- ũ�� �Լ� ���ø��� Ŭ���� ���ø����� ����
- ������ ������ Ư�� Ÿ������ ���� -> ������
- ���ø��� Ÿ���̸��� ��ȸ��

�� �Լ� ���ø�
- ȣ��� �ڷ����� �´� �Լ��� �����Ͽ� ����.
EX)
	template <typename T1, typename T2>
	void Output1(T1 a, T2 b)
	{
		cout << a <<", " << b << endl;
	}

�� Ŭ���� ���ø�
- Box2<int, double> box2; �� ���·� ��ü ����
- ȣ��� �ڷ����� �´� Ŭ������ �����Ͽ� ����.
EX)
	template <typename T1, typename T2>
	class Box2
	{
	private:
		T1 firstData;
		T2 secondData;
	public:
		void setFirstData(T1 data) { this->firstData = data; }
		T1 getFirstData() { return firstData; }

		void setSecondData(T2 data) { this->secondData = data; }
		T1 getSecondData() { return secondData; }
	};
*/
#pragma endregion

/*
����1. 
1. Gamescene�̶�� Ŭ������ ����
	- �ش� scene���� �����ϴ� ������ �����ϼ���.

int main()
{
	GameScene game
}

[�ܼ� ������Ʈ]
1. �ܼ� ������Ʈ�� �������� ����
2. ��� ������ ���� ������Ʈ��
3. ���� �ߴ��� ��ġ�� ����(��Ʈ����, ������ũ����)
4. ���� ����
5. ���� ���� �Ǽ��ϴ°�? -> �������!!! ����!!!!

*/