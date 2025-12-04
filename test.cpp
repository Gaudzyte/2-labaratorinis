#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"

#include "../include/studentas.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

// Pagalbinė funkcija – kad testai būtų švaresni
Studentas kurkStudenta(const string& vardas,
                       const string& pavarde,
                       const vector<int>& paz,
                       int egz) {
    return Studentas(vardas, pavarde, paz, egz);
}

TEST_CASE("Studentas: galutinis balas pagal vidurki skaiciuojamas teisingai") {
    // paz = {10, 8, 6, 4} -> vidurkis = (10+8+6+4)/4 = 7.0
    vector<int> paz = {10, 8, 6, 4};
    Studentas s = kurkStudenta("Vardas", "Pavarde", paz, 10);

    // galVid = 0.4 * vidurkis + 0.6 * egz = 0.4*7 + 0.6*10 = 2.8 + 6 = 8.8
    CHECK(doctest::Approx(8.8).epsilon(0.001) == s.galVid());
}

TEST_CASE("Studentas: galutinis balas pagal mediana lyginiu pazymiu skaiciui") {
    vector<int> paz = {1, 5, 9, 7}; 
    // Surikiuota: {1, 5, 7, 9} -> mediana = (5 + 7) / 2 = 6
    Studentas s = kurkStudenta("Vardas", "Pavarde", paz, 8);

    // galMed = 0.4 * 6 + 0.6 * 8 = 2.4 + 4.8 = 7.2
    CHECK(doctest::Approx(7.2).epsilon(0.001) == s.galMed());
}

TEST_CASE("Studentas: kai nera pazymiu, galutiniai balai yra 0") {
    vector<int> paz; // tuščias
    Studentas s = kurkStudenta("Vardas", "Pavarde", paz, 0);

    CHECK(doctest::Approx(0.0).epsilon(0.001) == s.galVid());
    CHECK(doctest::Approx(0.0).epsilon(0.001) == s.galMed());
}
