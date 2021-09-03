
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
void setup() {                // HomeSpan程序内容应写在setup()中
 
  Serial.begin(115200);       // 开启串口，用于接收HomeSpan的消息和进行交互
  // HomeSpan 库创建了一个名为“homeSpan”的全局对象，它封装了所有 HomeSpan 功能。
  // begin()方法用于初始化 HomeSpan 并启动所有 HomeSpan 进程。
  
  // 前两个参数是 Category 和 Name, 用于定义初始化

  homeSpan.begin(Category::Lighting,"HomeSpan LightBulb");   // initializes a HomeSpan device named "HomeSpan Lightbulb" with Category set to Lighting

  // Next, we construct a simple HAP Accessory Database with a single Accessory containing 3 Services,
  // each with their own required Characteristics.
  
  new SpanAccessory();                              // Begin by creating a new Accessory using SpanAccessory(), which takes no arguments
  
    new Service::AccessoryInformation();            // HAP requires every Accessory to implement an AccessoryInformation Service, which has 6 required Characteristics:
      new Characteristic::Name("My Table Lamp");      // Name of the Accessory, which shows up on the HomeKit "tiles", and should be unique across Accessories
      
  // The next 4 Characteristics serve no function except for being displayed in HomeKit's setting panel for each Accessory.  They are nevertheless required by HAP:
                                                      
      new Characteristic::Manufacturer("HomeSpan");   // Manufacturer of the Accessory (arbitrary text string, and can be the same for every Accessory)
      new Characteristic::SerialNumber("123-ABC");    // Serial Number of the Accessory (arbitrary text string, and can be the same for every Accessory)
      new Characteristic::Model("120-Volt Lamp");     // Model of the Accessory (arbitrary text string, and can be the same for every Accessory)
      new Characteristic::FirmwareRevision("0.9");    // Firmware of the Accessory (arbitrary text string, and can be the same for every Accessory)

  // The last required Characteristic for the Accessory Information Service is the special Identify Characteristic.  We'll learn more about this
  // Characteristic in later examples.  For now, you can just instantiate it without any arguments.
  
      new Characteristic::Identify();                 // Create the required Identify

  // *NOTE* HAP requires that the AccessoryInformation Service always be instantiated BEFORE any other Services, which is why we created it first.

  // HAP also requires every Accessory (with the exception of those in Bridges, as we will see later) to implement the HAP Protocol Information Service.
  // This Service supports a single required Characteristic that defines the version number of HAP used by the device.
  // HAP Release R2 requires this version to be set to "1.1.0" 
  
    new Service::HAPProtocolInformation();          // Create the HAP Protcol Information Service  
      new Characteristic::Version("1.1.0");           // Set the Version Characteristicto "1.1.0" as required by HAP

  // Now that the required "informational" Services have been defined, we can finally create our Light Bulb Service

    new Service::LightBulb();                       // Create the Light Bulb Service
      new Characteristic::On();                       // This Service requires the "On" Characterstic to turn the light on and off

  // That's all that's needed to define a database from scratch, including all required HAP elements, to control a single lightbulb.
  // Of course this sketch does not yet contain any code to implement the actual operation of the light - there is nothing to
  // turn on and off.  But you'll still see a Light Bulb tile show up in your Home App with an ability to toggle it on and off.

} // end of setup()

//////////////////////////////////////

void loop(){

  // The code in setup above implements the Accessory Attribute Database, but performs no operations.  HomeSpan itself must be
  // continuously polled to look for requests from Controllers, such as the Home App on your iPhone.  The poll() method below is all that
  // is needed to perform this continuously in each iteration of loop()
  
  homeSpan.poll();         // run HomeSpan!
  
} // end of loop()

// Congratulations!  You've created your first HomeSpan sketch, ready to be uploaded to your ESP32 board and paired with HomeKit.
//
//
