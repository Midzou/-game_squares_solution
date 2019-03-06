#include <iostream>
#include <ctime>
using namespace std;

int N; // ���������� N-������� ������
int Count = 0;//������� ��� �������

struct Node
{
	int v = 0; // �������� � ���� ������
	Node **cld; // ������ ��������
};

Node *root = 0; // ������ ������

int repet = 0;//������� ������������� ������

			  //����� ������ �� �����
			  //�������� �������
			  //�������� �������
void showTreeR(Node *r, int sh)
{
	if (!r) return; // ���� ��� �������
	for (int j = 0; j < sh; ++j) putchar(' ');
	cout << r->v << endl;
	for (int i = 0; i < N; ++i)
		showTreeR(r->cld[i], sh + 5); //sh-���-�� �������� ��� �����������
}

//��������� �������� ��������
//���������� value-�������� ��������� � ���������� ��������
int checking()
{
	int value = 0;
	while (true)
	{
		cin >> value;
		if (!cin)
		{
			cout << "WRONG!!Re-enter" << endl;
			cin.clear();//�������� ������
			while (cin.get() != '\n');
		}
		else
			return value;
	}
}


//��������� ������
//�������� �������, ������ ��������, ������ �������
void push(Node *&r, int *arr, int size)
{
	if (Count < size)
	{
		if (!r)//���� ��� �������
		{
			r = new Node();
			r->cld = new Node *[N];
			for (int i = 0; i < N; ++i)
				r->cld[i] = 0;
			r->v = arr[Count];
			Count++;

		}
		else
		{
			for (int i = 0; i < N; ++i)
				push(r->cld[i], arr, size);
		}
	}
}

//����� ������������� ������
//�������� �������, �������� ������� �������
void findOrderTreeR(Node *r, int value)
{
	if (!r) return; // ���� �� �����

	if (r->v == value)
	{
		repet++;
	}
	for (int i = 0; i < N; ++i)
		findOrderTreeR(r->cld[i], value);
}


//�������� ������
//�������� ������� 
void destroyTree(Node *r)
{
	if (!r)
	{
		for (int i = 0; i < N; ++i)
			destroyTree(r->cld[i]);
		delete(r);
	}
}


int main()
{
	N = 3; // ������ N-������� ������
	int size;
	cout << "pls enter count element :";
	size = checking();
	int *arr = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 10 + 1;
	for (int i = 0; i < size; i++)
		push(root, arr, size);
	cout << endl << "Tree : " << endl << endl;
	showTreeR(root, 0);
	cout << endl;
	int value;
	cout << "Repeat vertex value : ";
	value = checking();
	findOrderTreeR(root, value);
	cout << "Number of repetitions " << repet << endl;
	destroyTree(root);
	system("pause");
	return 0;
}
