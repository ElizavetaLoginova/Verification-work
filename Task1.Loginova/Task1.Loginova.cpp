#include <iostream>
#include <fstream>

using namespace std;


void ShowContentsFile(char*);
void CreateNewFile(char*, char*, char*);

int main()
{
	char fileName1[20], fileName2[20], fileNameResult[20];
	cout << "Enter the name of 1-st file: ";
	cin >> fileName1;
	system("cls");

	cout << "Enter the name of 2-nd file: ";
	cin >> fileName2;
	system("cls");

	cout << "Enter the name of the resulting file: ";
	cin >> fileNameResult;
	system("cls");


	cout << endl << "File 1: ";
	ShowContentsFile(fileName1);
	cout << endl << "File 2: ";
	ShowContentsFile(fileName2);

	CreateNewFile(fileName1, fileName2, fileNameResult);
	cout << endl << "DONE!";

	system("pause");
	return 0;
}

void CreateNewFile(char* fileName1, char* fileName2, char* fileName)
{
	ifstream streamIn1(fileName1);
	ifstream streamIn2(fileName2);
	ofstream streamOut(fileName);
	if (!streamIn1.is_open())
	{
		cout << " Cannot open file " << fileName1 << " to read!" << endl;
		system("pause");
		exit(1);
	}
	if (!streamIn2.is_open())
	{
		cout << " Cannot open file " << fileName2 << " to read!" << endl;
		system("pause");
		exit(1);
	}
	if (!streamOut.is_open())
	{
		cout << " Cannot open file " << fileName << " to write!" << endl;
		system("pause");
		exit(1);
	}

	system("cls");
	int a1, a2;
	streamIn1 >> a1;
	streamIn2 >> a2;
	streamOut.width(5);
	while ((!streamIn1.eof()) && (!streamIn2.eof()))
	{			
			if (a1 > a2)
			{
				streamOut << a2;
				streamIn2 >> a2;
			}
			
			else
			{
				streamOut << a1;
				streamIn1 >> a1;
			}
	}
	streamOut << a1;

	streamIn1.close();
	streamIn2.close();
	streamOut.close();
	return;
}



void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	char String[20] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(String, 20, '\n');
		cout << String << endl;
	}
}

