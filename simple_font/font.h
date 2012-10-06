#ifndef COMMON_FONT_H_
#define COMMON_FONT_H_
// by lrhnfs@gmail.com YMD 2012-7-18 HMS 13-49-44


namespace common
{
  class Font;

  extern Font kFont;
  extern bool kShowFont;

  // 字体类
  // 可以在屏幕任意位置显示字符串信息
  // 可以在屏幕特定位置有序输出字符串信息
  class Font
  {
  public:
    static const int kMaxRow = 64;
    static const int kMaxCol = 1024;
    static char buffer[kMaxRow][kMaxCol];
    typedef void (*FuncRender)(float x, float y, int align, const char* c_str);

  public:
    Font()
      : func_render_(0)
      , info_beg_x_(1200.0f)
      , info_beg_y_(0)
      , info_inter_y_(13)
      , info_align_(1)
      , line_(0)
    {}

    // 设置显示字符串函数
    void set_func_render(FuncRender val)
    {
      func_render_ = val;
    }

    // 指定位置渲染字符串
    void Render(float x, float y, int align, const char* c_str);

    // 指定位置渲染不定格式文本，用法如 printf
    void Print(float x, float y, int align, const char* format, ...);

    // 设置输出信息，用法如 printf（注：每帧清空一次）
    void AddInfo(char* format, ...);

    // 渲染输出信息（输入Add如的内容，默认右上角）
    void RenderInfo();

    // info位置
    void set_info_beg_x(float beg_x) { info_beg_x_ = beg_x; }
    void set_info_beg_y(float beg_y) { info_beg_y_ = beg_y; }
    void set_info_inter_y(float inter_y) { info_inter_y_ = inter_y; }
    void set_info_align(int align) { info_align_ = align; }

  private:
    FuncRender func_render_;
    float info_beg_x_, info_beg_y_;
    int info_inter_y_;
    int info_align_;
    int line_;

  };

}

#endif