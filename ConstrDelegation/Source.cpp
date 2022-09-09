#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Book(const char* n, int p):Book(n)
	{
		pages = p;
	}// ����������� �������������!!!
	void Print();
	~Book()
	{
		delete[]name;
	}
};
void Book::Print()
{
	cout << "�������� �����: " << name << endl;
	cout << "���������� �������: " << pages << endl;
}
class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student() :step(0), book(nullptr, 0)
	{
		name = nullptr;
	}
	Student(const char* n, double st, const char* bookName, int bookPages):step(st),book(bookName,bookPages)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);

	}// ������������ ��������������!!!
	~Student()
	{
		delete[]name;
	}
	void Print();

};
void Student::Print()
{
	cout << "��� ��������: " << name << endl;
	cout << "���: " << step << endl;
	book.Print();
}
// �������� ������������� �������� � ������� main
int main()
{
	setlocale(LC_ALL, "ru");
	Student first("Dima", 3, "Harry Potter", 540);
	first.Print();
}