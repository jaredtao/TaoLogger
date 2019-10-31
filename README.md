# TaoLogger

## 简介

Qt制作的简易、好看的Log系统

代码量极少

麻雀虽小五脏俱全

![预览](https://jaredtao.github.io/images/Logger/1.png)

## status
| [Ubuntu/MacOS][lin-link] | [Windows][win-link] |[License][license-link] |
| :---------------: | :-----------------: | :-----------------: |
| ![lin-badge]      | ![win-badge]        | ![license-badge]  |

[lin-badge]: https://travis-ci.org/jaredtao/TaoLogger.svg?branch=master "Travis build status"
[lin-link]: https://travis-ci.org/jaredtao/TaoLogger "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/biawnp5xfulvkwbw?svg=true "AppVeyor build status"
[win-link]: https://ci.appveyor.com/project/jiawentao/taologger "AppVeyor build status"
[license-link]: https://github.com/jaredtao/TaoLogger/blob/master/LICENSE "LICENSE"
[license-badge]: https://img.shields.io/badge/license-MIT-blue.svg "MIT"

## 使用

源代码拷过去，在main函数的QCoreApplication/QApplication构造之后，调用一下init函数就行了。

例如：
```C++
#include "TaoLogger.h"
//省略其它头文件
...
...
int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   initLog();
   ...
   return app.exec();
}
```

initLog函数的定义如下:
```
void initLog(const QString &logPath = QStringLiteral("Log"), int logMaxCount = 1024, bool async = true);
```
其中logPath为log存储路径，默认为Log文件夹。

logMaxCount最大文件数，默认为1024。

async为异步存储，默认为true。

## 开发环境

* Qt 5.9.x Windows

## 原理
详细的说明看我博客:
[Qt自制简易好看的日志系统](https://jaredtao.github.io/2019/04/30/Qt%E8%87%AA%E5%88%B6%E7%AE%80%E6%98%93%E5%A5%BD%E7%9C%8B%E7%9A%84%E6%97%A5%E5%BF%97%E7%B3%BB%E7%BB%9F/)



### 联系方式:

***

| 作者 | 涛哥                           |
| ---- | -------------------------------- |
|开发理念 | 传承工匠精神 |
| QQ   | 759378563                  |
| 微信 | xsd2410421                       |
| 邮箱 | jared2020@163.com                |
| blog | https://jaredtao.github.io |

***

QQ(TIM)、微信二维码

<img src="https://gitee.com/jaredtao/jaredtao/raw/master/img/qq_connect.jpg?raw=true" width="30%" height="30%" /><img src="https://gitee.com/jaredtao/jaredtao/raw/master/img/weixin_connect.jpg?raw=true" width="30%" height="30%" />


###### 请放心联系我，乐于提供咨询服务，也可洽谈有偿技术支持相关事宜。

***
#### **打赏**
<img src="https://gitee.com/jaredtao/jaredtao/raw/master/img/weixin.jpg?raw=true" width="30%" height="30%" /><img src="https://gitee.com/jaredtao/jaredtao/raw/master/img/zhifubao.jpg?raw=true" width="30%" height="30%" />

###### 觉得分享的内容还不错, 就请作者喝杯奶茶吧~~
***
