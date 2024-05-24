#include "Libraries.h"
#include "file_management_module.h"
#include "teacher_mode.h"
#include "student_mode.h"

bool checkadmin(string login, string password)
{
	string admin_login = "admin", admin_password = "admin";

	if ((login == admin_login) && (password == admin_password)) return true;
	return false;
}
	
int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 > NUL");
	ifstream student_file("students_information/students.txt");

	string login, password;

	cout << "\t/-----------------------/" << endl;
	cout << "\t|введите логин:\t\t|\n";
	cout << "\t/-----------------------/" << endl;

	cin >> login;

	cout << "\t/-----------------------/" << endl;
	cout << "\t|введите пароль:\t|\n";
	cout << "\t/-----------------------/" << endl;

	cin >> password;

	if (checkadmin(login, password))
	{
		cout << "вы вошли на правах администратора";
		//admin_mode();
		return 0;
	}
	else
	{
		string space = "-", line1 = "-", line2 = "-", name = "-", surname = "-";

		for (int i = 1; i <= 374; i++)
		{
			if (i % 15 == 1)
			{
				getline(student_file, name);
				name.erase(0, 5);
			}
			else if (i % 15 == 2)
			{
				getline(student_file, surname);
				surname.erase(0, 9);
			}
			else if (i % 15 == 3)
			{
				getline(student_file, line1);
				line1.erase(0, 7);
			}
			else if (i % 15 == 4)
			{
				getline(student_file, line2);
				line2.erase(0, 8);
			}
			else getline(student_file, space);

			if ((line1 == login) && (line2 == password)) break;
		}

		if (!((line1 == login) && (line2 == password)))
		{
			cout << "Допуск запрещён";
			return 0;
		}

		else
		{
			cout << endl << "Добро пожаловать, " << surname << " " << name << "!" << endl;
			MODE_MAIN(login);
		}
	}

	student_file.close();
	return 0;
}