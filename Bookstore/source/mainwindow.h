#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>
#include <QVBoxLayout>
#include <QPieSeries>
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

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;

    void fillVisualP();

    void fillVisualB();

    void fillVisualI();

    void fillBarChart();

    void fillDonutChart();

    QChart *chart;

    QVBoxLayout *layout;

    QChartView *chartView;
};
#endif // MAINWINDOW_H
