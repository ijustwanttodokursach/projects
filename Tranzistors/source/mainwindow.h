#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QChartView>
#include<QVBoxLayout>
#include<vector>
using std::vector;
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

private:
    Ui::MainWindow *ui;
    QChartView * chartView;
    QChartView* chartView1;
    QVBoxLayout *layout;
    void fillChart(vector<float> chartData[3]);
    int losses = 0;
    bool changeAll = false;
    int unitsChanged = 0;
    void changeUnit();
    void fillPieChart(int f, int s, int t);
};
#endif // MAINWINDOW_H
