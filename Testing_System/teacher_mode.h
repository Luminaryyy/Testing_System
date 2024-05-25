#pragma once
#include "Libraries.h"

struct question
{
	string text;
	string ans1;
	string ans2;
	string ans3;
	string ans4;
	string true_ans;
};
struct Students
{
	string name;
	string surname;
	string login;
	string password;
	string loops;
	string arrays;
	string str;
	string recursions;
	string structs;
	string files;
	string pointers;
	string dinamics;
	string controltests;
	string GPA;
	string space;
};
int PushStudents(struct Students* stud, const string& fileName, int size);
void outputStruct(struct Students* stud, int size);
void writeStudents(struct Students* stud, const string& fileName, int& size);
void delStudents(struct Students* stud, const string& fileName, int& size);
void addStudents(struct Students* stud, const string& fileName, int& size);
void changeProgress(struct Students* stud, const string& fileName, int& size2);
void outputStudents(struct Students* stud, const string& fileName, int& size2);
void filter(struct Students* stud, const string& fileName, int& size2);
void sort(struct Students* stud, const string& filename, int& size2);
int PushQuestions(struct question* quest, const string& fileName, int size);
void writeQuestions(struct question* quest, const string& fileName, int& size);
void output_cryption_ADMIN(const string& fileName);
void addQuestions(struct question* quest, const string& fileName, int& size);
void delQuestions(struct question* quest, const string& fileName, int& size);
void editQuestions(struct question* quest, const string& fileName, int& size);
void ADMIN_MODE();