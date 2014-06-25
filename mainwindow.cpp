#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonExit_clicked()
{
    close();
}

void MainWindow::on_pushButtonAudio_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Audio file (*.wav)"));

    ui->lineEditAudio->setText(fileName);
}

void MainWindow::on_pushButtonText_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Text file (*)"));

    ui->lineEditText->setText(fileName);
}

void MainWindow::on_pushButtonDo_clicked()
{
    music lab;
    QString aFile = ui->lineEditAudio->text();
    QString tFile = ui->lineEditText->text();

    if(ui->radioButtonWrite->isChecked())
    {
        if(aFile == "" && tFile == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Enter audio file and source text file");
            msgBox.exec();
        }
        else
        {
            lab.Write(ui->lineEditAudio->text(), ui->lineEditText->text());
        }
    }
    else if(ui->radioButtonRead->isChecked())
    {
        if(aFile == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Enter audio file!");
            msgBox.exec();
        }
        else
        {
            lab.Read(ui->lineEditAudio->text(), "outText");

            QMessageBox msgBox;
            msgBox.setText("Output file calles: outText");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Error.");
        msgBox.exec();
    }
}

void MainWindow::on_radioButtonWrite_clicked()
{
    ui->label_2->show();
    ui->lineEditText->show();
    ui->pushButtonText->show();
}

void MainWindow::on_radioButtonRead_clicked()
{
    ui->label_2->hide();
    ui->lineEditText->hide();
    ui->pushButtonText->hide();
}
