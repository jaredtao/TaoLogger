#include "Logger.h"
#include "LoggerTemplate.h"
#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QMutex>

#include <string>

#ifdef Q_OS_WIN
#include <Windows.h>
#else
#include <cstdio>
#endif

namespace Logger
{
static QString gLogDir;
static int gLogMaxCount;

static void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

void initLog(const QString &logPath, int logMaxCount)
{
    qInstallMessageHandler(outputMessage);
    gLogDir = QCoreApplication::applicationDirPath() + "/" + logPath;
    gLogMaxCount = logMaxCount;
    QDir dir(gLogDir);
    if (!dir.exists())
    {
        dir.mkpath(dir.absolutePath());
    }
    QStringList infoList = dir.entryList(QDir::Files, QDir::Name);
    while (infoList.size() > gLogMaxCount)
    {
        dir.remove(infoList.first());
        infoList.removeFirst();
    }
}
static void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static const QString messageTemp= QString("<div class=\"%1\">%2</div>\r\n");
    static const char typeList[] = {'d', 'w', 'c', 'f', 'i'};
    static QMutex mutex;
    Q_UNUSED(context);
    QDateTime dt = QDateTime::currentDateTime();

    //每小时一个文件
    QString fileNameDt = dt.toString("yyyy-MM-dd_hh");

    //每分钟一个文件
    //QString fileNameDt = dt.toString("yyyy-MM-dd_hh_mm");

    //每天一个文件
    //QString fileNameDt = dt.toString("yyyy-MM-dd_");
    QString contentDt = dt.toString("yyyy-MM-dd hh:mm:ss");
    QString message = QString("%1 %2").arg(contentDt).arg(msg);
    QString htmlMessage = messageTemp.arg(typeList[static_cast<int>(type)]).arg(message);
    QFile file(QString("%1/%2_log.html").arg(gLogDir).arg(fileNameDt));

    mutex.lock();
    bool exist = file.exists();
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream.setCodec("UTF-8");
    if (!exist)
    {
        text_stream << logTemplate << "\r\n";
    }
    text_stream << htmlMessage;

    file.close();
    mutex.unlock();
#ifdef Q_OS_WIN
    ::OutputDebugString(message.toStdWString().data());
    ::OutputDebugString(L"\r\n");
#else
    fprintf(stderr, message.toStdString().data());
#endif
}
} // namespace Logger
