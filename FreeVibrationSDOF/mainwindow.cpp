#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

#define dT 0.001
#define numSteps 1001
#define PI 3.14159

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    k(0),m(0),u0(0),v0(0),uMax(0),Tn(0),Td(0),
    z(0),
    unDampedResponse(numSteps), dampedResponse(numSteps), time(numSteps)
{

    k = 40;
    m = 0.04;
    z  = 0.;
    u0 = 1.;
    v0 = 0.;

    kMin = 30;
    kMax = 120;
    mMin = .01;
    mMax = 1.0;
    zMin = 0;
    zMax = 1.0;
    u0Min = 0.0;
    u0Max = 5.0;
    v0Min = 0.0;
    v0Max = 100;

    ui->setupUi(this);
    //dampedResponse = new double[numSteps];
    //undampedResponse = new double[numSteps];
    //time = new double[numSteps];
    for (int i=0; i<numSteps; i++)
        time[i] = i*dT;

    ui->responsePlot->clearGraphs();
    ui->responsePlot->addGraph(); // blue line
    ui->responsePlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->responsePlot->addGraph(); // red line
    ui->responsePlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    ui->responsePlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->responsePlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    ui->responsePlot->xAxis->setLabel("Time (sec)");
    ui->responsePlot->yAxis->setLabel("Displacement (in)");

    this->doAnalysis();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void
MainWindow::computeUndampedResponse()
{
    double wn = sqrt(k/m);
    Tn = 2*PI/wn;
    double alpha = atan(u0/(v0/wn));
    double C = sqrt(u0*u0+(v0/wn)*(v0/wn));
    for (int i=0; i<numSteps; i++) {
        unDampedResponse[i] = C*sin(wn*time[i]+alpha);
    }
    uMax = C;
}

void
MainWindow::computeDampedResponse()
{

    double wn = sqrt(k/m);

    if (z == 1.) {
        for (int i=0; i<numSteps; i++) {
            //uDamped = (app.U0*(1+wn*t)+app.V0*t).*exp(-wn*t);
            dampedResponse[i] = (u0*(1+wn*time[i])+v0*time[i])*exp(-wn*time[i]);
        }
    } else {
    qDebug() << z;
       // double wn = sqrt(k/m);
        double wd =wn*sqrt(1-z*z);
        qDebug() << wn << " " << wd;
        Td = 2*PI/wd;
        for (int i=0; i<numSteps; i++) {
            //uDamped = exp(-app.Z*wn*t).* ...
            //                   (app.U0*cos(wd*t) + ((app.V0 + app.Z*wn*app.U0)/wd)*sin(wd*t))

            dampedResponse[i] = exp(-z*wn*time[i])*
                    (u0*cos(wd*time[i])+(v0+z*wn*u0)/wd*sin(wd*time[i]));
        }
        qDebug() << dampedResponse[200] << " " << dampedResponse[700];
    }
}
void
MainWindow::doAnalysis()
{
    computeDampedResponse();
    computeUndampedResponse();

    ui->responsePlot->graph(0)->setData(time, unDampedResponse);
    ui->responsePlot->graph(1)->setData(time, dampedResponse);

    ui->responsePlot->xAxis->setRange(0, numSteps*dT);
    ui->responsePlot->yAxis->setRange(-1.1*uMax, 1.1*uMax);
   // ui->responsePlot->axisRect()->setAutoMargins(QCP::msNone);
   // ui->responsePlot->axisRect()->setMargins(QMargins(0,0,0,0));
    ui->responsePlot->replot();
}


void MainWindow::on_inV0_sliderMoved(int position)
{
    v0 = v0Min + position*(v0Max-v0Min)/200;

    this->doAnalysis();

}

void MainWindow::on_inU0_sliderMoved(int position)
{
    u0 = u0Min + position*(u0Max-u0Min)/200;

    this->doAnalysis();

}

void MainWindow::on_inM_sliderMoved(int position)
{
    m = mMin + position*(mMax-mMin)/200;

    this->doAnalysis();

}

void MainWindow::on_inK_sliderMoved(int position)
{
    k = kMin + position*(kMax-kMin)/200;

    this->doAnalysis();
}

void MainWindow::on_inZ_sliderMoved(int position)
{
    z = zMin + position*(zMax-zMin)/200;

    this->doAnalysis();
}
