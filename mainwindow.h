#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "model.h"

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
    void on_pB_Action_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    DBPlants* bd_;

    QMessageBox* msg_;
};
#endif // MAINWINDOW_H
