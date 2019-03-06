#include <iostream>
using namespace std;

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

//������� �������� � ������ 
//�������� �������� array_matrix-����������� �������
//�������� �������� size-����������� ���������� �������
void input(int * array_matrix, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(abs(i - j) > size / 4)) // abs-������
			{
				cout << "(" << i << ")(" << j << "): ";
				array_matrix[count] = checking();
				count++;
			}
		}
	}
}

//�������� �� ��������� ��������� �������
//�������� �������� array_matrix-����������� �������
//�������� �������� i_ - ������� ������ ��-��
//�������� �������� j_ - ������� ������� ��-��
//�������� �������� size-����������� ���������� �������
//���������� �������� �������� �� ������ � �������
int get_el(int * array_matrix, int i_, int j_, int size)
{
	if ((abs(i_ - j_) > size / 4))
	{
		return 0;
	}//���� �� ������������ �������
	int count = -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(abs(i - j) > size / 4)) { count++; }
			if ((i == i_) && (j == j_))
			{
				return array_matrix[count];
			}
		}
	}
}

//������� ���-�� ��-�� � ���������� �������
//�������� �������� size - ����������� �������
//���������� k - ���-�� ��������� � �������
int size_matrix(int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (!(abs(i - j) > size / 4))
			{
				k++;
			}
	return k;
}

//��������� ������������
//�������� �������� array_matrix - ����������� �������
//�������� �������� Size_arr - ����������� �������
//���������� det - ������������
void det(int *array_matrix, int size_arr)
{
	double **L = new double *[size_arr]; //�������� ������ ��� ������� L
	for (int i = 0; i < size_arr; i++)
		L[i] = new double[size_arr];

	double **U = new double *[size_arr]; //������ ��� ������� U
	for (int i = 0; i < size_arr; i++)
		U[i] = new double[size_arr];
	double sum = 0;

	for (int i = 0; i < size_arr; i++) //������ ������� L � U
	{
		for (int j = 0; j < size_arr; j++)
		{
			L[i][j] = 0;
			U[i][j] = 0;
			if (i == j)
				U[i][j] = 1;
		}
	}

	//������� ������ ������� L[][] � ������ ������ U[][]
	for (int i = 0; i < size_arr; i++)
	{
		L[i][0] = get_el(array_matrix, i, 0, size_arr);
		U[0][i] = get_el(array_matrix, 0, i, size_arr) / L[0][0];
	}

	//������� ������� L � U
	for (int i = 1; i < size_arr; i++)
	{
		for (int j = 1; j < size_arr; j++)
		{
			if (i >= j) //������ �����������
			{
				sum = 0;
				for (int k = 0; k < j; k++)
					sum += L[i][k] * U[k][j];
				L[i][j] = get_el(array_matrix, i, j, size_arr) - sum;
			}
			else // ������� �����������
			{
				sum = 0;
				for (int k = 0; k < i; k++)
					sum += L[i][k] * U[k][j];
				U[i][j] = (get_el(array_matrix, i, j, size_arr) - sum) / L[i][i];
			}
		}
	}

	cout << "\n\n";
	double det = 1; //������������
	for (int i = 0; i < size_arr; i++)
	{
		for (int j = 0; j < size_arr; j++)
		{
			cout << " " << L[i][j] << " ";
		}
		cout << "\n\n";
		//������������ ����� ������������ ������������ ��������� ������� L
		det = det * L[i][i];
	}
	cout << "Determinant = " << det << endl;

	for (int i = 0; i < size_arr; i++)
	{
		delete[] L[i];
		delete[] U[i];
	}
	delete[] U;
	delete[] L;
}

//������� �� ����� �������
//�������� �������� array_matrix - ����������� ������������� �������
//�������� �������� size - ����������� �������
void output(int * array_matrix, int size)
{
	cout << endl << "Matrix:" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << get_el(array_matrix, i, j, size) << " ";
		cout << endl;
	}
}

