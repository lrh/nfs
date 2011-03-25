
﻿#ifndef __MACRO_INSTANCE_H__
#define __MACRO_INSTANCE_H__
// lrhnfs@gmail.com

/*
 // One kind of C++ Singlton Implementation
 // C++单例的一种实现方式

 // Modify from MyGUI
 // 修改自 MyGUI

 // Get instance pointer by the static methord "GetIns()"
 // 通关静态方法 GetIns() 获取类的实例指针

 // Caution! Before use GetIns(), Please Instantiate the class first.
 // 注: 使用 GetIns() 前, 请先实例化该类

 // Example:
 // 例子:

 // scene_manager.h
 class SceneManager
 {
    INSTANCE_HEADER(SceneManager)
    // ...
 }
 
 // scene_manager.cpp
 INSTANCE_SOURCE(SceneManager)

 // test.cpp
 main()
 {
    SceneManager* scene_manager = new SceneManager;

    // assert error [断言报错]
    scene_manager = new SceneManager;
 }
 // ...
 void OtherMethord()
 {
    // Get instance pointer by GetIns() [通过静态方法获取实例指针]
    SceneManager* scene_manager = SceneManager::GetIns();
    // ...
 }
*/

#include <cassert>

#define INSTANCE_HEADER(type) \
public: \
    type();\
    ~type(); \
    static type* GetIns(); \
private: \
    static type* instance_;

#define INSTANCE_SOURCE(type) \
    type* type::instance_ = 0; \
    type::type() { assert(0 == instance_ && #type); instance_ = this; } \
    type::~type() { instance_ = 0; } \
    type* type::GetIns() { return instance_; }

#endif // __INSTANCE_H__
