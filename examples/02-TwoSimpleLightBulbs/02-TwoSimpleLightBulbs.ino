////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: ESP32的HomeKit支持库                       //
//    ------------------------------------------------    //
//                                                        //
// Example 1: 两个不起作用的LED控制程序，用于演示与家庭App连接   //
//                                                        //
////////////////////////////////////////////////////////////

//函数功能、注释见example-01
#include "HomeSpan.h"

void setup() 
{
  // Example 2 两个LED灯连接HomeKit，每个LDE灯为单独可控制的配件。
  Serial.begin(115200);
  homeSpan.begin(Category::Lighting,"HomeSpan LightBulbs");
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("我的第一个LED灯");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("123-ABC");
  new Characteristic::Model("灯1");
  new Characteristic::FirmwareRevision("0.9");
  new Characteristic::Identify();

  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new Service::LightBulb();
  new Characteristic::On();

  // 创建第二个配件

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Name("我的第二个LED灯");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("123-ABC");
  new Characteristic::Model("灯2");
  new Characteristic::FirmwareRevision("0.9");
  new Characteristic::Identify();

  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new Service::LightBulb();
  new Characteristic::On();
  // 提示！当你是从Examole-01转移到此例程的时候，请不要重新配对配件，HomeSpan会识别到属性数据库？？？已经更新，并且会在程序重启时会广播一个新的配置号。
  //使所有 iOS 和 MacOS HomeKit 控制器自动更新并反映上面的新配置。
} 

void loop(){
  homeSpan.poll();
}
