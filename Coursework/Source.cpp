#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

struct Stack { // ��������� �����
private:
	struct Node { // ��������� ��� ��������� �����
	
	public:
		int data; // ������
		Node* pnext; // ��������� �� ��������� �������
		Node() : data(0), pnext(nullptr) {} // ����������� �� ���������
	};
	Node* pfirst; // ��������� �� ������ ������� �����
public:
	Stack() : pfirst(nullptr) {}  // ����������� �� ���������
	~Stack() { // ���������� (��� �� ��������� ������ ������� �� ����������� �����)
	
		Node* ptr = pfirst, * delptr; // ������� � ������� ��������
		while (ptr) // ���� �� ����� �� �����
		{
			delptr = ptr; // ��������� ��������� ��������� ������ ��������
			ptr = ptr->pnext; // ���������� �������� ���������
			free(delptr); // �������� ������
		}
		pfirst = nullptr; // ��������� ��������� �� ������ �������
	}
	void menu();// ���� �����
	int Get_Stack_Lenght();// ������� �����
	void Add_elem();// ���������� �������� � ����
	void Take_elem();// ������ �������� �����
	void Stack_output(Stack*);// ����� �����
	void F_Data_Output();// ����� ������� �������� ����� �� �����
	void CheckMemmory(Node*);// �������� �� ��������� ������
	bool Resemblence(Stack*);// �������� �� �������� ���� ������
	void isEmpty();// �������� �� ������� �����
	void flush();// �������� �����
	void Delete_root();// �������� ������� ��������
	void Change_value();// ��������� �������� ��������
	int Digits_Count(int);// ������� ���������� ���� � �����

};

class Lot // ����� ���������
{
	class Node_Lot {// ����� ��� ��������� ���������
	public:
		Stack* stack_data; // ������
		Node_Lot* next; // ��������� �� ��������� �������
		Node_Lot* prev; // ��������� �� ���������� �������
		Node_Lot() : stack_data(0), next(nullptr), prev(nullptr) {} // ����������� �� ���������
	};
	Node_Lot* first, * last; // ��������� �� ������ � ��������� ��������
public:
	Lot() : first(nullptr), last(nullptr) {} // ����������� �� ���������
	~Lot() { // ���������� ��� �������� ���������
		Node_Lot* ptr = first, * temp = nullptr; // ������� � ������� ��������
		while (ptr) // ���� �� ����� �����
		{
			temp = ptr; // ��������� ��������� ������ � ���� ���������
			ptr = ptr->next; // ��������� ��������� �������� �� ���������
			temp->stack_data->~Stack(); // �������� ����� �������� (����)
			free(temp); // �������� �������� ���������
		}
		first = last = nullptr; // �������� ���������� �� null (������ �� ����� ��������������)
	}
	void menu(); // ���� ���������
	void CheckMemmory(Stack*); // �������� �� ���������� ��������� ������
	int Get_Lot_Lenght();// �������� ����� ���������
	void Del_Stack();// �������� �������� n �� ���������
	void flush();// �������� �����
	void isEmpty();// �������� ������ �� ���������
	void Take_Stack();// ������ �������� n �� ���������
	void Add_Stack(Stack*);// ���������� �������� � ���������
	void Belonging();// �������� �� �������������� ���������
	void Lot_output();// ����� ��������� � ������
	void Reverse_output();// ����� ��������� � �����
};

