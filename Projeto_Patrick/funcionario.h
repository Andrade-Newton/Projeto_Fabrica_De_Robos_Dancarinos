#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// bibliotecas usadas para a classe
#include <QString>
#include <QVector>

// classe que armazenará os dados do usuário
class Funcionario
{
private:
    // dados do usuário
    QString nome;
    QString email;
    QString senha;
public:
    // vector que armazena todas as atividades que o funcionário tem para realizar
    QVector<QString> atividades;

    // construtores
    Funcionario();
    Funcionario(const QString &nome, const QString &email, const QString &senha);

    // métodos setters
    void setNome(const QString &newNome);
    void setEmail(const QString &newEmail);
    void setSenha(const QString &newSenha);

    // métodos getters
    QString getNome() const;
    QString getEmail() const;
    QString getSenha() const;

};

#endif // FUNCIONARIO_H






