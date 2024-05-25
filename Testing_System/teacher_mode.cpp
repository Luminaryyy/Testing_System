#include "teacher_mode.h"
#include "file_management_module.h"

int PushStudents(struct Students* stud, const string& fileName, int size)
{
	ifstream inputFile(fileName);

	int k = 0;

	for (int i = 0; i < size; i++)
	{
		getline(inputFile, stud[i].name);
		if (stud[i].name == "")
		{
			break;
		}
		if (stud[i].name.substr(0, 3) == "Имя")
		{
			k++;
		}
		getline(inputFile, stud[i].surname);
		getline(inputFile, stud[i].login);
		getline(inputFile, stud[i].password);
		getline(inputFile, stud[i].loops);
		getline(inputFile, stud[i].arrays);
		getline(inputFile, stud[i].str);
		getline(inputFile, stud[i].recursions);
		getline(inputFile, stud[i].structs);
		getline(inputFile, stud[i].files);
		getline(inputFile, stud[i].pointers);
		getline(inputFile, stud[i].dinamics);
		getline(inputFile, stud[i].controltests);
		getline(inputFile, stud[i].GPA);
		getline(inputFile, stud[i].space);
	}

	inputFile.close();


	return k;
}

void outputStruct(struct Students* stud, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << stud[i].name << endl;
		cout << stud[i].surname << endl;
		cout << stud[i].login << endl;
		cout << stud[i].password << endl;
		cout << stud[i].loops << endl;
		cout << stud[i].arrays << endl;
		cout << stud[i].str << endl;
		cout << stud[i].recursions << endl;
		cout << stud[i].structs << endl;
		cout << stud[i].files << endl;
		cout << stud[i].pointers << endl;
		cout << stud[i].dinamics << endl;
		cout << stud[i].controltests << endl;
		cout << stud[i].GPA << endl;
		cout << stud[i].space << endl;
	}
}

void writeStudents(struct Students* stud, const string& fileName, int& size)
{
	ofstream outputFile(fileName, ofstream::out | ofstream::trunc);

	for (int i = 0; i < size; i++)
	{
		outputFile << stud[i].name << endl;
		outputFile << stud[i].surname << endl;
		outputFile << stud[i].login << endl;
		outputFile << stud[i].password << endl;
		outputFile << stud[i].loops << endl;
		outputFile << stud[i].arrays << endl;
		outputFile << stud[i].str << endl;
		outputFile << stud[i].recursions << endl;
		outputFile << stud[i].structs << endl;
		outputFile << stud[i].files << endl;
		outputFile << stud[i].pointers << endl;
		outputFile << stud[i].dinamics << endl;
		outputFile << stud[i].controltests << endl;
		outputFile << stud[i].GPA << endl;
		outputFile << stud[i].space << endl;
	}
}

void delStudents(struct Students* stud, const string& fileName, int& size)
{
	string line1;
	string line2;
	string line3 = "Имя: ";
	string line4 = "Фамилия: ";

	bool flag = true;

	while (flag)
	{
		cout << "Введите имя студента, которого хотите удалить: "; cin >> line1;
		cout << "Введите фамилию студента, которого хотите удалить: "; cin >> line2;

		for (int i = 0; i < size; i++)
		{
			if ((line3 + line1) == stud[i].name && (line4 + line2) == stud[i].surname)
			{
				for (int j = i; j < size; j++)
				{
					stud[j] = stud[j + 1];
				}
				size--;
				flag = false;
				break;
			}
			if (i == size - 1)
			{
				cout << "Студент не найден, пожалуйста, повторите попытку" << endl;
			}
		}
	}

	writeStudents(stud, fileName, size);
}

void addStudents(struct Students* stud, const string& fileName, int& size)
{
	writeStudents(stud, fileName, size);

	string name;
	string surname;
	string login;
	string password;

	cout << "Введите имя студента, которого хотите добавить: "; cin >> name;
	cout << "Введите фамилию студента, которого хотите добавить: "; cin >> surname;
	cout << "Введите логина студента, которого хотите добавить: "; cin >> login;
	cout << "Введите пароль студента, которого хотите добавить: "; cin >> password;

	size++;

	stud[size - 1].name = "Имя: " + name;
	stud[size - 1].surname = "Фамилия: " + surname;
	stud[size - 1].login = "Логин: " + login;
	stud[size - 1].password = "Пароль: " + password;
	stud[size - 1].loops = "Циклы: -";
	stud[size - 1].arrays = "Массивы: -";
	stud[size - 1].str = "Строки: -";
	stud[size - 1].recursions = "Рекурсия: -";
	stud[size - 1].structs = "Структуры: -";
	stud[size - 1].files = "Файлы: -";
	stud[size - 1].pointers = "Адреса и указатели: -";
	stud[size - 1].dinamics = "Динамическая память: -";
	stud[size - 1].controltests = "Итоговый тест: -";
	stud[size - 1].GPA = "Средний балл: -";
	//stud[size - 1].space = "\n";

	ofstream outputFile(fileName, ofstream::out | ofstream::app);

	outputFile << stud[size - 1].name << endl;
	outputFile << stud[size - 1].surname << endl;
	outputFile << stud[size - 1].login << endl;
	outputFile << stud[size - 1].password << endl;
	outputFile << stud[size - 1].loops << endl;
	outputFile << stud[size - 1].arrays << endl;
	outputFile << stud[size - 1].str << endl;
	outputFile << stud[size - 1].recursions << endl;
	outputFile << stud[size - 1].structs << endl;
	outputFile << stud[size - 1].files << endl;
	outputFile << stud[size - 1].pointers << endl;
	outputFile << stud[size - 1].dinamics << endl;
	outputFile << stud[size - 1].controltests << endl;
	outputFile << stud[size - 1].GPA << endl;
	//outputFile << stud[size - 1].space << endl;
}

