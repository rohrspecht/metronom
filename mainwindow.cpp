#include "mainwindow.h"
#include "ui_mainwindow.h"

//class QString;
//class QSound;
using namespace Phonon;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*m_audioFormat = new QAudioFormat();
    m_audioFormat->setFrequency(440);
    m_audioOut = new QAudioOutput(m_audioFormat);*/
    m_timer = new QTimer(this);

    timeLabel = new QLabel(this);
    timeLabel->setText("time");
    connect(m_timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));

    m_timer->start(1000);
    m_count = 0;
    countLabel = new QLabel(this);
    QWidget *mainWidget = new QWidget();
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setAlignment(Qt::AlignLeft);

    QVBoxLayout *labelLayout = new QVBoxLayout();

    labelLayout->addWidget(timeLabel);
    labelLayout->addWidget(countLabel);

    mainLayout->addLayout(labelLayout,0,0,Qt::AlignLeft);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    //QSound click = QSound("click.wav");
    //qDebug() << QSound::isAvailable();
    //click.play();
   /* Phonon::MediaObject *music = Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource("click.wav"));
    music->play();
    music->*/

    Phonon::MediaObject *mediaObject = new Phonon::MediaObject(this);
    mediaObject->setCurrentSource(Phonon::MediaSource("click.wav"));
    Phonon::AudioOutput *audioOutput =
        new Phonon::AudioOutput(Phonon::MusicCategory, this);
    //Phonon::Path path =
    Phonon::createPath(mediaObject, audioOutput);
    mediaObject->play();
    Phonon::AbstractMediaStream stream = new Phonon::AbstractMediaStream();

    //mediaObject->
}

void MainWindow::timeoutSlot()
{
    timeLabel->setText(QString(QTime::currentTime().toString()));
    countLabel->setText(QString().setNum(m_count));
    ++m_count;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
