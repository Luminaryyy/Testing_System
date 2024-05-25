#include "file_management_module.h"

void encryption(const string& inputFileName, const string& outputFileName, int step)
{
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);

	string line;

	while (getline(inputFile, line))
	{
		string encryptedLine = "";

		for (size_t i = 0; i < line.length(); i++)
		{
			encryptedLine += line[i] + step;
		}

		outputFile << encryptedLine << endl;
	}

	inputFile.close();
	outputFile.close();

	cout << "Файл успешно зашифрован" << endl;
}

void output_cryption_ADMIN(const string& fileName)
{
	ifstream inputFile(fileName);

	string line;

	while (getline(inputFile, line))
	{
		cout << line << endl;
	}

	inputFile.close();
}

void decryptionOutput(const string& fileName, int step)
{
	ifstream inputFile(fileName);

	string line;

	while (getline(inputFile, line))
	{
		string decryptedLine = "";

		for (size_t i = 0; i < line.length(); i++)
		{
			char decryptedChar = line[i] - step;
			decryptedLine += decryptedChar;
		}
		cout << decryptedLine << endl;
	}

	inputFile.close();
}

void recordingAddDataCryptyon(const string& fileName)
{
	ofstream outputFile(fileName, ios::app);

	string line;

	cout << "Введите необходимую добавочную информацию для файла: ";

	outputFile << endl;

	while (getline(cin, line) && line != "")
	{
		outputFile << line << endl;
	}

	outputFile.close();
}