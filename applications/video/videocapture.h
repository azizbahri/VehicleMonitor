#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H
#include <QString>
#include <QObject>
#include <QThread>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class VideoCapture : public QObject
{
    Q_OBJECT

    QThread videoThread;

public slots:
    void record();


public:

    void start();
    explicit VideoCapture(QObject *parent = 0);
    ~VideoCapture();
    int setup(int cam_index, QString fname);

    void stop() {cont_rec = false;}
    cv::Mat get_frame(){return preview_frame;}

private:
    cv::VideoCapture cap;
    cv::VideoWriter video;
    cv::Mat preview_frame;
    int frame_width;
    int frame_height;
    int frame_fps;
    bool cont_rec = true;
    QString file_name;

};

#endif // VIDEOCAPTURE_H