void changeProgress(struct Students* stud, const string& fileName, int& size2)
{
	string line1;
	string line2;
	string line3 = "Имя: ";
	string line4 = "Фамилия: ";

	bool flag = true;

	while (flag)
	{
		cout << "Введите имя студента, в прогресс которого хотите внести изменения: "; cin >> line1;
		cout << "Введите фамилию студента, в прогресс которого хотите внести изменения: "; cin >> line2;

		for (int i = 0; i < size2; i++)
		{
			if ((line3 + line1) == stud[i].name && (line4 + line2) == stud[i].surname)
			{
				flag = false;
				break;
			}
			if (i == size2 - 1)
			{
				cout << "Студент не найден, пожалуйста, повторите попытку" << endl;
			}
		}
	}

	for (int i = 0; i < size2; i++)
	{
		if ((line3 + line1) == stud[i].name && (line4 + line2) == stud[i].surname)
		{
			int o = 0;

			do
			{
				cout << "Введите номер темы, в которой хотите внести изменение в прогресс студента, где:" << \
					endl << "0 - выход из меню изменения програсса студентов" << endl << "1 - циклы" << endl << "2 - массивы" << \
					endl << "3 - строки" << endl << "4 - рекурсия" << endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << \
					endl << "8 - динамическая память" << endl << "9 - итоговый тест" << endl;

				while (true)
				{
					cin >> o;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o)
				{
				case 0:
					cout << "Вы вышли из меню редактирования прогресса" << endl;
					break;

				case 1:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].loops[size(stud[i].loops) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 2:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].arrays[size(stud[i].arrays) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 3:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].str[size(stud[i].str) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 4:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].recursions[size(stud[i].recursions) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 5:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].structs[size(stud[i].structs) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 6:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].files[size(stud[i].files) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 7:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].pointers[size(stud[i].pointers) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 8:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].dinamics[size(stud[i].dinamics) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}
					if (stud[i].controltests[size(stud[i].controltests) - 1] >= 49 && stud[i].controltests[size(stud[i].controltests) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].controltests[size(stud[i].controltests) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				case 9:
				{
					cout << "Вы можете вносить соответствующие изменения" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "Напишите оценку, на которую хотите заменить нынешний балл студента: "; cin >> number;
					}
					stud[i].controltests[size(stud[i].controltests) - 1] = number;

					int k = 1;
					double sum = number - '0';

					if (stud[i].arrays[size(stud[i].arrays) - 1] >= 49 && stud[i].arrays[size(stud[i].arrays) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].arrays[size(stud[i].arrays) - 1] - '0';
					}
					if (stud[i].str[size(stud[i].str) - 1] >= 49 && stud[i].str[size(stud[i].str) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].str[size(stud[i].str) - 1] - '0';
					}
					if (stud[i].recursions[size(stud[i].recursions) - 1] >= 49 && stud[i].recursions[size(stud[i].recursions) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].recursions[size(stud[i].recursions) - 1] - '0';
					}
					if (stud[i].structs[size(stud[i].structs) - 1] >= 49 && stud[i].structs[size(stud[i].structs) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].structs[size(stud[i].structs) - 1] - '0';
					}
					if (stud[i].files[size(stud[i].files) - 1] >= 49 && stud[i].files[size(stud[i].files) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].files[size(stud[i].files) - 1] - '0';
					}
					if (stud[i].pointers[size(stud[i].pointers) - 1] >= 49 && stud[i].pointers[size(stud[i].pointers) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].pointers[size(stud[i].pointers) - 1] - '0';
					}
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] >= 49 && stud[i].dinamics[size(stud[i].dinamics) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].dinamics[size(stud[i].dinamics) - 1] - '0';
					}
					if (stud[i].loops[size(stud[i].loops) - 1] >= 49 && stud[i].loops[size(stud[i].loops) - 1] <= 53)
					{
						k++;
						sum = sum + stud[i].loops[size(stud[i].loops) - 1] - '0';
					}

					sum = sum / k;
					sum = round(sum * 10) / 10;

					stud[i].GPA = stud[i].GPA.substr(0, 14);

					ostringstream ss;
					ss << sum;

					string numberAsString = ss.str();

					stud[i].GPA = stud[i].GPA + numberAsString;

					writeStudents(stud, fileName, size2);
					cout << "Изменения успешно внесены" << endl;
					break;
				}

				default:
					cout << "Тема выбрана неверно, пожалуйста, повторите попытку" << endl;
					break;
				}
			} while (o != 0);
		}
	}
}

void outputStudents(struct Students* stud, const string& fileName, int& size2)
{
	int o = 0;
	do
	{
		cout << "Укажите какой формат вывода информации о студентах вы хотите увидеть, где:" << endl << \
			"0 - выход из меню отображения информации" << endl << "1 - отображение информации о студентах по всем темам" << \
			endl << "2 - отображение информации о студентах по конкретной теме" << endl \
			<< "3 - отображение информации о студентах по итоговому тесту " << endl << \
			"4 - отображение информации о среднем балле студентов" << endl;

		while (true)
		{
			cin >> o;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}

		switch (o)
		{
		case 0:
			cout << "Вы вышли из меню вывода информации о студентах" << endl;
			break;

		case 1:
		{
			cout << "Вы выбрали отображение информации о студентах по всем темам" << endl;
			cout << "\"-\" означает, что студент не проходил тестирование по данной теме" << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << stud[i].name << endl;
				cout << stud[i].surname << endl;
				cout << stud[i].loops << endl;
				cout << stud[i].arrays << endl;
				cout << stud[i].str << endl;
				cout << stud[i].recursions << endl;
				cout << stud[i].structs << endl;
				cout << stud[i].files << endl;
				cout << stud[i].pointers << endl;
				cout << stud[i].dinamics << endl;
				cout << stud[i].controltests << endl;
				cout << stud[i].GPA << endl;
				cout << stud[i].space << endl;
			}
			break;
		}

		case 2:
		{
			int o1 = 0;

			do
			{
				cout << "Вы выбрали отображение информации о студентах по конкретной теме" << endl << \
					"Выберите тему, информацию о которой хотите увидеть, где:" << endl << \
					"0 - выход из меню отображения информации о студентах по конкретной теме" << endl << "1 - циклы" \
					<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
					endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
					<< "8 - динамическая память" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				cout << "\"-\" означает, что студент не проходил тестирование по данной теме" << endl;

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню отображение информации о студентах по конкретной теме" << endl;
					break;

				case 1:
					cout << "Вы выбрали отображение информации о студентах по теме \"циклы\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
					break;

				case 2:
					cout << "Вы выбрали отображение информации о студентах по теме \"массивы\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
					break;

				case 3:
					cout << "Вы выбрали отображение информации о студентах по теме \"строки\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
					break;

				case 4:
					cout << "Вы выбрали отображение информации о студентах по теме \"рекурсия\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
					break;

				case 5:
					cout << "Вы выбрали отображение информации о студентах по теме \"структуры\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
					break;

				case 6:
					cout << "Вы выбрали отображение информации о студентах по теме \"файлы\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
					break;

				case 7:
					cout << "Вы выбрали отображение информации о студентах по теме \"адреса и указатели\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
					break;

				case 8:
					cout << "Вы выбрали отображение информации о студентах по теме \"динамическая память\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
					break;

				default:
					cout << "Вы неверно выбрали отображаемую информацию о студентах по конкретной теме, пожалуйста, повторите попытку" << endl;
					break;
				}
			} while (o1 != 0);
			break;
		}

		case 3:
		{
			cout << "Вы выбрали отображение информации о студентах по итоговому тесту" << endl;
			cout << "\"-\" означает, что студент не проходил итоговое тестирование" << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << stud[i].name << endl;
				cout << stud[i].surname << endl;
				cout << stud[i].controltests << endl;
			}
			break;
		}

		case 4:
		{
			cout << "Вы выбрали отображение информации о среднем балле студентов" << endl;
			cout << "\"-\" означает, что студент не проходил никакое из тестирований" << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << stud[i].name << endl;
				cout << stud[i].surname << endl;
				cout << stud[i].GPA << endl;
			}
			break;
		}

		default:
			cout << "Вы выбрали неверный формат вывода информации о студентах, пожалуйста, повторите попытку" << endl;
			break;
		}
	} while (o != 0);
	//}
