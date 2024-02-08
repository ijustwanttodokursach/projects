#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"databasehandler.h"
#include"exc.h"
#include<QMessageBox>
QVector<DbHandler::patron> patrons;
QVector<DbHandler::book> books;
QVector<DbHandler::issue> issues;
QVector<DbHandler::chartStruct> popularBooks;
QVector<DbHandler::chartStruct> popularPublishers;

void MainWindow::fillBarChart(){
    delete chart;
    delete layout;
    popularBooks = DbHandler::fillBar();
    chart = new QChart();
    QBarSeries *series = new QBarSeries();
    for(const auto &t:popularBooks){
        QBarSet *barSet = new QBarSet(t.name);
        *barSet<<t.count;
        series->append(barSet);
    }
    QCategoryAxis* axisX = new QCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    unsigned int maxVal = 0;
    for(const auto &t : popularBooks)
    {
        if (t.count>maxVal){
            maxVal = t.count;
        }
    }
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxVal);
    axisY->setTickCount(maxVal+1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout = new QVBoxLayout(ui->widget);
    layout->addWidget(chartView);
    ui->widget->setLayout(layout);
}

void MainWindow::fillDonutChart(){
    delete chart;
    delete layout;
    QPieSeries* series = new QPieSeries();
    chartView = new QChartView();
    series->setHoleSize(0.3);
    popularPublishers = DbHandler::fillDonut();
    for(const auto &t :popularPublishers){
        auto *slice = new QPieSlice(t.name, t.count);
        slice->setLabelVisible(true);
        *series << slice;
    }
    chart = new QChart();
    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout = new QVBoxLayout(ui->widget);
    layout->addWidget(chartView);
    ui->widget->setLayout(layout);
}

void MainWindow::fillVisualP(){
    patrons = DbHandler::fillP();
    ui->listP->clear();
    for(const DbHandler::patron &p:patrons){
        ui->listP->addItem(p.name+" "+p.phone);
    }
}

void MainWindow::fillVisualB(){
    books = DbHandler::fillB();
    ui->listB->clear();
    for(const DbHandler::book &b:books){
        ui->listB->addItem(b.name+"; "+b.author+"; "+b.location);
    }
}
void MainWindow::fillVisualI(){
    ui->listI->clear();
    issues = DbHandler::fillI();
    for(const DbHandler::issue &i:issues){
        ui->listI->addItem(i.surname+"; "+i.title+"; "+i.authors+"; "+i.publisher+"; "+i.borrowD.toString()+"; "+i.deadline.toString());
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DbHandler::setupDb();
    DbHandler::createDB();
    this->fillVisualP();
    this->fillVisualB();
    this->fillVisualI();
    chart = new QChart();
    layout = new QVBoxLayout(ui->widget);
    ui->tabWidget->setTabText(0, "Stats");
    ui->tabWidget->setTabText(1, "Manage");
}

MainWindow::~MainWindow()
{
    delete ui;
    DbHandler::db.close();
    delete chartView;
    delete chart;
    delete layout;
}


void MainWindow::on_pushButton_clicked()
{
    try {
        if(ui->listP->currentRow()==-1){
            myException e("Select someone");
            throw e;
        }
        QVector<DbHandler::debt> d = DbHandler::fillD(patrons[ui->listP->currentRow()].id);

        QMessageBox msgBx;
        QString msg;
        if(d.size() == 0){
            msg = "No debt";
        }
        else{
            for (DbHandler::debt &dbt:d){
                msg+=dbt.author+" "+dbt.title+"\n";
            }
        }
        msgBx.setText(msg);
        msgBx.exec();
        qDebug()<<d.size();
    } catch (myException e) {
        QMessageBox::critical(this, "Warning", e.txt);
    }
    qDebug()<<ui->listP->currentRow();
}


void MainWindow::on_pushButton_2_clicked()
{
    try{
        if(ui->listP->currentRow()==-1 || ui->listB->currentRow()==-1){
            myException e("Select Book and Person");
            throw e;
        }
        if(DbHandler::insertIssue(books[ui->listB->currentRow()].id,patrons[ui->listP->currentRow()].id)==INSERT_FAIL){
            myException e("This book is already in use");
            throw e;
        }
        fillVisualI();
        fillVisualB();
    }
    catch(myException e){
        QMessageBox::critical(this, "Warning", e.txt);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    try{
        if(ui->listI->currentRow()==-1){
            myException e("Select Issue");
            throw e;
        }
        DbHandler::deleteIssue(issues[ui->listI->currentRow()].book_id,issues[ui->listI->currentRow()].card_num);
        fillVisualI();
        fillVisualB();
    }
    catch(myException e){
        QMessageBox::critical(this, "Warning", e.txt);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    try{
        if(ui->lineEdit->text().length()==0 ||
                ui->lineEdit_2->text().length()==0 ||
                ui->lineEdit_3->text().length() == 0
                ){
            myException e("Fill everything");
            throw e;
        }
        unsigned int exec = DbHandler::insert_Patron(ui->lineEdit->text(),
                                                     ui->lineEdit_2->text(),
                                                     ui->lineEdit_3->text());
        qDebug()<<DbHandler::db.lastError();
        if(exec == PATRONS_FAIL){
            myException e("Incorrect phone number");
            throw e;
        }
        else if(exec == INSERT_FAIL){
            myException e("Duplicate phone number");
            throw e;
        }
        fillVisualP();
    }
    catch(myException e){
        QMessageBox::critical(this, "Warning", e.txt);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    fillBarChart();
}


void MainWindow::on_pushButton_6_clicked()
{
    fillDonutChart();
}

