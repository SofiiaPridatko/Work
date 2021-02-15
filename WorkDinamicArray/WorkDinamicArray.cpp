// WorkDinamicArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

void Sort(int*, int, int, int);
void Merge(int*, int, int, int, int);
void ArrPrint(int*, int);


int main()
{
	int lenArr = 9;
	cout << "Enter length of your array ";
	cin >> lenArr;
	int* A = new int[lenArr];
	cout << "Enter the value (after each item press 'Enter')\n";
	for (int counter = 0; counter < lenArr; counter++)
		cin >> A[counter];
	cout << "\nResult of sort: ";
	int p = 0, r = lenArr - 1;

	Sort(A, p, r, lenArr);
	ArrPrint(A, lenArr);
	return 0;
}

void Sort(int *A, int p, int r, int lenArr)
{
	if (p < r)
	{
		int q = round((p + r) / 2);
		Sort(A, p, q, lenArr);
		Sort(A, q + 1, r, lenArr);
		Merge(A, p, q, r, lenArr);

	}
}

void Merge(int *A, int p, int q, int r, int lenArr)
{
	/**/
	int p0 = p, q0 = q, count = 0;
	int* temp = new int[lenArr];
	while ((p <= q0) and ((q + 1) <= r))
	{
		if (A[p] < A[q + 1])
		{
			temp[count] = A[p];
			p++;
		}
		else
		{
			temp[count] = A[q + 1];
			q++;
		}
		count++;
	}
	//дописываем, если одна из частей массива закончилась
	while (p <= q0)
	{
		temp[count] = A[p];
		count++; p++;
	}
	while ((q + 1) <= r)
	{
		temp[count] = A[q + 1];
		count++; q++;
	}
	count = 0;
	for (int counter = p0; counter <= r; counter++)
	{
		A[counter] = temp[count];
		count++;
	}
}

void ArrPrint(int *A, int lenArr)
{
	cout << "\n";
	for (int counter = 0; counter < lenArr; counter++)
		cout << A[counter] << " ";
}