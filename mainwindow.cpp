#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "common.h"
#include <qmessagebox.h>
#include <QDate>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#define PAGE_HOME (0)
#define PAGE_VIDEO (1)
#define INDEX_CAMERA (0)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vcap = new VideoCapture;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::preview_video()
{
//    DEBUG("Preview");
    cv::Mat capture = vcap->get_frame();
    img = QImage(
                (const unsigned char*)(capture.data),
                capture.cols,
                capture.rows,
                QImage::Format_RGB888
                );

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(
                QPixmap::fromImage(img).scaled(ui->label->size(),
                                               Qt::KeepAspectRatio,
                                               Qt::FastTransformation)
                );
}

void MainWindow::on_pushButton_goto_video_clicked()
{
    ui->stackedWidget->setCurrentIndex(PAGE_VIDEO);
    connect(&preview_timer, SIGNAL(timeout()), this, SLOT(preview_video()));
    preview_timer.start(5);
}

void MainWindow::on_pushButton_goto_home_clicked()
{
     ui->stackedWidget->setCurrentIndex(PAGE_HOME);
     preview_timer.stop();
     disconnect(&preview_timer, SIGNAL(timeout()), this, SLOT(preview_video()));
}



void MainWindow::on_pushButton_start_record_toggled(bool checked)
{
    QString fname = QDate::currentDate().currentDate().toString() + ".avi";
    if(checked)
    {
        /* update button name. */
        ui->pushButton_start_record->setText("Stop Recording");
        qDebug() << "File name : " << fname;

        /* Start the recording. this needs to be done on a new thread. */
        if(vcap->setup(INDEX_CAMERA,fname) == 0)
        {
            vcap->start();
        }
    }else{
        /* update button name to start */
        ui->pushButton_start_record->setText("Start Recording");

        /* Stop recording. */
        vcap->stop();
    }
}


void MainWindow::on_pushButton_goto_video_toggled(bool checked)
{
    if(checked){
        /* Run preview thread */

    }else
    {
        /* Stop preview thread */
    }
}
