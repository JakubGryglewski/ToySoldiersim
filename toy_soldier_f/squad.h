#ifndef SQUAD_H
#define SQUAD_H

#include <vector>
#include <memory>
#include <string>
#include "isoldier.h"

/**
 * @file squad.h
 * @brief Deklaracja klasy Squad grupujacej zolnierzy.
 */

/**
 * @class Squad
 * @brief Zarzadza grupa zolnierzy i przesyla rozkazy.
 */
class Squad
{
public:
    /**
     * @brief Konstruktor oddzialu.
     * @param name Nazwa tworzonego oddzialu.
     */
    Squad(std::string name);

    /**
     * @brief Dodaje zolnierza do grupy.
     * @param soldier Wskaznik na interfejs ISoldier.
     */
    void AddSoldier(std::unique_ptr<ISoldier> soldier);

    /**
     * @brief Rozsyla komende do wszystkich zolnierzy w oddziale.
     * @param c Komenda do wykonania.
     * @return Wektor odpowiedzi od kazdego zolnierza.
     */
    std::vector<std::string> BroadcastCommand(Command c);

    /**
     * @brief Rozsyla komende tylko do zolnierzy o podanym stopniu.
     * @param c Komenda do wykonania.
     * @param targetRank Celowy stopien wojskowy.
     * @return Wektor odpowiedzi zolnierzy.
     */
    std::vector<std::string> IssueCommandToRank(Command c, const std::string& targetRank);

    /**
     * @brief Tworzy raport logistyczny skladu osobowego.
     * @return Sformatowany tekst raportu.
     */
    std::string GenerateLogisticsReport() const;

    /**
     * @brief Umozliwia dostep do aktualnej listy zolnierzy.
     * @return Referencja do wektora wskaznikow na zolnierzy.
     */
    const std::vector<std::unique_ptr<ISoldier>>& GetSoldiers() const { return m_soldiers; }

private:
    std::string m_name; ///< Nazwa jednostki organizacyjnej.
    std::vector<std::unique_ptr<ISoldier>> m_soldiers; ///< Lista przypisanych zolnierzy.
};

#endif // SQUAD_H
