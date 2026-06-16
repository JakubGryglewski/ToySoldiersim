#ifndef OFFICER_H
#define OFFICER_H

#include "soldier.h"

/**
 * @file officer.h
 * @brief Deklaracja klasy Officer, dowodzacego oddzialem.
 */

/**
 * @class Officer
 * @brief Klasa reprezentujaca oficera o specyficznym zachowaniu wobec komend.
 */
class Officer : public Soldier {
public:
    /**
     * @brief Konstruktor oficera.
     * @param rank Stopien wojskowy.
     */
    Officer(std::string rank);

    /**
     * @brief Wykonanie komendy przez oficera.
     * @param c Komenda.
     * @return Opis reakcji oficera.
     */
    std::string ExecuteCommand(Command c) override;
};

#endif // OFFICER_H
