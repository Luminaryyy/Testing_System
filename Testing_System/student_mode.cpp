#include "student_mode.h"

int print_and_input()
{
    cout << endl << "�������� ���� �� ������:" << endl;
    cout << "1 - �����" << endl;
    cout << "2 - ������� (���������� � ���������)" << endl;
    cout << "3 - ������" << endl;
    cout << "4 - ��������" << endl;
    cout << "5 - ���������" << endl;
    cout << "6 - �����" << endl;
    cout << "7 - ������ � ���������" << endl;
    cout << "8 - ������������ ������" << endl;

    string str;
    do
    {
        cin >> str;
        if (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "4") ||
            (str == "5") || (str == "6") || (str == "7") || (str == "8"))))
            cout << "������ �����, ���������� ��� ���: ";
    } while (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "4") ||
        (str == "5") || (str == "6") || (str == "7") || (str == "8"))));

    int n = stoi(str);

    return n;
}

ifstream return_file(int n)
{
    switch (n)
    {
        case 1:
        {
            ifstream question_file("questions_list/loops.txt");
            return question_file;
            break;
        }
        case 2:
        {
            ifstream question_file("questions_list/matrix.txt");
            return question_file;
            break;
        }
        case 3:
        {
            ifstream question_file("questions_list/string.txt");
            return question_file;
            break;
        }
        case 4:
        {
            ifstream question_file("questions_list/recursion.txt");
            return question_file;
            break;
        }
        case 5:
        {
            ifstream question_file("questions_list/struct.txt");
            return question_file;
            break;
        }
        case 6:
        {
            ifstream question_file("questions_list/file.txt");
            return question_file;
            break;
        }
        case 7:
        {
            ifstream question_file("questions_list/pointer.txt");
            return question_file;
            break;
        }
        case 8:
        {
            ifstream question_file("questions_list/dinamic_RAM.txt");
            return question_file;
            break;
        }
    }
    
}

void training(int n)
{
    ifstream question_file = return_file(n);
    string line;
    getline(question_file, line);
    cout << endl;
    int k = 1, i = 2;
    while (!question_file.eof())
    {
        getline(question_file, line);
        if ((i % 6 != 1) && (i % 6 != 2)) cout << line << endl;
        else if (i % 6 == 2) cout << k++ << "." << line << endl;
        else
        {
            int num = -1;
            while (num != stoi(line))
            {
                string strng;
                do
                {
                    cin >> strng;
                    if (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))))
                        cout << "������ �����, ���������� ��� ���: ";
                } while (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))));

                num = stoi(strng);

                if (num != stoi(line)) cout << "����� ������������, ���������� ��� ���: ";
                else cout << endl;
            }
        }
        i++;
    }
    question_file.close();
    cout << "�� ������ �������";
}

int testing(int n)
{
    ifstream question_file = return_file(n);
    string line, question, name_theme;
    vector<string> questions;
    vector<int> num_questions;
    getline(question_file, name_theme);
    cout << endl;
    int k = 1, mistake = 0, i = 2;
    while (!question_file.eof())
    {
        getline(question_file, line);
        if ((i % 6 != 1) && (i % 6 != 2)) cout << line << endl;
        else if (i % 6 == 2)
        {
            cout << k++ << "." << line << endl;
            question = line;
        }
        else
        {
            int num = -1;
            string strng;
            do
            {
                cin >> strng;
                if (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))))
                    cout << "������ �����, ���������� ��� ���: ";
            } while (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))));

            num = stoi(strng);

            if (num != stoi(line))
            {
                questions.push_back(question);
                num_questions.push_back(k - 1);
                mistake++;
            }
            cout << endl;
        }
        i++;
    }
    cout << "�� ������ ����" << endl;
    
    if (questions.size() != 0)
    {
        cout << "���������� ������: " << mistake << endl;
        cout << "�������, � ������� �� ��������: " << endl;
        for (int i = 0; i < questions.size(); i++) cout << num_questions[i] << "." << questions[i] << endl;
    }
    else
        cout << "�� �� ��������� �� ����� ������" << endl;
    
    question_file.close();
    int val = 10 - mistake;
    if (val >= 9 && val <= 10) return 5;
    if (val >= 7 && val <= 8) return 4;
    if (val >= 5 && val <= 6) return 3;
    else return 2;
}

bool check(string login)
{
    ifstream student_file("students_information/students.txt");
    string line;
    int i = 1;
    while (!student_file.eof())
    {
        getline(student_file, line);

        if (i % 15 == 3)
        {
            line.erase(0, 7);
            if (login == line)
            {
                i++;
                getline(student_file, line);
                for (int j = 0; j < 8; j++)
                {
                    i++;
                    getline(student_file, line);
                    if ((line.back() == '-') || (line.back() == '2')) return false;
                }
                return true;
            }
        }
        i++;
    }
    student_file.close();
}

