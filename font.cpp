#include "font.h"
#include <cstdio>


namespace common
{
  Font kFont;
  bool kShowFont = false;

  char Font::buffer[Font::kMaxRow][Font::kMaxCol] = { 0 };

  void Font::Render(float x, float y, int align, const char* c_str)
  {
    if (func_render_ && kShowFont)
      func_render_(x, y, align, c_str);
  }

  void Font::Print(float x, float y, int align, const char* format, ...)
  {
    if (func_render_)
    {
      char buffer[kMaxCol] = { 0 };
      char* lps_arg = (char*)(&format) + sizeof(format);
      vsprintf(buffer, format, lps_arg);
      Render(x, y, align, buffer);
    }
  }

  void Font::AddInfo(char* format, ...)
  {
    if (line_ < kMaxRow)
    {
      char* lps_arg = (char*)(&format) + sizeof(format);
      vsprintf(buffer[line_], format, lps_arg);
      ++line_;
    }
  }

  void Font::RenderInfo()
  {
    for (int i = 0; i < line_; ++i)
      Render(info_beg_x_, info_beg_y_ + info_inter_y_ * i, info_align_, buffer[i]);
    line_ = 0;
  }

}
