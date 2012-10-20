/**////
///
///
#include <windows.h>
#include <stdio.h>
#include <dbghelp.h>

#pragma comment( lib, "dbghelp.lib" )

void dump_callstack( FILE* file, CONTEXT *context )
{
  STACKFRAME sf;
  memset( &sf, 0, sizeof( STACKFRAME ) );

  sf.AddrPC.Offset = context->Eip;
  sf.AddrPC.Mode = AddrModeFlat;
  sf.AddrStack.Offset = context->Esp;
  sf.AddrStack.Mode = AddrModeFlat;
  sf.AddrFrame.Offset = context->Ebp;
  sf.AddrFrame.Mode = AddrModeFlat;

  DWORD machineType = IMAGE_FILE_MACHINE_I386;

  HANDLE hProcess = GetCurrentProcess();
  HANDLE hThread = GetCurrentThread();

  for( ; ; )
  {
    if( !StackWalk(machineType, hProcess, hThread, &sf, context, 0, SymFunctionTableAccess, SymGetModuleBase, 0 ) )
    {
      break;
    }

    if( sf.AddrFrame.Offset == 0 )
    {
      break;
    }
    BYTE symbolBuffer[ sizeof( SYMBOL_INFO ) + 1024 ];
    PSYMBOL_INFO pSymbol = ( PSYMBOL_INFO ) symbolBuffer;

    pSymbol->SizeOfStruct = sizeof( symbolBuffer );
    pSymbol->MaxNameLen = 1024;

    DWORD64 symDisplacement = 0;
    if( !SymFromAddr( hProcess, sf.AddrPC.Offset, &symDisplacement, pSymbol ) )
    {
      pSymbol->Name[0] = 0;
    }

    IMAGEHLP_LINE lineInfo = { sizeof(IMAGEHLP_LINE) };
    DWORD dwLineDisplacement;

    if( SymGetLineFromAddr( hProcess, sf.AddrPC.Offset, &dwLineDisplacement, &lineInfo ) )
    {
      fprintf( file, "%s(%u):%s\n", lineInfo.FileName, lineInfo.LineNumber,pSymbol->Name );
    }
  }
}

DWORD excep_filter( LPEXCEPTION_POINTERS lpEP )
{
  FILE * file = fopen("dumpstack.log" ,"w+");
  if(file)
  {
    /**//// init dbghelp.dll
    if( SymInitialize( GetCurrentProcess(), NULL, TRUE ) )
    {
      fprintf( file, "Init ok.\n" );
    }

    dump_callstack( file, lpEP->ContextRecord );

    if( SymCleanup( GetCurrentProcess() ) )
    {
      fprintf( file, "Cleanup.\n" );
    }
    fclose(file);
  }

  return EXCEPTION_EXECUTE_HANDLER;
}


int main()
{
  __try
  {
    //to do
  }
  __except( excep_filter( GetExceptionInformation() ) )
  {
    printf( "Some exception occures.\n" );
  }

  return 0;
}