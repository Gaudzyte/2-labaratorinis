#include "studentas.h"
#include <algorithm>  
#include <iostream>   
#include <sstream> 

using namespace std;

// Konstruktorius (is streamo)
Studentas::Studentas(std::istream& is) {
    readStudent(is);
}

// Konstruktorius (is rankinio ivedimo)
Studentas::Studentas(const string& vardas,
                     const string& pavarde,
                     const vector<int>& paz,
                     int egz)
    : vardas_(vardas),
      pavarde_(pavarde),
      paz_(paz),
      egz_(egz),
      gal_vid_(0.0),
      gal_med_(0.0)
{
    skaiciuotiBalus();
}

// Nuskaito studento duomenis iš streamo į esamą objektą
std::istream& Studentas::readStudent(std::istream& is) {
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
