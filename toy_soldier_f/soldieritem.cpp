/**
 * @file soldieritem.cpp
 * @brief Implementacja narzedzi rysowania ksztaltu zolnierza w widoku top-down.
 */
#include "soldieritem.h"

SoldierItem::SoldierItem(ISoldier* soldier)
    : m_soldier(soldier)
{
    syncPosition();
}

QRectF SoldierItem::boundingRect() const {
    return QRectF(-30, -30, 60, 60);
}

void SoldierItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QColor armyColor = Qt::green;

    if (m_soldier) {
        std::string rank = m_soldier->GetRank();
        if (rank == "Lieutenant") {
            armyColor = QColor(100, 149, 237);
        }
    }

    painter->setBrush(armyColor);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawEllipse(-15, -15, 30, 30);

    if (m_soldier) {
        painter->setPen(Qt::black);
        QFont font = painter->font();
        font.setBold(true);
        font.setPixelSize(14);
        painter->setFont(font);

        std::string rank = m_soldier->GetRank();
        if (!rank.empty()) {
            QString letter = QString::fromStdString(rank).left(1).toUpper();
            painter->drawText(QRectF(-15, -15, 30, 30), Qt::AlignCenter, letter);
        }

        Direction dir = m_soldier->GetDirection();

        painter->setPen(QPen(Qt::black, 1));
        painter->setBrush(Qt::black);

        QPolygonF arrowHead;

        int tip = 28;
        int base = 17;
        int width = 9;

        switch (dir) {
        case Direction::UP:
            arrowHead << QPointF(0, -tip) << QPointF(-width, -base) << QPointF(width, -base);
            break;
        case Direction::DOWN:
            arrowHead << QPointF(0, tip) << QPointF(-width, base) << QPointF(width, base);
            break;
        case Direction::LEFT:
            arrowHead << QPointF(-tip, 0) << QPointF(-base, -width) << QPointF(-base, width);
            break;
        case Direction::RIGHT:
            arrowHead << QPointF(tip, 0) << QPointF(base, -width) << QPointF(base, width);
            break;
        }

        painter->drawPolygon(arrowHead);
    }
}

void SoldierItem::syncPosition() {
    if (m_soldier) {
        setPos(m_soldier->GetX(), m_soldier->GetY());
    }
}
