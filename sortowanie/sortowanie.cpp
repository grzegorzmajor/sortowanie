// This is only to learn c++ and git/gitHub
// PL: algorytmy i struktura danych na studiuje.it
// Tu będą poszczególne zadania.

#include <iostream>

using namespace std;

const int tableSize = 20;
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

void zamien(int t[], int a, int b) {
	int temp = t[a];
	t[a] = t[b];
	t[b] = temp;
	return;
}

void quickSort(int t[], int start, int stop) {
/* quicksort(tablica, indeks 1 elementu, indeks ostatniego 
	komentarze wewnątrz kodu to polecenia do wyświetlania przebiegu sortowania */
	if (stop - start > 1) {
		//cout << " Wiecej niz 2 elementy: " << start << " " << stop << endl;
		int podzial = start;
		for (int i = start; i < stop; i++) {
			//cout << "  Petla: element " << i << " wartosc " << t[i] << " dzielnika: " << t[stop];
			if (t[i]<t[stop]) {
				if (i != podzial) {
					zamien(t, i, podzial);
					//cout << " zamiana ";
				}
				podzial++;
				//cout << " zwiekszam indeks podzialu=" << podzial;
			}
			//cout << endl;
		}
		//cout << " ustawiam dzielnik na pozycji " << podzial << " wartosc dzielnika " << t[stop] << " element zmieniany " << t[podzial] <<endl;
		zamien(t, podzial, stop);
		quickSort(t, start, podzial - 1);
		quickSort(t, podzial + 1, stop);
	}
	if (stop - start == 1) {
		//cout << " dwa elementy: " << start << " " << stop << " wartosci: " << t[start] << " " << t[stop];
		if (t[start] > t[stop]) {
			//cout << " zamieniam ";
			zamien(t, start, stop);
		}
		//cout << endl;
	}
}

int main()
{
	randomizeTheTable();
	printTable();
	//cout <<"Liczba krokow: " << bubbleSort();
	quickSort(tab,0,tableSize-1);
	printTable();

}