//}
}

void filter(struct Students* stud, const string& fileName, int& size2)
{
	int o;

	do
	{
		cout << "Введите оценку, по которой хотите осуществить фильтрацию, где:" << endl << "0 - выйти из меню фильтрации вывода информации по оценкам студентов" \
			<< endl << "1, 2, 3, 4, 5 - оценки по темам, итоговому тесту и среднему баллу" << endl;

		while (true)
		{
			cin >> o;

			if (cin.fail() || o < 0 || o > 5)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}

		switch (o)
		{
		case 0:
			cout << "Вы вышли из меню фильтрации вывода информации по оценкам студентов" << endl;
			break;

		case 1:
		{
			int o1 = 0;

			do
			{
				cout << "Выберите, что хотите отобразить, где:" << endl << "0 - выйти из меню фильтрации по оценке \"1\"" << endl << \
					"1 - показать фильтрацию по оценке \"1\" по всем темам" << endl << "2 - показать фильтрацию по оценке \"1\" по конкретной теме" << \
					endl << "3 - показать фильтрацию по оценке \"1\" по итоговому тесту" << endl << "4 - показать фильтрацию по оценке \"1\" по среднему баллу" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню фильтрации по оценке \"1\" по всем темам" << endl;
					break;

				case 1:
					cout << "Вы выбрали фильтрацию по оценке \"1\" по всем темам" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 1)
						{
							cout << stud[i].loops << endl;

						}
						else
						{
							cout << "У студента по теме \"циклы\" оценка не \"1\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 1)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "У студента по теме \"массивы\" оценка не \"1\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 1)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "У студента по теме \"строки\" оценка не \"1\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 1)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "У студента по теме \"рекурсия\" оценка не \"1\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 1)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "У студента по теме \"структуры\" оценка не \"1\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 1)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "У студента по теме \"файлы\" оценка не \"1\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 1)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "У студента по теме \"адреса и указатели\" оценка не \"1\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 1)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "У студента по теме \"динамическая память\" оценка не \"1\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 1)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по итоговому тесту оценка не \"1\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "Вы выбрали фильтрацию по оценке \"1\" по конкретной теме" << endl << \
							"Выберите тему, информацию о которой хотите увидеть, где:" << endl << \
							"0 - выход из меню отображения информации о студентах по конкретной теме" << endl << "1 - циклы" \
							<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
							endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
							<< "8 - динамическая память" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}

						switch (o2)
						{
						case 0:
							cout << "Вы вышли из меню фильтрации по оценке \"1\" по конкретной теме" << endl;
							break;

						case 1:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"циклы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 1)
								{
									cout << stud[i].loops << endl;

								}
								else
								{
									cout << "У студента по теме \"циклы\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"массивы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 1)
								{
									cout << stud[i].arrays << endl;

								}
								else
								{
									cout << "У студента по теме \"массивы\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"строки\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].str[size(stud[i].str) - 1] - '0' == 1)
								{
									cout << stud[i].str << endl;

								}
								else
								{
									cout << "У студента по теме \"строки\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"рекурсия\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 1)
								{
									cout << stud[i].recursions << endl;

								}
								else
								{
									cout << "У студента по теме \"рекурсия\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"структуры\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 1)
								{
									cout << stud[i].structs << endl;

								}
								else
								{
									cout << "У студента по теме \"структуры\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"файлы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].files[size(stud[i].files) - 1] - '0' == 1)
								{
									cout << stud[i].files << endl;

								}
								else
								{
									cout << "У студента по теме \"файлы\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"адреса и указатели\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 1)
								{
									cout << stud[i].pointers << endl;

								}
								else
								{
									cout << "У студента по теме \"адреса и указатели\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "Вы выбрали отображение информации по оценке \"1\" по теме \"динамическая память\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 1)
								{
									cout << stud[i].dinamics << endl;

								}
								else
								{
									cout << "У студента по теме \"динамическая память\" оценка не \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "Вы неверно выбрали отображаемую информацию о студентах по конкретной теме, пожалуйста, повторите попытку" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}

				case 3:
				{
					cout << "Вы выбрали фильтрацию по оценке \"1\" по итоговому тесту" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 1)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по теме итоговому тесту оценка не \"1\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}

				case 4:
				{
					cout << "Вы выбрали фильтрацию по оценке \"1\" по среднему баллу" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].GPA[size(stud[i].GPA) - 1] - '0' == 1)
						{
							cout << stud[i].GPA << endl;

						}
						else
						{
							cout << "У студента средний балл не \"1\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}

				}

			} while (o1 != 0);
			break;
		}

		case 2:
		{
			int o1 = 0;

			do
			{
				cout << "Выберите, что хотите отобразить, где:" << endl << "0 - выйти из меню фильтрации по оценке \"2\"" << endl << \
					"1 - показать фильтрацию по оценке \"2\" по всем темам" << endl << "2 - показать фильтрацию по оценке \"2\" по конкретной теме" << \
					endl << "3 - показать фильтрацию по оценке \"2\" по итоговому тесту" << endl << "4 - показать фильтрацию по оценке \"2\" по среднему баллу" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню фильтрации по оценке \"2\" по всем темам" << endl;
					break;

				case 1:
				{
					cout << "Вы выбрали фильтрацию по оценке \"2\" по всем темам" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 2)
						{
							cout << stud[i].loops << endl;

						}
						else
						{
							cout << "У студента по теме \"циклы\" оценка не \"2\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 2)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "У студента по теме \"массивы\" оценка не \"2\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 2)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "У студента по теме \"строки\" оценка не \"2\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 2)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "У студента по теме \"рекурсия\" оценка не \"2\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 2)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "У студента по теме \"структуры\" оценка не \"2\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 2)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "У студента по теме \"файлы\" оценка не \"2\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 2)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "У студента по теме \"адреса и указатели\" оценка не \"2\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 2)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "У студента по теме \"динамическая память\" оценка не \"2\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 2)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по итоговому тесту оценка не \"2\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "Вы выбрали фильтрацию по оценке \"2\" по конкретной теме" << endl << \
							"Выберите тему, информацию о которой хотите увидеть, где:" << endl << \
							"0 - выход из меню отображения информации о студентах по конкретной теме" << endl << "1 - циклы" \
							<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
							endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
							<< "8 - динамическая память" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}

						switch (o2)
						{
						case 0:
							cout << "Вы вышли из меню фильтрации по оценке \"2\" по конкретной теме" << endl;
							break;

						case 1:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"циклы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 2)
								{
									cout << stud[i].loops << endl;

								}
								else
								{
									cout << "У студента по теме \"циклы\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"массивы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 2)
								{
									cout << stud[i].arrays << endl;

								}
								else
								{
									cout << "У студента по теме \"массивы\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"строки\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].str[size(stud[i].str) - 1] - '0' == 2)
								{
									cout << stud[i].str << endl;

								}
								else
								{
									cout << "У студента по теме \"строки\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"рекурсия\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 2)
								{
									cout << stud[i].recursions << endl;

								}
								else
								{
									cout << "У студента по теме \"рекурсия\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"структуры\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 2)
								{
									cout << stud[i].structs << endl;

								}
								else
								{
									cout << "У студента по теме \"структуры\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"файлы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].files[size(stud[i].files) - 1] - '0' == 2)
								{
									cout << stud[i].files << endl;

								}
								else
								{
									cout << "У студента по теме \"файлы\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"адреса и указатели\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 2)
								{
									cout << stud[i].pointers << endl;

								}
								else
								{
									cout << "У студента по теме \"адреса и указатели\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "Вы выбрали отображение информации по оценке \"2\" по теме \"динамическая память\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 2)
								{
									cout << stud[i].dinamics << endl;

								}
								else
								{
									cout << "У студента по теме \"динамическая память\" оценка не \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "Вы неверно выбрали отображаемую информацию о студентах по конкретной теме, пожалуйста, повторите попытку" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
				{
					cout << "Вы выбрали фильтрацию по оценке \"2\" по итоговому тесту" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 2)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по теме итоговому тесту оценка не \"2\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}
				case 4:
				{
					cout << "Вы выбрали фильтрацию по оценке \"2\" по среднему баллу" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].GPA[size(stud[i].GPA) - 1] - '0' == 2)
						{
							cout << stud[i].GPA << endl;

						}
						else
						{
							cout << "У студента средний балл не \"2\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}

				}

			} while (o1 != 0);
			break;
		}
		case 3:
		{
			int o1 = 0;

			do
			{
				cout << "Выберите, что хотите отобразить, где:" << endl << "0 - выйти из меню фильтрации по оценке \"3\"" << endl << \
					"1 - показать фильтрацию по оценке \"3\" по всем темам" << endl << "2 - показать фильтрацию по оценке \"3\" по конкретной теме" << \
					endl << "3 - показать фильтрацию по оценке \"3\" по итоговому тесту" << endl << "4 - показать фильтрацию по оценке \"3\" по среднему баллу" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню фильтрации по оценке \"3\" по всем темам" << endl;
					break;

				case 1:
					cout << "Вы выбрали фильтрацию по оценке \"3\" по всем темам" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 3)
						{
							cout << stud[i].loops << endl;

						}
						else
						{
							cout << "У студента по теме \"циклы\" оценка не \"3\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 3)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "У студента по теме \"массивы\" оценка не \"3\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 3)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "У студента по теме \"строки\" оценка не \"3\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 3)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "У студента по теме \"рекурсия\" оценка не \"3\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 3)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "У студента по теме \"структуры\" оценка не \"3\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 3)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "У студента по теме \"файлы\" оценка не \"3\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 3)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "У студента по теме \"адреса и указатели\" оценка не \"3\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 3)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "У студента по теме \"динамическая память\" оценка не \"3\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 3)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по итоговому тесту оценка не \"3\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "Вы выбрали фильтрацию по оценке \"3\" по конкретной теме" << endl << \
							"Выберите тему, информацию о которой хотите увидеть, где:" << endl << \
							"0 - выход из меню отображения информации о студентах по конкретной теме" << endl << "1 - циклы" \
							<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
							endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
							<< "8 - динамическая память" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}

						switch (o2)
						{
						case 0:
							cout << "Вы вышли из меню фильтрации по оценке \"3\" по конкретной теме" << endl;
							break;

						case 1:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"циклы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 3)
								{
									cout << stud[i].loops << endl;

								}
								else
								{
									cout << "У студента по теме \"циклы\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"массивы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 3)
								{
									cout << stud[i].arrays << endl;

								}
								else
								{
									cout << "У студента по теме \"массивы\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"строки\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].str[size(stud[i].str) - 1] - '0' == 3)
								{
									cout << stud[i].str << endl;

								}
								else
								{
									cout << "У студента по теме \"строки\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"рекурсия\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 3)
								{
									cout << stud[i].recursions << endl;

								}
								else
								{
									cout << "У студента по теме \"рекурсия\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"структуры\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 3)
								{
									cout << stud[i].structs << endl;

								}
								else
								{
									cout << "У студента по теме \"структуры\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"файлы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].files[size(stud[i].files) - 1] - '0' == 3)
								{
									cout << stud[i].files << endl;

								}
								else
								{
									cout << "У студента по теме \"файлы\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"адреса и указатели\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 3)
								{
									cout << stud[i].pointers << endl;

								}
								else
								{
									cout << "У студента по теме \"адреса и указатели\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "Вы выбрали отображение информации по оценке \"3\" по теме \"динамическая память\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 3)
								{
									cout << stud[i].dinamics << endl;

								}
								else
								{
									cout << "У студента по теме \"динамическая память\" оценка не \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "Вы неверно выбрали отображаемую информацию о студентах по конкретной теме, пожалуйста, повторите попытку" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
					cout << "Вы выбрали фильтрацию по оценке \"3\" по итоговому тесту" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 3)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по теме итоговому тесту оценка не \"3\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				case 4:
					cout << "Вы выбрали фильтрацию по оценке \"3\" по среднему баллу" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].GPA[size(stud[i].GPA) - 1] - '0' == 3)
						{
							cout << stud[i].GPA << endl;

						}
						else
						{
							cout << "У студента средний балл не \"3\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				}

			} while (o1 != 0);
			break;
		}
		case 4:
		{
			int o1 = 0;

			do
			{
				cout << "Выберите, что хотите отобразить, где:" << endl << "0 - выйти из меню фильтрации по оценке \"4\"" << endl << \
					"1 - показать фильтрацию по оценке \"4\" по всем темам" << endl << "2 - показать фильтрацию по оценке \"4\" по конкретной теме" << \
					endl << "3 - показать фильтрацию по оценке \"4\" по итоговому тесту" << endl << "4 - показать фильтрацию по оценке \"4\" по среднему баллу" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню фильтрации по оценке \"4\" по всем темам" << endl;
					break;

				case 1:
					cout << "Вы выбрали фильтрацию по оценке \"4\" по всем темам" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 4)
						{
							cout << stud[i].loops << endl;

						}
						else
						{
							cout << "У студента по теме \"циклы\" оценка не \"4\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 4)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "У студента по теме \"массивы\" оценка не \"4\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 4)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "У студента по теме \"строки\" оценка не \"4\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 4)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "У студента по теме \"рекурсия\" оценка не \"4\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 4)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "У студента по теме \"структуры\" оценка не \"4\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 4)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "У студента по теме \"файлы\" оценка не \"4\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 4)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "У студента по теме \"адреса и указатели\" оценка не \"4\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 4)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "У студента по теме \"динамическая память\" оценка не \"4\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 4)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по итоговому тесту оценка не \"4\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "Вы выбрали фильтрацию по оценке \"4\" по конкретной теме" << endl << \
							"Выберите тему, информацию о которой хотите увидеть, где:" << endl << \
							"0 - выход из меню отображения информации о студентах по конкретной теме" << endl << "1 - циклы" \
							<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
							endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
							<< "8 - динамическая память" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}

						switch (o2)
						{
						case 0:
							cout << "Вы вышли из меню фильтрации по оценке \"4\" по конкретной теме" << endl;
							break;

						case 1:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"циклы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 4)
								{
									cout << stud[i].loops << endl;

								}
								else
								{
									cout << "У студента по теме \"циклы\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"массивы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 4)
								{
									cout << stud[i].arrays << endl;

								}
								else
								{
									cout << "У студента по теме \"массивы\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"строки\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].str[size(stud[i].str) - 1] - '0' == 4)
								{
									cout << stud[i].str << endl;

								}
								else
								{
									cout << "У студента по теме \"строки\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"рекурсия\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 4)
								{
									cout << stud[i].recursions << endl;

								}
								else
								{
									cout << "У студента по теме \"рекурсия\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"структуры\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 4)
								{
									cout << stud[i].structs << endl;

								}
								else
								{
									cout << "У студента по теме \"структуры\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"файлы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].files[size(stud[i].files) - 1] - '0' == 4)
								{
									cout << stud[i].files << endl;

								}
								else
								{
									cout << "У студента по теме \"файлы\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"адреса и указатели\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 4)
								{
									cout << stud[i].pointers << endl;

								}
								else
								{
									cout << "У студента по теме \"адреса и указатели\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "Вы выбрали отображение информации по оценке \"4\" по теме \"динамическая память\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 4)
								{
									cout << stud[i].dinamics << endl;

								}
								else
								{
									cout << "У студента по теме \"динамическая память\" оценка не \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "Вы неверно выбрали отображаемую информацию о студентах по конкретной теме, пожалуйста, повторите попытку" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
					cout << "Вы выбрали фильтрацию по оценке \"4\" по итоговому тесту" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 4)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по теме итоговому тесту оценка не \"4\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				case 4:
					cout << "Вы выбрали фильтрацию по оценке \"4\" по среднему баллу" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].GPA[size(stud[i].GPA) - 1] - '0' == 4)
						{
							cout << stud[i].GPA << endl;

						}
						else
						{
							cout << "У студента средний балл не \"4\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				}

			} while (o1 != 0);
			break;
		}
		case 5:
		{
			int o1 = 0;

			do
			{
				cout << "Выберите, что хотите отобразить, где:" << endl << "0 - выйти из меню фильтрации по оценке \"5\"" << endl << \
					"1 - показать фильтрацию по оценке \"5\" по всем темам" << endl << "2 - показать фильтрацию по оценке \"5\" по конкретной теме" << \
					endl << "3 - показать фильтрацию по оценке \"5\" по итоговому тесту" << endl << "4 - показать фильтрацию по оценке \"5\" по среднему баллу" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню фильтрации по оценке \"5\" по всем темам" << endl;
					break;

				case 1:
					cout << "Вы выбрали фильтрацию по оценке \"5\" по всем темам" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 5)
						{
							cout << stud[i].loops << endl;

						}
						else
						{
							cout << "У студента по теме \"циклы\" оценка не \"5\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 5)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "У студента по теме \"массивы\" оценка не \"5\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 5)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "У студента по теме \"строки\" оценка не \"5\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 5)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "У студента по теме \"рекурсия\" оценка не \"5\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 5)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "У студента по теме \"структуры\" оценка не \"5\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 5)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "У студента по теме \"файлы\" оценка не \"5\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 5)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "У студента по теме \"адреса и указатели\" оценка не \"5\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 5)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "У студента по теме \"динамическая память\" оценка не \"5\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 5)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по итоговому тесту оценка не \"5\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "Вы выбрали фильтрацию по оценке \"5\" по конкретной теме" << endl << \
							"Выберите тему, информацию о которой хотите увидеть, где:" << endl << \
							"0 - выход из меню отображения информации о студентах по конкретной теме" << endl << "1 - циклы" \
							<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
							endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
							<< "8 - динамическая память" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}

						switch (o2)
						{
						case 0:
							cout << "Вы вышли из меню фильтрации по оценке \"5\" по конкретной теме" << endl;
							break;

						case 1:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"циклы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 5)
								{
									cout << stud[i].loops << endl;

								}
								else
								{
									cout << "У студента по теме \"циклы\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"массивы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 5)
								{
									cout << stud[i].arrays << endl;

								}
								else
								{
									cout << "У студента по теме \"массивы\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"строки\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].str[size(stud[i].str) - 1] - '0' == 5)
								{
									cout << stud[i].str << endl;

								}
								else
								{
									cout << "У студента по теме \"строки\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"рекурсия\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 5)
								{
									cout << stud[i].recursions << endl;

								}
								else
								{
									cout << "У студента по теме \"рекурсия\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"структуры\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 5)
								{
									cout << stud[i].structs << endl;

								}
								else
								{
									cout << "У студента по теме \"структуры\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"файлы\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].files[size(stud[i].files) - 1] - '0' == 5)
								{
									cout << stud[i].files << endl;

								}
								else
								{
									cout << "У студента по теме \"файлы\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"адреса и указатели\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 5)
								{
									cout << stud[i].pointers << endl;

								}
								else
								{
									cout << "У студента по теме \"адреса и указатели\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "Вы выбрали отображение информации по оценке \"5\" по теме \"динамическая память\"" << endl;
							for (int i = 0; i < size2; i++)
							{
								cout << stud[i].name << endl;
								cout << stud[i].surname << endl;
								if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 5)
								{
									cout << stud[i].dinamics << endl;

								}
								else
								{
									cout << "У студента по теме \"динамическая память\" оценка не \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "Вы неверно выбрали отображаемую информацию о студентах по конкретной теме, пожалуйста, повторите попытку" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
					cout << "Вы выбрали фильтрацию по оценке \"5\" по итоговому тесту" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 5)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "У студента по теме итоговому тесту оценка не \"5\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				case 4:
					cout << "Вы выбрали фильтрацию по оценке \"5\" по среднему баллу" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						if (stud[i].GPA[size(stud[i].GPA) - 1] - '0' == 5)
						{
							cout << stud[i].GPA << endl;

						}
						else
						{
							cout << "У студента средний балл не \"5\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}
			} while (o1 != 0);
			break;
		}
		}
	} while (o != 0);
}

