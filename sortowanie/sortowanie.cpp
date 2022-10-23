// This is only to learn c++ and git/gitHub
// PL: algorytmy i struktura danych na studiuje.it
// Tu będą poszczególne zadania.

#include <iostream>

using namespace std;

const int tableSize = 20;
const int maxNum = 1000;

int tab1[tableSize];
int tab2[tableSize];

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

void copyTable(int t[], int zrodlo[], int size) {
	for (int i=0; i < size; i++) {
		t[i] = zrodlo[i];
	}
}

void printTable(int t[],int size) {
	//wydruk tabeli na ekranie
	cout << "||====================================================================================||\n";
	cout << "||------------------------------         Tabela         ------------------------------||\n";
	cout << "||------------------------------------------------------------------------------------||\n";
	cout << "|| ";
	for (int i = 0; i < size; i++) {
		cout << t[i];
		if (i < size - 1) cout << ", ";
		if (i != 0 && i % 15 == 0) cout << endl << "|| ";
	}
	cout << "\n||------------------------------------------------------------------------------------||\n";
	cout << "||====================================================================================||\n";
}

void randomizeTheTable(int t[],int size) {
	initRand();
	for (int i = 0; i < size; i++) t[i] = randomInt(0, maxNum);
}

int bubbleSort(int t[],int size) {
	//zwraca liczbę kroków
	bool flaga = false;
	int d = 0;
	for (int j = 0; j < (size - 1); j++) {
		flaga = false;
		for (int i = (size - 1); i > j; i--) {
			if (t[i - 1] > t[i]) {
				int temp = t[i - 1];
				t[i - 1] = t[i];
				t[i] = temp;
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

int main() {
	randomizeTheTable(tab1,tableSize);
	copyTable(tab2, tab1,tableSize);
	printTable(tab1,tableSize);
	printTable(tab2,tableSize);

	cout << endl << endl << " Bubble Sort: " << endl;
	cout << "Liczba krokow: " << bubbleSort(tab1, tableSize) << endl;
	printTable(tab1, tableSize);

	cout << endl << endl << " Quick Sort: " << endl;
	quickSort(tab2,0,tableSize-1); //dla ułatwienia rekurencji w argumencie przekazywany jest index ostatniego elementu a nie ilość elem. 
	printTable(tab2,tableSize);
}
