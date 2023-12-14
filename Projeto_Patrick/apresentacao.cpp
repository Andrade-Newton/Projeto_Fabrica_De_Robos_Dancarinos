#include "apresentacao.h"
#include "ui_apresentacao.h"

// exibe a janela de apresentação dos Robôs
Apresentacao::Apresentacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Apresentacao)
{
    ui->setupUi(this);
}

Apresentacao::~Apresentacao()
{
    delete ui;
}
