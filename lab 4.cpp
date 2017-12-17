#include "stdafx.h"
#include<iostream>
#include <conio.h>

using namespace std;
const int n = 5, m = 5;

class Vector
{
private:
	double V[n][m];
public:
	friend void ReadFromConsole(Vector A[]);
	friend void PrintToConsole(Vector A[]);
	friend void Sort(Vector A[]);
	friend double * Products(Vector A[]);
	friend double AverageValue(Vector A[]);
};

void ReadFromConsole(Vector A[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> *A[i].V[j];
		}
	}
}


void PrintToConsole(Vector A[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << *A[i].V[j] << "\t";
		cout << endl;
	}
}

void Sort(Vector A[])
{
	double value;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1; j >= i + 1; j--)
			{
				if (*A[j].V[k] > *A[j - 1].V[k])
				{
					value = *A[j].V[k];
					*A[j].V[k] = *A[j - 1].V[k];
					*A[j - 1].V[k] = value;
				}
			}
		}
	}
}

double * Products(Vector A[])
{
	double * products = new double[n - 1]{};
	double result = 0;
	for (int i = 1; i < n; i++)
	{
		result = 1;
		for (int j = 0; j < n; j++)
		{
			if ((i + j) >= n)
			{
				result = result * (*A[i].V[j]);
			}
		}
		products[i] = result;
	}
	return products;
}

double AverageValue(Vector A[])
{
	double averagevalue = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += Products(A)[i];
	}
	averagevalue = sum / n;
	return averagevalue;
}

void main(void)
{
	Vector Bv[n];
	ReadFromConsole(Bv);
	PrintToConsole(Bv);
	Sort(Bv);
	cout << "Sorted matrix" << endl;
	PrintToConsole(Bv);
	for (int i = 0; i < n; i++)
	{
		cout << "Product in row #" << i + 1 << " under side dia is " << Products(Bv)[i] << endl;
	}

	cout << "Their averagevalue is " << AverageValue(Bv) << endl;
	_getch();
}
