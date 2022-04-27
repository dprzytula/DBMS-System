#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include<QDebug>
using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    includeFileAuthor(&nowa);
    includeFileBook(&nowa);
    includeFileGenre(&nowa);
    //includeFilePublisher(&nowa);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(int index)   //Tabela
{
}


void MainWindow::printBooks(){
    query = "SELECT idBook, idAuthorFK, idGenreFK, idPublisherFK, title FROM book;";
    printQuery();
}

void MainWindow::printQuery(){
    list<QMap<QString, QString>> results;
    qs.executeQuery(query.toStdString(), &nowa, &results);
    QMap<QString, QString> map;
    ui->tabelka->setRowCount(results.size()+1);
    QStringList fields;
    QTableWidgetItem *item;

    QMap<QString, QString> qs = results.front();
    for(QMap<QString, QString>::iterator it = qs.begin(); it != qs.end(); ++it) {
        fields << it.key();
    }

    ui->tabelka->setColumnCount(fields.size());
    ui->tabelka->setHorizontalHeaderLabels(fields);

    int i = 0, j = 0;
    for (std::list<QMap<QString, QString>>::iterator it = results.begin(); it != results.end(); ++it) {
        map = *it;

        for (QMap<QString, QString>::iterator it2 = map.begin(); it2 != map.end(); ++it2) {
            item = new QTableWidgetItem;
            item->setText(it2.value());
            ui->tabelka->setItem(i,j,item);
            j++;
        }

        j = 0;
        i++;
    }
}


void MainWindow::printAuthor(){
    query = "SELECT idAuthor, firstName, lastName FROM author;";
    printQuery();
}

void MainWindow::printPublisher() {
    query = "SELECT idPublisher, name FROM publisher;";
    printQuery();
}

void MainWindow::printGenre() {
    query = "SELECT idGenre, name FROM genre;";
    printQuery();
}

void MainWindow::printCopyOfBook() {
    query = "SELECT idCopyOfBook, idBookFK, ISBN FROM copyofbook;";
    printQuery();
}

void MainWindow::printRental() {
    query = "SELECT idRental, idReaderFK, idCopyOfBookFK, idLibrarianFK, dateOfRent, dateOfReturn FROM rental;";
    printQuery();
}

void MainWindow::printReader() {
    query = "SELECT idReader, firstName, lastName, dateOfBirth, numberOfPhone FROM reader;";
    printQuery();
}

void MainWindow::printLibrarian() {
    query = "SELECT idLibrarian, firstName, lastName, dateOfBirth, numberOfPhone, salary FROM librarian;";
    printQuery();
}

void MainWindow::checkTable(int index){
    switch(index)
    {
    case 0: printAuthor(); break;
    case 1: printPublisher(); break;
    case 2: printGenre(); break;
    case 3: printBooks(); break;
    case 4: printCopyOfBook(); break;
    case 5: printRental(); break;
    case 6: printReader(); break;
    case 7: printLibrarian(); break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Test", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        QApplication::quit();
      } else {
        qDebug() << "Yes was *not* clicked";
      }
}




void MainWindow::on_textEdit_textChanged()
{

}


void MainWindow::on_pushButton_4_clicked()
{
    query = ui->konsola->toPlainText();
    printQuery();


}


/*{
QString query = ui->konsola->toPlainText();
QTableWidgetItem *item;

list<QMap<QString, QString>> results;
qs.executeQuery(query.toStdString(), &nowa, &results);
QMap<QString, QString> map;

int i = 0, j = 0;
for (std::list<QMap<QString, QString>>::iterator it = results.begin(); it != results.end(); ++it) {
    map = *it;

    for (QMap<QString, QString>::iterator it2 = map.begin(); it2 != map.end(); ++it2) {
        //key to nazwa kolumny
        item = new QTableWidgetItem;
        item->setText(it2.value());
        ui->tabelka->setItem(i,j,item);
        j++;
    }

    j = 0;
    i++;
}
}*/




void MainWindow::on_tabelaNazwa_activated(int index)
{
    checkTable(ui->tabelaNazwa->currentIndex());
}


void MainWindow::on_pushButton_5_clicked()
{
    int index = ui->tabelaNazwa->currentIndex();
    int tableLength = ui->tabelka->rowCount();


    if(index==3)
    {
        QString idBook = ui->tabelka->item(tableLength-1, 2)->text();
        QString idAuthor = ui->tabelka->item(tableLength-1, 1)->text();
        QString idGenre = ui->tabelka->item(tableLength-1, 3)->text();
        QString idPublisher = ui->tabelka->item(tableLength-1, 4)->text();
        QString title = ui->tabelka->item(tableLength-1, 0)->text();
        nowa.pushBook(addBook2(idBook.toInt(),idAuthor.toInt(),idGenre.toInt(),idPublisher.toInt(),title.toStdString()));
        checkTable(index);
    }
     QMessageBox::information(this,"Informacje o danych","Dodano rekord");
}

