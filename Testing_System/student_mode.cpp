#include "student_mode.h"

int print_and_input()
{
    cout << endl << "Выберите тему из списка:" << endl;
    cout << "1 - Циклы" << endl;
    cout << "2 - Массивы (одномерные и двумерные)" << endl;
    cout << "3 - Строки" << endl;
    cout << "4 - Рекурсия" << endl;
    cout << "5 - Структуры" << endl;
    cout << "6 - Файлы" << endl;
    cout << "7 - Адреса и указатели" << endl;
    cout << "8 - Динамическая память" << endl;

    string str;
    do
    {
        cin >> str;
        if (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "4") ||
            (str == "5") || (str == "6") || (str == "7") || (str == "8"))))
            cout << "Ошибка ввода, попробуйте ещё раз: ";
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
    int k = 1;
    for (int i = 2; i <= 61; i++)
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
                        cout << "Ошибка ввода, попробуйте ещё раз: ";
                } while (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))));

                num = stoi(strng);

                if (num != stoi(line)) cout << "Ответ неправильный, попробуйте ещё раз: ";
                else cout << endl;
            }
        }
    }
    question_file.close();
    cout << "Вы прошли тренинг";
}

int testing(int n)
{
    ifstream question_file = return_file(n);
    string line, question, name_theme;
    vector<string> questions;
    vector<int> num_questions;
    getline(question_file, name_theme);
    cout << endl;
    int k = 1;
    int mistake = 0;
    for (int i = 2; i <= 61; i++)
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
                    cout << "Ошибка ввода, попробуйте ещё раз: ";
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
    }
    cout << "Вы прошли тест" << endl;
    
    if (questions.size() != 0)
    {
        cout << "Количество ошибок: " << mistake << endl;
        cout << "Вопросы, в которых вы ошиблись: " << endl;
        for (int i = 0; i < questions.size(); i++) cout << num_questions[i] << "." << questions[i] << endl;
    }
    else
        cout << "Вы не допустили ни одной ошибки" << endl;
    
    question_file.close();
    int val = 10 - mistake;
    if (val >= 9 && val <= 10) return 5;
    if (val >= 7 && val <= 8) return 4;
    if (val >= 5 && val <= 6) return 3;
    else return 2;
}

int control_testing()
{
    srand(time(NULL));

    ofstream final_test("questions_list/final_test.txt");
    ofstream extra("questions_list/extra.txt");
    ifstream file_question;
    string line, quest1, quest2;

    int* a = new int[8];
    int size_a = 0, x;
    bool generate = true;
    
    for (int i = 0; i < 8; i++)
    {
        while (generate)
        {
            x = 1 + rand() % 8;
            generate = false;
            for (int j = 0; j < size_a; j++)
            {
                if (x == a[j])
                {
                    generate = true;
                    break;
                }
            }
        }
        a[size_a++] = x;
        generate = true;

        file_question = return_file(x);
        int num_line_quest = 2 + 6 * (rand() % 8);
        for (int n = 1; n < num_line_quest; n++) getline(file_question, line);
        for (int n = 1; n <= 12; n++)
        {
            getline(file_question, line);
            if (n <= 6)
            {
                quest1 = line + "\n";
                final_test << quest1;
            }

            else
            {
                quest2 = line + "\n";
                extra << quest2;
            }
        }
        
    }
    delete[] a;

    file_question.close();
    extra.close();
    
    ifstream extra2("questions_list/extra.txt");
    for (int i = 1; i <= 48; i++)
    {
        getline(extra2, line);
        if (i != 48) final_test << line << endl;
        else final_test << line;
    }
    extra2.close();
    final_test.close();

    ifstream final_test2("questions_list/final_test.txt");
    string question;
    cout << endl;
    int k = 1;
    int mistake = 0;
    for (int i = 1; i <= 96; i++)
    {
        getline(final_test2, line);
        if ((i % 6 != 1) && (i % 6 != 0)) cout << line << endl;
        else if (i % 6 == 1)
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
                    cout << "Ошибка ввода, попробуйте ещё раз: ";
            } while (!((strng.length() == 1) && ((strng == "1") || (strng == "2") || (strng == "3") || (strng == "4"))));

            num = stoi(strng);

            if (num != stoi(line)) mistake++;
            cout << endl;
        }
    }
    final_test2.close();

    cout << "Вы прошли итоговый тест" << endl;

    if (mistake != 0) cout << "Количество ошибок: " << mistake << endl;
    else cout << "Вы не допустили ни одной ошибки" << endl;

    int val = 16 - mistake;
    if (val >= 14 && val <= 16) return 5;
    if (val >= 11 && val <= 13) return 4;
    if (val >= 8 && val <= 10) return 3;
    else return 2;
}

void copy_file()
{
    string line;
    ofstream student_file("students_information/students.txt");
    ifstream student_file_copy("students_information/students_copy.txt");

    for (int i = 1; i <= 374; i++)
    {
        getline(student_file_copy, line);
        if (i != 374) student_file << line << endl;
        else student_file << line;
    }

    student_file.close();
    student_file_copy.close();
}

void recordingAddData(string login, int est, int n)
{
    ifstream student_file("students_information/students.txt");
    ofstream student_file_copy("students_information/students_copy.txt");
    string line;

    for (int i = 1; i <= 374; i++)
    {
        getline(student_file, line);
        
        if (i != 374) student_file_copy << line << endl;
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

    for (int i = 1; i <= 374; i++)
    {
        getline(student_file, line);

        if (i != 374) student_file_copy << line << endl;
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
                        if (line.back() != ' ')
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
        cout << "1 - Тренинг по теме" << endl;
        cout << "2 - Тестирование по теме" << endl;
        cout << "3 - Итоговый тест" << endl;
        cout << "0 - Для выхода" << endl;

        string str;
        do
        {
            cin >> str;
            if (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "0"))))
                cout << "Ошибка ввода, попробуйте ещё раз: ";
        } while (!((str.length() == 1) && ((str == "1") || (str == "2") || (str == "3") || (str == "0"))));

        n = stoi(str);
       
        switch (n)
        {
            case 0:
                cout << "Вы вышли из режима студента";
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
                cout << "Ваша оценка: " << est;
                recordingAddData(login, est, num);
                avg_data_recording(login, est);
                break;
            }
            case 3:
                int est = control_testing();
                cout << "Ваша оценка: " << est;
                recordingAddData(login, est, 9);
                avg_data_recording(login, est);
                break;  
        }
        cout << endl;
    } while (n != 0);
}