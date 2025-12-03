/**
 * @file timer.h
 * @brief Laiko matavimo (timingo) įrankis, naudojantis high_resolution_clock.
 *
 * Šiame faile aprašoma klasė @c Timer, skirta matuoti funkcijų ar kodo
 * blokų vykdymo trukmę sekundėmis. Naudojama spartos testavime visame projekte.
 */

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

/**
 * @class Timer
 * @brief Paprastas laikmatis, skirtas matuoti vykdymo laiką.
 *
 * Ši klasė leidžia lengvai matuoti funkcijų ar kodo blokų trukmę.
 * Ji naudoja @c std::chrono::high_resolution_clock, todėl suteikia
 * didelį tikslumą.
 *
 * Naudojimas:
 * @code
 * Timer t;
 * // vykdomas kodas...
 * double sec = t.elapsed();
 * @endcode
 */
class Timer
{
    using clock = std::chrono::high_resolution_clock; ///< Naudojamas didelės raiškos laikrodis.
    std::chrono::time_point<clock> start_time;        ///< Fiksuotas laikrodis paleidimo momentu.

public:
    /**
     * @brief Konstruktorius.
     *
     * Inicializuoja laikmatį ir iškart nustato pradžios laiką.
     */
    Timer() { reset(); }

    /**
     * @brief Nustato laikmatį į dabartinį laiką.
     *
     * Naudojama norint pradėti matuoti iš naujo.
     */
    void reset() { start_time = clock::now(); }

    /**
     * @brief Grąžina praėjusį laiką nuo paskutinio @c reset() ar konstruktoriaus iškvietimo.
     *
     * @return Laikas sekundėmis (double).
     */
    double elapsed() const
    {
        return std::chrono::duration<double>(clock::now() - start_time).count();
    }
};

#endif
