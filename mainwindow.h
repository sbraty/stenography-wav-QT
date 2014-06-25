#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "music.h"

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
    void on_pushButtonExit_clicked();

    void on_pushButtonAudio_clicked();

    void on_pushButtonText_clicked();

    void on_pushButtonDo_clicked();

    void on_radioButtonWrite_clicked();

    void on_radioButtonRead_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
