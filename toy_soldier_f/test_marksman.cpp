/**
 * @file test_marksman.cpp
 * @brief Sprawdzenie wlasciwosci specjalnej klasy strzelca wyborowego.
 */
#include <QtTest/QtTest>
#include "marksman.h"

class MarksmanTests : public QObject {
    Q_OBJECT

private slots:
    /**
     * @brief Sprawdza inicjalizacje strzelca wyborowego.
     * Upewnia sie, czy po utworzeniu obiektu przypisywana jest mu wlasciwa ranga.
     */
    void testMarksmanCreation() {
        Marksman marksman("Sniper");
        QCOMPARE(marksman.GetRank(), std::string("Sniper"));
    }
};

void runMarksmanTests(int argc, char *argv[], int &status) {
    MarksmanTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_marksman.moc"
