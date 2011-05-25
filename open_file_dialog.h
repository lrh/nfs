#ifndef OPEN_FILE_DIALOG_H_
#define OPEN_FILE_DIALOG_H_
// lrhnfs@gmail.com [2011/5/25 YMD]
// windows 下的打开/保存文件对话框
// example:
//  std::cout << ShowOpenFileDialog() << std::endl;
//  std::cout << ShowSaveFileDialog() << std::endl;
//  

#include <string>
#include <Windows.h>

// 打开文件对话框
std::string ShowOpenFileDialog()
{
  std::string sPath;
  char szFile[MAX_PATH] = { 0 };
  OPENFILENAMEA openName;
  ZeroMemory(&openName, sizeof(openName));
  openName.lStructSize = sizeof(OPENFILENAME); 
  openName.hwndOwner   = 0; 
  openName.lpstrFilter = "All File(*.*)\0*.*\0"; 
  openName.lpstrDefExt = "";
  openName.lpstrFile   = szFile; 
  openName.nMaxFile    = sizeof(szFile); 
  openName.Flags       = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; 

  if (GetOpenFileNameA(&openName))
  {
    sPath = szFile;
  }
  return sPath;
}

// 保存文件对话框
std::string ShowSaveFileDialog()
{
  std::string sPath;
  char szFile[MAX_PATH] = { 0 };
  OPENFILENAMEA saveName;
  ZeroMemory(&saveName, sizeof(saveName));
  saveName.lStructSize = sizeof(OPENFILENAME); 
  saveName.hwndOwner   = 0; 
  saveName.lpstrFilter = "All File(*.*)\0*.*\0"; 
  saveName.lpstrDefExt = "";
  saveName.lpstrFile   = szFile; 
  saveName.nMaxFile    = sizeof(szFile); 
  saveName.Flags       = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST; 

  if (GetSaveFileNameA(&saveName))
  {
    sPath = szFile;
  }
  return sPath;
}

#endif // OPEN_FILE_DIALOG_H_
