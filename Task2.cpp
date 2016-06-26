//---------------------Task 2------------------------------------
//В бинарный файл записать n целых чисел. Изменить содержимое файла,
//записав после серии подряд идущих чисел количество их повторений.
//Массивы не использовать!
//Пример: 
//Исходный данные - 1, 3, 3, 3, 3, 5, 5, 6, 7, 7, 7, 7, 7
//Результат - 1, 1, 3, 3, 3, 3, 4, 5, 5, 2, 6, 1, 7, 7, 7, 7, 7, 5

void CreateFile(char*, int);
void ChangeContentFile(char*);
void DisplayContentFile(char*);

int main()
{
	//TODO
}

------------------------------------------------------------------------------------------

#include <iostream>
#include <io.h>
#include <fstream>

using namespace std;

void CreateFile(char*, int);
void ChangeContentFile(char*, char*);
void DisplayContentFile(char*);

const int N = 30;
const int n = 7;

int main()
{
	char fileName[N] = "", fileName1[N] = "";
	cout << "Enter the name of file: ";
	cin.getline(fileName, N, '\n');
	cout << "Enter the name of new file: ";
	cin.getline(fileName1, N, '\n');
	CreateFile(fileName, n);
	DisplayContentFile(fileName);
	ChangeContentFile(fileName, fileName1);
	cout << endl;
	DisplayContentFile(fileName1);
	system("pause");
	return 0;
}

void DisplayContentFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	int bufSize = sizeof(int);
	int a;
	while (streamIn.read((char*)&a, bufSize))
	{
		cout << a;
		cout.width(3);
	}
	streamIn.close();
}

void CreateFile(char* fileName, int n)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	int bufSize = sizeof(int);
	int a;
	char Ok = 'y';
	while (Ok == 'y')
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			streamOut.write((char*)&a, bufSize);
		}
		cout << " If do you want to continue, press 'y' :";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeContentFile(char* fileName, char* fileName1)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	fstream stream1InOut(fileName1, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	int bufSize = sizeof(int);
	int a1, a2;
	int count = 1;
	streamInOut.read((char*)&a1, bufSize);
	while (streamInOut.read((char*)&a2, bufSize))
	{
		stream1InOut.write((char*)&a1, bufSize);
		if (a1 == a2)
		{
			count++;
		}
		else
		{
			stream1InOut.write((char*)&count, bufSize);
			count = 1;
		}
		a1 = a2;
	}
	stream1InOut.write((char*)&a1, bufSize);
	stream1InOut.write((char*)&count, bufSize);
	streamInOut.close();
}
