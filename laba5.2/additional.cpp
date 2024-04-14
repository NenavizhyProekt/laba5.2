#include "Header.h"

bool isValidName(string name) {
	if (name[0] == ' ' || name[0] == '.')
		return false;
	for (int i = 1; i < name.length(); i++) {
		if (name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'À' && name[i] <= 'ß' || name[i] >= 'à' && name[i] <= 'ÿ' ||
			name[i] == ' ' || name[i] == '.')
			continue;
		else
			return false;
	}
	return true;
}


bool isInt(string user_num) {
	for (int i = 0; i < user_num.length(); i++)
		if (!isdigit(user_num[i])) {
			cout << "Ââåäåíû íåêîððåêòíûå äàííûå" << endl;
			return false;
			break;
		}
	return true;
}


Film fillStruct() {
	string filmName, directorName, cost, year;
	int costInt, yearInt;

	cout << "Введите название фильма: ";
	do {
		getline(cin, filmName);
		if (isValidName(filmName))
			break;
		cout << "Введено неверное название, попробуйте еще раз: ";
	} while (true);

	cout << "Введите имя режиссера: ";
	do {
		getline(cin, directorName);
		if (isValidName(directorName))
			break;
		cout << "Введено неверное имя, попробуйте еще раз: ";
	} while (true);

	cout << "Стоимость фильма: ";
	do {
		getline(cin, cost);
		if (isInt(cost)) {
			costInt = stoi(cost);
			if (costInt > 0)
				break;
		}
		else
			continue;
		cout << "Введено неверное число, попробуйте еще раз: ";
	} while (true);

	cout << "Введите год выпуска фильма: ";
	do {
		getline(cin, year);
		if (isInt(year)) {
			yearInt = stoi(year);
			if (yearInt >= 1895 && yearInt <= 2024)
				break;
		}
		else
			continue;
		cout << "Введена неверная дата, попробуйте еще раз: ";
	} while (true);


	Film film = { filmName, directorName, costInt, yearInt};
	return film;
}


void new_massiv(int userNum, Film *film, vector<string> &directors) {
	for (struct Film* p = film; p < film + userNum; p++) {
		if(directors.empty())
			directors.push_back(p->directorName);
		else{
			for (int i = 0; i < directors.size(); i++) {
				if (p->directorName == directors[i])
					break;
				directors.push_back(p->directorName);
			}
		}
	}
}


bool cmp(Film& a, Film& b) {
	if (a.year < b.year) return true;
	if (a.year > b.year) return false;
}