void Lot::menu() {// ���� ���������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ����������� ������������ ������ ����� ������
	SetConsoleTextAttribute(hConsole, 11);// ����� ����� ������
	int choice = 0, opt = 0, ex = 0;// ��������������� ���������� ������, ����� �� �����
	Stack* st;
	do {// ���� ��� ������ ��� ���������� ������
		cout << " 1 - ������ ������ � ����������\n 2 - ��������� ������ � ���������� " << endl;
		cin >> choice;
		while (cin.fail() || (choice != 1 && choice != 2)) {// �������� �� ������������ �����
			cout << "������ ������ ���� �� ����������\n���������� �����" << endl;
			cin.clear();//������� �����
			cin.ignore(256, '\n');// ������� � ������ �����
			cin >> choice;// ����
			cout << endl;
		}
		system("CLS");
		if (choice == 1) {

			do {// ���� ��� ������� ����
				cout << ("\n 1 - ������� ��������� ������\n 2 - �������� �� ������ ���������\n 3 - ������� ���� �� ��������\n 4 - ����� ����\n 5 - �������� ���� � ���������\n 6 - ����������� �� ���� ���������\n 7 - ������� ��������� c ������\n 8 - ������� ��������� � �����\n 0 - ��������� ������") << endl;
				cout << endl;
				cin >> choice;
				while (!(!(cin.fail()) && (choice > -1 && choice < 9))) {// �������� �� ������������ �����
					cout << "������ ������ ���� �� ����������\n���������� �����" << endl;
					cin.clear();//������� �����
					cin.ignore(256, '\n');// ������� � ������ �����
					cin >> choice;// ����
					cout << endl;
				}
				switch (choice) {
				case  1:
					system("CLS");
					flush();// �������� �����
					break;
				case  2:
					system("CLS");
					isEmpty();// �������� ������ �� ���������
					break;
				case  3:
					system("CLS");
					Del_Stack();// �������� �������� n �� ���������
					break;
				case  4:
					system("CLS");
					Take_Stack();// ������ �������� n �� ���������
					break;
				case  5:
					if (Get_Lot_Lenght() == 10) {// �������� �� ������ ���������� ��������� �����
						cout << "��������� ������ ��������� ���������" << endl;
						break;
					}
					system("CLS");
					st = (Stack*)malloc(sizeof(Stack));// ��������� ������
					CheckMemmory(st);// �������� �� ���������� ��������� ������
					*st = Stack();// ����� ������������ ����� ��� ��������� ������
					st->menu();// ����� ���� ��� �������� ������ �������� ���������
					Add_Stack(st);//���������� �����
					break;
				case  6:
					system("CLS");
					Belonging();// �������� �� �������������� ���������
					break;
				case  7:
					system("CLS");
					Lot_output(); // ����� ������� ��� ������ �� ����� ����� ���������
					break;
				case 8:
					system("CLS");
					Reverse_output();// ����� ������� ��� ������ �� ����� ����� ��������� � �����
					break;
				case  0:
					system("CLS");
					this->~Lot();//�������� ���������
					break;
				
				}

			} while (choice != 0);
		}
	} while (choice != 2);
}

void Lot::Reverse_output() {// ������� ������ �� ����� ����� ��������� � �����
	if (!first) { //�������� �� �������
		cout << "��������� �����" << endl;
		return;
	}
	Node_Lot* ptr = last;
	while (ptr) {//���� �� ����� ������� ��������
		ptr->stack_data->Stack_output(ptr->stack_data);// ����� ������� 
		if (ptr->prev) {// �������� ���������� ��������
			cout << endl;
			cout << " ||" << endl;
		}
		ptr = ptr->prev;// ����������� ��������� �� ����������
	}
}

void Lot::Del_Stack() {
	if (!first) {//�������� �� �������
		cout << "��������� �����" << endl;
		return;
	}
	Node_Lot* ptr = first;
	Stack obj;
	cout << "������� �������� ����� ��� ��������" << endl;
	obj.menu();
	while (ptr) {
		if (ptr->stack_data->Resemblence(&obj)) {// ���� ��������� ������ ��������� �������, ����� ����� ���������� ��������� ����������
			ptr->stack_data->~Stack(); // ����� ����������� ��� �������� ������� ��������
			// ���� ���������� �������������� ���������� � ���������� ��������
			if (ptr->prev) {
				ptr->prev->next = ptr->next;
			}
			else {
				first = ptr->next;
			}
			if (ptr->next) {
				ptr->next->prev = ptr->prev;
			}
			else {
				last = ptr->prev;
			}

			free(ptr);
			cout << "�������� �������" << endl;
			return;
		}
		ptr = ptr->next; 

	}
	cout << "�������� �� �������" << endl;
}

