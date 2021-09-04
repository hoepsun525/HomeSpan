
////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                                                        //
// Example 5: 两个正真能够控制的LED例程                       //
//                                                        //
//                                                        //
////////////////////////////////////////////////////////////


#include "HomeSpan.h" 
#include "DEV_LED.h"          // 新! 引用这个新的文件：DEV_LED.h, 下面会进行讲解
void setup() {

  // 首先! 使用HomeKit控制LED灯!
  
  // 例程 5 是例程2的延展，在例程2的基础上添加了正真能够使用HomeKit来控制的LED。
  // 例程2中，我们已经实现了在HomeKit中添加ESP32的设备，但是只能够添加到Home App中，但是不能够正真的去控制ESP32， 为了正真的控制ESP32，HomSpan需要通过某种形式来让HomeKit
  // 响应我们的操作。
  //开发者不需要通过复杂的代码来使用HomeSpan，HomeSpan在后端已经将流程设计好了，开发者只需要声明调用就行了。

  // 在Homekit中定义的每个服务, 比如Service:LightBulb 和 Service:Fan (甚至 Service::AccessoryInformation) 都能执行一个 update()方法，
  // 情况下，除了返回true之外什么也不会做。为了能够实际的去操作设备，你需要是用自己的代码方法来覆盖默认的 update()方法。最简单的方法是创建一个基于内置 HomeSpan 服务之一的 DERIVED 类。
  // 使用这个衍生类，您可以执行初始设置程序 (如果需要的话), 使用你自己的函数来覆盖update()函数, 甚至去创建任何其他你需要的方法或者特定于类的变量(class-specific variables)去操作复杂的设备。
  // 最重要的是，派生类可以带参数。
  // 这样做就可以让代码做到更通用，并且可以多次使用他们（见下面的例程），将它们转换成独立的模块 (见下面的例程)。
  // 所有HomeSpan执行的HomeKit服务都可以在 Services.h 中查看

  Serial.begin(115200);

  homeSpan.begin(Category::Lighting,"HomeSpan LEDs");
  
  new SpanAccessory(); 

  new Service::AccessoryInformation(); 
  new Characteristic::Name("LED #1"); 
  new Characteristic::Manufacturer("HomeSpan"); 
  new Characteristic::SerialNumber("123-ABC"); 
  new Characteristic::Model("20mA LED"); 
  new Characteristic::FirmwareRevision("0.9"); 
  new Characteristic::Identify();            

  new Service::HAPProtocolInformation();      
  new Characteristic::Version("1.1.0");     

  //  在实例2中，我们创建了一个 LightBulb 服务，并且是处于"On"这个特征。我们现在把这两行注释掉
  //  new Service::LightBulb();                   
  //  new Characteristic::On();                 

  // ...实例化一个新类： DEV_LED():

  new DEV_LED(16);        // 这行实例化了一个新的LED服务。那么它是如何完成的呢，在哪里定义的呢？ 为什么不用 Characteristic::On 了呢？ 请继续阅读...

  // 在历程的开始，我们引用了DEV_LED.h这个文件，在这个文件中，定义了DEV_LE的作用以及其它一些功能。
  // 前面的 “DEV_” 不是必须的，在HomeSpan的习惯中，使用“DEV_”开头是一个很好的命名方式。 请注意，DEV_LED 包含了服务所需要的所有特征，所以你不再去实例一个Characteristic::On 。
  // DEV_LED()括号内的参数指的是开发版的引脚。更多详情请查阅 ”DEV_LED.h“
  new SpanAccessory(); 
  
  new Service::AccessoryInformation();    
  new Characteristic::Name("LED #2");    
  new Characteristic::Manufacturer("HomeSpan"); 
  new Characteristic::SerialNumber("123-ABC");  
  new Characteristic::Model("20mA LED");   
  new Characteristic::FirmwareRevision("0.9");  
  new Characteristic::Identify();               

  new Service::HAPProtocolInformation();          
  new Characteristic::Version("1.1.0");  
  new DEV_LED(17);

} 
void loop(){
  homeSpan.poll();
}
