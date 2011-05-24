///////////////////////////////////////////////////////////////////////////
// if 条件编译用2中方式实现了差不多的功能，使函数指针和仿函数能够兼容
//   1. 模板方式：更加灵活，不限制参数类型 [stl 算法使用的都是模板方式]
//   2. 函数重载方式：如果要用到 “虚函数” 或 “函数实现需要放到 cpp” 时
// lrhnfs@gmail.com [2011/5/24 YMD] [14:12:25]
//
 
#include <iostream>

// 函数
void Function0(char* text)
{
  printf("Function Result = %s\n", text);
}

// 仿函数
struct Functor0
{
  void operator()(char* text)
  {
    printf("Functor Result = %s\n", text);
  }
} functor0;

// 同名方法调用仿函数和函数指针的方式
// 1 -- 模板方式
// 2 -- 函数重载方式
#if 1
  template<class T>
  void CallFunc(T& func)
  {
    func("Template Func");
  }
#else
  typedef void (*FuncPtr)(char*);
  void CallFunc(FuncPtr func)
  {
    func("FuncPtr");
  }
  void CallFunc(Functor0& func)
  {
    func("Functor");
  }
#endif

// 运行测试
struct RunTest
{
  RunTest()
  {
    CallFunc(Function0);  // 调用函数指针
    CallFunc(functor0);   // 调用仿函数
    CallFunc(Functor0()); // 调用仿函数
  }
} RunTest;

// 程序运行需要
int main()
{
  system("pause");
}

///////////////////////////////////////////////////////////////////////////