void Lot::Take_Stack() {// ������ �������� n �� ���������
	Node_Lot* ptr = first;
	if (!first) {
		cout << "��������� �����" << endl;
		return;
	}
	int choice = 0;
	cout << "����� ���� ��� �������: ";
	cin >> choice;
	cout << endl;
	if (!(choice > 0 && choice <= Get_Lot_Lenght())) {// �������� ������������� ������
		cout << "��������� �������� " << Get_Lot_Lenght() << " ���������" << endl;
		cout << "����������, �������� ������� �� ������������� ��������� " << endl;
		return;
	}
	for (int i = 1; i < choice; i++) {
		ptr = ptr->next;
	}
	cout << "������ ���� �����: " << endl;
	ptr->stack_data->Stack_output(ptr->stack_data);// ����� �����
	ptr->stack_data->~Stack();// �������� �����
	// ���� ���������� �������������� ���������� � ���������� ��������
	if (ptr->prev) {
		ptr->prev->next = ptr->next;
	}
	else {
		first = ptr->next;
	}
	if (ptr->next) {
		ptr->next->prev = ptr->prev;
	}
	else {
		last = ptr->prev;
	}

	free(ptr);
}

void Lot::Lot_output() {// ������� ������ �� ����� ����� ��������� � ������
	if (!first) {
		cout << "��������� �����" << endl;
		return;
	}
	Node_Lot* ptr = first;
	while (ptr) {
		ptr->stack_data->Stack_output(ptr->stack_data); // ����� �����
		if (ptr->next) {
			cout << endl;
			cout << " ||" << endl;
		}
		ptr = ptr->next;
	}
}

void Lot::isEmpty() {// �������� �� �������
	if (Get_Lot_Lenght()) {// ��������� ����� �����
		cout << "� ��������� ���������� " << Get_Lot_Lenght() << " ���������" << endl;
		return;
	}
	cout << "��������� �����" << endl;

}

void Lot::flush() {
	if (!first) {
		cout << "��������� �����" << endl;
		return;
	}
	this->~Lot(); // �������� ���������
	cout << "��������� �������" << endl;
}

void Lot::Belonging() { //�������� �� ��������������
	if (!first) {
		cout << "��������� �����" << endl;
		return;
	}
	Node_Lot* ptr = first;// ������� � ������� ��������
	Stack obj;// �������� ������� �����
	obj.menu();// ����� ���� �����
	bool flag = 0;// ���� ��� �������� �� ��������� � ����
	while(ptr) {// ���� ��� �������� ���� ��������� ���������
		if (ptr->stack_data->Resemblence(&obj)) // ����� �������� ��� ������� ��������
		{
			flag = 1;
			break;
		}
		ptr = ptr->next; // ����� ����� ���������� ���������
	}
	if (flag) // ��� ���������� ������� ����� ���������������� ���������
	{
		cout << "�������� ����������� ���������" << endl;;
		return;
	} // ��� ���������������� ��������� ����� ���������
	cout << "�������� �� ����������� ���������" << endl;
}

void Lot::CheckMemmory(Stack* st) {
	if (!st) { //�������� �� ��������� ������
		cout << "�� ������� �������� ������" << endl;
		exit(0);
	}
}

