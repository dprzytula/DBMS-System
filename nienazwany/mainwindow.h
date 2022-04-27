#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "DBMS.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Database nowa;
    QuerySystem qs;
    QString query;
    void addBok();
    void printAuthor();
    void printPublisher();
    void printBooks();
    void printQuery();
    void printGenre();
    void printCopyOfBook();
    void printRental();
    void printReader();
    void printLibrarian();

    void checkTable(int index);
private slots:
    void on_comboBox_activated(int index);
    void on_pushButton_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_4_clicked();


    void on_tabelaNazwa_activated(int index);

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
