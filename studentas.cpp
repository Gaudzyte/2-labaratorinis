#include "studentas.h"
#include <algorithm>  
#include <iostream>   
#include <sstream> 

using namespace std;

Studentas::Studentas(istringstream& iss) {
    int pazymys;
    iss >> vardas_ >> pavarde_;
    while (iss >> pazymys) {
        paz_.push_back(pazymys);
    }
    egz_ = paz_.back();
    paz_.pop_back();
    skaiciuotiBalus();
}

double Studentas::vidurkis() const {
    if (paz_.empty()) return 0.0;
    double suma = 0;
    for (int p : paz_) suma += p;
    return suma / paz_.size();
}


void Studentas::skaiciuotiBalus() {
    gal_vid_ = 0.4 * vidurkis() + 0.6 * egz_;
}

void Studentas::keistiDuomenis(string v, string p, vector<int> paz, int e) {
    vardas_ = v;
    pavarde_ = p;
    paz_ = paz;
    egz_ = e;
    skaiciuotiBalus();
}
