/**
 * @file test_officer.cpp
 * @brief Testy behawioralne oficera dowodzacego zaleznie od komend.
 */
#include <QtTest/QtTest>
#include "officer.h"

class OfficerTests : public QObject {
    Q_OBJECT

private slots:
    /**
     * @brief Sprawdza proces inicjalizacji oficera.
     * Weryfikuje, czy nowo utworzony oficer otrzymuje poprawna range zadeklarowana w konstruktorze.
     */
    void testOfficerCreation() {
        Officer officer("Captain");
        QCOMPARE(officer.GetRank(), std::string("Captain"));
    }
};

void runOfficerTests(int argc, char *argv[], int &status) {
    OfficerTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_officer.moc"