//����������� ������� � ������� �� �����
//�������� �������� array - ������ ��������� �������
//�������� �������� size_arr - ����������� ���������� �������
void matrix_storage(int *array, int size_arr)
{
	double * A = NULL;
	double *JA = NULL;
	double *IA;
	IA = new double[size_arr + 1];

	int col = 1; //������� �������� IA
	int counter = 0; //������� ��� ������� JA
	int test = 0; //������� ��� ������� A

	for (int i = 0; i<size_arr; i++)
	{
		for (int j = 0; j<size_arr; j++)
		{
			if ((get_el(array, i, j, size_arr) != 0))
			{
				counter++;
				//realloc-����������������� ������ ������ � ������� A 

				A = (double*)realloc(A, counter * sizeof(double));
				JA = (double*)realloc(JA, counter * sizeof(double));
				A[test++] = get_el(array, i, j, size_arr);
				JA[counter - 1] = j + 1;
				col += 1;
			}
		}
		IA[0] = 1;
		IA[i + 1] = col;
	}

	cout << "N :  ";
	for (int i = 1; i < counter + 1; i++)
		cout << i << " ";
	cout << endl << "A :  ";
	for (int i = 0; i < counter; i++)
		cout << A[i] << " ";
	cout << endl << "JA :  ";
	for (int i = 0; i < counter; i++)
		cout << JA[i] << " ";
	cout << endl << "IA :  ";
	for (int i = 0; i < size_arr + 1; i++)
		cout << IA[i] << " ";
	cout << endl;

	free(A);
	free(JA);
	delete[] IA;
}

//������� ������������ ���-�� ��������� ��-�� � ������ �������
//�������� �������� array_matrix - ���������� �������
//�������� �������� size - ����������� ���������� �������
//���������� max - �������� ��������� ��-�� � ������
int width(int * array_matrix, int size)
{
	int value = 0;
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(abs(i - j) > size / 4)) // abs-������
			{
				value++;
				if (value>max) { max = value; }
			}
		}
		value = 0;
	}
	return max;
}

//������� ���-�� ��������� ���-��� � ������ �������
//�������� �������� array_matrix - ���������� �������
//�������� �������� size - ����������� ���������� �������
//�������� �������� i - ����� ������ �������
//���������� value - ���-� ��������� ��-�� � ������
int size_width(int *array, int size, int i)
{
	int value = 0;
	for (int j = 0; j < size; j++)
	{
		if (!(abs(i - j) > size / 4))
		{
			value++;
		}
	}
	return value;
}

//��������� ���������� ������� � ��������� ��� ���������
//�������� �������� array - ���������� �������
//�������� �������� size - ����������� ���������� �������
void pack(int *array, int size)
{
	int maks = width(array, size);
	int **pack = new int *[size]; //������
	for (int i = 0; i < size; i++)//������� 
	{
		pack[i] = new int[maks];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < maks; j++)
		{
			pack[i][j] = 0;
		}
	}

	int j_ = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(abs(i - j) > size / 4)) // ����� ������� �����
			{
				pack[i][j_] = get_el(array, i, j, size);
				j_++;
			}
		}
		j_ = 0;
	}

	for (int i = 0; i < size; i++)
	{
		if (size_width(array, size, i) != maks) // ����� ������� �����
		{
			int first = 0;
			if (i<size / 2)
			{
				for (int n = maks; n > 0; n--)
				{
					pack[i][n] = pack[i][size_width(array, size, i) - first];
					first++;
				}
				for (int n = 0; n < maks - size_width(array, size, i); n++)
				{
					pack[i][n] = 0;
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < maks; j++)
		{
			cout << pack[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int size; //������ �������
	cout << "Enter the size of the matrix: ";
	size = checking();

	int *array_matrix = new int[size_matrix(size)];
	cout << "Enter the elements of the matrix : " << endl;

	input(array_matrix, size);
	output(array_matrix, size);

	cout << endl << "Packaging :" << endl;
	pack(array_matrix, size);

	cout << endl << "Storage :" << endl;
	matrix_storage(array_matrix, size);

	cout << endl << "Matrix L :" << endl;
	det(array_matrix, size);
	delete[] array_matrix;
	system("pause");
	return 0;
}
