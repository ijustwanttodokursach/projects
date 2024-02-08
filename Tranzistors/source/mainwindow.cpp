#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<boost/random.hpp>
#include<QLineSeries>
#include<QPieSeries>
#include<QValueAxis>
#include<QRegularExpression>
#include<QMessageBox>
#include"tranz.h"
#include"exc.h"
#define BREAK 8
int iterations;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chartView = new QChartView();
    chartView1 = new QChartView();
    layout = new QVBoxLayout(ui->widget_2);
    fillPieChart(UT1, UT2, UT3);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete chartView;
    delete chartView1;
}

bool isNumber(const std::string &s){
    return !s.empty() && std::find_if(s.begin(),
          s.end(), [s](unsigned char c) { return !std::isdigit(c)||*s.begin()=='0'; }) == s.end();
}
void MainWindow::on_pushButton_clicked()
{
    vector<float> chartData[3];
    QString s = ui->lineEdit->text();
    losses = 0;
    unitsChanged = 0;
    if(ui->radioButton->isChecked()){
        changeAll = true;
    }
    if(ui->radioButton_2->isChecked()){
        changeAll = false;
    }
    try {
        if(!isNumber(s.toStdString())){
            myException exc("Incorrect input");
            throw exc;
        }
        else{
            Tranz t1(0, PRICE1), t2(0, PRICE2), t3(0, PRICE3);
            iterations = s.toInt();
            vector<float> problist1{2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
            vector<float> problist2{2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
            vector<float> problist3{2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
            int time1 =1 ,time2 = 1,time3 = 1;
            for(int i = 0; i<iterations; i++){
                if((t1.breakProb = prob_Gen(problist1, time1)) >= BREAK || time1 == UT1){
                    if(changeAll == false){
                        time1 = 1;
                        problist1 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        losses+=t1.price;
                        unitsChanged++;
                    }
                    else{
                        time1 = 1;
                        time2 = 1;
                        time3 = 1;
                        problist1 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        problist2 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        problist3 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        losses+=t1.price+t2.price+t3.price;
                        unitsChanged+=3;
                        chartData[0].push_back((float)t2.breakProb/10);
                        chartData[1].push_back(0);
                        chartData[2].push_back(0);
                        continue;
                    }
                }
                else{
                    time1++;
                }
                chartData[0].push_back((float)t1.breakProb/10);
                if((t2.breakProb = prob_Gen(problist2, time2)) >= BREAK||time2 == UT2){
                    if(changeAll == false){
                        time2 = 1;
                        problist2 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        losses+=t2.price;
                        unitsChanged++;
                    }
                    else{
                        time1 = 1;
                        time2 = 1;
                        time3 = 1;
                        problist1 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        problist2 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        problist3 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        losses+=t1.price+t2.price+t3.price;
                        unitsChanged+=3;
                        chartData[1].push_back((float)t2.breakProb/10);
                        chartData[2].push_back(0);
                        continue;
                    }
                }
                else{
                    time2++;
                }
                chartData[1].push_back((float)t2.breakProb/10);
                if((t3.breakProb = prob_Gen(problist3, time3)) >= BREAK||time3 == UT3){
                    if(changeAll == false){
                        time3 = 1;
                        problist3 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        losses+=t3.price;
                        unitsChanged++;
                    }
                    else{
                        time1 = 1;
                        time2 = 1;
                        time3 = 1;
                        problist1 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        problist2 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        problist3 = {2.0f,2.0f,2.0f,2.0f,2.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
                        losses+=t1.price+t2.price+t3.price;
                        unitsChanged+=3;
                        chartData[2].push_back((float)t3.breakProb/10);
                        continue;
                    }
                }
                else{
                    time3++;
                }
                chartData[2].push_back((float)t3.breakProb/10);
            }
            for (float &t: chartData[0]){
                qDebug()<<t;
            }
            fillChart(chartData);

            ui->lineEdit_2->setText(QString::number(losses));
            ui->lineEdit_3->setText(QString::number(unitsChanged));
        }
    } catch (myException e) {
        QMessageBox::critical(this, "Warning", e.txt);
    }
}

void MainWindow::fillChart(vector<float> chartData[3]){
    delete chartView;
    chartView = new QChartView();
    QLineSeries * series[3];
    for (int i = 0; i<3; i++){
        series[i] = new QLineSeries();
    }
    for (int i = 0; i<3; i++){
        int j = 1;
        for (float &t: chartData[i]){
            series[i]->append(j,t);
            j++;
        }
    }
    series[0]->setColor("Green");
    series[0]->setName("First");
    series[1]->setColor("Blue");
    series[1]->setName("Second");
    series[2]->setColor("Red");
    series[2]->setName("Third");
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(1,iterations);
    axisX->setTickInterval(0.1);
    axisX->setTickCount(iterations);
    //axisX->setTickCount(iterations-1);
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0.0, 1);
    axisY->setTickCount(11);
    //axisY->setTickInterval(0.1);
    QChart *chart = new QChart();
    for (int i = 0; i<3; i++){
        chart->addSeries(series[i]);
    }
    chart->setTitle("Tranzistors stats");
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series[0]->attachAxis(axisX);
    series[0]->attachAxis(axisY);
    series[1]->attachAxis(axisX);
    series[1]->attachAxis(axisY);
    series[2]->attachAxis(axisX);
    series[2]->attachAxis(axisY);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->widget);
    chartView->setMinimumSize(ui->widget->geometry().width(),ui->widget->geometry().height());
    chartView->show();
}

void MainWindow::fillPieChart(int f, int s, int t){
    delete layout;
    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.3);
    *series << new QPieSlice("first", f) << new QPieSlice("second", s) << new QPieSlice("third", t);
    series->slices().at(0)->setColor(Qt::green);
    series->slices().at(1)->setColor(Qt::blue);
    series->slices().at(2)->setColor(Qt::red);
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pie Chart Example");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);
    layout = new QVBoxLayout(ui->widget_2);
    layout->addWidget(chartView1);
    ui->widget_2->setLayout(layout);
}
