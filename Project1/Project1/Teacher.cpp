#include <iostream>
#include <string>
#include "Students.h"
#include "Teacher.h"
using namespace std;



void get_average_score(Students *arr, int  &size) //������� ��� ��������� �������������
{

	Teacher teacher("Elena", "Aleksandrovna", NULL, NULL, NULL, NULL);

	teacher.Print(); //������� ��� � �������

	int sum = 0; //����� ������ ���� ���������
	for (int i = 0; i < size; i++) 
	{
		sum = sum + arr[i].GetValue_1() + arr[i].GetValue_2() + arr[i].GetValue_3() + arr[i].GetValue_4();
	}
	cout << endl;
	cout << "Average score Teacher : " << sum / (size * 4) << endl;
}



