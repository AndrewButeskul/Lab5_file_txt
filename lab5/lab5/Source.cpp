#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int const M = 4;
int const N = 3;
int const L = 4;

struct Arrays
{
	int arr1[M][N];
	int arr2[N][L];
};

struct Array
{
	int arr[M][L];
};

void Multiply(Arrays *object, Array *res, int k)
{	
	for (size_t t = 0; t < k; t++)
	{
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < L; j++)
			{
				res[t].arr[i][j] = 0;
				for (size_t l = 0; l < N; l++)
				{
					res[t].arr[i][j] += object[t].arr1[i][l] * object[t].arr2[l][j];
				}
			}
		}
	}
}

void Fill(Arrays *object, int k)
{
	for (size_t m = 0; m < k; m++)
	{
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				object[m].arr1[i][j] = rand() % 20;
			}
		}
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < L; j++)
			{
				object[m].arr2[i][j] = rand() % 20;
			}
		}
	}
}

void Print_1(ofstream &out, Arrays *object, int k)
{
	for (int m = 0; m < k; m++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out << "\t" << object[m].arr1[i][j];				
			}
			out << "\n";
		}
		out << "\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < L; j++)
			{
				out << "\t" << object[m].arr2[i][j];
			}
			out << "\n";
		}
		out << "__________________________________________________\n";		
	}
}

void Print_2(ofstream &out2, Array *res, int k)
{
	for (int m = 0; m < k; m++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < L; j++)
			{
				out2 << "\t" << res[m].arr[i][j];
			}
			out2 << "\n";
		}
		out2 << "__________________________________________________\n";
	}
}

int main()
{
	srand(time(NULL));
	ofstream out, out2;
	out.open("myfile.txt");
	out2.open("file_2.txt");
	int k = 0;
	cout << "Enter k" << endl;
	cin >> k;
	Arrays *object = new Arrays[k];
	Array *res = new Array[k];
	
	Fill(object, k);
	if (!out.is_open())	
		cout << "Error!" << endl;	
	else
	{
		Print_1(out, object, k);
	}

	if (!out2.is_open())
		cout << "Error!" << endl;
	else
	{
		Multiply(object, res, k);
		Print_2(out2, res, k);
	}
	out.close();
	out2.close();
	system("Pause");
	return 0;
}