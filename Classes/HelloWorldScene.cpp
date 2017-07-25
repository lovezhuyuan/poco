#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Types.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketAddress.h"
using namespace std;
USING_NS_CC;
#define BUFFER_SIZE 1024
#include <iostream>
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    Poco::DateTime now;
    std::string str = std::string("Today is")
    +Poco::DateTimeFormat::WEEKDAY_NAMES[now.dayOfWeek()]
    + ", "
    + Poco::DateTimeFormat::MONTH_NAMES[now.month() - 1]
    + " "
    + StringUtils::format("%d",now.day())
    + " - "
    + "day number "
    + StringUtils::format("%d",now.dayOfYear())
    + " in "
    + StringUtils::format("%d",now.year())
    + " and day number "
    + StringUtils::format("%ld",(long) now.julianDay())
    + " in the Julian calendar.";
    MessageBox(str.c_str(), "11111");
    
//    Poco::Net::SocketAddress address("123.206.90.21", 2007);
//    Poco::Net::StreamSocket socket(address);
//    char buffer[BUFFER_SIZE];
//    socket.sendBytes("我爱你啊 ", sizeof("我爱你啊 "));
//    if (socket.available())
//    {
//        int len = socket.receiveBytes(buffer, BUFFER_SIZE);
//        buffer[len] = '\0';
//        std::cout << "" << buffer << std::endl;
//        socket.sendBytes(buffer,sizeof(buffer));
//    }
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
