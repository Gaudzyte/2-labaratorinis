/**
 * @file main.cpp
 * @brief Programos įėjimo taškas ir vartotojo meniu valdymas.
 *
 * Šis failas apibrėžia pagrindinę programos eigą:
 * - pateikia vartotojui meniu su trimis pasirinkimais,
 * - leidžia rankiniu būdu įvesti studentų duomenis,
 * - nuskaito studentų failą ir jį apdoroja,
 * - atlieka spartos testavimą naudojant skirtingus duomenų kiekius.
 *
 * Funkcijos šiame faile neapdoroja duomenų tiesiogiai — jos iškviečia
 * kitus modulinius komponentus:
 * - @c VartotojoIvedimas() – rankinei įvesčiai,
 * - @c PaprastasFailoApdorojimas() – vieno failo apdorojimui,
 * - @c TestavimasIsFailo() – spartos matavimui.
 *
 * Failas priklauso nuo:
 * - studentas.h (studentų klasė),
 * - mylib.h (logika ir apdorojimo funkcijos),
 * - timer.h (spartos matavimas),
 * - zmogus.h (bazinė klasė).
 *
 * Tai yra pagrindinis vykdomasis failas, kuris valdo visos programos veikimą.
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <chrono>
#include "studentas.h"
#include "mylib.h"
#include "timer.h"
#include "zmogus.h" 

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    //Zmogus zmog;  //sukeltų klaidą: error: cannot declare variable 'zmog' to be of abstract type 'Zmogus'

    int pasirinkimas;
    cout << "Pasirinkite veiksma:\n";
    cout << "1 - Ivesti studentus ranka\n";
    cout << "2 - Nuskaityti pasirinkta faila \n";
    cout << "3 - Spartos testavimas failams\n";
    cout << "Jusu pasirinkimas: ";

    if (!(cin >> pasirinkimas)) return 0;

    if (pasirinkimas == 1) {
        VartotojoIvedimas();
    }
    else if (pasirinkimas == 2) {
        PaprastasFailoApdorojimas();
    }
    else if (pasirinkimas == 3) {
        cout << "Nuskaitomi failai\n" << flush;

        vector<pair<string, int>> failai = {
            //{"studentai.1000.txt", 1000},
            //{"studentai.10000.txt", 10000},
            {"studentai.100000.txt", 100000},
            {"studentai.1000000.txt", 1000000}
            //{"studentai.10000000.txt", 10000000}
        };

        for (auto& f : failai)
            TestavimasIsFailo(f.first, f.second);
    }
    else {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}
