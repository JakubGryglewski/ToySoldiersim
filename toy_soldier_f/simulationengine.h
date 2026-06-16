#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <memory>
#include <vector>
#include <string>
#include "squad.h"
#include "isoldier.h"

/**
 * @file simulationengine.h
 * @brief Definicja klasy zarzadzajacej globalna logika symulacji.
 */

/**
 * @enum SimulationStatus
 * @brief Przedstawia mozliwe stany calej symulacji.
 */
enum class SimulationStatus { STOPPED, RUNNING, PAUSED };

/**
 * @class simulationengine
 * @brief Klasa koordynujaca oddzial i uplyw czasu w symulacji.
 */
class simulationengine
{
public:
    /** @brief Konstruktor domyslny silnika symulacji. */
    simulationengine();

    /** @brief Uruchamia proces symulacji. */
    void Start();
    /** @brief Zatrzymuje symulacje (resetuje jej cykl). */
    void Stop();
    /** @brief Wstrzymuje tymczasowo symulacje. */
    void Pause();

    /**
     * @brief Zwraca status dzialania silnika.
     * @return Status silnika.
     */
    SimulationStatus GetStatus() const;

    /**
     * @brief Tworzy oddzial z podana nazwa w obrebie silnika.
     * @param name Nazwa tworzonego oddzialu.
     */
    void CreateSquad(const std::string& name);

    /**
     * @brief Przekazuje instancje zolnierza do kontrolowanego oddzialu.
     * @param soldier Unikalny wskaznik na zolnierza.
     */
    void AddSoldierToSquad(std::unique_ptr<ISoldier> soldier);

    /**
     * @brief Wywoluje rozkaz rzutowany na caly oddzial.
     * @param c Komenda.
     * @return Tekstowy log raportu.
     */
    std::vector<std::string> ExecuteBroadcastCommand(Command c);

    /**
     * @brief Wywoluje rozkaz przeznaczony dla jednej rangi.
     * @param c Komenda.
     * @param targetRank Stopien, ktory ma odebrac rozkaz.
     * @return Tekstowy log raportu.
     */
    std::vector<std::string> ExecuteCommandForRank(Command c, const std::string& targetRank);

    /**
     * @brief Tworzy logistyczne podsumowanie stanu kontrolowanej formacji.
     * @return Sformatowany tekst statystyk.
     */
    std::string GetLogisticsReport() const;

    /**
     * @brief Daje bezposredni dostep wylacznie do odczytu (wskaznik) dla GUI.
     * @return Wskaznik na obiekt oddzialu.
     */
    Squad* GetSquad() const;

    /**
     * @brief Glowna funkcja tykajaca zegar logiki, przesuwa zolnierzy.
     */
    void UpdateSimulation();

private:
    SimulationStatus m_status; ///< Zapamietany obecny status.
    std::unique_ptr<Squad> m_squad; ///< Skonfigurowana jednostka zolnierzy.
};

#endif // SIMULATIONENGINE_H