void sort(struct Students* stud, const string& filename, int& size2)
{
	int o;

	do
	{
		cout << "Введите критерий сортировки" << endl << "0 - выйти из меню сортировки оценок студентов" \
			<< endl << "1 - Определённая тема" << endl << "2 - По итоговому тесту" << endl << "3 - По среднему баллу" << endl;

		while (true)
		{
			cin >> o;

			if (cin.fail() || o < 0 || o > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		switch (o)
		{
		case 0:
			cout << "Вы вышли из меню сортировки оценок студентов" << endl;
			break;
		case 1:
		{
			int o2;
			cout << "0 - выход из меню сортировки оценок по конкретным предметам" << endl << "1 - циклы" \
				<< endl << "2 - массивы" << endl << "3 - строки" << endl << "4 - рекурсия" << \
				endl << "5 - структуры" << endl << "6 - файлы" << endl << "7 - адреса и указатели" << endl \
				<< "8 - динамическая память" << endl;
			while (true)
			{
				cin >> o2;

				if (cin.fail() || o2 < 0 || o2 > 8)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
				}
				else
				{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
			switch (o2)
			{
			case 0:
			{
				cout << "Вы вышли из меню сортировки оценок студентов по предметам" << endl;
				break;
			}
			case 1:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].loops[size(stud[i].loops) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
				}
				break;
			}
			case 3:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].str[size(stud[i].str) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].str[size(stud[i].str) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].str[size(stud[i].str) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].str[size(stud[i].str) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].str[size(stud[i].str) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
				}
				break;
			}
			case 4:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
				}
				break;
			}
			case 5:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
				}
				break;
			}
			case 6:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].files[size(stud[i].files) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].files[size(stud[i].files) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].files[size(stud[i].files) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].files[size(stud[i].files) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].files[size(stud[i].files) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
				}
				break;
			}
			case 7:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
				}
				break;
			}
			case 8:
			{
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 5)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 4)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 3)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 2)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
				}
				for (int i = 0; i < size2; i++)
				{
					if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 1)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
				}
				break;
			}
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 5)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].controltests << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 4)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].controltests << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 3)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].controltests << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 2)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].controltests << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 1)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].controltests << endl;
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].GPA[size(stud[i].GPA) - 3] - '0' == 5)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].GPA << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].GPA[size(stud[i].GPA) - 3] - '0' == 4)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].GPA << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].GPA[size(stud[i].GPA) - 3] - '0' == 3)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].GPA << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].GPA[size(stud[i].GPA) - 3] - '0' == 2)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].GPA << endl;
				}
			}
			for (int i = 0; i < size2; i++)
			{
				if (stud[i].GPA[size(stud[i].GPA) - 3] - '0' == 1)
				{
					cout << stud[i].name << endl;
					cout << stud[i].surname << endl;
					cout << stud[i].GPA << endl;
				}
			}
			break;
		}
		}
	} while (o != 0);
}

