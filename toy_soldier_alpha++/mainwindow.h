#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "simulationengine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();
    void on_btnPause_clicked();
    void on_btnStop_clicked();
    void on_btnStep_clicked();
    void on_btnReset_clicked();


    void onFormationChanged();
    void onCommandChanged();

private:
    Ui::MainWindow *ui;
    simulationengine m_engine;

    QGraphicsScene *scene;
    QTimer *simulationTimer;

    void updateInterface();
    void applyFormation();
};

#endif // MAINWINDOW_H