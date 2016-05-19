#include <iostream>
#include <fstream>

using namespace std;

int ContentsFile(char*);
int* InitArray(char*, int);
void BubbleSort(int*, int);
void CreateFile(char*, int, int*);
int *MergeArrays(int *a, int n, int *b, int m, int& l);
void Swap(int &a, int &b);

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

	int n = ContentsFile(fileName1);
	int m = ContentsFile(fileName2);
	int* Array1 = InitArray(fileName1, n);
	int* Array2 = InitArray(fileName2, m);
	int l = 0;
	int* Result = MergeArrays(Array1, n, Array2, m, l);
	BubbleSort(Result, l);
	CreateFile(fileNameResult, l, Result);
	cout << endl;
	system("pause");
	delete[] Array1;
	delete[] Array2;
	delete[] Result;
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

void BubbleSort(int* arr, int n)//error dimention!
{
	for (int i = 1; i <= n - 1; i++)
	{
		int max = i - 1;
		for (int j = i - 1; j <= n - 1; j++)
		if (arr[j] > arr[max])
			max = j;
		Swap(arr[i - 1], arr[max]);
	}
}
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void CreateFile(char* fileName, int n, int* array)
{
	ofstream streamOut(fileName);
	//ofstream streamOut; streamOut.open(fileName, ios::out);
	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}
	int temp;
	for (int i = 0; i < n; i++)
			{
				temp = array[i];
				streamOut.width(5);
				streamOut << temp;
			}
	streamOut.close();
}

int *MergeArrays(int *a, int n, int *b, int m, int& l)
{
	l = n + m;
	int *c = new int[l];
	int i = 0, j = 0, k = 0;
	for (; i < n && j < m; k++)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
	}
	if (i == n)
	for (; j < m; j++, k++)
		c[k] = b[j];
	else
	for (; i < n; i++, k++)
		c[k] = a[i];
	return c;
}