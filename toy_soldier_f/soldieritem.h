#ifndef SOLDIERITEM_H
#define SOLDIERITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "isoldier.h"

/**
 * @file soldieritem.h
 * @brief Klasa odpowiedzialna za wizualne przedstawienie zolnierza.
 */

/**
 * @class SoldierItem
 * @brief Typ rozszerzajacy element Qt renderowany na scenie.
 */
class SoldierItem : public QGraphicsItem
{
public:
    /**
     * @brief Konstruktor obiektu z warstwy GUI.
     * @param soldier Dowiazany zolnierz logiki z silnika.
     */
    SoldierItem(ISoldier* soldier);

    /**
     * @brief Zwraca przestrzen uzywana przez wyrysowany element.
     * @return Wymiary renderowania QRectF.
     */
    QRectF boundingRect() const override;

    /**
     * @brief Rysuje ksztalty i informacje obiektu graficznego.
     * @param painter Pedzel rysujacy.
     * @param option Opcje dodatkowe stylu.
     * @param widget Kontener widzetu.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    /**
     * @brief Pobiera aktualne wspolrzedne X Y i ustawia w elemencie Qt.
     */
    void syncPosition();

private:
    ISoldier* m_soldier; ///< Referencja wylacznie wskazujaca zrodlo pozycji.
};

#endif // SOLDIERITEM_H