int PushQuestions(struct question* quest, const string& fileName, int size, string &tema)
{
	ifstream inputFile(fileName);

	int k = 0;

	getline(inputFile, tema);
	
	for (int i = 0; i < size; i++)
	{
		getline(inputFile, quest[i].text);
		getline(inputFile, quest[i].ans1);
		if (quest[i].ans1 == "")
		{
			break;
		}
		getline(inputFile, quest[i].ans2);
		getline(inputFile, quest[i].ans3);
		getline(inputFile, quest[i].ans4);
		getline(inputFile, quest[i].true_ans);
		k++;
	}

	inputFile.close();


	return k;
}

void writeQuestions(struct question* quest, const string& fileName, int& size, string &tema)
{
	ofstream outputFile(fileName, ofstream::out | ofstream::trunc);
	outputFile << tema << endl;
	for (int i = 0; i < size; i++)
	{
		outputFile << quest[i].text << endl;
		outputFile << quest[i].ans1 << endl;
		outputFile << quest[i].ans2 << endl;
		outputFile << quest[i].ans3 << endl;
		outputFile << quest[i].ans4 << endl;
		if (i < size - 1) 
		{
			outputFile << quest[i].true_ans << endl;
		}
		else 
		{
			outputFile << quest[i].true_ans;
		}
	}
}

