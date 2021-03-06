// Decimal to Hexadecimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
string hexa(int number, string hex = "");
string bina(int number, string bin = "");
string binaWithMaxConsec(int number, int& cons, int& maxCons, string bin = "");

int main()
{
	for(int i=0; i < 4; i++)
	{
		int consec = 0;
		int maxConsec = 0;
		int num;

		cout << "Enter a number to convert.\n";
		cin >> num;

		cout << "The decimal number " << num << " converted to hexadecimal is " << hexa(num) << endl << endl;
	    //cout << "The decimal number " << num << " converted to binary is " << bina(num) << endl << endl;

		cout << "The decimal number " << num << " converted to binary is: " << binaWithMaxConsec(num, consec, maxConsec) << endl;
		cout << "The max number of consecutive 1s is: " << maxConsec << endl;
	}

    return 0;
}

string hexa(int number, string hex)
{
	int val = number % 16;

	if (number == 0) {

		if (hex == "")
		{
			hex = to_string(number);
			return hex;
		}
		else
			return hex;
	}

	if (val > 9) {
		if (val == 10) {
			hex = "A" + hex;
		}
		else if (val == 11) {
			hex = "B" + hex;
		}
		else if (val == 12) {
			hex = "C" + hex;
		}
		else if (val == 13) {
			hex = "D" + hex;
		}
		else if (val == 14) {
			hex = "E" + hex;
		}
		else if (val == 15) {
			hex = "F" + hex;
		}
	}
	else {
		hex = to_string(val) + hex;
	}

	number = number / 16;

	return hexa(number, hex);
}

//Just for viewing purposes: currently using just binaWithMaxNum for binary conversion plus maximum consecutive 1 counter
string bina(int number, string bin)
{
	int val = number % 2;

	if (number == 0)
	{
		if (bin == "") {
			bin = to_string(number);
			return bin;
		}
		else
			return bin;
	}

	bin = to_string(val) + bin;

	number = number / 2;

	return bina(number, bin);
}

string binaWithMaxConsec(int number, int& cons, int& maxCons, string bin)
{
	int val = number % 2;

	if (number == 0)
	{
		if (bin == "") {
			bin = to_string(number);
			return bin;
		}
		else
			return bin;
	}

	if (val == 1)
	{
		cons++;

		if (cons > maxCons)
		{
			maxCons = cons;
		}
	}
	else {
		cons = 0;
	}

	bin = to_string(val) + bin;

	number = number / 2;

	return binaWithMaxConsec(number, cons, maxCons, bin);
}