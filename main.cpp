#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <serialportlistmodel.h>
#include <serialportworker.h>
#include <QtQml>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;


    SerialPortWorker *portWorker = new SerialPortWorker();
    SerialPortListModel listPortModel(portWorker);


    qmlRegisterType<SerialPortListModel>("SerialNameList", 1, 0, "SerialNameList_qml");


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
