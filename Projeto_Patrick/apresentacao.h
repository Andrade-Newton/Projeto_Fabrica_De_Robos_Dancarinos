#ifndef APRESENTACAO_H
#define APRESENTACAO_H

#include <QMainWindow>

namespace Ui {
class Apresentacao;
}

class Apresentacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit Apresentacao(QWidget *parent = nullptr);
    ~Apresentacao();

private:
    Ui::Apresentacao *ui;
};

#endif // APRESENTACAO_H
