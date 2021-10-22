#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>
#include <Windows.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButton()
{

  QString  textvalue = ui->lineEdit->displayText();



    double b = textvalue.toDouble();


    QMessageBox msgBox;
    msgBox.setText("Set click intervel to: " +  textvalue);
    msgBox.exec();
}
