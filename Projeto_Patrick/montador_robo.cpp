#include "montador_robo.h"
#include "ui_montador_robo.h"

// contrtor da janela montadora
Montador_Robo::Montador_Robo(QString local,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Montador_Robo)
{
    // inicializa a janela
    ui->setupUi(this);

    // armazenando o local que contém o arquivo com as informações do estoque
    this->local_estoque = local;

    // declarando o arquivo
    QFile arquivo(local_estoque);

    if(arquivo.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream in(&arquivo);

        QString line = in.readLine();

        while(!in.atEnd())
        {
            // inteiro que servirá como referência para armazenamento das informações do Robô
            int i = 0;

            Robo Robo_Aux;

            QString nome_robo,cores,especialidade,arte;

            line = in.readLine();

            // classe que cria uma lista de strings que são separadas por um caracter específico
            QStringList parts = line.split(",");

            for (const QString& part : parts)
            {
                // no primeiro caso, retira o nome do Robô e armazena
                if(i == 0)
                {
                    nome_robo = part;

                    Robo_Aux.setNome(nome_robo);

                // para o segundo caso, retira a cor do Robô e armazena
                }else if(i == 1)
                {
                    cores = part;

                    Robo_Aux.setCor(cores);

                // para o terceiro caso, retira a especialidade do Robõ e armazena
                }else if(i == 2)
                {
                    especialidade = part;


                    Robo_Aux.setEspecialidade(especialidade);

                // para o quarto e último caso, retira o estilo do Robô e armazena
                } else if(i == 3)
                {
                    arte = part;

                    Robo_Aux.setEstilo(arte);
                }

                i++;
            }

            // coloca o objeto da classe Robô no vector para armazena-lo
            Estoque.push_back(Robo_Aux);
        }
    } else {
        // caixa de mensagem que indíca que não foi possível ler o arquivo
        QMessageBox::warning(this,"ERRO","Falha na leitura do arquivo");
    }

    arquivo.flush();
    arquivo.close();
}

Montador_Robo::~Montador_Robo()
{
    delete ui;
}

// função que contém o funcionamento da exibição do estoque
void Montador_Robo::on_button_mostrar_clicked()
{
    QString texto;

    ui->label_tamanho_do_estoque->setText("Tamanho da Fabrica: " + QString::number(Estoque.size()));

    // limpa toda planilha para evitar repetição de conteúdo
    ui->plain_estoque->clear();

    if(Estoque.size() > 0){

        for(Robo &it : Estoque)
        {
            // armazena na variável com o método de apresentação padrão da planilha
            texto += it.apresentar() + "\n";
        }

        ui->plain_estoque->setPlainText(texto);
    } else {

        // exibe na planilha a informação de que o estoque está vazio
        ui->plain_estoque->setPlainText("Ta tudo vazio por aqui...");
    }
}

// função que contém o funcionamento da criação de objetos da classe Robô
void Montador_Robo::on_button_criar_robo_clicked()
{
    QString nome,cor,especialidade,estilo;

    nome = ui->line_nome_do_robo->text();
    cor = ui->line_cor_estilosa->text();
    especialidade = ui->line_especialidade->text();
    estilo = ui->line_estilo_arte->text();

    // método de verificação se as informações lidas são válidas
    if(nome.size() > 0 and cor.size() > 0 and especialidade.size() > 0 and estilo.size() > 0)
    {
        Robo Aux(nome,cor,especialidade,estilo);

        Estoque.push_back(Aux);

        // caixa de mensagem que exibe quando o robô é fabricado com sucesso
        QMessageBox::information(this,"Relátorio","Robô criado para o SUCESSO!");

        ui->line_nome_do_robo->clear();
        ui->line_cor_estilosa->clear();
        ui->line_especialidade->clear();
        ui->line_estilo_arte->clear();
    }else
    {
        // se não, exibe um caixa de mensagem informando que os dados lidos são inválidos
        QMessageBox::warning(this,"Relátorio","Infomações inválidas, Bip-Bop!");
    }
}

// função que contém o funcionamento da desconstrução de um robô
void Montador_Robo::on_button_desfazer_robo_clicked()
{

    QString nome,cor,especialidade,estilo;

    Robo Aux;

    // retirando as informações armazenadas nos line_edit
    nome = ui->line_nome_do_robo_des->text();
    cor = ui->line_cor_estilosa_des->text();
    especialidade = ui->line_especialidade_des->text();
    estilo = ui->line_estilo_arte_des->text();

    if(nome.size() > 0 and cor.size() > 0 and especialidade.size() > 0 and estilo.size() > 0)
    {

        Aux.setNome(nome);
        Aux.setCor(cor);
        Aux.setEspecialidade(especialidade);
        Aux.setEstilo(estilo);

        /* declarando um inteiro que armazenará o endereço onde o objeto da classe Robô esta,
           caso encontre a função retornará seu endereço de localização, caso contrário retornará
           o valor -1 */
        int indice = Estoque.indexOf(Aux);

        if(indice != -1){

            // se sim, remove o objeto do vector
            Estoque.remove(indice);

            // caixa de mensagem que exibe quando o robô é removido com sucesso
            QMessageBox::information(this,"Relátorio","Robô desmontado com SUCESSO!");

            // limpa tudo que foi inserido nos line_edit
            ui->line_nome_do_robo_des->clear();
            ui->line_cor_estilosa_des->clear();
            ui->line_especialidade_des->clear();
            ui->line_estilo_arte_des->clear();

        } else {
            // se não, exibe uma caixa de mensagem que informa que o robô não foi encontrado
            QMessageBox::warning(this,"Relátorio","O robô não foi encontrado, ou escapou...");
        }
    }else
    {
        // se não, exibe uma caixa de mensagem que informa que os valores inseridos são inválidos
        QMessageBox::warning(this,"Relátorio","Infomações inválidas, Bip-Bop!");
    }
}

