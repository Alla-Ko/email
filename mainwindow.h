
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QRegularExpressionMatch>

class Validator{
    QRegularExpression reg;
public:
    Validator (QString str){
        reg=QRegularExpression (str);
    }
    virtual bool isValid(QString somestring){
        QRegularExpressionMatch regmatch=reg.match(somestring);
        return regmatch.hasMatch();
    }
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
