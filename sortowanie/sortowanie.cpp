// This is only to learn c++ and git/gitHub
// That's why I am writing Polish below
// PL: algorytmy i struktury danych na studiuje.it
// Tu będą poszczególne zadania.
// 
// To jest już coś więcej niż w algorytmach.
// pobawiłem się trochę
// Dodałem swoją klasę stoper do liczenia czasu
// pracy algorytmów

#include <iostream>
#include <chrono>
#include <algorithm>
#include "stoper.cpp"

using namespace std;

 
const int tableSize = 20000; //wielkosc tabeli 
const int maxNum = 1000; //maksymalna wartosc elementu tablicy

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

void copyTable(int cel[], int zrodlo[], int size) {
	//kopiowanie calej tablicy
	for (int i = 0; i < size; i++) {
		cel[i] = zrodlo[i];
	}
}

void partialCopyTable(int cel[], int zrodlo[], int start, int stop) {
	//kopiowanie czesciowe tablicy
	for (int i = start; i <= stop; i++) {
		cel[i] = zrodlo[i];
	}
}

void moveValuesUp(int tab[], int start, int stop) {
	for (int i = stop; i >= start; i--) {
		tab[i+1] = tab[i];
		if (i=start) tab[i] = NULL;
	}
}

void printTable(int tab[],int size) {
	//wydruk tabeli na ekranie
	cout << "||============================================================================================================||\n";
	cout << "||============------------------------------         Tabela         ------------------------------============||\n";
	cout << "||============------------------------------------------------------------------------------------============||\n";
	cout << "|| ";
	for (int i = 0; i < size; i++) {
		cout << tab[i];
		if (i < size - 1) cout << ", ";
		if (i != 0 && i % 15 == 0) cout << endl << "|| ";
	}
	cout << "\n||============------------------------------------------------------------------------------------============||\n";
	cout << "||============================================================================================================||\n";
}

void randomizeTheTable(int tab[],int size) {
	initRand();
	for (int i = 0; i < size; i++) tab[i] = randomInt(0, maxNum);
}

int bubbleSort(int tab[],int size) {
	//zwraca liczbę kroków
	bool flaga = false;
	int d = 0;
	for (int j = 0; j < (size - 1); j++) {
		flaga = false;
		for (int i = (size - 1); i > j; i--) {
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

void zamien(int tab[], int a, int b) {
	int temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
	return;
}

void quickSort(int tab[], int start, int stop) {
/* quicksort(tablica, indeks 1 elementu, indeks ostatniego 
	komentarze wewnątrz kodu to polecenia do wyświetlania przebiegu sortowania */
	if (stop - start > 1) {
		//cout << " Wiecej niz 2 elementy: " << start << " " << stop << endl;
		int podzial = start;
		for (int i = start; i < stop; i++) {
			//cout << "  Petla: element " << i << " wartosc " << t[i] << " dzielnika: " << t[stop];
			if (tab[i]<tab[stop]) {
				if (i != podzial) {
					zamien(tab, i, podzial);
					//cout << " zamiana ";
				}
				podzial++;
				//cout << " zwiekszam indeks podzialu=" << podzial;
			}
			//cout << endl;
		}
		//cout << " ustawiam dzielnik na pozycji " << podzial << " wartosc dzielnika " << t[stop] << " element zmieniany " << t[podzial] <<endl;
		zamien(tab, podzial, stop);
		quickSort(tab, start, podzial - 1);
		quickSort(tab, podzial + 1, stop);
	}
	if (stop - start == 1) {
		//cout << " dwa elementy: " << start << " " << stop << " wartosci: " << t[start] << " " << t[stop];
		if (tab[start] > tab[stop]) {
			//cout << " zamieniam ";
			zamien(tab, start, stop);
		}
		//cout << endl;
	}
}

void selectionSort(int tab[], int size) {
	int indexSmallestVar;
	for (int i = 0; i <size-1; i++) {
		indexSmallestVar = i;
		for (int j = i+1; j <size; j++) {
			if (tab[indexSmallestVar] > tab[j]) {
				indexSmallestVar = j;
			}				
		}
		if (indexSmallestVar!=i) zamien(tab, i, indexSmallestVar);
	}
}

void insertSort(int tab[], int size) {
	for (int i = 1; i < size; i++) {
		int temp = tab[i];
		int j = i - 1;
		while (i > 0 && tab[j] > temp) {
			tab[j + 1] = tab[j--];
			tab[j + 1] = temp;
		}
	}
}

int main() {
	int tab1[tableSize];
	int tab2[tableSize];
	int tab3[tableSize];
	int tab4[tableSize];
	int tab5[tableSize];

	Stoper sBubble, sQuick, sSelect, sInsert,sOther;
	randomizeTheTable(tab1,tableSize);
	copyTable(tab2, tab1,tableSize);
	copyTable(tab3, tab1, tableSize);
	copyTable(tab4, tab1, tableSize);
	copyTable(tab5, tab1, tableSize);
	cout << endl << " Tabela wejsciowa: " << endl;
	printTable(tab1,tableSize);
	


	cout << endl << endl << " Bubble Sort: " << endl;
	cout << "Liczba krokow: ";	
	sBubble.setStartTime();
	cout << bubbleSort(tab1, tableSize);
	sBubble.setStopTime();	
	cout << endl;
	printTable(tab1, tableSize);

	cout << endl << endl << " Quick Sort: " << endl;
	sQuick.setStartTime();
	quickSort(tab2,0,tableSize-1); //dla ułatwienia rekurencji w argumencie przekazywany jest index ostatniego elementu a nie ilość elem. 
	sQuick.setStopTime();
	printTable(tab2,tableSize);

	cout << endl << endl << " Selection Sort: " << endl;
	sSelect.setStartTime();
	selectionSort(tab3, tableSize);
	sSelect.setStopTime();
	printTable(tab3, tableSize);

	cout << endl << endl << " Insertion Sort: " << endl;
	sInsert.setStartTime();
	selectionSort(tab4, tableSize);
	sInsert.setStopTime();
	printTable(tab4, tableSize);

	cout << endl << endl << " Funkcja sortowania wbudowana w biblioteke algorithm: " << endl;
	sOther.setStartTime();
	sort(tab5,tab5+tableSize);
	sOther.setStopTime();
	printTable(tab5, tableSize);

	cout << "Czas pracy algorytmow (w mikrosekundach):" << endl;
	int jednostkaCzasu = 1; //1 mikrosekundy
	cout << "	   Bubble Sort : " << sBubble.getStopwachTime(jednostkaCzasu) << endl;
	cout << "	    Quick Sort : " << sQuick.getStopwachTime(jednostkaCzasu) << endl;
	cout << "	Selection Sort : " << sSelect.getStopwachTime(jednostkaCzasu) << endl;
	cout << "	Insertion Sort : " << sInsert.getStopwachTime(jednostkaCzasu) << endl << endl;
	cout << "	Funkcja sortowania wbudowana w biblioteke algorithm: " << endl;
	cout << "	                 " << sOther.getStopwachTime(jednostkaCzasu) << endl;
}