void addQuestions(struct question* quest, const string& fileName, int& size, string &tema)
{

	PushQuestions(quest, fileName, size, tema);
	writeQuestions(quest, fileName, size, tema);

	string question1;
	string ans11;
	string ans21;
	string ans31;
	string ans41;
	string true_ans1;

	cout << "Введите текст вопроса: "; getline(cin, question1);
	cout << "Введите первый вариант ответа: "; getline(cin, ans11);
	cout << "Введите второй вариант ответа: "; getline(cin, ans21);
	cout << "Введите третий вариант ответа: "; getline(cin, ans31);
	cout << "Введите четвёртый вариант ответа: "; getline(cin, ans41);
	cout << "Введите номер правильного варианта ответа: "; getline(cin, true_ans1);

	size++;

	quest[size - 1].text = question1 + "\n";
	quest[size - 1].ans1 = "1)" + ans11 + "\n";
	quest[size - 1].ans2 = "2)" + ans21 + "\n";
	quest[size - 1].ans3 = "3)" + ans31 + "\n";
	quest[size - 1].ans4 = "4)" + ans41 + "\n";
	quest[size - 1].true_ans = true_ans1;

	ofstream outputFile(fileName, ofstream::out | ofstream::app);

	outputFile << endl;

	outputFile << quest[size - 1].text;
	outputFile << quest[size - 1].ans1;
	outputFile << quest[size - 1].ans2;
	outputFile << quest[size - 1].ans3;
	outputFile << quest[size - 1].ans4;
	outputFile << quest[size - 1].true_ans;
}

void delQuestions(struct question* quest, const string& fileName, int& size, string &tema)
{
	PushQuestions(quest, fileName, size, tema);

	string line1;

	bool flag = true;

	while (flag)
	{
		cout << "Введите вопрос, который желаете удалить: ";
		getline(cin, line1);
		for (int i = 0; i < size; i++)
		{
			if (line1 == quest[i].text)
			{
				for (int j = i; j < size; j++)
				{
					quest[j] = quest[j + 1];
				}
				size--;
				flag = false;
				break;
			}
			if (i == size - 1)
			{
				cout << "Вопрос не найден, повторите попытку" << endl;
			}
		}
	}

	writeQuestions(quest, fileName, size, tema);
}

