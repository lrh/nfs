#ifndef COMMON_FONT_H_
#define COMMON_FONT_H_
// by lrhnfs@gmail.com YMD 2012-7-18 HMS 13-49-44


namespace common
{
  class Font;

  extern Font kFont;
  extern bool kShowFont;

  // ������
  // ��������Ļ����λ����ʾ�ַ�����Ϣ
  // ��������Ļ�ض�λ����������ַ�����Ϣ
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

    // ������ʾ�ַ�������
    void set_func_render(FuncRender val)
    {
      func_render_ = val;
    }

    // ָ��λ����Ⱦ�ַ���
    void Render(float x, float y, int align, const char* c_str);

    // ָ��λ����Ⱦ������ʽ�ı����÷��� printf
    void Print(float x, float y, int align, const char* format, ...);

    // ���������Ϣ���÷��� printf��ע��ÿ֡���һ�Σ�
    void AddInfo(char* format, ...);

    // ��Ⱦ�����Ϣ������Add������ݣ�Ĭ�����Ͻǣ�
    void RenderInfo();

    // infoλ��
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