// This is only to learn c++ and git/gitHub
// PL: algorytmy i struktura danych na studiuje.it
// Tu będą poszczególne zadania.

#include <iostream>

using namespace std;

const int tableSize = 100;
const int maxNum = 1000;

int tab[tableSize];

void initRand() {
	//inicjacja losowości
	srand(time(NULL));
	return;
}
int randomInt(int start, int stop) {
	//losowanie z zakresu
	int num = (rand() % (stop - start + 1)) + start;
	return num;
}

void printTable() {
	//wydruk tabeli na ekranie
	cout << "\n\n**------------------------------------------------------------------------------------**\n";
	cout << "**------------------------------         Tabela         ------------------------------**\n";
	cout << "**------------------------------------------------------------------------------------**\n";
	for (int i = 0; i < tableSize; i++) {
		cout << tab[i];
		if (i < tableSize - 1) cout << ", ";
		if (i != 0 && i % 16 == 0) cout << endl;
	}
	cout << "\n**------------------------------------------------------------------------------------**\n";
	cout << "**------------------------------------------------------------------------------------**\n";
}

void randomizeTheTable() {
	initRand();
	for (int i = 0; i < tableSize; i++) tab[i] = randomInt(0, maxNum);
}

int bubbleSort() {
	//zwraca liczbę kroków
	bool flaga = false;
	int d = 0;
	for (int j = 0; j < (tableSize - 1); j++) {
		flaga = false;
		for (int i = (tableSize - 1); i > j; i--) {
			if (tab[i - 1] > tab[i]) {
				int temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
				flaga = true;
			}
			d++;
		}
		if (!flaga) break;
	}
	return d;
}


int main()
{
	randomizeTheTable();
	printTable();
	cout <<"Liczba krokow: " << bubbleSort();
	printTable();

}
