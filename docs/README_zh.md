<p align="center">
  <img width="18%" align="center" src="https://raw.githubusercontent.com/zhiyiYo/PyQt-Fluent-Widgets/master/docs/source/_static/logo.png" alt="logo">
</p>
  <h1 align="center">
  QFluentWidgets
</h1>
<p align="center">
  基于 Qt5 的 Fluent Design 风格组件库
</p>

<p align="center">
  <a href="https://pypi.org/project/PyQt-Fluent-Widgets" target="_blank">
    <img src="https://img.shields.io/pypi/v/pyqt-fluent-widgets?color=%2334D058&label=Version" alt="Version">
  </a>

  <a style="text-decoration:none">
    <img src="https://static.pepy.tech/personalized-badge/pyqt-fluent-widgets?period=total&units=international_system&left_color=grey&right_color=brightgreen&left_text=Downloads" alt="Download"/>
  </a>

  <a style="text-decoration:none">
    <img src="https://img.shields.io/badge/License-GPLv3-blue?color=#4ec820" alt="GPLv3"/>
  </a>

  <a style="text-decoration:none">
    <img src="https://img.shields.io/badge/Platform-Win32%20|%20Linux%20|%20macOS-blue?color=#4ec820" alt="Platform Win32 | Linux | macOS"/>
  </a>
</p>

<p align="center">
<a href="../README.md">English</a> | 简体中文
</p>

![Interface](https://raw.githubusercontent.com/zhiyiYo/PyQt-Fluent-Widgets/master/docs/source/_static/Interface.jpg)


## 编译
1. 从[官网](https://qfluentwidgets.com/zh/price)购买商业许可证后获取所需的 dll 和头文件
2. 将 `libFramelessHelperCore.dll`、`libFramelessHelperWidgets.dll` 和 `libQFluentWidgets.dll` 放在 `lib` 文件夹中
3. 将 `QFluentWidgets` 头文件夹放在 `include` 文件夹中
4. 编译示例程序：

   ```shell
   cmake -B ./build -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_PREFIX_PATH="D:/Qt/6.5.2/mingw81_64" -G "MinGW Makefiles" .

   cd build
   make -j8
   ```

## 在线文档📕
想要了解 PyQt-Fluent-Widgets 的正确使用姿势？请仔细阅读 [帮助文档](https://qfluentwidgets.com/zh/) 👈

## 支持💖
个人开发不易，如果这个组件库帮助了您，可以考虑在 [爱发电](https://afdian.net/a/zhiyiYo) 或者 [ko-fi](https://ko-fi.com/zhiyiYo) 上请作者喝一瓶快乐水。您的支持就是作者继续开发和维护项目的动力 🥰。

## 演示视频📽️
请查收哔哩哔哩上的 [视频合集](https://www.bilibili.com/video/BV12c411L73q)，它展示了 PyQt-Fluent-Widgets 的全部组件和特性 🎉

## 搭配 QtDesigner🚀
从[发行页面](https://github.com/zhiyiYo/PyQt-Fluent-Widgets/releases)下载 Fluent Designer 软件，导出 ui 文件后将其拖拽到 Fluent Studio 软件的设计师界面中，点击转换按钮导出 C++ QFluentWidgets ui 文件。

## 另见👀
下面是一些基于 PyQt-Fluent-Widgets 的项目：
* [**zhiyiYo/QMaterialWidgets**: 基于 PySide 的 Material Design 风格组件库](https://github.com/zhiyiYo/QMaterialWidgets)
* [**zhiyiYo/Groove**: 基于 PyQt5 的跨平台音乐播放器](https://github.com/zhiyiYo/Groove)
* [**zhiyiYo/Alpha-Gobang-Zero**: 基于强化学习的五子棋机器人](https://github.com/zhiyiYo/Alpha-Gobang-Zero)

## 参考
* [**Windows design**: Design guidelines and toolkits for creating native app experiences](https://learn.microsoft.com/zh-cn/windows/apps/design/)
* [**Microsoft/WinUI-Gallery**: An app demonstrates the controls available in WinUI and the Fluent Design System](https://github.com/microsoft/WinUI-Gallery)

## 许可证
PyQt-Fluent-Widgets 使用 [GPLv3](./LICENSE) 许可证.

Copyright © 2021 by zhiyiYo.
