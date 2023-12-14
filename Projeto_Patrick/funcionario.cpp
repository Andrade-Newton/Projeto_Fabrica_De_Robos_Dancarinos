#include "funcionario.h"

// construtores da classe funcionário
Funcionario::Funcionario()
{

}

Funcionario::Funcionario(const QString &nome, const QString &email, const QString &senha) :
    nome(nome),
    email(email),
    senha(senha)
{}

// métodos setters das informações do funcionário
void Funcionario::setNome(const QString &newNome)
{
    nome = newNome;
}

void Funcionario::setEmail(const QString &newEmail)
{
    email = newEmail;
}

void Funcionario::setSenha(const QString &newSenha)
{
    senha = newSenha;
}

// métodos getters das informações do funcionário
QString Funcionario::getNome() const
{
    return nome;
}

QString Funcionario::getEmail() const
{
    return email;
}

QString Funcionario::getSenha() const
{
    return senha;
}


