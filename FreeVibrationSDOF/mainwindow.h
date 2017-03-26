#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void computeDampedResponse();
    void computeUndampedResponse();
    void doAnalysis();

private slots:
    void on_inV0_sliderMoved(int position);
    void on_inU0_sliderMoved(int position);
    void on_inM_sliderMoved(int position);
    void on_inK_sliderMoved(int position);
    void on_inZ_sliderMoved(int position);

    void on_inZ_sliderPressed();

    void on_inZ_sliderReleased();

    void on_inK_sliderPressed();

    void on_inK_sliderReleased();

    void on_inM_sliderPressed();

    void on_inM_sliderReleased();

    void on_inU0_sliderPressed();

    void on_inU0_sliderReleased();

    void on_inV0_sliderPressed();

    void on_inV0_sliderReleased();

private:
    Ui::MainWindow *ui;

    double k;
    double m;
    double u0;
    double v0;
    double uMax;
    double Tn;
    double Td;
    double z;

    //double *unDampedResponse;
    //double *dampedResponse;
    //double *time;

    QVector<double> time;
    QVector<double> unDampedResponse;
    QVector<double> dampedResponse;

    double kMin;
    double kMax;
    double mMin;
    double mMax;
    double zMin;
    double zMax;
    double u0Min;
    double u0Max;
    double v0Min;
    double v0Max;
};

#endif // MAINWINDOW_H
