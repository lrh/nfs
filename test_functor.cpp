///////////////////////////////////////////////////////////////////////////
// if ����������2�з�ʽʵ���˲��Ĺ��ܣ�ʹ����ָ��ͷº����ܹ�����
//   1. ģ�巽ʽ�������������Ʋ������� [stl �㷨ʹ�õĶ���ģ�巽ʽ]
//   2. �������ط�ʽ�����Ҫ�õ� ���麯���� �� ������ʵ����Ҫ�ŵ� cpp�� ʱ
// lrhnfs@gmail.com [2011/5/24 YMD] [14:12:25]
//
 
#include <iostream>

// ����
void Function0(char* text)
{
  printf("Function Result = %s\n", text);
}

// �º���
struct Functor0
{
  void operator()(char* text)
  {
    printf("Functor Result = %s\n", text);
  }
} functor0;

// ͬ���������÷º����ͺ���ָ��ķ�ʽ
// 1 -- ģ�巽ʽ
// 2 -- �������ط�ʽ
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

// ���в���
struct RunTest
{
  RunTest()
  {
    CallFunc(Function0);  // ���ú���ָ��
    CallFunc(functor0);   // ���÷º���
    CallFunc(Functor0()); // ���÷º���
  }
} RunTest;

// ����������Ҫ
int main()
{
  system("pause");
}

///////////////////////////////////////////////////////////////////////////