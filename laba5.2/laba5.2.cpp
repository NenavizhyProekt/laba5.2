#include "Header.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array_size;
    int parts = 0;
    string user_str;
    cout << "������� ����� �������: ";
    do {
        getline(cin, user_str);
    } while (!isInt(user_str));
    int userNumber = stoi(user_str);


    array_size = userNumber;
    vector<string> directors;
    Film* allFilms = new Film[array_size];

    while (array_size > 0) {
        cout << "����� �������� ��� " << array_size << " �������" << endl;

        allFilms[parts] = fillStruct();
        parts++;
        array_size--;
    }

    new_massiv(userNumber, allFilms, directors);
    sort(allFilms, allFilms + userNumber - 1, cmp);

    for (int i = 0; i < directors.size(); i++) {
        cout << "��� ��������� : " << directors[i] << endl;
        for (struct Film* p = allFilms; p < allFilms + userNumber; p++) {
            if (directors[i] == p->directorName)
                cout << "��� �����: " << p->filmName << " � ���� �������: " << p->year << endl;
        }
    }
}