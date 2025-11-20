#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::istream;
using std::ostream;
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
    Studentas();              
    explicit Studentas(std::istream& is); 
    Studentas(const std::string& vardas,        // is rankinio ivedimo
              const std::string& pavarde,
              const std::vector<int>& paz,
              int egz);  
              
    Studentas(const Studentas& other); // kopijavimo konstruktorius
    Studentas& operator=(const Studentas& other);// kopijavimo priskyrimas

    ~Studentas(){    //Destruktorius
        vardas_.clear();
        pavarde_.clear();
        paz_.clear();
        egz_ = 0;
        gal_vid_ = 0.0;
        gal_med_ = 0.0;
    }                
   
    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline double galVid() const { return gal_vid_; }
    inline double galMed() const { return gal_med_; }

    std::istream& readStudent(std::istream& is);

    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

};

#endif
