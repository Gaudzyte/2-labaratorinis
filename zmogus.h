/**
 * @file zmogus.h
 * @brief Abstrakti bazinė klasė žmogui aprašyti.
 *
 * Šiame faile aprašoma abstrakti klasė @c Zmogus, kuri nustato bendrą
 * vardą ir pavardę turinčioms paveldėtoms klasėms (pvz., Studentas).
 * Failas yra projekto paveldėjimo hierarchijos pagrindas.
 */

#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė, apibrėžianti žmogaus duomenis.
 *
 * Ši klasė yra skirta būti pagrindu paveldėtoms klasėms, tokioms kaip
 * Studentas. Ji saugo bendrus laukus – vardą ir pavardę – ir reikalauja,
 * kad paveldinčios klasės pateiktų konkrečias šių reikšmių grąžinimo
 * funkcijų implementacijas.
 *
 * Klasė yra abstrakti, nes turi dvi grynąsias virtualiąsias funkcijas:
 * - @c vardas()
 * - @c pavarde()
 */
class Zmogus {

protected:
    std::string vardas_;   ///< Žmogaus vardas.
    std::string pavarde_;  ///< Žmogaus pavardė.

public:
    /**
     * @brief Numatytasis konstruktorius.
     *
     * Sukuria tuščią Zmogus objektą. Naudojamas paveldėjimui.
     */
    Zmogus() = default;

    /**
     * @brief Konstruktorius su parametrais.
     * @param vardas Žmogaus vardas.
     * @param pavarde Žmogaus pavardė.
     */
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    /**
     * @brief Virtualus destruktorius.
     *
     * Būtinas paveldėtoms klasėms, kad užtikrintų teisingą išvalymą.
     */
    virtual ~Zmogus() = default;

    /**
     * @brief Grąžina žmogaus vardą.
     *
     * Grynoji virtualioji funkcija – privalo būti perrašyta paveldinčiose klasėse.
     *
     * @return Vardas.
     */
    virtual std::string vardas() const = 0;

    /**
     * @brief Grąžina žmogaus pavardę.
     *
     * Grynoji virtualioji funkcija – privalo būti perrašyta paveldinčiose klasėse.
     *
     * @return Pavardė.
     */
    virtual std::string pavarde() const = 0;
};

#endif
