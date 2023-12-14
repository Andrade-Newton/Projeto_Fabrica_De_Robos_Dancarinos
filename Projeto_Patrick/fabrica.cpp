#include "fabrica.h"
#include "ui_fabrica.h"

// construtor da janela fábrica
Fabrica::Fabrica(Funcionario Usuario,QString localizacao,QString local_arquivo,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fabrica)
{
    ui->setupUi(this);

    this->User = Usuario;

    // define na planinha uma mensagem padrão antes de exibir as atividades
    ui->plain_atividade->setPlainText("Esperando atividades...\n\nBip-Bop!");

    this->local = localizacao;
    this->local_estoque = local_arquivo;

    QString nome = User.getNome();
    QString email = User.getEmail();

    // exibe nos labels o nome e o e-mail armazenado
    ui->label_nome_usuario->setText("  Nome do Funcionário : " + nome);
    ui->label_email_usuario->setText("  E-mail do Funcionário : " + email);

    // declarando o arquivo
    QFile arquivo(local + nome + ".txt");

    // método de leitura do arquivo para saída de dados
    if(arquivo.open(QFile::ReadOnly|QFile::Text)){

        QTextStream entrada(&arquivo);

        QString line = entrada.readLine();

        while(!entrada.atEnd())
        {
            line = entrada.readLine();

            User.atividades.push_back(line);
        }
    } else {
        // caixa de mensagem que indíca que não foi possível ler o arquivo
        QMessageBox::warning(this,"ERRO","Falha na leitura do arquivo");
    }

    arquivo.flush();
    arquivo.close();
}

Fabrica::~Fabrica()
{
    delete ui;
}

// função que contém o funcionamento da listagem das atividades em função do botão
void Fabrica::on_button_listar_clicked()
{
    // limpa a tela da lista para evitar repetição na apresentação
    ui->lista_Atividades->clear();

    // laço que retira do vector as atividades e mostra na lista
    for(const QString &str : User.atividades){
        ui->lista_Atividades->addItem(str);
    }
}

/* função que contém o funcionamento da vizualização
   da atividade de maneira detalhada */
void Fabrica::on_button_vizualizar_clicked()
{
    // limpa a planilha de texto para evitar repetição na apresentação
    ui->plain_atividade->clear();

    // armazenando o nome da atividade marcada em uma string
    QString atividade = ui->lista_Atividades->currentItem()->text();

    /* declarando o arquivo baseado na pasta do nome do usuário que
       contém os detalhes da atividade especificada */
    QFile arquivo(local + User.getNome() + " Atividades/" + atividade + ".txt");

    if(arquivo.open(QFile::ReadOnly|QFile::Text)){

        QTextStream in(&arquivo);

        QString texto = in.readAll();

        // exibindo na planilha
        ui->plain_atividade->setPlainText(texto);

    } else {
        // caixa de mensagem que indíca que não foi possível ler o arquivo
        QMessageBox::warning(this,"ERRO","Falha na leitura do arquivo");
    }

    arquivo.flush();
    arquivo.close();
}

// função que contém o funcionamento de conclusão de atividade
void Fabrica::on_button_concluir_clicked()
{
    // armazenando o índice da ativididade concluída pelo funcionário
    int indice = ui->lista_Atividades->currentRow();

    /* removendo a atividade concluída do vector para salvar apenas as
       atividades pendentes pelo funcionário */
    User.atividades.erase(User.atividades.begin() + indice);

    ui->lista_Atividades->clear();

    for(const QString &str : User.atividades){

        ui->lista_Atividades->addItem(str);
    }

    // caixa de mensagem que indíca que a atividade foi concluída
    QMessageBox::information(this,"Atividade","Atividade concluída com sucesso, Bip-Bop!");

    if(User.atividades.size() == 0)
    {
        ui->plain_atividade->setPlainText("Esperando atividades...\n\nBip-Bop!");
    }
}

// função que contém o funcionamento para acesso da área de montagem
void Fabrica::on_button_ir_para_fabrica_clicked()
{
    /* abre a janela de exibição da montadora que recebe como parâmetro de entrada a localização do estoque,
       sem fechar a janela da fábrica, para facilitar acesso a outros dados que funcionário deseje */
    ki = new Montador_Robo(local_estoque,this);
    ki->show();
}

// função que contém o funcionamento para atualização da lista de atividades do funcionário
void Fabrica::on_button_salvar_dados_clicked()
{
    // declarando o arquivo específico do usuário para atualizá-lo
    QFile arquivo(local + User.getNome() + ".txt");

    if(arquivo.open(QFile::WriteOnly|QFile::Text))
    {
        QTextStream in(&arquivo);

        QString texto = "Nome_da_Atividade\n";

        for(QString &str : User.atividades)
        {
            texto += str + "\n";
        }

        // sobrescrevendo o arquivo com as informações atualizadas
        in << texto;

        arquivo.flush();
        arquivo.close();

        // caixa de mensagem que informa caso a inserção dos dados tem ocorrido de maneira correta
        QMessageBox::information(this,"Relatório","Dados salvos com SUCESSO!");
    } else {
        // caixa de mensagem que indíca que não foi possível ler o arquivo
        QMessageBox::warning(this,"ERRO","Falha na leitura do arquivo");
    }
}

// função que contém o método de exibição dos tipos de Robô
void Fabrica::on_button_apresentar_instrucoes_clicked()
{
    ji = new Apresentacao(this);
    ji->show();
}

