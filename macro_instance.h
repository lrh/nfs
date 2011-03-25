#ifndef __MACRO_INSTANCE_H__
#define __MACRO_INSTANCE_H__
// lrhnfs@gmail.com

/*
 // One kind of C++ Singlton Implementation
 // C++������һ��ʵ�ַ�ʽ

 // Modify from MyGUI
 // �޸��� MyGUI

 // Get instance pointer by the static methord "GetIns()"
 // ͨ�ؾ�̬���� GetIns() ��ȡ���ʵ��ָ��

 // Caution! Before use GetIns(), Please Instantiate the class first.
 // ע: ʹ�� GetIns() ǰ, ����ʵ��������

 // Example:
 // ����:

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

    // assert error [���Ա���]
    scene_manager = new SceneManager;
 }
 // ...
 void OtherMethord()
 {
    // Get instance pointer by GetIns() [ͨ����̬������ȡʵ��ָ��]
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
