#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QTime>
#include <QString>
#include <QVBoxLayout>
#include <phonon/audiooutput.h>
#include <phonon/MediaObject>
#include <qdebug.h>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    QLabel *timeLabel;
    QLabel *countLabel;

    int m_count;
    //QAudioOutput *m_audioOut;
    //QAudioFormat *m_audioFormat;

public slots:
    void timeoutSlot();
};

#endif // MAINWINDOW_H
