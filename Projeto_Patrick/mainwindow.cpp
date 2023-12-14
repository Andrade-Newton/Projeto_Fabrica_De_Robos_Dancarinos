#include "mainwindow.h"
#include "ui_mainwindow.h"

// string que armazena o caminho que contêm os arquivos de leitura dos funcionários e das atividades
QString local = "C:/Users/biela/Documents/IFPB - EE/Qtcreator/Projeto_Patrick/Arquivos_Csv/";

// string que armazena o local onde os nomes de todos os funcionários estão registrados
QString nome = "nomes_usuarios.txt";

// string que armazena o caminho que contêm o arquivo onde todos os robôs estão cadastrados
QString local_estoque = "C:/Users/biela/Documents/IFPB - EE/Qtcreator/Projeto_Patrick/Robô/Robôs_Fabricados.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// função que contém o funcionamento do login em função do botão
void MainWindow::on_button_Login_clicked()
{
    // lógica de funcionamento

    bool flag = false;

    // declarando o arquivo
    QFile arquivo(local+nome);

    if(arquivo.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream entrada(&arquivo);

        QString line = entrada.readLine();

        while(!entrada.atEnd())
        {
            line = entrada.readLine();

            nomes.push_back(line);
        }
    } else {
        // caixa de mensagem que indíca que não foi possível ler o arquivo
        QMessageBox::warning(this,"ERRO","Não foi possível abrir o arquivo");
    }

    arquivo.flush();
    arquivo.close();

    // armazenando os valores inseridos nos line_edit
    QString id_aux = ui->line_id->text();
    QString email_aux = ui->line_email->text();
    QString senha_aux = ui->line_senha->text();

    /* juntando todos valores lidos em uma string para comparar como se fosse uma linha de um arquivo csv
       para também facilitar a sua comparação com as linhas lidas do arquivo*/
    QString aux = id_aux + "," + email_aux + "," + senha_aux;

    for(const QString &it : nomes){
        if(it == aux){
            flag = true;
            break;
        }
    }

    if(flag){
        Usuario.setNome(id_aux);
        Usuario.setEmail(email_aux);
        Usuario.setSenha(senha_aux);

        // fecha a janela de login
        this->close();

        /* abre uma nova janela que recebe como parâmetro de entrada
           o funcionário e as localizações dos arquivos*/
        ji = new Fabrica(Usuario,local,local_estoque,this);
        ji->show();
    } else {
        // se não, mostra uma caixa de mensagem informando que os dados inseridos são inválidos
        QMessageBox::information(this,"Login","Acesso Negado");
    }

    // limpa tudo que foi inserido no line_edit
    ui->line_id->clear();
    ui->line_email->clear();
    ui->line_senha->clear();

    // determina o foco de inserção de dados na primeira line_edit
    ui->line_id->setFocus();
}



