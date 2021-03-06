#include "pch.h"
#include <iostream>
#include <string>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"

using namespace std;

const string outOfRangeError = "Blad, wartosc musi byc liczba calkowita, wieksza od zera";
const string eliteSizeOutOfRangeError = "Blad, wartosc musi byc liczba calkowita, podzielna przez 2, wieksza od zera i mniejsza od wielkosci populacji";
const string giveKnapsackSize = "Podaj rozmiar plecaka: ";
const string giveElemenstPossibleNumber = "Podaj ilosc elementow mozliwych w plecaku: ";
const string giveEliteNumber = "Podaj ilosc elementow elitarnych: ";
const string space = "	";
const string textElement = "Element nr: ";
const string textValue = "Wartosc: ";
const string textSize = "Rozmiar: ";

const int populationSize = 50;
const int iterationsAmount = 20;
const int mutationProbabilityPromiles = 100;
const int crossingProbabilityPromiles = 900;

int main()
{
	int maximalSize=0, elementsAmount=0;
	do
	{
		if (elementsAmount != 0)
		{
			cout << outOfRangeError << endl;
		}
		cout << giveElemenstPossibleNumber << endl;
		cin >> elementsAmount;
	} while (elementsAmount <= 0);

	do
	{
		if (maximalSize != 0)
		{
			cout << outOfRangeError << endl;
		}
		cout << giveKnapsackSize << endl;
		cin >> maximalSize;
	} while (maximalSize <= 0);

	CKnapsackProblem ourKnapsackProblem(elementsAmount, maximalSize);

	for (int i = 0; i < ourKnapsackProblem.getElementsAmount(); i++)
	{
		cout<<textElement << i << space<<textValue << ourKnapsackProblem.getValueTable()[i] << space<<textSize << ourKnapsackProblem.getSizeTable()[i] << endl;
	}

	int eliteSize = 0;

	do
	{
		if (eliteSize != 0)
		{
			cout << eliteSizeOutOfRangeError << endl;
		}
		cout << giveEliteNumber << endl;
		cin >> eliteSize;
	} while (eliteSize <= 0 || eliteSize>=populationSize || eliteSize%2!=0);

	CGeneticAlgorithm algorithm(&ourKnapsackProblem, populationSize, iterationsAmount, mutationProbabilityPromiles, crossingProbabilityPromiles, eliteSize);
	
	algorithm.run();
}
