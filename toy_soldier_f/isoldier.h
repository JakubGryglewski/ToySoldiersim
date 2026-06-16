#ifndef ISOLDIER_H
#define ISOLDIER_H

#include <string>

/**
 * @file isoldier.h
 * @brief Definicja interfejsu ISoldier oraz podstawowych typow wyliczeniowych.
 */

/**
 * @enum Command
 * @brief Reprezentuje komendy, jakie moga zostac wydane zolnierzom.
 */
enum class Command { ATTENTION, AT_EASE, LEFT_FACE, RIGHT_FACE, FALL_IN, MARCH, HALT };

/**
 * @enum State
 * @brief Reprezentuje aktualny stan zolnierza.
 */
enum class State { IDLE, AT_ATTENTION, MARCHING };

/**
 * @enum Direction
 * @brief Reprezentuje kierunek, w ktorym zwrocony jest zolnierz.
 */
enum class Direction { UP, RIGHT, DOWN, LEFT };

/**
 * @class ISoldier
 * @brief Interfejs bazowy dla wszystkich typow zolnierzy w symulacji.
 */
class ISoldier {
public:
    virtual ~ISoldier() = default;

    /**
     * @brief Wykonuje zadana komende.
     * @param c Komenda do wykonania.
     * @return Ciag znakow opisujacy akcje wykonana przez zolnierza.
     */
    virtual std::string ExecuteCommand(Command c) = 0;

    /**
     * @brief Pobiera aktualny stan zolnierza.
     * @return Stan zolnierza.
     */
    virtual State GetState() const = 0;

    /**
     * @brief Pobiera stopien wojskowy zolnierza.
     * @return Ciag znakow reprezentujacy stopien.
     */
    virtual std::string GetRank() const = 0;

    /**
     * @brief Pobiera wspolrzedna X zolnierza.
     * @return Wspolrzedna X.
     */
    virtual int GetX() const = 0;

    /**
     * @brief Pobiera wspolrzedna Y zolnierza.
     * @return Wspolrzedna Y.
     */
    virtual int GetY() const = 0;

    /**
     * @brief Pobiera kierunek, w ktorym zwrocony jest zolnierz.
     * @return Kierunek (Direction).
     */
    virtual Direction GetDirection() const = 0;

    /**
     * @brief Ustawia nowa pozycje zolnierza na mapie.
     * @param x Wspolrzedna X.
     * @param y Wspolrzedna Y.
     */
    virtual void SetPosition(int x, int y) = 0;

    /**
     * @brief Aktualizuje pozycje zolnierza.
     */
    virtual void UpdatePosition() = 0;
};

#endif // ISOLDIER_H
