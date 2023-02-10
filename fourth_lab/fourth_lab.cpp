#include <iostream>
using namespace std;
int sizeMas;

int* bubbleSort(int* arr, int size) {
	for (int i = size - 1; i > 0; i--) {
		for (int j = size - 1; j >= size - i; j--) {
			if (arr[j] > arr[j - 1]) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	return arr;
}

void masiveOutput(int mas[], int size, int k) {
	if (k > size) k %= size;
	for (int i = k - 1; i >= 0; i--) {
		cout << mas[i] << " ";
	}
	for (int i = size - 1; i >= k; i--) {
		cout << mas[i] << " ";
	}
}

int* deleteOddElement(int mas[], int size) {
	int newSize = 0;
	for (int i = 0; i < size; i++)
		if (mas[i] % 2 == 0) {
			mas[newSize++] = mas[i];
		}
			
	sizeMas = newSize;
	return mas;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int k;
	
	cout << "Введите длину массива: ";
	cin >> sizeMas;

	int* mas = new int[sizeMas];
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < sizeMas; ++i) {
		cout << "Элемент массива " << i + 1 << " : ";
		cin >> mas[i] ;
	}

	cout << "Введите элемент к: ";
	cin >> k;

	cout << "Вывод массива, начиная с элемента k до k + 1: " << endl;
	masiveOutput(mas, sizeMas, k);

	//Функция,сортирующая массив методом пузырька
	bubbleSort(mas, sizeMas);

	//Функция, удаляющая нечетные элементы
	deleteOddElement(mas, sizeMas);

	cout << endl << "Вывод упорядоченного по убыванию массива четных чисел от k до k + 1: " << endl;
	masiveOutput(mas, sizeMas, k);

	delete[] mas;
	return 0;
}