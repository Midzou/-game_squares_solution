#include <iostream>
#include <ctime>
using namespace std;

int N; // ���������� N-������� ������
int Count = 0;
struct Node
{
	int v; // �������� � ���� ������
	int n; // ���-�� ����� � ��������� � ������ � ������ ����
	Node **cld; // ������ ��������
	Node() : v(0), n(1), cld(new Node *[N]) { for (int i = 0; i < N; ++i) cld[i] = 0; }
};

Node *root = 0; // ������ ������

int *arr;//������ ��� �������� ������� ����

int maks_way = 0;//������������ �����

void showTreeR(Node *r, int sh) // ���������� ������
{
	if (!r) return; // ���� �� �����
	for (int j = 0; j < sh; ++j) putchar(' ');
	cout << r->v << endl;
	for (int i = 0; i < N; ++i)
		showTreeR(r->cld[i], sh + 5); //sh-���-�� �������� ��� ����������� �����������
}

void showTree() // ����������
{
	cout << endl << "Tree : " << endl << endl;
	showTreeR(root, 0);
	cout << endl;
}



void push(Node *&r, int *arr, int size)
{
	if (Count < size)
	{

		if (!r)
		{
			{
				r = new Node();
				r->v = arr[Count];
				Count++;
			}
		}
		else
		{
			for (int i = 0; i < N; ++i)
			{

				push(r->cld[i], arr, size);
			}
		}
	}

}

void findMaksWay(int *array, int size)//��� �������� �������!
{
	if (size > maks_way)
	{
		arr = (int *)realloc(arr, size * sizeof(int));
		maks_way = size;

		for (int i = 0; i < size; i++)
		{
			arr[i] = array[i];
		}
	}
}

void findOrderTreeR(Node *r, int *array, int sh, int size) //size -����� ����
{

	if (!r)// ���� �� �����
	{

		findMaksWay(array, size - 1);
		return;
	}


	int *array_;
	array_ = (int *)malloc(0);
	array_ = (int *)realloc(array_, size * sizeof(int));
	for (int i = 0; i < size; i++)
		array_[i] = 0;


	for (int v = 0; v < size; v++)//��������
		array_[v] = array[v];



	for (int i = 0; i < N; ++i)
	{
		if (r->cld[i] != NULL)
		{
			if (r->v < r->cld[i]->v)
			{
				array_[size] = r->cld[i]->v;
			}
			else return;
		}
		findOrderTreeR(r->cld[i], array_, sh + 5, size + 1); //sh-���-�� �������� ��� ����������� �����������

	}

}


void findOrderTree()
{
	int *array;
	array = (int *)malloc(sizeof(int));
	array[0] = root->v;//����� ��������� ������ �������
	findOrderTreeR(root, array, 0, 1);
	cout << endl << "Answer : " << endl << endl;

	cout << maks_way << endl;

	for (int i = 0; i < maks_way; i++)
	{
		cout << arr[i] << "    ";
	}

	cout << endl;
}

int main()
{

	N = 3; // ������ N-������� ������
	int size;
	int a;
	cout << "pls enter count element :";
	cin >> size;
	int *arr = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{

		arr[i] = i + 1;
	}
	int value;

	for (int i = 0; i < size; i++)
		push(root, arr, size);
	showTree();
	findOrderTree();


	system("pause");
	return 0;
}


