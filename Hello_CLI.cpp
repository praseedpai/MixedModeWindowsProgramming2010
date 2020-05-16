/////////////////////////////////
//
// A Mixed Mode Hello World Program
//          in C++/CLI
//
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
//
// 
//
// cl /clr Hello_CLI.cpp
//  
//


//------- instruct to link Advapi32.dll 

#pragma comment(lib,"Advapi32")


//----------------- standard windows header file...

#include <windows.h>

//---------- standard .net include...!

using namespace System;

////////////////////////////////////////
//
// A ANSI C/C++ entry point...
//
//

int main( int argc , char **argv )
{
    /////////////////////////////////////
    // Call a Windows API function to retrieve 
    // the current user name...
    //

    char ComputerUserName[1024];
    DWORD len = 1024;
    GetUserName(ComputerUserName,&len);

    ////////////////////////////////////////////
    // spit a message by formatting it....
    //
    String^ message = "Hello World to ...";
    Console::WriteLine("{0} {1}",message , gcnew String(ComputerUserName));
    return 0; 
                 
}
