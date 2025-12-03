/**
 * @file mylib.h
 * @brief Pagalbinės funkcijos studentų duomenų nuskaitymui, paskirstymui ir spartos testavimui.
 *
 * Šiame faile deklaruojamos funkcijos, naudojamos:
 * - studentų duomenims nuskaityti iš failo į konteinerius,
 * - studentų paskirstymui pagal strategijas (vector ir list),
 * - spartos testavimui skirtingiems konteineriams ir metodams,
 * - rezultatų spausdinimui į failus,
 * - vartotojo sąveikai (rankinis įvedimas, paprastas failo apdorojimas).
 */
#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "studentas.h"
#include "timer.h"

/**
 * @brief Nuskaito studentų duomenis iš failo į @c std::vector<Studentas>.
 *
 * Tikimasi, kad failas turi antraštės eilutę ir po jos – studentų duomenis.
 *
 * @param failas Failo pavadinimas (kelias iki failo).
 * @return Vektorius su visais nuskaitytais studentais.
 */

std::vector<Studentas> NuskaitytiVector(const std::string& failas);


// -----------------------------------------------------------------------------
// PASKIRSTYMO STRATEGIJOS
// -----------------------------------------------------------------------------

/**
 * @brief Paskirsto studentus į dvi grupes (pvz. "vargšiukai" ir "kietiakai") – 1 strategija (vector).
 *
 * Naudoja @c std::vector<Studentas> (konstanti nuoroda), todėl pradinė grupė nėra modifikuojama.
 * Grupės rezultatai paprastai išvedami į atskirus failus.
 *
 * @param Grupe Pradinė studentų grupė.
 * @param irasu_sk Įrašų (studentų) skaičius.
 * @param failo_vardas Bazinis failo pavadinimas, naudojamas rezultatų išvedimui.
 */
void Paskirstymas_vector_1_strategija(const std::vector<Studentas>& Grupe, const int irasu_sk, const std::string& failo_vardas);

/**
 * @brief Paskirsto studentus – 2 strategija (vector, perdavimas pagal reikšmę).
 *
 * @c Grupe perduodamas pagal reikšmę, todėl funkcija dirba su kopija.
 * Tai gali būti naudinga testuojant spartos/atminties aspektus.
 *
 * @param Grupe Studentų grupė (kopija).
 * @param irasu_sk Įrašų (studentų) skaičius.
 * @param failo_vardas Bazinis failo pavadinimas, naudojamas rezultatų išvedimui.
 */
void Paskirstymas_vector_2_strategija(std::vector<Studentas> Grupe, const int irasu_sk, const std::string& failo_vardas);

/**
 * @brief Paskirsto studentus – 3 strategija (vector su modifikavimu vietoje).
 *
 * @c Grupe perduodamas pagal nuorodą ir gali būti modifikuojamas (studentai šalinami/pertvarkomi).
 * Dažnai naudojama efektyvesniam atminties panaudojimui.
 *
 * @param Grupe Studentų grupė (modifikuojama vietoje).
 * @param irasu_sk Įrašų (studentų) skaičius.
 * @param failo_vardas Bazinis failo pavadinimas, naudojamas rezultatų išvedimui.
 */
void Paskirstymas_vector_3_strategija(std::vector<Studentas>& Grupe, const int irasu_sk, const std::string& failo_vardas);

/**
 * @brief Paskirsto studentus – 1 strategija naudojant @c std::list<Studentas>.
 *
 * Pradinė grupė perduodama kaip konstanti nuoroda ir nėra modifikuojama.
 *
 * @param Grupe Pradinė studentų grupė @c std::list konteineryje.
 * @param irasu_sk Įrašų (studentų) skaičius.
 * @param failo_vardas Bazinis failo pavadinimas, naudojamas rezultatų išvedimui.
 */
void Paskirstymas_list_1_strategija(const std::list<Studentas>& Grupe, const int irasu_sk, const std::string& failo_vardas);

/**
 * @brief Paskirsto studentus – 2 strategija (@c std::list<Studentas> pagal reikšmę).
 *
 * @c Grupe perduodama pagal reikšmę (kopija), leidžiant modifikuoti sąrašą
 * neveikiant originalių duomenų.
 *
 * @param Grupe Studentų grupė (kopijuota @c std::list).
 * @param irasu_sk Įrašų (studentų) skaičius.
 * @param failo_vardas Bazinis failo pavadinimas, naudojamas rezultatų išvedimui.
 */
void Paskirstymas_list_2_strategija(std::list<Studentas> Grupe, const int irasu_sk, const std::string& failo_vardas);

/**
 * @brief Paskirsto studentus – 3 strategija (@c std::list<Studentas> su modifikavimu vietoje).
 *
 * @c Grupe perduodamas pagal nuorodą ir gali būti modifikuojamas (studentai perkeliami,
 * trinami ir pan.).
 *
 * @param Grupe Studentų grupė @c std::list konteineryje (modifikuojama).
 * @param irasu_sk Įrašų (studentų) skaičius.
 * @param failo_vardas Bazinis failo pavadinimas, naudojamas rezultatų išvedimui.
 */
void Paskirstymas_list_3_strategija(std::list<Studentas>& Grupe, const int irasu_sk, const std::string& failo_vardas);


// Testavimas
/**
 * @brief Atlieka spartos testavimą, nuskaitant duomenis iš failo.
 *
 * Naudojamas @c Timer matuoti, kiek laiko užtrunka nuskaitymas ir apdorojimas
 * konkrečiam įrašų skaičiui.
 *
 * @param failas Failo pavadinimas (kelias iki testuojamo failo).
 * @param irasu_sk Tikėtinas įrašų (studentų) skaičius faile.
 */
void TestavimasIsFailo(const std::string& failas, int irasu_sk);

// Spausdinimas
/**
 * @brief Išspausdina (dažniausiai į failą) studentų grupės duomenis.
 *
 * Tai šabloninė funkcija, kuri gali dirbti su įvairiais konteineriais
 * (pvz. @c std::vector<Studentas>, @c std::list<Studentas> ir pan.), jei
 * juos galima iteruoti „range-based for“ būdu.
 *
 * @tparam T Konteinerio tipas (pvz. vector, list).
 * @param Spausd_gr Spausdinama studentų grupė.
 * @param strat Naudota strategija (numeris ar kodas), gali būti naudojama
 *              pavadinimuose ar papildomai informacijai.
 * @param failo_vardas Failo pavadinimas, į kurį bus išvedama.
 */
template <typename T>
void Spausdinimas(const T &Spausd_gr, const int& strat, const std::string& failo_vardas);

// Vieno failo apdorojimas ir rankinis įvedimas
/**
 * @brief Apdoroja vieną studentų failą naudojant numatytą logiką.
 *
 * Tipiškai:
 * - nuskaito failą,
 * - paskirsto studentus į grupes,
 * - išveda rezultatus.
 */
void PaprastasFailoApdorojimas();

/**
 * @brief Leidžia vartotojui rankiniu būdu įvesti studentų duomenis iš klaviatūros.
 *
 * Dažniausiai kviečiama, kai vartotojas meniu pasirenka „rankinis įvedimas“.
 * Gali:
 * - paprašyti įvesti vardą, pavardę, pažymius, egzaminą,
 * - apskaičiuoti galutinius balus,
 * - išvesti rezultatus į ekraną ar failą.
 */
void VartotojoIvedimas();

#endif // MYLIB_H

