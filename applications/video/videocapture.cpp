#include "videocapture.h"
#include "QDate"

#include "common.h"

VideoCapture::VideoCapture(QObject *parent) :
    QObject(parent)
{

}

VideoCapture::~VideoCapture()
{

}

int VideoCapture::setup(int cam_index, QString fname)
{
    int rc = 0;
    /* Setup QT Threads. */
    cap.open(cam_index);
    if(!cap.isOpened()) {
        qDebug()<< "setup failed";
        rc = -1;
    }else{
        cap.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
        cap.set(cv::CAP_PROP_FPS, 10);
        frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
        frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
        frame_fps = cap.get(CV_CAP_PROP_FPS);
        qDebug() << frame_height << "x" << frame_width << "@" << frame_fps << "fps";
        file_name = fname;
        rc = 0;
    }
    return rc;
}

void VideoCapture::record()
{
    if(cap.read(preview_frame)){
        video.open(file_name.toStdString(),CV_FOURCC('M','J','P','G'),5, cv::Size(frame_width,frame_height));
        qDebug() << "CAPTURING: " << file_name;
        do{
            cap >> preview_frame;
            video.write(preview_frame);
        }while(cont_rec);

        /* Reset flag. */
        cont_rec = true;
        qDebug() << "CAPTURE STOP.";
        videoThread.quit();
    }
    cap.release();
}

void VideoCapture::start()
{
    moveToThread(&videoThread);
    connect(&videoThread, SIGNAL(started()), this, SLOT(record()));

    videoThread.start();
}
