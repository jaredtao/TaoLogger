#include <QQuickView>
#include <QGuiApplication>
#include "Logger.h"

using namespace  Logger;

void showSomeLogger()
{
    //在文件本身的编码是utf-8的前提下，以下三种方式都可以直接输出中文。
    //u8是c++11标准支持的字符串字面量写法，可以参考https://zh.cppreference.com/w/cpp/language/string_literal
    //QStringLiteral是Qt特有的宏，用来在编译期生成字符串字面量
    //QString::fromLocal8Bit可以在运行过程中，动态处理中文字符串。

    LOG_DEBUG << u8"山有木兮木有枝，心悦君兮君不知。";
    LOG_DEBUG << QStringLiteral("黄河远上白云间，一片孤城万仞山。");
    LOG_DEBUG << QString::fromLocal8Bit("人生若只如初见，何事秋风悲画扇。");
    LOG_INFO << u8"玲珑骰子安红豆，入骨相思知不知。";
    LOG_WARN << u8"此情可待成追忆，只是当时已惘然。";

    LOG_CRIT << u8"严重的事情发生了，股票跌了!";
    LOG_CRIT << u8"严重的事情发生了，股票跌了!";
    LOG_CRIT << u8"严重的事情发生了，股票跌了!";

}
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //app创建之后，调一下initLog就行了
    initLog();

    //写了个输出log的函数，随便打印一点信息
    showSomeLogger();

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(800, 600);
    view.setSource(QUrl(QStringLiteral("qrc:/Qml/main.qml")));
    view.show();

    app.exec();
}
