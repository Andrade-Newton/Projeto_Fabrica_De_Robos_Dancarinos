#ifndef MONTADOR_ROBO_H
#define MONTADOR_ROBO_H

// bibliotecas usadas para a janela da montadora
#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>

// bibliotecas locais para o funcionamento dos objetos da classe Robô
#include "robo.h"

namespace Ui {
class Montador_Robo;
}

class Montador_Robo : public QMainWindow
{
    Q_OBJECT

public:

    // construtor personalizado com parâmetros para manipular os dados na janela da montadora
    explicit Montador_Robo(QString local_estoque,QWidget *parent = nullptr);
    ~Montador_Robo();

private slots:

    // função que contém o funcionamento da exibição do estoque
    void on_button_mostrar_clicked();

    // função que contém o funcionamento da criação de objetos da classe Robô
    void on_button_criar_robo_clicked();

    // função que contém o funcionamento da descontrução de objetos da classe Robô
    void on_button_desfazer_robo_clicked();

    // função que contém o funcionamento da atualização do arquivo que armazena o estoque
    void on_button_salvar_estoque_clicked();

    // função que contém o funcionamento da modificação de objetos da classe Robô
    void on_button_modificar_clicked();

private:

    // janela da montadora
    Ui::Montador_Robo *ui;

    // string que armazena a localização das informações do estoque
    QString local_estoque;

    // vector que armazena todos os objetos da classe Robô fabricados
    QVector<Robo> Estoque;
};

#endif // MONTADOR_ROBO_H
