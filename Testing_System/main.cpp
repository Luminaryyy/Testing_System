#include "Libraries.h"
#include "file_management_module.h"
#include "teacher_mode.h"
#include "student_mode.h"

int standart(const char *valution)
{
	int val = atoi(valution);
	if (val >= 9 && val <= 10) return 5;
	if (val >= 7 && val <= 8) return 4;
	if (val >= 5 && val <= 6) return 3;
	else return 2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	ifstream student_file("students_information/students.txt");

	int choice = -1;
	string login, password, line;
	do
	{
		cout << "\t/-----------------------/" << endl;
		cout << "\t|¬ведите логин:\t|\n";
		cout << "\t/-----------------------/" << endl;

		cin >> login;

		cout << "\t/-----------------------/" << endl;
		cout << "\t|¬ведите пароль:\t|\n";
		cout << "\t/-----------------------/" << endl;

		cin >> password;
		getline(student_file, line);
		if (login == line[0] && password == line[1])

	} while (choice != 0);

	return 0;
}