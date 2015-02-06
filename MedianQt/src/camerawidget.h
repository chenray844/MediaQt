#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QCameraViewfinder>

class CameraWidget : public QCameraViewfinder
{
    Q_OBJECT
public:
    CameraWidget(QWidget *parent=0);

};


/*
 * camera = new QCamera;

viewfinder = new QCameraViewfinder();
viewfinder->show();

camera->setViewfinder(viewfinder);

imageCapture = new QCameraImageCapture(camera);

camera->setCaptureMode(QCamera::CaptureStillImage);
camera->start();
 *
 * */

#endif // CAMERAWIDGET_H

