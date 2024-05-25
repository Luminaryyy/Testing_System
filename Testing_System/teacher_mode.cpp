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
		if (stud[i].name.substr(0, 3) == "���")
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
	string line3 = "���: ";
	string line4 = "�������: ";

	bool flag = true;

	while (flag)
	{
		cout << "������� ��� ��������, �������� ������ �������: "; cin >> line1;
		cout << "������� ������� ��������, �������� ������ �������: "; cin >> line2;

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
				cout << "������� �� ������, ����������, ��������� �������" << endl;
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

	cout << "������� ��� ��������, �������� ������ ��������: "; cin >> name;
	cout << "������� ������� ��������, �������� ������ ��������: "; cin >> surname;
	cout << "������� ������ ��������, �������� ������ ��������: "; cin >> login;
	cout << "������� ������ ��������, �������� ������ ��������: "; cin >> password;

	size++;

	stud[size - 1].name = "���: " + name;
	stud[size - 1].surname = "�������: " + surname;
	stud[size - 1].login = "�����: " + login;
	stud[size - 1].password = "������: " + password;
	stud[size - 1].loops = "�����: -";
	stud[size - 1].arrays = "�������: -";
	stud[size - 1].str = "������: -";
	stud[size - 1].recursions = "��������: -";
	stud[size - 1].structs = "���������: -";
	stud[size - 1].files = "�����: -";
	stud[size - 1].pointers = "������ � ���������: -";
	stud[size - 1].dinamics = "������������ ������: -";
	stud[size - 1].controltests = "�������� ����: -";
	stud[size - 1].GPA = "������� ����: -";
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
	string line3 = "���: ";
	string line4 = "�������: ";

	bool flag = true;

	while (flag)
	{
		cout << "������� ��� ��������, � �������� �������� ������ ������ ���������: "; cin >> line1;
		cout << "������� ������� ��������, � �������� �������� ������ ������ ���������: "; cin >> line2;

		for (int i = 0; i < size2; i++)
		{
			if ((line3 + line1) == stud[i].name && (line4 + line2) == stud[i].surname)
			{
				flag = false;
				break;
			}
			if (i == size2 - 1)
			{
				cout << "������� �� ������, ����������, ��������� �������" << endl;
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
				cout << "������� ����� ����, � ������� ������ ������ ��������� � �������� ��������, ���:" << \
					endl << "0 - ����� �� ���� ��������� ��������� ���������" << endl << "1 - �����" << endl << "2 - �������" << \
					endl << "3 - ������" << endl << "4 - ��������" << endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << \
					endl << "8 - ������������ ������" << endl << "9 - �������� ����" << endl;

				while (true)
				{
					cin >> o;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� �������������� ���������" << endl;
					break;

				case 1:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 2:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 3:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 4:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 5:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 6:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 7:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 8:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				case 9:
				{
					cout << "�� ������ ������� ��������������� ���������" << endl;
					char number = 1;
					while (number <= 48 || number >= 54)
					{
						cout << "�������� ������, �� ������� ������ �������� �������� ���� ��������: "; cin >> number;
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
					cout << "��������� ������� �������" << endl;
					break;
				}

				default:
					cout << "���� ������� �������, ����������, ��������� �������" << endl;
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
		cout << "������� ����� ������ ������ ���������� � ��������� �� ������ �������, ���:" << endl << \
			"0 - ����� �� ���� ����������� ����������" << endl << "1 - ����������� ���������� � ��������� �� ���� �����" << \
			endl << "2 - ����������� ���������� � ��������� �� ���������� ����" << endl \
			<< "3 - ����������� ���������� � ��������� �� ��������� ����� " << endl << \
			"4 - ����������� ���������� � ������� ����� ���������" << endl;

		while (true)
		{
			cin >> o;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
			cout << "�� ����� �� ���� ������ ���������� � ���������" << endl;
			break;

		case 1:
		{
			cout << "�� ������� ����������� ���������� � ��������� �� ���� �����" << endl;
			cout << "\"-\" ��������, ��� ������� �� �������� ������������ �� ������ ����" << endl;
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
				cout << "�� ������� ����������� ���������� � ��������� �� ���������� ����" << endl << \
					"�������� ����, ���������� � ������� ������ �������, ���:" << endl << \
					"0 - ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl << "1 - �����" \
					<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
					endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
					<< "8 - ������������ ������" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
					}
					else
					{
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				cout << "\"-\" ��������, ��� ������� �� �������� ������������ �� ������ ����" << endl;

				switch (o1)
				{
				case 0:
					cout << "�� ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl;
					break;

				case 1:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"�����\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].loops << endl;
					}
					break;

				case 2:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"�������\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].arrays << endl;
					}
					break;

				case 3:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"������\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].str << endl;
					}
					break;

				case 4:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"��������\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].recursions << endl;
					}
					break;

				case 5:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"���������\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].structs << endl;
					}
					break;

				case 6:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"�����\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].files << endl;
					}
					break;

				case 7:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"������ � ���������\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].pointers << endl;
					}
					break;

				case 8:
					cout << "�� ������� ����������� ���������� � ��������� �� ���� \"������������ ������\"" << endl;
					for (int i = 0; i < size2; i++)
					{
						cout << stud[i].name << endl;
						cout << stud[i].surname << endl;
						cout << stud[i].dinamics << endl;
					}
					break;

				default:
					cout << "�� ������� ������� ������������ ���������� � ��������� �� ���������� ����, ����������, ��������� �������" << endl;
					break;
				}
			} while (o1 != 0);
			break;
		}

		case 3:
		{
			cout << "�� ������� ����������� ���������� � ��������� �� ��������� �����" << endl;
			cout << "\"-\" ��������, ��� ������� �� �������� �������� ������������" << endl;
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
			cout << "�� ������� ����������� ���������� � ������� ����� ���������" << endl;
			cout << "\"-\" ��������, ��� ������� �� �������� ������� �� ������������" << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << stud[i].name << endl;
				cout << stud[i].surname << endl;
				cout << stud[i].GPA << endl;
			}
			break;
		}

		default:
			cout << "�� ������� �������� ������ ������ ���������� � ���������, ����������, ��������� �������" << endl;
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
		cout << "������� ������, �� ������� ������ ����������� ����������, ���:" << endl << "0 - ����� �� ���� ���������� ������ ���������� �� ������� ���������" \
			<< endl << "1, 2, 3, 4, 5 - ������ �� �����, ��������� ����� � �������� �����" << endl;

		while (true)
		{
			cin >> o;

			if (cin.fail() || o < 0 || o > 5)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
			cout << "�� ����� �� ���� ���������� ������ ���������� �� ������� ���������" << endl;
			break;

		case 1:
		{
			int o1 = 0;

			do
			{
				cout << "��������, ��� ������ ����������, ���:" << endl << "0 - ����� �� ���� ���������� �� ������ \"1\"" << endl << \
					"1 - �������� ���������� �� ������ \"1\" �� ���� �����" << endl << "2 - �������� ���������� �� ������ \"1\" �� ���������� ����" << \
					endl << "3 - �������� ���������� �� ������ \"1\" �� ��������� �����" << endl << "4 - �������� ���������� �� ������ \"1\" �� �������� �����" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ���������� �� ������ \"1\" �� ���� �����" << endl;
					break;

				case 1:
					cout << "�� ������� ���������� �� ������ \"1\" �� ���� �����" << endl;
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
							cout << "� �������� �� ���� \"�����\" ������ �� \"1\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 1)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�������\" ������ �� \"1\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 1)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������\" ������ �� \"1\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 1)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"��������\" ������ �� \"1\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 1)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"���������\" ������ �� \"1\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 1)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�����\" ������ �� \"1\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 1)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"1\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 1)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������������ ������\" ������ �� \"1\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 1)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "� �������� �� ��������� ����� ������ �� \"1\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "�� ������� ���������� �� ������ \"1\" �� ���������� ����" << endl << \
							"�������� ����, ���������� � ������� ������ �������, ���:" << endl << \
							"0 - ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl << "1 - �����" \
							<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
							endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
							<< "8 - ������������ ������" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
							cout << "�� ����� �� ���� ���������� �� ������ \"1\" �� ���������� ����" << endl;
							break;

						case 1:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"�������\"" << endl;
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
									cout << "� �������� �� ���� \"�������\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"������\"" << endl;
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
									cout << "� �������� �� ���� \"������\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"��������\"" << endl;
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
									cout << "� �������� �� ���� \"��������\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"���������\"" << endl;
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
									cout << "� �������� �� ���� \"���������\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"������ � ���������\"" << endl;
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
									cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "�� ������� ����������� ���������� �� ������ \"1\" �� ���� \"������������ ������\"" << endl;
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
									cout << "� �������� �� ���� \"������������ ������\" ������ �� \"1\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "�� ������� ������� ������������ ���������� � ��������� �� ���������� ����, ����������, ��������� �������" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}

				case 3:
				{
					cout << "�� ������� ���������� �� ������ \"1\" �� ��������� �����" << endl;
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
							cout << "� �������� �� ���� ��������� ����� ������ �� \"1\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}

				case 4:
				{
					cout << "�� ������� ���������� �� ������ \"1\" �� �������� �����" << endl;
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
							cout << "� �������� ������� ���� �� \"1\"" << endl;
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
				cout << "��������, ��� ������ ����������, ���:" << endl << "0 - ����� �� ���� ���������� �� ������ \"2\"" << endl << \
					"1 - �������� ���������� �� ������ \"2\" �� ���� �����" << endl << "2 - �������� ���������� �� ������ \"2\" �� ���������� ����" << \
					endl << "3 - �������� ���������� �� ������ \"2\" �� ��������� �����" << endl << "4 - �������� ���������� �� ������ \"2\" �� �������� �����" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ���������� �� ������ \"2\" �� ���� �����" << endl;
					break;

				case 1:
				{
					cout << "�� ������� ���������� �� ������ \"2\" �� ���� �����" << endl;
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
							cout << "� �������� �� ���� \"�����\" ������ �� \"2\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 2)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�������\" ������ �� \"2\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 2)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������\" ������ �� \"2\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 2)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"��������\" ������ �� \"2\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 2)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"���������\" ������ �� \"2\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 2)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�����\" ������ �� \"2\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 2)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"2\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 2)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������������ ������\" ������ �� \"2\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 2)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "� �������� �� ��������� ����� ������ �� \"2\"" << endl;
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
						cout << "�� ������� ���������� �� ������ \"2\" �� ���������� ����" << endl << \
							"�������� ����, ���������� � ������� ������ �������, ���:" << endl << \
							"0 - ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl << "1 - �����" \
							<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
							endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
							<< "8 - ������������ ������" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
							cout << "�� ����� �� ���� ���������� �� ������ \"2\" �� ���������� ����" << endl;
							break;

						case 1:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"�������\"" << endl;
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
									cout << "� �������� �� ���� \"�������\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"������\"" << endl;
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
									cout << "� �������� �� ���� \"������\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"��������\"" << endl;
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
									cout << "� �������� �� ���� \"��������\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"���������\"" << endl;
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
									cout << "� �������� �� ���� \"���������\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"������ � ���������\"" << endl;
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
									cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "�� ������� ����������� ���������� �� ������ \"2\" �� ���� \"������������ ������\"" << endl;
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
									cout << "� �������� �� ���� \"������������ ������\" ������ �� \"2\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "�� ������� ������� ������������ ���������� � ��������� �� ���������� ����, ����������, ��������� �������" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
				{
					cout << "�� ������� ���������� �� ������ \"2\" �� ��������� �����" << endl;
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
							cout << "� �������� �� ���� ��������� ����� ������ �� \"2\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				}
				case 4:
				{
					cout << "�� ������� ���������� �� ������ \"2\" �� �������� �����" << endl;
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
							cout << "� �������� ������� ���� �� \"2\"" << endl;
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
				cout << "��������, ��� ������ ����������, ���:" << endl << "0 - ����� �� ���� ���������� �� ������ \"3\"" << endl << \
					"1 - �������� ���������� �� ������ \"3\" �� ���� �����" << endl << "2 - �������� ���������� �� ������ \"3\" �� ���������� ����" << \
					endl << "3 - �������� ���������� �� ������ \"3\" �� ��������� �����" << endl << "4 - �������� ���������� �� ������ \"3\" �� �������� �����" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ���������� �� ������ \"3\" �� ���� �����" << endl;
					break;

				case 1:
					cout << "�� ������� ���������� �� ������ \"3\" �� ���� �����" << endl;
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
							cout << "� �������� �� ���� \"�����\" ������ �� \"3\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 3)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�������\" ������ �� \"3\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 3)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������\" ������ �� \"3\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 3)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"��������\" ������ �� \"3\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 3)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"���������\" ������ �� \"3\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 3)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�����\" ������ �� \"3\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 3)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"3\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 3)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������������ ������\" ������ �� \"3\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 3)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "� �������� �� ��������� ����� ������ �� \"3\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "�� ������� ���������� �� ������ \"3\" �� ���������� ����" << endl << \
							"�������� ����, ���������� � ������� ������ �������, ���:" << endl << \
							"0 - ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl << "1 - �����" \
							<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
							endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
							<< "8 - ������������ ������" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
							cout << "�� ����� �� ���� ���������� �� ������ \"3\" �� ���������� ����" << endl;
							break;

						case 1:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"�������\"" << endl;
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
									cout << "� �������� �� ���� \"�������\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"������\"" << endl;
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
									cout << "� �������� �� ���� \"������\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"��������\"" << endl;
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
									cout << "� �������� �� ���� \"��������\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"���������\"" << endl;
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
									cout << "� �������� �� ���� \"���������\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"������ � ���������\"" << endl;
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
									cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "�� ������� ����������� ���������� �� ������ \"3\" �� ���� \"������������ ������\"" << endl;
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
									cout << "� �������� �� ���� \"������������ ������\" ������ �� \"3\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "�� ������� ������� ������������ ���������� � ��������� �� ���������� ����, ����������, ��������� �������" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
					cout << "�� ������� ���������� �� ������ \"3\" �� ��������� �����" << endl;
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
							cout << "� �������� �� ���� ��������� ����� ������ �� \"3\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				case 4:
					cout << "�� ������� ���������� �� ������ \"3\" �� �������� �����" << endl;
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
							cout << "� �������� ������� ���� �� \"3\"" << endl;
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
				cout << "��������, ��� ������ ����������, ���:" << endl << "0 - ����� �� ���� ���������� �� ������ \"4\"" << endl << \
					"1 - �������� ���������� �� ������ \"4\" �� ���� �����" << endl << "2 - �������� ���������� �� ������ \"4\" �� ���������� ����" << \
					endl << "3 - �������� ���������� �� ������ \"4\" �� ��������� �����" << endl << "4 - �������� ���������� �� ������ \"4\" �� �������� �����" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ���������� �� ������ \"4\" �� ���� �����" << endl;
					break;

				case 1:
					cout << "�� ������� ���������� �� ������ \"4\" �� ���� �����" << endl;
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
							cout << "� �������� �� ���� \"�����\" ������ �� \"4\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 4)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�������\" ������ �� \"4\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 4)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������\" ������ �� \"4\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 4)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"��������\" ������ �� \"4\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 4)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"���������\" ������ �� \"4\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 4)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�����\" ������ �� \"4\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 4)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"4\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 4)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������������ ������\" ������ �� \"4\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 4)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "� �������� �� ��������� ����� ������ �� \"4\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "�� ������� ���������� �� ������ \"4\" �� ���������� ����" << endl << \
							"�������� ����, ���������� � ������� ������ �������, ���:" << endl << \
							"0 - ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl << "1 - �����" \
							<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
							endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
							<< "8 - ������������ ������" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
							cout << "�� ����� �� ���� ���������� �� ������ \"4\" �� ���������� ����" << endl;
							break;

						case 1:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"�������\"" << endl;
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
									cout << "� �������� �� ���� \"�������\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"������\"" << endl;
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
									cout << "� �������� �� ���� \"������\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"��������\"" << endl;
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
									cout << "� �������� �� ���� \"��������\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"���������\"" << endl;
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
									cout << "� �������� �� ���� \"���������\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"������ � ���������\"" << endl;
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
									cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "�� ������� ����������� ���������� �� ������ \"4\" �� ���� \"������������ ������\"" << endl;
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
									cout << "� �������� �� ���� \"������������ ������\" ������ �� \"4\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "�� ������� ������� ������������ ���������� � ��������� �� ���������� ����, ����������, ��������� �������" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
					cout << "�� ������� ���������� �� ������ \"4\" �� ��������� �����" << endl;
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
							cout << "� �������� �� ���� ��������� ����� ������ �� \"4\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				case 4:
					cout << "�� ������� ���������� �� ������ \"4\" �� �������� �����" << endl;
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
							cout << "� �������� ������� ���� �� \"4\"" << endl;
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
				cout << "��������, ��� ������ ����������, ���:" << endl << "0 - ����� �� ���� ���������� �� ������ \"5\"" << endl << \
					"1 - �������� ���������� �� ������ \"5\" �� ���� �����" << endl << "2 - �������� ���������� �� ������ \"5\" �� ���������� ����" << \
					endl << "3 - �������� ���������� �� ������ \"5\" �� ��������� �����" << endl << "4 - �������� ���������� �� ������ \"5\" �� �������� �����" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail() || o1 < 0 || o1 > 4)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ���������� �� ������ \"5\" �� ���� �����" << endl;
					break;

				case 1:
					cout << "�� ������� ���������� �� ������ \"5\" �� ���� �����" << endl;
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
							cout << "� �������� �� ���� \"�����\" ������ �� \"5\"" << endl;
						}
						if (stud[i].arrays[size(stud[i].arrays) - 1] - '0' == 5)
						{
							cout << stud[i].arrays << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�������\" ������ �� \"5\"" << endl;
						}
						if (stud[i].str[size(stud[i].str) - 1] - '0' == 5)
						{
							cout << stud[i].str << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������\" ������ �� \"5\"" << endl;
						}
						if (stud[i].recursions[size(stud[i].recursions) - 1] - '0' == 5)
						{
							cout << stud[i].recursions << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"��������\" ������ �� \"5\"" << endl;
						}
						if (stud[i].structs[size(stud[i].structs) - 1] - '0' == 5)
						{
							cout << stud[i].structs << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"���������\" ������ �� \"5\"" << endl;
						}
						if (stud[i].files[size(stud[i].files) - 1] - '0' == 5)
						{
							cout << stud[i].files << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"�����\" ������ �� \"5\"" << endl;
						}
						if (stud[i].pointers[size(stud[i].pointers) - 1] - '0' == 5)
						{
							cout << stud[i].pointers << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"5\"" << endl;
						}
						if (stud[i].dinamics[size(stud[i].dinamics) - 1] - '0' == 5)
						{
							cout << stud[i].dinamics << endl;

						}
						else
						{
							cout << "� �������� �� ���� \"������������ ������\" ������ �� \"5\"" << endl;
						}
						if (stud[i].controltests[size(stud[i].controltests) - 1] - '0' == 5)
						{
							cout << stud[i].controltests << endl;

						}
						else
						{
							cout << "� �������� �� ��������� ����� ������ �� \"5\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;

				case 2:
				{
					int o2 = 0;

					do
					{
						cout << "�� ������� ���������� �� ������ \"5\" �� ���������� ����" << endl << \
							"�������� ����, ���������� � ������� ������ �������, ���:" << endl << \
							"0 - ����� �� ���� ����������� ���������� � ��������� �� ���������� ����" << endl << "1 - �����" \
							<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
							endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
							<< "8 - ������������ ������" << endl;

						while (true)
						{
							cin >> o2;

							if (cin.fail() || o2 < 0 || o2 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
							cout << "�� ����� �� ���� ���������� �� ������ \"5\" �� ���������� ����" << endl;
							break;

						case 1:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 2:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"�������\"" << endl;
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
									cout << "� �������� �� ���� \"�������\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 3:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"������\"" << endl;
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
									cout << "� �������� �� ���� \"������\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 4:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"��������\"" << endl;
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
									cout << "� �������� �� ���� \"��������\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 5:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"���������\"" << endl;
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
									cout << "� �������� �� ���� \"���������\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 6:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"�����\"" << endl;
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
									cout << "� �������� �� ���� \"�����\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 7:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"������ � ���������\"" << endl;
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
									cout << "� �������� �� ���� \"������ � ���������\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						case 8:
							cout << "�� ������� ����������� ���������� �� ������ \"5\" �� ���� \"������������ ������\"" << endl;
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
									cout << "� �������� �� ���� \"������������ ������\" ������ �� \"5\"" << endl;
								}
								cout << stud[i].space << endl;
							}
							break;

						default:
							cout << "�� ������� ������� ������������ ���������� � ��������� �� ���������� ����, ����������, ��������� �������" << endl;
							break;
						}
					} while (o2 != 0);
					break;
				}
				case 3:
					cout << "�� ������� ���������� �� ������ \"5\" �� ��������� �����" << endl;
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
							cout << "� �������� �� ���� ��������� ����� ������ �� \"5\"" << endl;
						}
						cout << stud[i].space << endl;
					}
					break;
				case 4:
					cout << "�� ������� ���������� �� ������ \"5\" �� �������� �����" << endl;
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
							cout << "� �������� ������� ���� �� \"5\"" << endl;
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
		cout << "������� �������� ����������" << endl << "0 - ����� �� ���� ���������� ������ ���������" \
			<< endl << "1 - ����������� ����" << endl << "2 - �� ��������� �����" << endl << "3 - �� �������� �����" << endl;

		while (true)
		{
			cin >> o;

			if (cin.fail() || o < 0 || o > 3)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
			cout << "�� ����� �� ���� ���������� ������ ���������" << endl;
			break;
		case 1:
		{
			int o2;
			cout << "0 - ����� �� ���� ���������� ������ �� ���������� ���������" << endl << "1 - �����" \
				<< endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << \
				endl << "5 - ���������" << endl << "6 - �����" << endl << "7 - ������ � ���������" << endl \
				<< "8 - ������������ ������" << endl;
			while (true)
			{
				cin >> o2;

				if (cin.fail() || o2 < 0 || o2 > 8)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
				cout << "�� ����� �� ���� ���������� ������ ��������� �� ���������" << endl;
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

	cout << "������� ����� �������: "; getline(cin, question1);
	cout << "������� ������ ������� ������: "; getline(cin, ans11);
	cout << "������� ������ ������� ������: "; getline(cin, ans21);
	cout << "������� ������ ������� ������: "; getline(cin, ans31);
	cout << "������� �������� ������� ������: "; getline(cin, ans41);
	cout << "������� ����� ����������� �������� ������: "; getline(cin, true_ans1);

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
		cout << "������� ������, ������� ������� �������: ";
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
				cout << "������ �� ������, ��������� �������" << endl;
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
		cout << "������� ������, ������� ������� ��������: ";
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
					cout << "��������, ��� �������� � �������: " << endl << "0 - ������ ��������" << endl << "1,2,3,4 - ������" << endl << "5 - ���������� �����" << endl << "6 - ����� �������" << endl;
					cin >> tr;
					switch (tr)
					{
					case 6:
					{
						cout << "������� ����� �������� ��� ����" << endl;
						cin.ignore();
						getline(cin, quest[i].text);
						break;
					}
					case 1:
					{
						cout << "������� ����� �������� ��� ����" << endl;
						cin.ignore();
						getline(cin, quest[i].ans1);
						quest[i].ans1 = "1)" + quest[i].ans1;
						break;
					}
					case 2:
					{
						cout << "������� ����� �������� ��� ����" << endl;
						cin.ignore();
						getline(cin, quest[i].ans2);
						quest[i].ans2 = "2)" + quest[i].ans2;
						break;
					}
					case 3:
					{
						cout << "������� ����� �������� ��� ����" << endl;
						cin.ignore();
						getline(cin, quest[i].ans3);
						quest[i].ans3 = "3)" + quest[i].ans3;
						break;
					}
					case 4:
					{
						cout << "������� ����� �������� ��� ����" << endl;
						cin.ignore();
						getline(cin, quest[i].ans4);
						quest[i].ans4 = "4)" + quest[i].ans4;
						break;
					}
					case 5:
					{
						cout << "������� ����� �������� ��� ����" << endl;
						cin.ignore();
						getline(cin, quest[i].true_ans);
						break;
					}
					default: cout << "����������� ����!" << endl;
					}
				} while (tr != 0);


				flag = false;
				break;
			}
			if (i == size - 1)
			{
				cout << "������ �� ������, ��������� �������" << endl;
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
		cout << "�������� ��������" << endl << "0.����� �� ������ �������������" << endl << "1.�������������� ��������" << endl \
			<< "2.������ �� ������� ���������" << endl << "3.�������� �����" << endl << "4.�������� �������������� �����" <<\
			endl << "5.��������� ������ �� �����" << endl;
		while (true)
		{
			cin >> fl1;

			if (cin.fail() || fl1 < 0 || fl1 > 6)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
			cout << endl << "�� ����� �� ������ �������������" << "\n\n";
			break;
		}
		case 1:
		{
			do
			{
				cout << "�������� �������� �� ������" << endl << "0.��������� �����" << endl << "1.�������� �������" << endl << "2.���������� �������" << endl << "3.��������� �������" << endl;
				while (true)
				{
					cin >> fl2;

					if (cin.fail() || fl2 < 0 || fl2 > 3)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
						cout << "�������� ����" << endl << "0.�����" << endl << "1.�����" << endl << "2.�����" << endl << "3.�������" << endl << "4.���������" << endl << "5.��������" << endl << "6.������" << endl << "7.���������" << endl << "8.������������ ������" << endl;
						while (true)
						{
							cin >> fl4;

							if (cin.fail() || fl4 < 0 || fl4 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
						default: cout << "������������ ����!" << endl;
						}
					} while (fl4 != 0);
					break;
				}
				case 2:
				{
					do
					{
						cout << "�������� ����" << endl << "0.�����" << endl << "1.�����" << endl << "2.�����" << endl << "3.�������" << endl << "4.���������" << endl << "5.��������" << endl << "6.������" << endl << "7.���������" << endl << "8.������������ ������" << endl;
						while (true)
						{
							cin >> fl4;

							if (cin.fail() || fl4 < 0 || fl4 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
						default: cout << "������������ ����!" << endl;
						}
					} while (fl4 != 0);
					break;
				}
				case 3:
				{
					do
					{
						cout << "�������� ����" << endl << "0.�����" << endl << "1.�����" << endl << "2.�����" << endl << "3.�������" << endl << "4.���������" << endl << "5.��������" << endl << "6.������" << endl << "7.���������" << endl << "8.������������ ������" << endl;
						while (true)
						{
							cin >> fl4;

							if (cin.fail() || fl4 < 0 || fl4 > 8)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
						default: cout << "������������ ����!" << endl;
						}
					} while (fl4 != 0);
					break;
				}
				default: cout << "����������� ����!" << endl;
				}
			} while (fl2 != 0);
			break;
		}
		case 2:
		{
			do
			{
				cout << "�������� �������� �� ������" << endl << "0.��������� �����" << endl << "1.�������� ��������" << endl << "2.���������������� ��������" << endl << "3.�������� �������� ��������" << endl
					<< "4.������� ������ ���������" << endl << "5.������� ��������������� ������ ���������" << endl << "6.������� ��������������� ������" << endl;
				while (true)
				{
					cin >> fl3;

					if (cin.fail() || fl3 < 0 || fl3 > 6)
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
				default: cout << "����������� ����!" << endl;
				}
			} while (fl3 != 0);
			break;
		}
		case 3:
		{
			cout << "�� ������� �������� ��������� �����" << endl;

			int o1 = -1;

			do
			{
				cout << "�������� ����, ������� ������ �����������:" << endl << "0 - ������� ���� ������ �����" << endl << "1 - ���� � �������� �����"\
					<< endl << "2 - ���� � ����� ���������" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ������ �����" << endl;
					break;

				case 1:
					cout << "�� ������� ��� �������� ���� � �������� �����" << endl;
					encryption("questions_list/questionsforencryptions.txt", "encryption_questions_list/encryptionQuestions.txt", 5);
					break;

				case 2:
					cout << "�� ������� ��� �������� ���� � ����� ���������" << endl;
					encryption("students_information/students.txt", "students_information/encryptionStudents.txt", 5);
					break;

				default:
					cout << "�� ����� ������������ ����� �����. ����������, ��������� �������" << endl;
					break;
				}
			} while (o1 != 0);

			break;
		}
		case 4:
		{
			cout << "�� ������� ����� ������������� ����������" << endl;

			int o1 = -1;

			do
			{
				cout << "�������� ����, ������� ������ �������:" << endl << "0 - ������� ���� ������ �����" << endl << "1 - ���� � �������� �����"\
					<< endl << "2 - ���� � ����� ���������" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ������ �����" << endl;
					break;

				case 1:
					cout << "�� ������� ��� ������ ���� � �������� �����" << endl;
					output_cryption_ADMIN("encryption_questions_list/encryptionQuestions.txt");
					break;

				case 2:
					cout << "�� ������� ��� ������ ���� � ����� ���������" << endl;
					output_cryption_ADMIN("students_information/encryptionStudents.txt");
					break;

				default:
					cout << "�� ����� ������������ ����� �����. ����������, ��������� �������" << endl;
					break;
				}
			} while (o1 != 0);

			break;
		}

		case 5:
		{
			cout << "�� ������� ��������� ������ �� ����� � �� �����" << endl;

			int o1 = -1;

			do
			{
				cout << "�������� ����, ������� ������ �������:" << endl << "0 - ������� ���� ������ �����" << endl << \
					"1 - �������� ���� � �������� �����" << endl << "2 - �������� ���� � ����� ���������" << endl << \
					"3 - ������������� ���� � �������� �����" << endl << "4 - ������������� ���� � ����� ���������" << endl;

				while (true)
				{
					cin >> o1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�� ����� ������������ ��������. ����������, ��������� �������" << endl;
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
					cout << "�� ����� �� ���� ������ �����" << endl;
					break;

				case 1:
					cout << "�� ������� ��� ��������� ������ �� ����� � �� ������ �������� ���� � �������� �����" << endl;
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
					cout << "�� ������� ��� ��������� ������ �� ����� � �� ������ �������� ���� � ����� ���������" << endl;
					output_cryption_ADMIN("students_information/students.txt");
					break;

				case 3:
					cout << "�� ������� ��� ��������� ������ �� ����� � �� ������ ������������� ���� � �������� �����" << endl;
					decryptionOutput("encryption_questions_list/encryptionQuestions.txt", 5);
					break;

				case 4:
					cout << "�� ������� ��� ��������� ������ �� ����� � �� ������ ������������� ���� � ����� ���������" << endl;
					decryptionOutput("students_information/encryptionStudents.txt", 5);
					break;

				default:
					cout << "�� ����� ������������ ����� �����. ����������, ��������� �������" << endl;
					break;
				}
			} while (o1 != 0);

			break;
		}
		default: cout << "����������� ����!" << endl;
		}
	} while (fl1 != 0);
}