int control_testing()
{
    srand(time(NULL));

    ofstream final_test1("questions_list/final_test.txt");
    ifstream file_question;
    string line;
    int table[8][10] = {};
    int num_theme, num_line_quest, num_last_theme = -1;
    bool generate = true;
    
    for (int i = 0; i < 20; i++)
    {
        while (generate)
        {
            num_theme = rand() % 8;
            num_line_quest = rand() % 10;
            if ((table[num_theme][num_line_quest] == 0) && (num_theme != num_last_theme)) break;
        }
        num_last_theme = num_theme;
        table[num_theme][num_line_quest] = 1;

        file_question = return_file(num_theme + 1);
        for (int n = 1; n < 2 + num_line_quest * 6; n++) getline(file_question, line);
        for (int n = 1; n <= 6; n++)
        {
            getline(file_question, line);
            if (!((i == 19) && (n == 6))) final_test1 << line + "\n";
            else final_test1 << line;
        }   
    }

    final_test1.close();
    file_question.close();

    ifstream final_test2("questions_list/final_test.txt");
    string question;
    cout << endl;
    int k = 1, mistake = 0, i1 = 1;
    while (!final_test2.eof())
    {
        getline(final_test2, line);
        if ((i1 % 6 != 1) && (i1 % 6 != 0)) cout << line << endl;
        else if (i1 % 6 == 1)
        {
            cout << k++ << "." << line << endl;
            question = line;
        }
        else
        {
            int num = -1;
            string strng;
            do
            {
                cin >> strng;
                if (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))))
                    cout << "������ �����, ���������� ��� ���: ";
            } while (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))));

            num = stoi(strng);

            if (num != stoi(line)) mistake++;
            cout << endl;
        }
        i1++;
    }
    final_test2.close();

    cout << "�� ������ �������� ����" << endl;

    if (mistake != 0) cout << "���������� ������: " << mistake << endl;
    else cout << "�� �� ��������� �� ����� ������" << endl;

    int val = 20 - mistake;
    if (val >= 18 && val <= 20) return 5;
    if (val >= 14 && val <= 17) return 4;
    if (val >= 10 && val <= 13) return 3;
    else return 2;
}

void copy_file()
{
    string line;
    ofstream student_file("students_information/students.txt");
    ifstream student_file_copy("students_information/students_copy.txt");
    int i = 1;
    while (!student_file_copy.eof())
    {
        getline(student_file_copy, line);
        if (!student_file_copy.eof()) student_file << line << endl;
        else student_file << line;
        i++;
    }

    student_file.close();
    student_file_copy.close();
}

void recordingAddData(string login, int est, int n)
{
    ifstream student_file("students_information/students.txt");
    ofstream student_file_copy("students_information/students_copy.txt");
    string line;

    int i = 1;
    while (!student_file.eof())
    {
        getline(student_file, line);
        
        if (!student_file.eof()) student_file_copy << line << endl;
        else student_file_copy << line;
        if (i % 15 == 3)
        {
            line.erase(0, 7);
            if (login == line)
            {
                i++;
                getline(student_file, line);
                student_file_copy << line << endl;
                for (int j = 0; j < n; j++)
                {
                    i++;
                    getline(student_file, line);
                    if (j + 1 != n) student_file_copy << line << endl;
                    else
                    {
                        line.pop_back();
                        student_file_copy << line << to_string(est) << endl;
                    }
                }
            }
        }
        i++;
    }
    
    student_file.close();
    student_file_copy.close();

    copy_file();
}

void avg_data_recording(string login, int est)
{
    ifstream student_file("students_information/students.txt");
    ofstream student_file_copy("students_information/students_copy.txt");
    string line;
    int n = 10, k = 0;
    double avg = 0;

    int i = 1;
    while (!student_file.eof())
    {
        getline(student_file, line);

        if (!student_file.eof()) student_file_copy << line << endl;
        else student_file_copy << line;
        if (i % 15 == 3)
        {
            line.erase(0, 7);
            if (login == line)
            {
                i++;
                getline(student_file, line);
                student_file_copy << line << endl;
                for (int j = 0; j < n; j++)
                {
                    i++;
                    getline(student_file, line);
                    if (j + 1 != n)
                    {
                        if (line.back() != '-')
                        {
                            k++;
                            avg += int(line.back()) - 48;
                        }
                        student_file_copy << line << endl;
                    }
                    else
                    {
                        line = line.substr(0, 14);
                        avg = round (avg / k * 10) / 10;
                        student_file_copy << line << to_string(avg).substr(0, 3) << endl;
                    }
                }
            }
        }
        i++;
    }

    student_file.close();
    student_file_copy.close();

    copy_file();
}

void MODE_MAIN(string login)
{
    int n;
    do
    {
        cout << endl;
        cout << "1 - ������� �� ����" << endl;
        cout << "2 - ������������ �� ����" << endl;
        cout << "3 - �������� ����" << endl;
        cout << "0 - ��� ������ �� ������ ��������" << endl;

        string str;
        do
        {
            cin >> str;
            if (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "0"))))
                cout << "������ �����, ���������� ��� ���: ";
        } while (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "0"))));

        n = stoi(str);
       
        switch (n)
        {
            case 0:
                cout << endl << "�� ����� �� ������ ��������" << endl;
                break;
            case 1:
            {
                int num = print_and_input();
                training(num);
                break;
            } 
            case 2:
            {
                int num = print_and_input();
                int est = testing(num);
                if (est == 2) cout << "���� ������: 2, �� �� ����� ����";
                else cout << "���� ������: " << est;
                recordingAddData(login, est, num);
                avg_data_recording(login, est);
                break;
            }
            case 3:
                if (check(login))
                {
                    int est = control_testing();
                    cout << "���� ������: " << est;
                    recordingAddData(login, est, 9);
                    avg_data_recording(login, est);
                    break;
                }
                else cout << endl << "�� ��� �� ����� ��� �����";
        }
        cout << endl;
    } while (n != 0);
}