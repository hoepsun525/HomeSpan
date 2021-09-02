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

* Embedded WiFi Access Point and Web Interface to allow end-users (non-developers) to:
  * Set up Homespan with their own home WiFi Credentials
  * Create their own HomeKit Pairing Setup Code
* Status LED and Control Button to allow end-users to:
  * Force-unpair the device from HomeKit
  * Perform a Factory Reset
  * Launch the WiFi Access Point
* A standalone, detailed End-User Guide

## Latest Update - HomeSpan 1.3.0 (6/20/2021)

This update brings a number of new features and enhancements:

  * The PWM library has been—
    * upgraded to allow for much easier control of up to 16 dimmable LEDs, ***and***
    * extended with a dedicated class to simultaneously operate up to 8 Servo Motors!
  * Characteristic values can be automatically saved in non-volatile storage for retention in the event of a power loss.  When power is restored your Accessories will automatically revert to their most recent state!
  * The HomeSpan CLI can now be customized — extend the CLI with your own functions and commands!
  * Enable the automatic launch of HomeSpan's WiFi Access Point upon start-up whenever WiFi Credentials are not found.
  * For advanced users: create your own custom WiFi Access Point and set your WiFi Credentials programmatically.
  
See [Releases](https://github.com/HomeSpan/HomeSpan/releases) for details on all changes included in this update.

# HomeSpan Resources

HomeSpan includes the following documentation:

* [Getting Started with HomeSpan](https://github.com/HomeSpan/HomeSpan/blob/master/docs/GettingStarted.md) - setting up the software and the hardware needed to develop HomeSpan devices
* [HomeSpan API Overview](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Overview.md) - an overview of the HomeSpan API, including a step-by-step guide to developing your first HomeSpan Sketch
* [HomeSpan Tutorials](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Tutorials.md) - a guide to HomeSpan's tutorial-sketches
* [HomeSpan Services and Characteristics](https://github.com/HomeSpan/HomeSpan/blob/master/docs/ServiceList.md) - a list of all HAP Services and Characterstics supported by HomeSpan
* [HomeSpan Accessory Categories](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Categories.md) - a list of all HAP Accessory Categories defined by HomeSpan
* [HomeSpan Command-Line Interface (CLI)](https://github.com/HomeSpan/HomeSpan/blob/master/docs/CLI.md) - configure a HomeSpan device's WiFi Credentials, modify its HomeKit Setup Code, monitor and update its status, and access detailed, real-time device diagnostics from the Arduino IDE Serial Monitor
* [HomeSpan User Guide](https://github.com/HomeSpan/HomeSpan/blob/master/docs/UserGuide.md) - turnkey instructions on how to configure an already-programmed HomeSpan device's WiFi Credentials, modify its HomeKit Setup Code, and pair the device to HomeKit.  No computer needed!
* [HomeSpan API Reference](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Reference.md) - a complete guide to the HomeSpan Library API
* [HomeSpan QR Codes](https://github.com/HomeSpan/HomeSpan/blob/master/docs/QRCodes.md) - create and use QR Codes for pairing HomeSpan devices
* [HomeSpan OTA](https://github.com/HomeSpan/HomeSpan/blob/master/docs/OTA.md) - update your sketches Over-the-Air directly from the Arduino IDE without a serial connection
* [HomeSpan Extras](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Extras.md) - integrated access to the ESP32's on-chip LED, Servo Motor, and Remote Control peripherals!
* [HomeSpan Projects](https://github.com/topics/homespan) - real-world applications of the HomeSpan Library
* [HomeSpan FAQ](https://github.com/HomeSpan/HomeSpan/blob/master/docs/FAQ.md) - answers to frequently-asked questions

Note that all documentation is version-controlled and tied to each branch.  The *master* branch generally points to the latest release.  The *dev* branch, when available, will contain code under active development.

# External Resources

In addition to HomeSpan resources, developers who are new to HomeKit programming should download Apple's [HomeKit Accessory Protocol Specification, Release R2 (HAP-R2)](https://developer.apple.com/homekit/specification/). The download is free, but Apple requires you to register your Apple ID for access to the document.

You ***do not*** need to read the entire document.  The whole point of HomeSpan is that it implements all the required HAP operations under the hood so you can focus on just programming whatever logic is needed to control your real-world appliances (lights, fans, RF remote controls, etc.) with the device.  However, you will find Chapters 8 and 9 of the HAP guide to be an invaluable reference as it lists and describes all of the Services and Characteristics implemented in HomeSpan, many of which you will routinely utilize in your own HomeSpan sketches.

---

### Feedback or Questions?

Please consider adding to the [HomeSpan Discussion Board](https://github.com/HomeSpan/HomeSpan/discussions), or email me directly at [homespan@icloud.com](mailto:homespan@icloud.com).
