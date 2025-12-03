/**
 * @file studentas.cpp
 * @brief Studentas klasės metodų implementacija.
 *
 * Šiame faile pateikiamos visos klasės @c Studentas funkcijų realizacijos:
 * - konstruktoriai (numatytasis, iš srauto, rankinis įvedimas, kopijavimo),
 * - kopijavimo priskyrimo operatorius,
 * - įvesties operatorius >>,
 * - išvesties operatorius <<,
 * - pažymių skaičiavimo logika (vidurkis, mediana, galutiniai balai),
 * - studento duomenų nuskaitymas iš @c std::istream.
 *
 * Failas yra glaudžiai susijęs su:
 * - studentas.h (deklaracijos),
 * - zmogus.h (paveldėjimas iš Zmogus),
 * - mylib.h (Studentas naudojamas duomenų apdorojimo funkcijose).
 *
 * Tai yra pagrindinis failas, apibrėžiantis studento elgesį ir skaičiavimus.
 */

#include "studentas.h"
#include <algorithm>  
#include <iostream>   
#include <sstream> 
#include <iomanip>

using namespace std;

Studentas::Studentas()
    : Zmogus(), 
      paz_(),
      egz_(0),
      gal_vid_(0.0),
      gal_med_(0.0)
{}
// Konstruktorius (is streamo)
Studentas::Studentas(istream& is)
    : Zmogus(), paz_(), egz_(0), gal_vid_(0.0), gal_med_(0.0)
{
    readStudent(is);
}

// Konstruktorius (is rankinio ivedimo)
Studentas::Studentas(const string& vardas,
                     const string& pavarde,
                     const vector<int>& paz,
                     int egz)
    : Zmogus(vardas, pavarde),  
      paz_(paz),
      egz_(egz),
      gal_vid_(0.0),
      gal_med_(0.0)
{
    skaiciuotiBalus();
}


Studentas::Studentas(const Studentas& other)
    : Zmogus(other.vardas_, other.pavarde_),  // kopijuojam bazinę dalį
      paz_(other.paz_),
      egz_(other.egz_),
      gal_vid_(other.gal_vid_),
      gal_med_(other.gal_med_) {}

// Kopijavimo priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        paz_     = other.paz_;
        egz_     = other.egz_;
        gal_vid_ = other.gal_vid_;
        gal_med_ = other.gal_med_;
    }
    return *this;
}
// Nuskaito studento duomenis iš streamo į esamą objektą
istream& Studentas::readStudent(std::istream& is) {
    // išvalom senus duomenis (jei kas nors kviestų antrą kartą)
    vardas_.clear();
    pavarde_.clear();
    paz_.clear();
    egz_ = 0;
    gal_vid_ = 0.0;
    gal_med_ = 0.0;

    if (!(is >> vardas_ >> pavarde_)) {
        return is;
    }

    int pazymys;
    while (is >> pazymys) {
        paz_.push_back(pazymys);
    }

    if (!paz_.empty()) {
        egz_ = paz_.back();
        paz_.pop_back();
    } else {
        egz_ = 0;
    }

    skaiciuotiBalus();
    return is;
}

istream& operator>>(istream& in, Studentas& s)
{
    return s.readStudent(in);
}

// operator<< (spausdina studentą į ostream)
ostream& operator<<(ostream& os, const Studentas& s) {
    os << setw(15) << left << s.vardas()
       << setw(20) << left << s.pavarde()
       << setw(17) << left << fixed << setprecision(2) << s.galVid()
       << setw(17) << left << fixed << setprecision(2) << s.galMed();
    return os;
}


double Studentas::vidurkis() const {
    if (paz_.empty()) return 0.0;
    double suma = 0;
    for (int p : paz_) suma += p;
    return suma / paz_.size();
}

double Studentas::mediana() const {
    if (paz_.empty()) return 0.0;
    vector<int> tmp = paz_;
    sort(tmp.begin(), tmp.end());
    size_t n = tmp.size();
    if (n % 2 == 0)
        return (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
    else
        return tmp[n / 2];
}

void Studentas::skaiciuotiBalus() {
    gal_vid_ = 0.4 * vidurkis() + 0.6 * egz_;
    gal_med_ = 0.4 * mediana() + 0.6 * egz_;
}