void editQuestions(struct question* quest, const string& fileName, int& size, string &tema)
{
	PushQuestions(quest, fileName, size, tema);
	int tr;
	string line1;

	bool flag = true;

	while (flag)
	{
		cout << "Введите вопрос, который желаете изменить: ";
		getline(cin, line1);

		for (int i = 0; i < size; i++)
		{
			if (line1 == quest[i].text)
			{
				cout << quest[i].text << endl;
				cout << quest[i].ans1 << endl;
				cout << quest[i].ans2 << endl;
				cout << quest[i].ans3 << endl;
				cout << quest[i].ans4 << endl;
				cout << quest[i].true_ans << endl;
				do
				{
					cout << "Выберите, что изменить в вопросе: " << endl << "0 - отмена операции" << endl << "1,2,3,4 - Ответы" << endl << "5 - Правильный ответ" << endl << "6 - текст вопроса" << endl;
					cin >> tr;
					switch (tr)
					{
					case 6:
					{
						cout << "Введите новое значение для поля" << endl;
						cin.ignore();
						getline(cin, quest[i].text);
						break;
					}
					case 1:
					{
						cout << "Введите новое значение для поля" << endl;
						cin.ignore();
						getline(cin, quest[i].ans1);
						quest[i].ans1 = "1)" + quest[i].ans1;
						break;
					}
					case 2:
					{
						cout << "Введите новое значение для поля" << endl;
						cin.ignore();
						getline(cin, quest[i].ans2);
						quest[i].ans2 = "2)" + quest[i].ans2;
						break;
					}
					case 3:
					{
						cout << "Введите новое значение для поля" << endl;
						cin.ignore();
						getline(cin, quest[i].ans3);
						quest[i].ans3 = "3)" + quest[i].ans3;
						break;
					}
					case 4:
					{
						cout << "Введите новое значение для поля" << endl;
						cin.ignore();
						getline(cin, quest[i].ans4);
						quest[i].ans4 = "4)" + quest[i].ans4;
						break;
					}
					case 5:
					{
						cout << "Введите новое значение для поля" << endl;
						cin.ignore();
						getline(cin, quest[i].true_ans);
						break;
					}
					default: cout << "Некорретный ввод!" << endl;
					}
				} while (tr != 0);


				flag = false;
				break;
			}
			if (i == size - 1)
			{
				cout << "Вопрос не найден, повторите попытку" << endl;
			}
		}
	}

	writeQuestions(quest, fileName, size, tema);
}