void Lot::Add_Stack(Stack* st) {
	Node_Lot* ptr = first;
	if (!first) { // �������� ������� ��������, ���� ��������� �����
		last = first = (Node_Lot*)malloc(sizeof(Node_Lot));//��������� ������
		if (!last && !first) { //�������� �� ��������� ������
			cout << "�� ������� �������� ������" << endl;
			exit(0);
		}
		*first = Node_Lot();
		first->stack_data = st;
		return;
	}

	while(ptr) {//������ �� ���� ��������� ���������
		if (ptr->stack_data->Resemblence(st)) {//�������� �� ��������� ������
			printf("\n����� �������� ��� �������\n");
			return;
		}
		ptr = ptr->next;// ����� ����� ���������� ��������� 
	}

	
	ptr = (Node_Lot*)malloc(sizeof(Node_Lot));//  ��������� ������ ��� ����������� �������
	if (!ptr) {
		cout << "�� ������� �������� ������" << endl;
		exit(0);
	}
	*ptr = Node_Lot(); // ����� ������������ ��������� ��� ��������� ���� ������ / ������
	ptr->prev = last; // �������� ����� ������ � ������
	last->next = ptr;
	ptr->next = NULL;
	ptr->stack_data = st;
	last = ptr;
}

int Lot::Get_Lot_Lenght() { // ������� ���������� ��������� �����
	Node_Lot* ptr = first;
	int counter = 0;
	while (ptr) {
		counter++; // �������
		ptr = ptr->next; // ����������� ���������
	}
	return counter; // ����������� ���������� ���������
}



void Stack::menu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// ����������� ������������ ������ ����� ������
	SetConsoleTextAttribute(hConsole, 11);// ����� ����� ������
	int choice = 0, ex = 0;// ��������������� ���������� ������, ����� �� �����
	Stack* fake = NULL;// �������� �������� ��������� �� ���� ��� ����������� �������� � ������� ������ �����
	do {// ���� ��� ������ ��� ����� ������
		cout << " 1 - ������ ������ �� ������\n 2 - ��������� ������ �� ������ " << endl;
		cin >> choice;
		while (1) {
			if (cin.fail() || (choice == 2 && pfirst == NULL)) {// �������� ������������ ������
				cout << "����������, ������� ������� �������� �����!" << endl;
				cin.clear();//������� �����
				cin.ignore(256, '\n');// ������� � ������ �����
				cin >> choice;// ����
				cout << endl;
			}
			else if (cin.fail() || (choice != 1 && choice != 2)) {
				cout << "������ ������ ���� �� ����������\n���������� �����" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> choice;
				cout << endl;
			}
			else {
				break;
			}
		}
		system("CLS");
		if (choice == 1) {
			do {// ���� ��� ������ ����
				cout << ("\n 1 - ������� ���� ������\n 2 - �������� �� ������ ����\n 3 - �������� �������� ������� ��������\n 4 - ������� ������ ������� �����\n 5 - ����� ������� �����\n 6 - �������� �������� ������� ��������\n 7 - �������� ������� � ����\n 8 - ������� ����\n 0 - ��������� ������ �� ������") << endl;
				cout << endl;
				cin >> choice;
				while (!(!(cin.fail()) && (choice > -1 && choice < 9))) {
					cout << "������ ������ ���� �� ����������\n���������� �����" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> choice;
					cout << endl;
				}
				switch (choice) {
				case  1:
					system("CLS");
					flush();// �������� �����
					break;
				case  2:
					system("CLS");
					isEmpty();// �������� �� ������� �����
					break;
				case  3:
					system("CLS");
					F_Data_Output();// ����� ������� �������� ����� �� �����
					break;
				case  4:
					system("CLS");
					Delete_root();// �������� ������� ��������
					break;
				case  5:
					system("CLS");
					Take_elem();// ������ �������� �����
					break;
				case  6:
					Change_value();// ��������� �������� ��������
					system("CLS");
					Stack_output(fake);// ����� �����
					break;
				case  7:
					if (Get_Stack_Lenght() == 10) {// �������� �� ���������� ���������� ���������
						cout << "��������� ������ ��������� �����" << endl;
						break;
					}
					Add_elem();// ���������� �������� � ����
					system("CLS");
					cout << "\n���������� ��������� � �����: " << Get_Stack_Lenght() << endl;
					Stack_output(fake);// �����
					break;
				case  8:
					system("CLS");
					cout << "���������� ��������� � �����: " << Get_Stack_Lenght() << endl;
					Stack_output(fake);// �����
					break;
				case  0:
					system("CLS");
					break;
				}
			} while (choice != 0);
		}

	} while (choice != 2);
} 

