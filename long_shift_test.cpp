
#ifdef USE_LONG
long cc = 0xFFFFFFFF;
long tt = (cc >> 24);
#else
DWORD cc = 0xFFFFFFFF;
DWORD tt = (cc >> 24);
#endif

int sd = sizeof(DWORD);
int sl = sizeof(long);

std::cout << std::hex << "tt = " << tt << std::endl;
std::cout << "sd = " << sd << std::endl;
std::cout << "sl = " << sl << std::endl;

//////////////////////////////////////////////////////////////////////////
// ide: visual studio 2005
// 
// if define USE_LONG
// the result is:
// " tt = ffffffff
//   sd = 4
//   sl = 4 "
//   
// else
// the result is:
// " tt = ff
//   sd = 4
//   sl = 4 "
// 
