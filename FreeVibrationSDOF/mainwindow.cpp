#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QPen>

#define dT 0.001
#define numSteps 1001
#define PI 3.14159
#define MAX_SLIDER 200

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

  //  QPen pen1(QColor(0,0,255));
  //  pen1.setWidth(1);
    ui->inZ->setMaximum(MAX_SLIDER);
    ui->inZ->setMinimum(0);
    ui->inZ->setTickInterval(20);
    ui->outZ->setHidden(true);

    ui->inK->setMaximum(MAX_SLIDER);
    ui->inK->setMinimum(0);
    ui->inK->setTickInterval(20);
    ui->outK->setHidden(true);

    ui->inM->setMaximum(MAX_SLIDER);
    ui->inM->setMinimum(0);
    ui->inM->setTickInterval(20);
    ui->outM->setHidden(true);

    ui->inU0->setMaximum(MAX_SLIDER);
    ui->inU0->setMinimum(0);
    ui->inU0->setTickInterval(20);
    ui->outU0->setHidden(true);

    ui->inV0->setMaximum(MAX_SLIDER);
    ui->inV0->setMinimum(0);
    ui->inV0->setTickInterval(20);
    ui->outV0->setHidden(true);

    ui->responsePlot->clearGraphs();
    ui->responsePlot->addGraph(); // blue line
    ui->responsePlot->graph(0)->setPen(QPen(QColor(0, 0, 255)));

    ui->responsePlot->addGraph(); // red line
    ui->responsePlot->graph(1)->setPen(QPen(QColor(255, 0, 0)));

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
    ui->outTn->setText(QString().setNum(Tn,'f',4));
    ui->outUmax->setText(QString().setNum(C,'f',3));
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
        ui->outTd->setText(QString("NA"));
    } else {

        double wd =wn*sqrt(1-z*z);

        Td = 2*PI/wd;
        for (int i=0; i<numSteps; i++) {

            dampedResponse[i] = exp(-z*wn*time[i])*
                    (u0*cos(wd*time[i])+(v0+z*wn*u0)/wd*sin(wd*time[i]));
        }

        ui->outTd->setText(QString().setNum(Td,'f',3));
    }
}
void
MainWindow::doAnalysis()
{
    computeDampedResponse();
    computeUndampedResponse();

    // NOTE clear graphs so not drawing with z =0, graphs on top ugly
    ui->responsePlot->clearGraphs();
    ui->responsePlot->addGraph(); // blue line
    ui->responsePlot->graph(0)->setPen(QPen(QColor(0, 0, 255)));
    ui->responsePlot->graph(0)->setData(time, unDampedResponse);

     if (z != 0) {
    ui->responsePlot->addGraph(); // red line
    ui->responsePlot->graph(1)->setPen(QPen(QColor(255, 0, 0)));
    ui->responsePlot->graph(1)->setData(time, dampedResponse);
     }

    ui->responsePlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->responsePlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    ui->responsePlot->xAxis->setLabel("Time (sec)");
    ui->responsePlot->yAxis->setLabel("Displacement (in)");

    ui->responsePlot->xAxis->setRange(0, numSteps*dT);
    ui->responsePlot->yAxis->setRange(-1.1*uMax, 1.1*uMax);
   // ui->responsePlot->axisRect()->setAutoMargins(QCP::msNone);
   // ui->responsePlot->axisRect()->setMargins(QMargins(0,0,0,0));
    ui->responsePlot->replot();
}


void MainWindow::on_inV0_sliderMoved(int position)
{
    v0 = v0Min + position*(v0Max-v0Min)/MAX_SLIDER;
ui->outV0->setText(QString().setNum(v0,'f',3));
    this->doAnalysis();

}

void MainWindow::on_inU0_sliderMoved(int position)
{
    u0 = u0Min + position*(u0Max-u0Min)/MAX_SLIDER;
    ui->outU0->setText(QString().setNum(u0,'f',3));
    this->doAnalysis();

}

void MainWindow::on_inM_sliderMoved(int position)
{
    m = mMin + position*(mMax-mMin)/MAX_SLIDER;
    ui->outM->setText(QString().setNum(m,'f',3));
    this->doAnalysis();

}

void MainWindow::on_inK_sliderMoved(int position)
{
    k = kMin + position*(kMax-kMin)/MAX_SLIDER;
    ui->outK->setText(QString().setNum(k,'f',3));
    this->doAnalysis();
}

void MainWindow::on_inZ_sliderMoved(int position)
{
  //  z = zMin + log(1+position*1.0/MAX_SLIDER)/log(2);
  //  qDebug() << log((zMax-zMin)/MAX_SLIDER);
    if (position == 0)
        z = 0.0;
    else if (position == MAX_SLIDER)
        z = 1.0;
    else {
        double logMax = log(1./(MAX_SLIDER*1.0));
      //  qDebug() << logMax;
        z = log((MAX_SLIDER-position)/(1.0*MAX_SLIDER))/logMax;

    }
    ui->outZ->setText(QString().setNum(z,'f',3));
    this->doAnalysis();
}

void MainWindow::on_inZ_sliderPressed()
{
    ui->outZ->setHidden(false);
}

void MainWindow::on_inZ_sliderReleased()
{
    ui->outZ->setHidden(true);
}

void MainWindow::on_inK_sliderPressed()
{
    ui->outK->setHidden(false);
}

void MainWindow::on_inK_sliderReleased()
{
    ui->outK->setHidden(true);
}

void MainWindow::on_inM_sliderPressed()
{
    ui->outM->setHidden(false);
}

void MainWindow::on_inM_sliderReleased()
{
    ui->outM->setHidden(true);
}


void MainWindow::on_inU0_sliderPressed()
{
  ui->outU0->setHidden(false);
}

void MainWindow::on_inU0_sliderReleased()
{
    ui->outU0->setHidden(true);
}


void MainWindow::on_inV0_sliderPressed()
{
  ui->outV0->setHidden(false);
}

void MainWindow::on_inV0_sliderReleased()
{
    ui->outV0->setHidden(true);
}