int Stack::Digits_Count(int num) { // ������� ���������� ���� � �����
	int counter = 0;
	while(num>0) {
		counter++;// �������
		num = num / 10;// ������� �� 10/��������� ��������� �����
	}
	return counter;
}

void Stack::flush() {// �������� �����
	if (pfirst == NULL)// �������� �� �������
	{
		cout << "������ ����" << endl;
	}
	else {
		this->~Stack();//�������� �����
		cout << "������ ������" << endl;
	}
}

void Stack::F_Data_Output() {// ����� ������� �������� ����� �� �����
	if (pfirst == NULL) {// �������� �� �������
		cout << "������ ����, ������� ������� ��������" << endl;
	}
	else {
		cout << "������ ������� �����: " << pfirst->data << endl; 
	}
}

void Stack::isEmpty() {// �������� �� ������� �����
	if (pfirst == NULL) {
		cout << "������ ����" << endl;
	}
	else {
		cout << "� ������ �������� " << Get_Stack_Lenght() << " ���������" << endl;
	}
}

void Stack::Delete_root() {// �������� ������� ��������
	if (pfirst == NULL) {
		cout << "������ ����, ������� ������� ��������" << endl;
	}
	else {
		struct Node* next_root;
		next_root = pfirst->pnext;
		free(pfirst);
		pfirst = next_root;
	}
}

void Stack::Take_elem() {// ������ �������� �����
	if (pfirst == NULL) {
		cout << "������ ����, ������� ������� ��������" << endl;
	}
	else {
		cout << "������ ������� �����: " << pfirst->data << endl;
		Delete_root();
	}
}

int Stack::Get_Stack_Lenght() {// ���������� ����� �����
	int counter = 0;
	Node* p = pfirst;
	while (p != NULL) {
		counter++;// �������
		p = p->pnext;// ����� ����� ����������
	}
	return counter;// ����������� ����� �����
}

void Stack::Change_value() {// ��������� �������� ��������
	int add = 0;
	if (pfirst == NULL) {
		cout << "������ ����, ������� ������� ��������" << endl;

	}
	else {
		cout << "�������� �������� ��������: ";
		cin >> add;
		while (cin.fail()) { // �������� �� ������������ ����� �������� ���� int
			cout << "\n����������, ������� ������������� ����������� �����" << endl; 
			cin.clear();//������� �����
			cin.ignore(256, '\n');// ������� � ������ �����
			cout << "\n�������� �������� ��������: ";
			cin >> add;// ����
			cout << endl;
		}
		pfirst->data = add;

	}
}

void Stack::Add_elem() {// ���������� �������� � ����
	int add = 0;
	cout << "�������� �������� ��������: ";
	cin >> add;
	while (cin.fail()) {// �������� �� ������������ ����� �������� ���� int
		cout << "\n����������, ������� ������������� ����������� �����" << endl;
		cin.clear();//������� �����
		cin.ignore(256, '\n');// ������� � ������ �����
		cout << "\n�������� �������� ��������: ";
		cin >> add;// ����
		cout << endl;
	}
	if (pfirst != NULL) {// �������� �� ������� ���������
		Node* new_s, * p;
		new_s = (Node*)malloc(sizeof(Node));// ��������� ������
		CheckMemmory(new_s);// �������� ��������� ������
		p = pfirst->pnext;// ���������� ����� ������ � ������
		pfirst->pnext = new_s;
		new_s->pnext = p;
		new_s->data = pfirst->data;
		pfirst->data = add;
	}
	else {
		pfirst = (Node*)malloc(sizeof(Node));// ��������� ������
		CheckMemmory(pfirst);// �������� ��������� ������
		pfirst->data = add;// ���������� ������
		pfirst->pnext = NULL;
	}
}

void Stack::CheckMemmory(Node* elem) {
	if (elem == NULL) { // �������� �� ��������� ������
		cout << "������ �� ���� ��������" << endl;
		exit(0);
	}
}

