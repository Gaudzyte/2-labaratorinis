#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::istringstream;

class Studentas {
    string vardas_;
    string pavarde_;
    vector<int> paz_;
    int egz_;
    double gal_vid_;
    double gal_med_;

    double vidurkis() const;
    double mediana() const;
    void skaiciuotiBalus();

public:
    // Konstruktoriai
    Studentas()
        : vardas_(),
          pavarde_(),
          paz_(),
          egz_(0),
          gal_vid_(0.0),
          gal_med_(0.0) {}

    Studentas(std::istream& is);

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline double galVid() const { return gal_vid_; }
    inline double galMed() const { return gal_med_; }

    std::istream& readStudent(std::istream& is);


    ~Studentas() = default;
};

#endif
