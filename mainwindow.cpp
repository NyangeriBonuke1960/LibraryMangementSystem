#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button1()
{
    QString books[] = {"Blossoms of Savannah", "I will marry when I want", "Things fall apart"};
    int rollNumber[] = {123, 456, 478};

    QString urollNum = ui->lineEdit->text();
    QString ubook = ui->lineEdit_2->text();
    int rollnum_int = urollNum.toInt();
    bool found = false;

    for(int i = 0; i < sizeof(rollNumber); i++){
        if(rollnum_int == rollNumber[i]){
            for(int j = 0; j < sizeof(rollNumber); j++){
                if(ubook == books[j]){
                    QMessageBox::information(this, "Library Management", "Book: "+books[j]+"\n" "To student: "+urollNum);
                    found = true;
                    break;
                }
            }
        }
    }

    if(!found){
        QMessageBox::information(this, "Error box", "Book not found");
    }
}


void MainWindow::exit()
{

}

