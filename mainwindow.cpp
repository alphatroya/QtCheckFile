#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&findFiles, SIGNAL(result(QString)), ui->textEdit, SLOT(append(QString)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(reflashWidget()));

    timer.setInterval(500);
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    findFiles.setFileDirectory(ui->lineEdit->text());
    QFile file("found.txt");
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly)){
            QString text = file.readAll();
            findFiles.setSearchWord(text);
        }
    } else {

        findFiles.setSearchWord(ui->textEdit_2->toPlainText());
    }

    QDir directory(ui->lineEdit->text());

    if (directory.exists())
    {
        findFiles.findFiles(directory);
    } else {
        qDebug()<<"Error! Directory is not exist";
    }
}

void MainWindow::reflashWidget()
{
    QFile file("found.txt");
    if (file.exists())
    {
            ui->textEdit_2->clear();
            ui->textEdit_2->append("Фраза взята из файла found.txt");
            ui->textEdit_2->append("------------------------------");
            if (file.open(QIODevice::ReadOnly))ui->textEdit_2->append(file.readAll());
            ui->textEdit_2->setReadOnly(true);
    } else {
            QString check = ui->textEdit_2->toPlainText();
            if (check.contains("Фраза взята из файла found.txt")) ui->textEdit_2->clear();
            ui->textEdit_2->setReadOnly(false);
    }
}
