#ifndef MARKSMAN_H
#define MARKSMAN_H

#include "soldier.h"

/**
 * @file marksman.h
 * @brief Deklaracja klasy Marksman, reprezentujacej strzelca wyborowego.
 */

/**
 * @class Marksman
 * @brief Klasa reprezentujaca strzelca wyborowego, dziedziczaca po klasie Soldier.
 */
class Marksman : public Soldier{
public:
    /**
     * @brief Konstruktor klasy Marksman.
     * @param rank Stopien wojskowy.
     * @param ammo Poczatkowa ilosc amunicji (domyslnie 5).
     */
    Marksman(std::string rank, int ammo = 5);

    /**
     * @brief Wykonuje rozkaz z uwzglednieniem specyfiki strzelca.
     * @param c Rozkaz do wykonania.
     * @return Opis wykonanej akcji.
     */
    std::string ExecuteCommand(Command c) override;

private:
    int m_ammo; ///< Ilosc pozostalej amunicji.
};

#endif // MARKSMAN_H
