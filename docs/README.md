# 欢迎!
本项目翻译自[HomeSpan](https://github.com/HomeSpan/HomeSpan)

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
* [HomeSpan 配件类别](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Categories.md) - 所有HomeSpan支持的配件
* [HomeSpan 命令行交互 (CLI)](https://github.com/HomeSpan/HomeSpan/blob/master/docs/CLI.md) - 通过串口来配置 HomeSpan 设备的 WiFi连接，修改HomeKit配对码和进行运行监控
* [HomeSpan 用户使用文件](https://github.com/HomeSpan/HomeSpan/blob/master/docs/UserGuide.md) - 有关如何配置 HomeSpan 设备的 WiFi连接、修改配对码以及HomeKit 配对教程
* [HomeSpan API 指南](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Reference.md) - HomeSpan 库 API 的完整指南
* [HomeSpan QR Codes](https://github.com/HomeSpan/HomeSpan/blob/master/docs/QRCodes.md) - 使用二维码来进行设备配对
* [HomeSpan OTA](https://github.com/HomeSpan/HomeSpan/blob/master/docs/OTA.md) - 不通过串口，使用OTA进行代码升级
* [HomeSpan 其他配件](https://github.com/HomeSpan/HomeSpan/blob/master/docs/Extras.md) - 集成访问 ESP32 的片上 LED、伺服电机和远程控制外设！
* [HomeSpan 项目](https://github.com/topics/homespan) - HomeSpan 库的实际应用
* [HomeSpan FAQ](https://github.com/HomeSpan/HomeSpan/blob/master/docs/FAQ.md) - 常见问题解答

请注意，所有文档都受版本控制并绑定到每个分支。 *master* 分支通常指向最新版本。 *dev* 分支（如果可用）将包含正在开发中的代码。

# 外部资源

除了 HomeSpan 资源外，刚接触 HomeKit 编程的开发者应该下载 Apple 的 [HomeKit Accessory Protocol Specification, Release R2 (HAP-R2)](https://developer.apple.com/homekit/specification/)。下载是免费的，但 Apple 要求您注册您的 Apple ID 才能访问该文档。

你***不需要***阅读整个文档。 HomeSpan 的全部意义在于它在底层实现了所有 HAP 的必须操作，因此您可以专注于编程逻辑来控制真实的设备（灯、风扇、RF 遥控器等）。但是，请仔细学习第八章和第九章的内容，因为它列出并描述了 HomeSpan 中实现的所有服务和特性，其中许多将在您自己的 HomeSpan 实例中使用。
---
### 反馈&问题

请加入 [HomeSpan Discussion Board](https://github.com/HomeSpan/HomeSpan/discussions), 或者直接发送邮件给作者 [homespan@icloud.com](mailto:homespan@icloud.com).
