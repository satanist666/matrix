#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int Create(int n, int **A)
{
	A = new int*[n];// Выделение памяти под массив
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[n]; // Добавление указателя
	}
	return 0;
}
int Fill(int n, int **A)// Заполнить матрицу рандомными числами
{	
	for (int i = 0; i < n; i++)// Строчки (Внешний цикл)
	{
		for (int j = 0; j < n; j++)// Столбцы (внутрений цикл)
		{
			A[i][j] = (rand() % 100) - (rand() % 35);// Генерирование  рандомных чисел и добавление в матрицу
			cout.setf(ios::right); // Выравнивание по правой стороне
			cout.width(3); // Выделение по 3 знака на каждую ячейку в матрице A
			cout << A[i][j] << " "; // Вывод матрицы на экран

		}
		cout << endl;
	}
	return 0;

}
void Read(int n, int **A, int i, int j)// Считывание инфформации о матрице 
{
	return;
}
int Calculus(int n, int **A)
{
	int a = 0;
	int b = 0;
	for (int i = 0; i<n; i++)//Проход по строчкам 
	{
		for (int j = 0; j<n; j++)// Проход по столбцам
		{
			// В случае если индексы по осям равны, складываем их в сумму 
			if (i == j) a = a + A[i][j];// Для оси справа налево
			if ((i + j) == n - 1) b = b + A[i][j];//Для оси слева направо
		}
	}
	cout << a << " " << b;
	return 0;
}
int Delete(int n, int **A)
{
	for (int i = 0; i < n; i++)// Очищаем память, выделеную под указатели в матрице 
	{
		delete[] A[i];
	}
	delete[] A;// Очищаем память выделеную под матрицу

	return 0;
}


int main(int argc, const char * argv[])
{
	int n, i, j;
	cin >> n;
	int** A = new int*[n];// Создание массива указателей 
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[n]; // Объявление нового указателя

	}
	Create(n, A);
	Fill(n, A);
	Read(n, A, i, j);
	Calculus(n, A);
	Delete(n, A);


	return 0;
}