#ifndef SOLDIERITEM_H
#define SOLDIERITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "isoldier.h"
class SoldierItem : public QGraphicsItem
{
public:
    SoldierItem(ISoldier* soldier);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


    void syncPosition();

private:
    ISoldier* m_soldier;
};

#endif // SOLDIERITEM_H