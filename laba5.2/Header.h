#include <iostream>
#include <ctime>
#include <string>
#include <windows.h> 
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Film {
	string filmName;
	string directorName;
	int cost;
	int year;
};

bool isInt(string);
bool isValidName(string);
Film fillStruct();
void new_massiv(int, Film*, vector<string>&);
bool cmp(Film&, Film&);