void Stack::Stack_output(Stack* el) { // ����� �����
	if (pfirst != NULL) {// �������� �� ������� �����
		setlocale(LC_ALL, "C");// ������������ �� ������������ ���������� �������� ��� ������������� �������� �� ����������� ���������� ASCII
		Node* d = pfirst;
		if (el != NULL) {// �������� �� ��������� �������� �� ����, ���� ��������� �����������, ����� ���������� �� ������� ������ ��������� 
			Node* d = el->pfirst;
		}
		int len = 0, counter = 0;
		char temp0, temp1 = 201, temp2 = 205, temp3 = 187, temp4 = 186, temp5 = 200, temp6 = 188, temp7 = 203, temp8 = 202; // ���������� �������� ����� ������ ���������� 
		len = 0;
		while (d != NULL) {// ��������� ����� �����
			len++;
			d = d->pnext;// ����� ��� ��������� �����
		}
		d = pfirst;

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// ����������� ������������ ������ ����� ������
		while (counter < len) {
			SetConsoleTextAttribute(hConsole, 1);// ����� �����
			cout << temp1 << temp2;// ����� �����
			if (d->data == 0) {
				cout << temp2;
			}
			else {
				for (int i = 0; i < Digits_Count(d->data); i++) {// ������� ���������� ���� ��� ����������� ����� ����� ��� ������
					cout << temp2;
				}
			}
			cout << temp2 << temp3 << "   ";// ����� �����
			d = d->pnext;// ����� ��� ��������� �����
			counter++;
		}
		d = pfirst;
		cout << endl;
		counter = 0;
		while (counter < len) {
			SetConsoleTextAttribute(hConsole, 6);// ����� �����
			temp0 = ' ';
			if (d->pnext == NULL) {
				cout << temp4 << temp0 << d->data << ' ' << temp4 << "   ";// ����� ����� ������ � ������� ��� ��������� ��������
			}
			else {
				cout << temp4 << temp0 << d->data << ' ' << temp4 << "==>";// ����� ����� ������ � ������� ��� ����� ������ ��������
			}

			counter++;
			d = d->pnext;// ����� ��� ��������� �����
		}
		cout << endl;
		counter = 0;
		d = pfirst;
		while (counter < len) {
			SetConsoleTextAttribute(hConsole, 11);// ����� �����
			cout << temp5 << temp2;// ����� �����
			if (d->data == 0) {
				cout << temp2;// ����� �����
			}
			else {
				for (int i = 0; i < Digits_Count(d->data); i++) { // ������� ���������� ���� ��� ����������� ����� ����� ��� ������
					cout << temp2;// ����� �����
				}
			}
			cout << temp2 << temp6 << "   ";// ����� �����
			counter++;
			d = d->pnext;// ����� ��� ��������� �����
		}
		d = pfirst;
		setlocale(0, "rus");// ����������� ����������� ������������� �������� �����
	}
	else {
		cout << "������ ����, ������� ������� ��������" << endl;
	}
}	

bool Stack::Resemblence(Stack* st) {
	Node* ptr = pfirst, * tempntr = st->pfirst; // �������� ���� ���������� �� ��� �����
	bool flag = 0; // ���� ��� �������� ���������
	if (!ptr && !tempntr) { // �������� �� ������� ���� ������ 
		return true;
	}
	while (ptr && tempntr) {// ���� �� ����� ����� ����������
		if ((ptr->data == tempntr->data) && (!ptr->pnext == !tempntr->pnext)) {// �������� �� ��������� �������� � ����� ������
			flag = true;
		}
		else {
			flag = false;  // ���� ������� ���� ���� �������������� - ������������ false
			break;
		}
		ptr = ptr->pnext;// ����� ��� ��������� �����
		tempntr = tempntr->pnext;
	}
	return flag;
}

void main()
{
	setlocale(0, "rus");
	Lot obj;// �������� ������� ��������
	obj.menu();// ����� ���� ���������
}
