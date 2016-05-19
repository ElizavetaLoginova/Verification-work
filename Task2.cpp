#include <iostream>
#include <fstream>

using namespace std;

void InitFile(char*);
void SystemFun();
void InitNumber(long&);
void ChangeFile(char*, int*, int);
int HowMuch(int*, int, int&);
int* InitArray(char* fileName, int n);
int ContentsFile(char*);

int main()
{
	char fileName[20];
	cout << "Enter the name of the file: ";
	cin >> fileName;
	system("cls");

	InitFile(fileName);
	int n = ContentsFile(fileName);

	int* array = InitArray(fileName, n);
	ChangeFile(fileName, array, n);

	system("pause");
	return 0;

}












int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int count = 0, term;
	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}


void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int temp, n=10;
		for (int i = 0; i < n; i++)
		{
			cout << "enter temp variable:";
			cin >> temp;
			//temp = i + 1;
			streamOut.width(5);
			streamOut << temp;
			//cout << temp << endl;
		}
	streamOut.close();
}
void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void ChangeFile(char* fileName, int* array, int n)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int i = 0;
	int bufSize = sizeof(array);
	while (i != bufSize)
	{
		int k = HowMuch(array, bufSize, i);
		streamInOut.seekp((i - 1) * bufSize, ios::beg);
		streamInOut.write((char*)&k, bufSize);
		streamInOut.close();
	}
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

int HowMuch(int* array, int n, int& i)
{
	int counter = 0;
	for (i; i < n; i++)
	{
		int num = array[i];
		if (array[i] == num)
			counter++;
	}
	return counter;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}
