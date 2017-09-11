#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "applications/video/videocapture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void preview_video();

private slots:

    
    void on_pushButton_goto_video_clicked();
    void on_pushButton_goto_home_clicked();
    void on_pushButton_start_record_toggled(bool checked);
    void on_pushButton_goto_video_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    VideoCapture *vcap;
    QImage img;
    QTimer preview_timer;
    QThread previewThread;
};

#endif // MAINWINDOW_H
