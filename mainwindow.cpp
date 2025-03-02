#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete bd_;
}


void MainWindow::on_pB_Action_clicked()
{
    bool connected = bd_->ConnectToDataBase(bd_->ConnectionInfo());

    if(connected) ui->statusbar->showMessage(bd_->databaseName());

}


void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->clearMessage();
}

