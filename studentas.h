/**
 * @file zmogus.h
 * @brief Abstrakti bazinė klasė žmogui aprašyti.
 *
 * Šiame faile aprašoma abstrakti klasė Zmogus, kuri saugo bendrus žmogaus
 * duomenis (vardą ir pavardę) ir reikalauja, kad paveldėtos klasės įgyvendintų
 * šių reikšmių grąžinimo funkcijas.
 *
 * Failas yra projekto paveldėjimo struktūros pagrindas — iš šios klasės
 * paveldi Studentas bei kitos galimos ateities klasės.
 */
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "zmogus.h"

using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::istringstream;

/**
 * @class Studentas
 * @brief Klasė, reprezentuojanti studentą ir jo pažymius.
 *
 * Paveldi bazinę klasę Zmogus (vardas, pavardė) ir papildomai
 * saugo namų darbų pažymius, egzamino pažymį bei galutinius balus
 * pagal vidurkį ir medianą.
 *
 * Galutiniai balai saugomi:
 * - @c gal_vid_ – 0.4 * vidurkis + 0.6 * egzaminas,
 * - @c gal_med_ – 0.4 * mediana + 0.6 * egzaminas.
 */

class Studentas : public Zmogus {
    vector<int> paz_;   ///< Namų darbų pažymiai.
    int egz_;   ///< Egzamino rezultatas.
    double gal_vid_;    ///< Galutinis balas pagal vidurkį.
    double gal_med_;    ///< Galutinis balas pagal medianą.

/**
* @brief Apskaičiuoja namų darbų pažymių vidurkį.
* @return Vidurkis arba 0.0 jei nėra pažymių.
*/
    double vidurkis() const;

    /**
     * @brief Apskaičiuoja namų darbų pažymių medianą.
     * @return Mediana arba 0.0 jei nėra pažymių.
     */
    double mediana() const;

    /**
     * @brief Perskaičiuoja @c gal_vid_ ir @c gal_med_ reikšmes.
     */
    void skaiciuotiBalus();

public:
    /**
     * @brief Numatytasis konstruktorius.
     *
     * Sukuria studentą be pažymių ir egzamino balo.
     */
    Studentas(); 
    
    /**
     * @brief Konstruktorius, skaitantis studentą iš įvesties srauto.
     *
     * Tikimasi tokio formato:
     * @code
     * vardas pavarde paz1 paz2 ... pazN egz
     * @endcode
     *
     * @param is Įvesties srautas.
     */
    explicit Studentas(std::istream& is); 

    /**
     * @brief Konstruktorius rankiniam įvedimui.
     * @param vardas Studentas vardas.
     * @param pavarde Studentas pavardė.
     * @param paz Namų darbų pažymiai.
     * @param egz Egzamino balas.
     */
    Studentas(const std::string& vardas,
              const std::string& pavarde,
              const std::vector<int>& paz,
              int egz);  
     
    /**
     * @brief Kopijavimo konstruktorius.
     * @param other Objekto kopija.
     */
    Studentas(const Studentas& other); 

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param other Objektas, iš kurio kopijuojama.
     * @return Nuoroda į modifikuotą objektą.
     */
    Studentas& operator=(const Studentas& other);

    /**
     * @brief Destruktorius. Išvalo vidinę studento informaciją.
     */
    ~Studentas(){   
        vardas_.clear();
        pavarde_.clear();
        paz_.clear();
        egz_ = 0;
        gal_vid_ = 0.0;
        gal_med_ = 0.0;
    }                
   
    /**
     * @brief Grąžina studento vardą.
     * @return Vardas.
     */
    string vardas() const override { return vardas_; }

    /**
     * @brief Grąžina studento pavardę.
     * @return Pavardė.
     */
    string pavarde() const override { return pavarde_; }

    /**
     * @brief Galutinis balas pagal vidurkį.
     * @return 0.4 * vidurkis + 0.6 * egz.
     */
    inline double galVid() const { return gal_vid_; }

    /**
     * @brief Galutinis balas pagal medianą.
     * @return 0.4 * mediana + 0.6 * egz.
     */
    inline double galMed() const { return gal_med_; }

    /**
     * @brief Nuskaito studento duomenis iš srauto.
     *
     * Išvalo senus duomenis ir nuskaito naujus.
     *
     * @param is Įvesties srautas.
     * @return Tas pats srautas.
     */
    std::istream& readStudent(std::istream& is);


    /**
     * @brief Nuskaitymo operatorius.
     * @param is Įvesties srautas.
     * @param s Studentas objektas.
     * @return Įvesties srautas.
     */
    friend std::istream& operator>>(std::istream& is, Studentas& s);

    /**
     * @brief Spausdinimo operatorius.
     * @param os Išvesties srautas.
     * @param s Studentas objektas.
     * @return Išvesties srautas.
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

};

#endif
