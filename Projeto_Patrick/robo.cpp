#include "robo.h"

// construtores da classe robô
Robo::Robo()
{

}

Robo::Robo(const QString &newNome, const QString &newCor, const QString &newEspecialidade, const QString &newEstilo)
{
    nome = newNome;
    cor = newCor;
    especialidade = newEspecialidade;
    estilo = newEstilo;
}

// métodos setters das informações do robô
void Robo::setNome(const QString &newNome)
{
    nome = newNome;
}

void Robo::setCor(const QString &newCor)
{
    cor = newCor;
}

void Robo::setEspecialidade(const QString &newEspecialidade)
{
    especialidade = newEspecialidade;
}

void Robo::setEstilo(const QString &newEstilo)
{
    estilo = newEstilo;
}

// métodos getters das informações do robô
QString Robo::getNome() const
{
    return nome;
}

QString Robo::getCor() const
{
    return cor;
}

QString Robo::getEspecialidade() const
{
    return especialidade;
}

QString Robo::getEstilo() const
{
    return estilo;
}

// função que apresenta os dados de um robô para a panilha da janela
QString Robo::apresentar() const
{
    // string que armazena as informações
    QString mensagem;

    // armazenando as informações de maneira padronizada para exibição
    mensagem += "Nome do Robô: " + this->nome
                + "\nCor do Robô: " + this->cor
                + "\nTipo de Especialidade: " + this->especialidade
                + "\nEstilo: " + this->estilo + "\n";

    // retornando a mensagem finalizada
    return mensagem;
}

// função que apresenta os dados de um robô de maneira csv
QString Robo::apresentar_Csv() const{

    // string que armazena as informações
    QString mensagem;

    // armazenando as informações no estilo csv
    mensagem += this->nome + "," + this->cor + "," + this->especialidade + "," + this->estilo;

    // retornando a mensagem finalizada
    return mensagem;
}

// adicionando um método de comparação para os robôs
bool Robo::operator==(const Robo &outro) const {
    /* retornando 'true' caso os objetos da classe Robô sejam iguais,
       e 'false' caso sejam diferentes */
    return (nome == outro.nome && cor == outro.cor &&
            especialidade == outro.especialidade &&
            estilo == outro.estilo);
}


