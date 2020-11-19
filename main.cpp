#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSerialPort>
#include <QThread>
#include <serialportlistmodel.h>
#include <serialportworker.h>
#include <speedlistmodel.h>
#include <reader.h>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QThread* th = new QThread();
    portWorker::Instance()->moveToThread(th);

    qmlRegisterType<Reader>("Reader", 1, 0, "Reader_qml");
    qmlRegisterType<SerialPortListModel>("SerialNameList", 1, 0, "SerialNameList_qml");
    qmlRegisterType<SpeedListModel>("SpeedList", 1, 0, "SpeedList_qml");



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
