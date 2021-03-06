#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

template <typename A> void printArray(A tab[]) {
	for (int i = 0; i < 5; i++) {
		cout << tab[i] << " ";
	}
}

template <typename T> bool compare(T i, T j) {
	return (i < j); 
}

template <typename B> void bubble_sort(B tab[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tab[j] > tab[j + 1]) {
				B tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
	printArray<B>(tab);
}

template <typename B> void insertion_sort(B tab[]) {
	B temporary;
	for (int i = 1; i < 5; i++) {
		int j = i;
		temporary = tab[i];
		while ((j > 0) && (tab[j - 1] > temporary)) {
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = temporary;
	}
	printArray<B>(tab);
}

template <typename M> void menu(M array1[]) {
	int userInput = 0;

	while (userInput != 4) {
		cout << "\n\nWybierz sortowanie" << endl;
		cout << "\n1. Sortowanie babelkowe" << endl;
		cout << "2. Sortowanie przez wstawianie" << endl;
		cout << "3. Sortowanie algorytmem Quicksort" << endl;
		cout << "4. Wyjdz" << endl;

		cin >> userInput;

		switch (userInput) {
				case 1:
					bubble_sort<M>(array1);
					break;
				case 2:
					insertion_sort<M>(array1);
					break;
				case 3:
					sort(array1, array1+5,compare<M>);
					printArray(array1);
					break;
				default:
					continue;
		}
	}
}

template <typename T> void newArray() {
	T userInput;
	T array1[5];

	system("cls");	
	cout << "\nPodaj po kolei 5 wybranych znakow" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> userInput;
		array1[i] = userInput ;
	}

	cout << "Uzupelniona tablica:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array1[i] << " ";
	}
	menu<T>(array1);
}

int main()
{
	int decision;
	do {
		system("cls");
		cout << "Wybierz typ danych" << endl;
		cout << "1. Integer" << endl;
		cout << "2. Double" << endl;
		cout << "3. Char" << endl;
		cout << "4. Wyjdz" << endl;

		cin >> decision;
		if (decision == 1)
			newArray<int>();
		else if (decision == 2)
			newArray<double>();
		else if (decision == 3)
			newArray<char>();
		if (decision < 1 || decision > 4)
			cout << "Bledny wybor" << endl;
	} while (decision != 4);

	return 0;
}