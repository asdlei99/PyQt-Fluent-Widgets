<p align="center">
  <img width="18%" align="center" src="https://raw.githubusercontent.com/zhiyiYo/PyQt-Fluent-Widgets/master/docs/source/_static/logo.png" alt="logo">
</p>
  <h1 align="center">
  QFluentWidgets
</h1>
<p align="center">
  A fluent design widgets library based on Qt5
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
English | <a href="docs/README_zh.md">简体中文</a>
</p>

![Interface](https://raw.githubusercontent.com/zhiyiYo/PyQt-Fluent-Widgets/master/docs/source/_static/Interface.jpg)


## Build
1. Fetch the dll and header files by purchasing the commercial license of C++ QFluentWidgets in [official website](https://qfluentwidgets.com/price).

2. Put `libFramelessHelperCore.dll`、`libFramelessHelperWidgets.dll` and `libQFluentWidgets.dll`  in the `lib` folder

3. Put `QFluentWidgets` header files folder in the `include` folder.

4. build examples:

   ```shell
   cmake -B ./build -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_PREFIX_PATH="D:/Qt/6.5.2/mingw81_64" -G "MinGW Makefiles" .

   cd build
   make -j8
   ```


## Documentation

Want to know more about QFluentWidgets? Please read the [help document](https://qfluentwidgets.com) 👈

## Video Demonstration
Check out this [▶ example video](https://www.bilibili.com/video/BV12c411L73q) that shows off what PyQt-Fluent-Widgets are capable of 🎉

## Work with QtDesigner
You can download [Fluent Designer](https://github.com/zhiyiYo/PyQt-Fluent-Widgets/releases) from the assets of release page, and use it to generate `ui` file. Then drag the `ui` file to Fluent Studio and convert it to QFluentWidgets ui file.

## Support
If this project helps you a lot and you want to support the development and maintenance of this project, feel free to sponsor me via [爱发电](https://afdian.net/a/zhiyiYo) or [ko-fi](https://ko-fi.com/zhiyiYo). Your support is highly appreciated 🥰

## See Also
Here are some projects based on PyQt-Fluent-Widgets:
* [**zhiyiYo/QMaterialWidgets**: A material design widgets library based on PySide](https://github.com/zhiyiYo/QMaterialWidgets)
* [**zhiyiYo/Groove**: A cross-platform music player based on PyQt5](https://github.com/zhiyiYo/Groove)
* [**zhiyiYo/Alpha-Gobang-Zero**: A gobang robot based on reinforcement learning](https://github.com/zhiyiYo/Alpha-Gobang-Zero)

## Reference
* [**Windows design**: Design guidelines and toolkits for creating native app experiences](https://learn.microsoft.com/zh-cn/windows/apps/design/)
* [**Microsoft/WinUI-Gallery**: An app demonstrates the controls available in WinUI and the Fluent Design System](https://github.com/microsoft/WinUI-Gallery)

## License
PyQt-Fluent-Widgets is licensed under [GPLv3](./LICENSE).

Copyright © 2021 by zhiyiYo.
