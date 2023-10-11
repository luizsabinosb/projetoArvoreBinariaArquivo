#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <vector>
#include <ArvoreBinaria.h>
//Biblioteca para tratamento de arquivos
#include<fstream>

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


    void on_pushButton_AbrirArquivo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
