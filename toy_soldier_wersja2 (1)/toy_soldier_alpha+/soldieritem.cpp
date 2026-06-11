#include "soldieritem.h"

SoldierItem::SoldierItem(ISoldier* soldier)
    : m_soldier(soldier)
{
    syncPosition();
}

QRectF SoldierItem::boundingRect() const {
    return QRectF(-15, -15, 30, 30);
}

void SoldierItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    QColor armyColor = Qt::green;

    // 2.
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
    }
}

void SoldierItem::syncPosition() {
    if (m_soldier) {

        setPos(m_soldier->GetX(), m_soldier->GetY());
    }
}