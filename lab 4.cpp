// laboratorna4.cpp: определяет точку входа для консольного приложения.
//

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
	friend void InputMatrix(Vector A[]);
	friend void OutputMatrix(Vector A[]);
	friend void Sort(Vector A[]);
	friend double * Products(Vector A[]);
	friend double Average(Vector A[]);
};

void InputMatrix(Vector A[])
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


void OutputMatrix(Vector A[])
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

double Average(Vector A[])
{
	double average = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += Products(A)[i];
	}
	average = sum / n;
	return average;
}

void main(void)
{
	Vector Bv[n];
	InputMatrix(Bv);
	OutputMatrix(Bv);
	Sort(Bv);
	cout << "Sorted matrix" << endl;
	OutputMatrix(Bv);
	for (int i = 0; i < n; i++)
	{
		cout << "Product in row #" << i + 1 << " under side dia is " << Products(Bv)[i] << endl;
	}

	cout << "Their average is " << Average(Bv) << endl;
	_getch();
}
