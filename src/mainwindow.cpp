#include <QFileDialog>
#include <QLabel>
#include <QBuffer>
#include <QBitArray>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


