#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// bibliotecas usadas no funcionamento da janela principal
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QVector>

// bibliotecas locais para o funiconamento da janela da login e da classe funcionário
#include "fabrica.h"
#include "funcionario.h"

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
    // função que contém o funcionamento do login
    void on_button_Login_clicked();

private:
    // janela de login
    Ui::MainWindow *ui;
    // janela da fábrica
    Fabrica *ji;
    // classe que armazena as informações do usuário
    Funcionario Usuario;
    // vector que armazena strings com os nomes dos usuários cadastrados
    QVector<QString> nomes;
};
#endif // MAINWINDOW_H



