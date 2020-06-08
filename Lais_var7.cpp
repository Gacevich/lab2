#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cfloat>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int size = 4;
	srand(time(NULL));
	double arr[size][size];
	double maxNeg = -DBL_MAX, minPos = DBL_MAX;
	int iN = -1, jN = -1, iP = -1, jP = -1;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			arr[i][j] = (double(rand()) / double(1000)) - 15;
			cout << setw(9) << arr[i][j];

			if ((i >= j) && (j <= size - i - 1))//Красная область
			{
				if (arr[i][j] > 0)
				{
					if (minPos > arr[i][j])
					{
						minPos = arr[i][j];
						iP = i;
						jP = j;
					}
				}
			}
			else if ((i <= j) && (j >= size - i - 1))//Зеленая область
			{
				if (arr[i][j] < 0)
				{
					if (maxNeg < arr[i][j])
					{
						maxNeg = arr[i][j];
						iN = i;
						jN = j;
					}
				}
			}
		}
		cout << endl;
	}

	if (iN == -1) cout << "Отрицательных элементов в зеленой области НЕТ!" << endl;
	if (iP == -1) cout << "Положительных элементов в красной области НЕТ!" << endl;

	if (iN >= 0 && iP >= 0)
	{
		cout << endl << " Mаксимальный отрицательный элемент в зеленой области " << maxNeg
			<< "  Позиция: " << iN << "," << jN << endl;
		cout << " Mинимальный положительный элемент в красной области " << minPos
			<< "  Позиция: " << iP << "," << jP << endl << endl;

		swap(arr[iP][jP], arr[iN][jN]);//Замена элементов, если таковы имеются.

		for (int i = 0; i < size; ++i)//Вывод нового массива
		{
			for (int j = 0; j < size; ++j)
			{
				cout << setw(9) << arr[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}
