#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&findFiles, SIGNAL(result(QString)), ui->textEdit, SLOT(append(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    findFiles.setFileDirectory(ui->lineEdit->text());
    findFiles.setSearchWord(ui->lineEdit_2->text());
    QDir directory(ui->lineEdit->text());

    if (directory.exists())
    {
        findFiles.findFiles(directory);
    } else {
        qDebug()<<"Error! Directory is not exist";
    }

}
