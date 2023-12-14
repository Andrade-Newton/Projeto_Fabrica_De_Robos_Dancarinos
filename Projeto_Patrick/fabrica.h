#ifndef FABRICA_H
#define FABRICA_H

// bibliotecas usadas no funcionamento da janela da fábrica
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

/* bibliotecas locais para o funiconamento da janela da fábrica
   e do aceso a janela da montadora */
#include "funcionario.h"
#include "montador_robo.h"
#include "apresentacao.h"

namespace Ui {
class Fabrica;
}

class Fabrica : public QMainWindow
{
    Q_OBJECT

public:

    // construtor personalizado com parâmetros para manipular os dados na janela da fábrica
    explicit Fabrica(Funcionario Usuario,QString local,QString local_estoque,QWidget *parent = nullptr);
    ~Fabrica();

private slots:

    // função que contém a funcionamento da listagem das atividades
    void on_button_listar_clicked();

    // função que contém o funcionamento da apresentação da atividade específica
    void on_button_vizualizar_clicked();

    // função que contém o funcionamento da conclusão da atividade
    void on_button_concluir_clicked();

    /* função que contém o funcionamento para direcionar o usuário para área de criação
       e desconstrução de robôs e vizualização do estoque da fábrica */
    void on_button_ir_para_fabrica_clicked();

    // função que contém o método que salva os dados das atividades do usuário
    void on_button_salvar_dados_clicked();

    // função que contém o método de exibição dos tipos de Robô
    void on_button_apresentar_instrucoes_clicked();

private:

    // janela da fábrica
    Ui::Fabrica *ui;
    // janela da montadora
    Montador_Robo *ki;
    // janela da apresentação
    Apresentacao *ji;
    // strings que armazenam as localizações dos arquivos usados
    QString local, local_estoque;
    // classe funcionário
    Funcionario User;
};

#endif // FABRICA_H
