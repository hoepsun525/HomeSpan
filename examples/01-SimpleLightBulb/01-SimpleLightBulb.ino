
////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: ESP32的HomeKit支持库                       //
//    ------------------------------------------------    //
//                                                        //
// Example 1: 一个不起作用的LED控制程序，用于演示与家庭App连接   //
//                                                        //
////////////////////////////////////////////////////////////


// 欢迎使用Homespan！

// 第一个示例介绍了 HomeSpan 库并演示了如何实现简单的开/关灯控制。
// 使用 HomeSpan Accessory、Service 和 Characteristic 对象的组合。编译上传此程序到
// 你的 ESP32 设备，然后打开iPhone、Mac、iPad上的家庭App，添加配件，你就会发现多了一个LED模块。

// 尽管例程能成功的执行 (即你可以通过App来改变灯的状态)，现实是我们还未连接一个正真的LED在开发版上，所以说什么事情都不会发生。
// 在其他的例程中我们将会学习怎样去连接和控制正真的器件。 从例程5开始，我们将学习如何去控制一个LED和去学习其中的方法。

// 本例程是基于苹果的Homekit，欲知详情，请访问[HAP](https://developer.apple.com/support/homekit-accessory-protocol)

// 让我们开始吧！

#include "HomeSpan.h"         // HomeSpan永远是先引用HomeSpan.h头文件
void setup() // HomeSpan程序内容应写在setup()中
{
  Serial.begin(115200);       // 开启串口，用于接收HomeSpan的消息和进行交互
  // HomeSpan 库创建了一个名为“homeSpan”的全局对象，它封装了所有 HomeSpan 功能。
  // begin()方法用于初始化 HomeSpan 并启动所有 HomeSpan 进程。
  
  // 前两个参数是 Category 和 Name, 用于初始化连接时Home App中显示的图表图标和名称。

  homeSpan.begin(Category::Lighting,"HomeSpan LED灯");   // 初始化名为“HomeSpan Lightbulb”的 HomeSpan 设备，并将 Category 设置为 Lighting

  // 接下来，我们构建一个简单的 HAP 附件数据库，其中包含 3 个服务的单个附件，
  // 每个都有自己所需的特征。？？？
  new SpanAccessory();                          // 首先使用 SpanAccessory() 创建一个不带参数的新附件。
  new Service::AccessoryInformation();          // HAP 要求每个附件实现一个AccessoryInformation 服务，它具有 6 个必需的特征：
  new Characteristic::Name("LED灯");    // 1.配件的名称, 即显示在HomeKit的“标题”上，应该为唯一值。
      
  // 接下来的4个特征除了显示在 HomeKit 的每个配件的设置面板中外，没有任何功能。但依循HAP协议，这四个特征是必要的：
  
  new Characteristic::Manufacturer("HomeSpan");   // 2.配件生产厂家 (任意文本且不同配件可重复)
  new Characteristic::SerialNumber("123-ABC");    // 3.配件序列号 (任意文本且不同配件可重复)
  new Characteristic::Model("20mA LED");     // 4.配件型号 (任意文本且不同配件可重复)
  new Characteristic::FirmwareRevision("0.9");    // 5.配件版本(任意文本且不同配件可重复)

  // 附件信息服务所需的最后一个特征是特殊的识别特征。我们将在接下来的其他例程再次学习这个特征？？？。现在，您可以在没有任何参数的情况下实例化它。
  new Characteristic::Identify();                 //创建所需的标识
  // *注意* HAP 要求始终在任何其他服务之前实例化 AccessoryInformation 服务，这就是我们首先创建它的原因。
  // HAP 还要求每个配件（除了 Bridges 中的配件，我们将在后面看到）来实现 HAP 协议信息服务。
  // 此服务支持定义设备使用的 HAP 版本号的单个必需特性。
  // HAP R2协议要求将此版本设置为“1.1.0”  
  new Service::HAPProtocolInformation();          // 创建 HAP 协议信息服务
  new Characteristic::Version("1.1.0");           // 6.根据HAP协议，版本号："1.1.0"是必须的

  // 现在已经定义了所需的“信息”服务，我们终于可以创建我们的LED服务了。
  new Service::LightBulb();                       // 创建LightBulb服务
  new Characteristic::On();                       // 此服务需要“开”字符来打开和关闭灯？？？
  // 这就是整个HomeSpan控制单个LED前期准备的全部内容，包括所有必需的 HAP 元素。
  // 现在已经定义了所需要的“信息”服务，可以创建我们的控制LED服务了。
  // 注意！这个例程只是用来演示连接手机用，并没有正真的连接LED，只能够在手机上查看例程的功能，可以开关LED，但是开发板上的LED并不会有任何反应。
} 

void loop()
{
  //上面设置中的代码实现了附件属性数据库，但不执行任何操作。 HomeSpan 本身必须是
  // 不断轮询以查找来自控制器的请求，例如 iPhone 上的家庭应用程序。下面的 poll() 方法就是这样
  // 需要在 loop() 的每次迭代中连续执行此操作
  homeSpan.poll();         // 运行 HomeSpan!
}
