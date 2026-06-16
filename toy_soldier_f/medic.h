#ifndef MEDIC_H
#define MEDIC_H

#include "soldier.h"

/**
 * @file medic.h
 * @brief Deklaracja klasy Medic, reprezentujacej medyka.
 */

/**
 * @class Medic
 * @brief Klasa dziedziczaca po Soldier, umozliwiajaca korzystanie z apteczek.
 */
class Medic : public Soldier
{
public:
    /**
     * @brief Konstruktor klasy Medic.
     * @param rank Stopien wojskowy.
     * @param medkits Ilosc apteczek dostepnych dla medyka (domyslnie 3).
     */
    Medic(std::string rank, int medkits = 3);

    /**
     * @brief Wykonuje rozkaz z unikalna logika medyka.
     * @param c Rozkaz do wykonania.
     * @return Opis podjetej akcji.
     */
    std::string ExecuteCommand(Command c) override;

private:
    int m_medkits; ///< Ilosc pozostalych apteczek.
};

#endif // MEDIC_H