void ADMIN_MODE()
{
	int size1 = 100;
	int size11 = 199, size12 = 299, size13 = 399, size14 = 499, size15 = 599, size16 = 699, size17 = 799, size18 = 899;
	const int size2 = 100;
	struct Students stud[size2];
	struct question quest[size2 * 10];
	string tema;
	size11 = PushQuestions(quest, "questions_list/file.txt", size11, tema);
	size12 = PushQuestions(quest, "questions_list/loops.txt", size12, tema);
	size13 = PushQuestions(quest, "questions_list/matrix.txt", size13, tema);
	size14 = PushQuestions(quest, "questions_list/pointer.txt", size14, tema);
	size15 = PushQuestions(quest, "questions_list/recursion.txt", size15, tema);
	size16 = PushQuestions(quest, "questions_list/string.txt", size16, tema);
	size17 = PushQuestions(quest, "questions_list/struct.txt", size17, tema);
	size18 = PushQuestions(quest, "questions_list/dinamic_RAM.txt", size18, tema) - 1;

	int size = PushStudents(stud, "students_information/students.txt", size1);

	int fl1, fl2, fl3, fl4;
	do
	{
		cout << "Выберите действие" << endl << "0.Выйти из режима преподавателя" << endl << "1.Редактирование вопросов" << endl \
			<< "2.Работа со списком студентов" << endl << "3.Шифрация файла" << endl << "4.Открытие зашифрованного файла" <<\
			endl << "5.Получение данных из файла" << endl;
		while (true)
		{
			cin >> fl1;

			if (cin.fail() || fl1 < 0 || fl1 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		switch (fl1)
		{
		case 0:
		{
			cout << endl << "Вы вышли из режима преподавателя" << "\n\n";
			break;
		}
		case 1:
		{
			do
			{
				cout << "Выберите действие из списка" << endl << "0.Вернуться назад" << endl << "1.Удаление вопроса" << endl << "2.Добавление вопроса" << endl << "3.Изменение вопроса" << endl;
				while (true)
				{
					cin >> fl2;

					if (cin.fail() || fl2 < 0 || fl2 > 3)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}
				switch (fl2)
				{
				case 0:
					break;
				case 1:
				{
					do
					{
						cout << "Выберите тему" << endl << "0.Выход" << endl << "1.Файлы" << endl << "2.Циклы" << endl << "3.Матрицы" << endl << "4.Указатели" << endl << "5.Рекурсия" << endl << "6.Строки" << endl << "7.Структуры" << endl << "8.Динамическая память" << endl;
						while (true)
						{
							cin >> fl4;

							if (cin.fail() || fl4 < 0 || fl4 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}
						switch (fl4)
						{
						case 0: break;
						case 1:
						{
							delQuestions(quest, "questions_list/file.txt", size11, tema);
							break;
						}
						case 2:
						{
							delQuestions(quest, "questions_list/loops.txt", size12, tema);
							break;
						}
						case 3:
						{
							delQuestions(quest, "questions_list/matrix.txt", size13, tema);
							break;
						}
						case 4:
						{
							delQuestions(quest, "questions_list/pointer.txt", size14, tema);
							break;
						}
						case 5:
						{
							delQuestions(quest, "questions_list/recursion.txt", size15, tema);
							break;
						}
						case 6:
						{
							delQuestions(quest, "questions_list/string.txt", size16, tema);
							break;
						}
						case 7:
						{
							delQuestions(quest, "questions_list/struct.txt", size17, tema);
							break;
						}
						case 8:
						{
							delQuestions(quest, "questions_list/dinamic_RAM.txt", size18, tema);
							break;
						}
						default: cout << "Некорректный ввод!" << endl;
						}
					} while (fl4 != 0);
					break;
				}
				case 2:
				{
					do
					{
						cout << "Выберите тему" << endl << "0.Выход" << endl << "1.Файлы" << endl << "2.Циклы" << endl << "3.Матрицы" << endl << "4.Указатели" << endl << "5.Рекурсия" << endl << "6.Строки" << endl << "7.Структуры" << endl << "8.Динамическая память" << endl;
						while (true)
						{
							cin >> fl4;

							if (cin.fail() || fl4 < 0 || fl4 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}
						switch (fl4)
						{
						case 0: break;
						case 1:
						{
							addQuestions(quest, "questions_list/file.txt", size11, tema);
							break;
						}
						case 2:
						{
							addQuestions(quest, "questions_list/loops.txt", size12, tema);
							break;
						}
						case 3:
						{
							addQuestions(quest, "questions_list/matrix.txt", size13, tema);
							break;
						}
						case 4:
						{
							addQuestions(quest, "questions_list/pointer.txt", size14, tema);
							break;
						}
						case 5:
						{
							addQuestions(quest, "questions_list/recursion.txt", size15, tema);
							break;
						}
						case 6:
						{
							addQuestions(quest, "questions_list/string.txt", size16, tema);
							break;
						}
						case 7:
						{
							addQuestions(quest, "questions_list/struct.txt", size17, tema);
							break;
						}
						case 8:
						{
							addQuestions(quest, "questions_list/dinamic_RAM.txt", size18, tema);
							break;
						}
						default: cout << "Некорректный ввод!" << endl;
						}
					} while (fl4 != 0);
					break;
				}
				case 3:
				{
					do
					{
						cout << "Выберите тему" << endl << "0.Выход" << endl << "1.Файлы" << endl << "2.Циклы" << endl << "3.Матрицы" << endl << "4.Указатели" << endl << "5.Рекурсия" << endl << "6.Строки" << endl << "7.Структуры" << endl << "8.Динамическая память" << endl;
						while (true)
						{
							cin >> fl4;

							if (cin.fail() || fl4 < 0 || fl4 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
							}
							else
							{
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}
						switch (fl4)
						{
						case 0: break;
						case 1:
						{
							editQuestions(quest, "questions_list/file.txt", size11, tema);
							break;
						}
						case 2:
						{
							editQuestions(quest, "questions_list/loops.txt", size12, tema);
							break;
						}
						case 3:
						{
							editQuestions(quest, "questions_list/matrix.txt", size13, tema);
							break;
						}
						case 4:
						{
							editQuestions(quest, "questions_list/pointer.txt", size14, tema);
							break;
						}
						case 5:
						{
							editQuestions(quest, "questions_list/recursion.txt", size15, tema);
							break;
						}
						case 6:
						{
							editQuestions(quest, "questions_list/string.txt", size16, tema);
							break;
						}
						case 7:
						{
							editQuestions(quest, "questions_list/struct.txt", size17, tema);
							break;
						}
						case 8:
						{
							editQuestions(quest, "questions_list/dinamic_RAM.txt", size18, tema);
							break;
						}
						default: cout << "Некорректный ввод!" << endl;
						}
					} while (fl4 != 0);
					break;
				}
				default: cout << "Некоррентый ввод!" << endl;
				}
			} while (fl2 != 0);
			break;
		}
		case 2:
		{
			do
			{
				cout << "Выберите действие из списка" << endl << "0.Вернуться назад" << endl << "1.Удаление студента" << endl << "2.Зарегестрировать студента" << endl << "3.Изменить прогресс студента" << endl
					<< "4.Вывести список студентов" << endl << "5.Вывести отфильтрованный список студентов" << endl << "6.Вывести отсортированный список" << endl;
				while (true)
				{
					cin >> fl3;

					if (cin.fail() || fl3 < 0 || fl3 > 6)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}
				switch (fl3)
				{
				case 0: break;
				case 1:
				{
					delStudents(stud, "students_information/students.txt", size);
					break;
				}
				case 2:
				{
					addStudents(stud, "students_information/students.txt", size);
					break;
				}
				case 3:
				{
					changeProgress(stud, "students_information/students.txt", size);
					break;
				}
				case 4:
				{
					outputStudents(stud, "students_information/students.txt", size);
					break;
				}
				case 5:
				{
					filter(stud, "students_information/students.txt", size);
					break;
				}
				case 6:
				{
					sort(stud, "students_information/students.txt", size);
					break;
				}
				default: cout << "Некоррентый ввод!" << endl;
				}
			} while (fl3 != 0);
			break;
		}
		case 3:
		{
			cout << "Вы выбрали шифрацию исходного файла" << endl;

			int o1 = -1;

			do
			{
				cout << "Выберите файл, который хотите зашифровать:" << endl << "0 - закрыть меню выбора файла" << endl << "1 - файл с тестовой базой"\
					<< endl << "2 - файл с базой студентов" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню выбора файла" << endl;
					break;

				case 1:
					cout << "Вы выбрали для шифрации файл с тестовой базой" << endl;
					encryption("questions_list/questionsforencryptions.txt", "encryption_questions_list/encryptionQuestions.txt", 5);
					break;

				case 2:
					cout << "Вы выбрали для шифрации файл с базой студентов" << endl;
					encryption("students_information/students.txt", "students_information/encryptionStudents.txt", 5);
					break;

				default:
					cout << "Вы ввели некорректный номер файла. Пожалуйста, повторите попытку" << endl;
					break;
				}
			} while (o1 != 0);

			break;
		}
		case 4:
		{
			cout << "Вы выбрали вывод зашифрованной информации" << endl;

			int o1 = -1;

			do
			{
				cout << "Выберите файл, который хотите вывести:" << endl << "0 - закрыть меню выбора файла" << endl << "1 - файл с тестовой базой"\
					<< endl << "2 - файл с базой студентов" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню выбора файла" << endl;
					break;

				case 1:
					cout << "Вы выбрали для вывода файл с тестовой базой" << endl;
					output_cryption_ADMIN("encryption_questions_list/encryptionQuestions.txt");
					break;

				case 2:
					cout << "Вы выбрали для вывода файл с базой студентов" << endl;
					output_cryption_ADMIN("students_information/encryptionStudents.txt");
					break;

				default:
					cout << "Вы ввели некорректный номер файла. Пожалуйста, повторите попытку" << endl;
					break;
				}
			} while (o1 != 0);

			break;
		}

		case 5:
		{
			cout << "Вы выбрали получение данных из файла и их вывод" << endl;

			int o1 = -1;

			do
			{
				cout << "Выберите файл, который хотите вывести:" << endl << "0 - закрыть меню выбора файла" << endl << \
					"1 - исходный файл с тестовой базой" << endl << "2 - исходный файл с базой студентов" << endl << \
					"3 - зашифрованный файл с тестовой базой" << endl << "4 - зашифрованный файл с базой студентов" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Вы ввели некорректное значение. Пожалуйста, повторите попытку" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				switch (o1)
				{
				case 0:
					cout << "Вы вышли из меню выбора файла" << endl;
					break;

				case 1:
					cout << "Вы выбрали для получения данных из файла и их вывода исходный файл с тестовой базой" << endl;
					output_cryption_ADMIN("questions_list/file.txt");
					output_cryption_ADMIN("questions_list/loops.txt");
					output_cryption_ADMIN("questions_list/matrix.txt");
					output_cryption_ADMIN("questions_list/pointer.txt");
					output_cryption_ADMIN("questions_list/recursion.txt");
					output_cryption_ADMIN("questions_list/string.txt");
					output_cryption_ADMIN("questions_list/struct.txt");
					output_cryption_ADMIN("questions_list/dinamic_RAM.txt");
					break;

				case 2:
					cout << "Вы выбрали для получения данных из файла и их вывода исходный файл с базой студентов" << endl;
					output_cryption_ADMIN("students_information/students.txt");
					break;

				case 3:
					cout << "Вы выбрали для получения данных из файла и их вывода зашифрованный файл с тестовой базой" << endl;
					decryptionOutput("encryption_questions_list/encryptionQuestions.txt", 5);
					break;

				case 4:
					cout << "Вы выбрали для получения данных из файла и их вывода зашифрованный файл с базой студентов" << endl;
					decryptionOutput("students_information/encryptionStudents.txt", 5);
					break;

				default:
					cout << "Вы ввели некорректный номер файла. Пожалуйста, повторите попытку" << endl;
					break;
				}
			} while (o1 != 0);

			break;
		}
		default: cout << "Некоррентый ввод!" << endl;
		}
	} while (fl1 != 0);
}