// função que contém o funcionamento da atualização do estoque de Robôs
void Montador_Robo::on_button_salvar_estoque_clicked()
{
    // declarando o arquivo
    QFile arquivo(local_estoque);

    if(arquivo.open(QFile::WriteOnly|QFile::Text))
    {
        QTextStream in(&arquivo);

        QString texto = "Nome_do_Nome,Cor_Estilosa,Especialidade,Estilo_de_Arte\n";

        for(Robo &Aux : Estoque)
        {
            // armazena na string os dados do Robô usando a função da classe
            texto += Aux.apresentar_Csv() + "\n";
        }

        // sobrescrevendo o arquivo com as informações atualizadas
        in << texto;

        arquivo.flush();
        arquivo.close();

        // caixa de mensagem que informa caso a inserção dos dados tem ocorrido de maneira correta
        QMessageBox::information(this,"Relatório","Estoque salvo com SUCESSO!");
    } else {
        // caixa de mensagem que indíca que não foi possível ler o arquivo
        QMessageBox::warning(this,"ERRO","Falha na leitura do arquivo");
    }
}

// função que contém o funcionamento da modificação de objetos da classe Robô
void Montador_Robo::on_button_modificar_clicked()
{
    QString nome_p,cor_p,especialidade_p,estilo_p;
    QString nome_f,cor_f,especialidade_f,estilo_f;

    // armazenando os dados de um robô para modifica-lo
    nome_p = ui->line_nome_do_robo_mod->text();
    cor_p = ui->line_cor_estilosa_mod->text();
    especialidade_p = ui->line_especialidade_mod->text();
    estilo_p = ui->line_estilo_arte_mod->text();

    // método que verifica se as entradas são válidas
    if(nome_p.size() > 0 and cor_p.size() > 0 and especialidade_p.size() > 0 and estilo_p.size() > 0){
        // se sim

        nome_f = ui->line_nome_do_robo_mod_2->text();
        cor_f = ui->line_cor_estilosa_mod_2->text();
        especialidade_f = ui->line_especialidade_mod_2->text();
        estilo_f = ui->line_estilo_arte_mod_2->text();

        // método de verificação das entradas de modificação
        if(nome_f.size() > 0 or cor_f.size() > 0 or especialidade_f.size() > 0 or estilo_f.size() > 0){

            Robo Aux(nome_p,cor_p,especialidade_p,estilo_p);

            int indice = Estoque.indexOf(Aux);

            if(indice != -1)
            {

                if(nome_f.size() > 0)
                {
                    // o objeto da classe Robô específico recebe alteração no nome
                    Estoque[indice].setNome(nome_f);
                }
                if(cor_f.size() > 0)
                {
                    // o objeto da classe Robô específico recebe alteração na cor
                    Estoque[indice].setCor(cor_f);
                }
                if(especialidade_f.size() > 0)
                {
                    // o objeto da classe Robô específico recebe alteração no especialidade
                    Estoque[indice].setEspecialidade(especialidade_f);
                }
                if(estilo_f.size() > 0)
                {
                    // o objeto da classe Robô específico recebe alteração no estilo
                    Estoque[indice].setEstilo(estilo_f);
                }

                // caixa de mensagem que informa caso a modificação tem ocorrido de maneira correta
                QMessageBox::information(this,"Relátorio","Robô foi modificado para o SUCESSO!");

                ui->line_nome_do_robo_mod->clear();
                ui->line_cor_estilosa_mod->clear();
                ui->line_especialidade_mod->clear();
                ui->line_estilo_arte_mod->clear();

                ui->line_nome_do_robo_mod_2->clear();
                ui->line_cor_estilosa_mod_2->clear();
                ui->line_especialidade_mod_2->clear();
                ui->line_estilo_arte_mod_2->clear();
            } else {
                // se não, exibe uma caixa de mensagem que informa que o robô não foi encontrado
                QMessageBox::warning(this,"Relátorio","O robô não foi encontrado, ou escapou...");
            }
        } else {
            // se não, exibe uma caixa de mensagem que informa que os valores inseridos são inválidos
            QMessageBox::warning(this,"Relátorio","Infomações inválidas, Bip-Bop!");
        }
    } else {
        // se não, exibe uma caixa de mensagem que informa que os valores inseridos são inválidos
        QMessageBox::warning(this,"Relátorio","Infomações inválidas, Bip-Bop!");
    }
}

