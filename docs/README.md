# 欢迎!

欢迎来到HomeSpan - 基于Arduino IDE的一个开源库文件，用于ESP32系列芯片连接Apple HomeKit。

HomeSpan包含一个基于微控制器执行([HAP-R2](https://developer.apple.com/homekit/specification/))的库文件，专门为Arduino IDE开发环境下的ESP32芯片所设计。HomeSpan可以做到将ESP32开发芯片所附带的其他周围配件通过WiFI直接与Apple的HomeKit相连接，且无需其他网桥或者配件。使用Homespan你可以做到使用ESP32强大的I/O功能来完成外围控件的控制，或者使用iPhone、iPad、Mac、Siri等的Home APP来执行自动化操作。

### HomeSpan 亮点

* 提供一个原生、直接、易用的框架。
* 利用独特的*以服务为中心*的方法来创建HomeKit设备。
* 充分利用广受欢迎的 Arduino IDE。
* 100% HAP-R2适配。
* 集成38个HomeKit服务。
* 配件、网桥双模式。
* 支持使用识别码和QR Code

### 写给Homespan开发者

* 充分利用Arduino IDE的串口监视器
  * 实时, 易理解的诊断消息。
  * 对每个底层 HomeKit 操作、数据请求和数据响应完全透明。
  * 带有各种信息、调试和配置命令的命令行界面。
* 内置数据库验证以确保您的配置满足所有 HAP 要求。
* 使用ESP32的16通道PWM，可轻松控制：
  * LED亮度
  * 伺服电机
* 支持单次、双次和长时间按压的集成按钮功能。
* 集成了ESP32片上遥控外围设备，轻松生成红外和射频信号。
* 18个详细的教程草图，包括大量注释、HomeSpan文档和提示与技巧。

### 写给Homespan终端用户

* 嵌入式WiFi接入点和Web界面，允许最终用户（非开发人员）：
  * 使用自己家庭WiFi热点来设置Homespan。
  * 设置自己想要的配对码。
* 状态显示灯和按钮允许他用户去：
  * 强制取消HomeKit配对。
  * 执行出厂设置。
  * 启动Wi-Fi接入点？？？
* 独立、详细的最终用户指南

## 最新更新 - HomeSpan 1.3.0 (2021/06/20)

此更新带来了许多新功能和增强功能：
  * PWM库的改动—
    * u升级后可更轻松地控制多达 16 个可调光 LED, ***and***
    * 增加一个专用类，最多可同时操作 8 个伺服电机！
  * 特定的变量值可以存储在非易失性存储中，以达到断电保存。当电源恢复时，配件会自动恢复原状态！
  * 只要找不到 WiFi 凭据，就可以在启动时自动启动 HomeSpan 的 WiFi 接入点。？？？
  * 对于高级用户：创建您自己的自定义 WiFi 接入点并以编程方式设置您的 WiFi 账户与密码。
  
有关此更新中包含的所有更改的详细信息，请参阅 [发布](https://github.com/HomeSpan/HomeSpan/releases)。

# HomeSpan 资源

HomeSpan 包含了以下文档：

* [初识HomeSpan](https://github.com/HomeSpan/HomeSpan/blob/master/docs/GettingStarted.md) -设置开发 HomeSpan 设备所需的软件和硬件
* [HomeSpan API 总览](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Overview.md) - HomeSpan API 概述，包括开发第一个 HomeSpan 项目的指南
* [HomeSpan 教程](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Tutorials.md) - HomeSpan 的教程草图指南
* [HomeSpan 功能与特色](https://github.com/HomeSpan/HomeSpan/blob/master/docs/ServiceList.md) - HomeSpan 支持的所有 HAP 服务和特性的列表
* [HomeSpan 配件类别](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Categories.md) - a list of all HAP Accessory Categories defined by HomeSpan
* [HomeSpan Command-Line Interface (CLI)](https://github.com/HomeSpan/HomeSpan/blob/master/docs/CLI.md) - configure a HomeSpan device's WiFi Credentials, modify its HomeKit Setup Code, monitor and update its status, and access detailed, real-time device diagnostics from the Arduino IDE Serial Monitor
* [HomeSpan User Guide](https://github.com/HomeSpan/HomeSpan/blob/master/docs/UserGuide.md) - turnkey instructions on how to configure an already-programmed HomeSpan device's WiFi Credentials, modify its HomeKit Setup Code, and pair the device to HomeKit.  No computer needed!
* [HomeSpan API Reference](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Reference.md) - a complete guide to the HomeSpan Library API
* [HomeSpan QR Codes](https://github.com/HomeSpan/HomeSpan/blob/master/docs/QRCodes.md) - create and use QR Codes for pairing HomeSpan devices
* [HomeSpan OTA](https://github.com/HomeSpan/HomeSpan/blob/master/docs/OTA.md) - update your sketches Over-the-Air directly from the Arduino IDE without a serial connection
* [HomeSpan Extras](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Extras.md) - integrated access to the ESP32's on-chip LED, Servo Motor, and Remote Control peripherals!
* [HomeSpan Projects](https://github.com/topics/homespan) - real-world applications of the HomeSpan Library
* [HomeSpan FAQ](https://github.com/HomeSpan/HomeSpan/blob/master/docs/FAQ.md) - answers to frequently-asked questions

请注意，所有文档都受版本控制并绑定到每个分支。 *master* 分支通常指向最新版本。 *dev* 分支（如果可用）将包含正在开发中的代码。

# External Resources

In addition to HomeSpan resources, developers who are new to HomeKit programming should download Apple's [HomeKit Accessory Protocol Specification, Release R2 (HAP-R2)](https://developer.apple.com/homekit/specification/). The download is free, but Apple requires you to register your Apple ID for access to the document.

You ***do not*** need to read the entire document.  The whole point of HomeSpan is that it implements all the required HAP operations under the hood so you can focus on just programming whatever logic is needed to control your real-world appliances (lights, fans, RF remote controls, etc.) with the device.  However, you will find Chapters 8 and 9 of the HAP guide to be an invaluable reference as it lists and describes all of the Services and Characteristics implemented in HomeSpan, many of which you will routinely utilize in your own HomeSpan sketches.

---

### Feedback or Questions?

Please consider adding to the [HomeSpan Discussion Board](https://github.com/HomeSpan/HomeSpan/discussions), or email me directly at [homespan@icloud.com](mailto:homespan@icloud.com).
