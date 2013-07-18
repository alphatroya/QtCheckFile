#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filefinder.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void reflashWidget();

private:
    Ui::MainWindow *ui;    
    FileFinder findFiles;
    QTimer timer;
};

#endif // MAINWINDOW_H
