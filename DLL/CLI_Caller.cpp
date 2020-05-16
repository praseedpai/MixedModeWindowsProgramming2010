///////////////////////////////////////
// CLI_Caller.cpp
//
// a C++/CLI caller for Windows native DLL
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
// @ the Visual Studio command prompt...
//
// cl /clr CLI_Caller.cpp  
//
using namespace System;
using namespace System::Runtime::InteropServices;

[DllImport("DllSrc.dll")]
int Add(int , int );

int main( array<String^>^ arr )
{
	Console::WriteLine("{0}",Add(1,1));

}