#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegExp>


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
    void setCorrectInput();
    void setIncorrectInput();

private:
    Ui::MainWindow *ui;
    QLineEdit enterNumber;
    QLineEdit validation;
};
#endif // MAINWINDOW_H
