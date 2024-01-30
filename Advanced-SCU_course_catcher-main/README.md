# <h1 align="center">✋🏻Advanced SCU Course Catcher</h1>

## 🚙用途
本软件仅供用于学习和研究，用于学习selenium,python,web api相关功能

## ⚖使用须知&免责声明

- 本项目只适用于编程学习用途，**不得用于实际选课阶段**，请在下载后24小时内删除！
- 不得随意传播本项目至任何公开场合（包括但不限于QQ群、微信群、贴吧论坛等）
- 因用户使用或修改项目源码而产生的一切责任与本人无关，本人不负任何连带责任
- 本人代码水平低下，智力低下，这段代码也是乱写的，本人也不知道写的是什么
- 可能您所在的国家和地区禁止使用本软件，请遵守您所在地的相关规则
- 本软件基于GPL-3协议开源，请遵守该协议内容，若不同意，请勿下载、使用、传播本软件
- 若不同意以上使用条例，请停止clone本项目并不得通过任何途径使用本项目
- 本项目源码以及条例解释权归本人所有


## 🔧使用方式

运行`main.py`以启动主程序

若要更改抢课内容请运行`initialize.py`

程序会先自行尝试读取验证码并输入，如果失败超过3次，则会自动切换为手动输入验证码

## 🖥开发框架/依赖项
|项目|框架|安装来源|安装方式|
|:---:|:---:|:---:|:---|
|语言🗨|Python3.8+环境|用户安装|[Python Org](https://www.python.org/downloads/)|
|浏览器🌏|Edge(Chromium)|用户安装|[Microsoft Edge](https://www.microsoft.com/en-us/edge/download)|
|Web库👨‍💻|selenium|pip|pip install selenium|
|Web库👨‍💻|fake_useragent|pip|pip install fake_useragent|
|验证码处理库🪪|[ddddocr](https://github.com/sml2h3/ddddocr)|pip|pip install ddddocr|

如果你没有安装由`pip`安装的包，运行`main.py`时会提示，确认后会自动安装

安装默认使用[清华镜像源](https://mirrors.tuna.tsinghua.edu.cn/help/pypi/)

## ⚛️原理
本软件使用`selenium`来控制浏览器，模拟按下按钮，因为点击的都是网页上的按钮，因此不存在喝🍵风险

## 📄无关事项

[~~SCUCourseSelectHelper/README.md~~](https://github.com/A2u13/SCUCourseSelectHelper/blob/master/README.md)

> 纪念文档:[SCUCourseSelectHelper-master/README.md](https://github.com/The-Brotherhood-of-SCU/SCUCourseSelectHelper-master/blob/main/README.md)

## ✨灵感来源
[~~SCUCourseSelectHelper~~](https://github.com/A2u13/SCUCourseSelectHelper)

> 纪念网址:[SCUCourseSelectHelper-master](https://github.com/The-Brotherhood-of-SCU/SCUCourseSelectHelper-master)

可惜这个项目已经archived了，作者不再更新，也有许多问题没有解决

2023/12/21更正：该项目已删库跑路

