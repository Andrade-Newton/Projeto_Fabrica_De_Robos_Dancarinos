#ifndef ROBO_H
#define ROBO_H

// biblioteca usada para a classe
#include <QString>

// classe que armazenará as informações do robô
class Robo
{
private:
    // informações do robô
    QString nome;
    QString cor;
    QString especialidade;
    QString estilo;
public:

    // construtores
    Robo();
    Robo(const QString &newNome, const QString &newCor, const QString &newEspecialidade, const QString &newEstilo);

    // métodos setters
    void setNome(const QString &newNome);
    void setCor(const QString &newCor);
    void setEspecialidade(const QString &newEspecialidade);
    void setEstilo(const QString &newEstilo);

    // métodos getters
    QString getNome() const;
    QString getCor() const;
    QString getEspecialidade() const;
    QString getEstilo() const;

    // função para apresentação no estoque
    QString apresentar() const;

    // função para apresentar estilo csv
    QString apresentar_Csv() const;

    // adicionando um método ao operador para comparação dos objetos da classe Robô
    bool operator==(const Robo &outro) const;
};

#endif // ROBO_H



