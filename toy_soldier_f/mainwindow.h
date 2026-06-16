#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "simulationengine.h"

/**
 * @file mainwindow.h
 * @brief Plik z deklaracja glownego okna uzytkownika dla widoku Qt.
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Okno aplikacji laczace silnik logiczny z widokiem QGraphicsScene.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor widoku.
     * @param parent Rodzic widzetu.
     */
    MainWindow(QWidget *parent = nullptr);

    /** @brief Niszczy interfejs zwalniajac zasoby. */
    ~MainWindow();

private slots:
    /** @brief Akcja wywolywana po kliknieciu przycisku Start. */
    void on_btnStart_clicked();
    /** @brief Akcja wywolywana po kliknieciu przycisku Pause. */
    void on_btnPause_clicked();
    /** @brief Akcja wywolywana po kliknieciu przycisku Stop. */
    void on_btnStop_clicked();
    /** @brief Akcja wywolywana po kliknieciu pojedynczego kroku logiki. */
    void on_btnStep_clicked();
    /** @brief Akcja wywolywana po zresetowaniu sceny. */
    void on_btnReset_clicked();

    /** @brief Przeprowadza reorganizacje wizualna po zmianie formacji. */
    void onFormationChanged();
    /** @brief Reaguje na wybranie komendy z listy UI. */
    void onCommandChanged();

private:
    Ui::MainWindow *ui; ///< Wskaznik na wygenerowana klase interfejsu.
    simulationengine m_engine; ///< Kontekst silnika symulacyjnego w oknie.

    QGraphicsScene *scene; ///< Kontekst malowania dla przestrzeni operacyjnej.
    QTimer *simulationTimer; ///< Timer pedzacy klatki logiki.

    /** @brief Odswieza wylacznie elementy wizualne sceny i metryki. */
    void updateInterface();
    /** @brief Oblicza wektory pozycyjne w wybranej strukturze taktycznej. */
    void applyFormation();
};

#endif // MAINWINDOW_H
