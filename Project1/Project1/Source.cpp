#include <iostream>
using namespace std;

class Queue {
public:
	Queue();
	void push(int num);
	void print();
	int size();
	void pop_front();
	void pop_back();
	int checking();
	int front();
	int back();
private:
	const int SIZE = 40; //�������� ����� ������ �����
	int *queue;
	int value, last;
};
//�����������
Queue::Queue() {
	queue = new int[SIZE];
	value = last = 0;
}
//����� ��������� �������
void Queue::print() {
	for (int i = value + 1; i < last + 1; i++)
	{
		if (queue[i] == 1)
			std::cout << " white";
		if (queue[i] == 2)
			std::cout << " black";
	}
}
//��������� �������� � �������
void Queue::push(int num) {
	if (last + 1 == value || (last + 1 == SIZE && !value)) {
		std::cout << "FULL" << std::endl;
		return;
	}
	last++;
	if (last == SIZE) last = 0;
	queue[last] = num;
}

void Queue::pop_front() { // ���������� ������� �������� �� �������
	if (value == last) {
		std::cout << "FULL" << std::endl;
		return;
	}
	value++;
	if (value == SIZE) value = 0;
}

void Queue::pop_back() { // ���������� ���������� �������� �� �������
	if (value == last) {
		std::cout << "FULL" << std::endl;
		return;
	}
	last--;
	if (last == SIZE) last = 0;
}


//����������� ������� �������
int Queue::size() {
	int s = 0;
	for (int i = value; i<last; i++)
		s++;
	return s;
}
// ��������� ������� �������
int Queue::back() {
	return queue[last];
}
// ������ ������� �������
int Queue::front() {
	return queue[value + 1];
}

int Cheking1() //������ �� ������
{
	int value = 0;
	while (true)
	{
		cin >> value;
		if (!cin)
		{
			cout << "WRONG!!Re-enter" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else
			return value;
	}

}


void Cheking(int &fg, int &lg, int &fw, int &lw, int &step) //������ �� ������
{

	cout << "Pls enter count first Gray mous:";
	fg = Cheking1();
	cout << "Pls enter count first  White mous:";
	fw = Cheking1();
	cout << "Pls enter count last Gray mous:";
	lg = Cheking1();
	while (!(lg < fg))//���� ����4��� ���-�� ����� ������ ��4�������
	{
		cout << "Last gray mouse more first gray mouse!!Re-enter" << endl;
		cin.clear();
		while (cin.get() != '\n');
		lg = Cheking1();
	}
	cout << "Pls enter count last White mous:";
	lw = Cheking1();
	while (!(lw < fw))//���� ����4��� ���-�� ����� ������ ��4�������
	{
		cout << "Last white mouse more first white mouse!!Re-enter" << endl;
		cin.clear();
		while (cin.get() != '\n');
		lw = Cheking1();
	}
	cout << "Pls enter step cat:";
	step = Cheking1();
	while (!(step != 0))//���� ����� �� ����� ������ ������ �����
	{
		cout << "Re-enter" << endl;
		cin.clear();
		while (cin.get() != '\n');
		step = Cheking1();
	}
}



int main()
{
	int first_gray_mouse;//��������� ���-�� ����� �����
	int last_gray_mouse;//�������� ���-�� ����� �����
	int first_white_mouse;//��������� ���-�� ����� �����
	int last_white_mouse;//�������� ���-�� ����� �����
	int step;//��� �����
	Cheking(first_gray_mouse, last_gray_mouse, first_white_mouse, last_white_mouse, step); //���������� � ����������

	int difference_white = first_white_mouse - last_white_mouse;//���-�� ��������� ����� �����
	int difference_gray = first_gray_mouse - last_gray_mouse;//����- ��������� ����� �����

	Queue deck1; //����������� �4�����
	Queue deck2; //��������� ����
	Queue deck3; //����� ����



	int counter_1 = difference_gray;//�4���� ��� ��������� ����� �����
	int counter_2 = difference_white;//�4���� ��� ��������� ����� �����
	for (int i = 0; i < difference_white + difference_gray; i++)//��������� deck2 ���������� ������
	{
		if (counter_1 != 0)
		{
			deck2.push(1);
			counter_1--;
		}
		else
		{
			deck2.push(2);
			counter_2--;
		}
	}


	int counter_3 = last_white_mouse;//�4��4�� ��� ���. ����� ����� �����
	int counter_4 = last_gray_mouse;//�4��4�� ��� ���. ����� ����� �����

	for (int i = 0; i < last_white_mouse + last_gray_mouse; i++)//��������� deck3 ���. ������ ������
	{
		if (counter_4 != 0)
		{
			deck3.push(1);
			counter_4--;
		}
		else
		{
			deck3.push(2);
			counter_3--;
		}
	}
	////////////////////////////////////////////////////////////////

	int t = 0;//������� ���� �����
	bool eat = false;//��� ��� �� ���
	for (int i = 1; i < first_white_mouse + first_gray_mouse + 1; i++)//���-�� ����� �����
	{

		for (int j = 1; j < difference_white + difference_gray + 1; j++)//����� �� ���-�� ����� �����
		{
			t = j * step;

			if (j * step > first_white_mouse + first_gray_mouse) //���� ��� ����� �� �������� ������ ���� �������
			{
				t = t % (first_white_mouse + first_gray_mouse);
			}

			if (t == i)//���� ���
			{
				eat = true;
			}
		}

		if (eat == true)//���� ���
		{
			deck1.push(deck2.front());//��������� � �����,�.� ������� �������� ����� �����
			deck2.pop_front();
			eat = false;
		}
		else
		{
			deck1.push(deck3.back());
			deck3.pop_back();
		}

	}

	deck1.print();
	std::cout << std::endl;
	system("pause");
	return 0;
}
