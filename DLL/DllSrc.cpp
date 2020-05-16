///////////////////////////////////////
//
// A Simple C/C++ source module which will be 
// converted to a Win32 Dynamic Link Library
// 
//
// cl /c DllSrc.cpp
// link /DLL /DEF:DllSrc.def /out:DllSrc.dll DllSrc.obj
//
//
// using dumpbin utility , we can check whether export is
// properly done
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
//
//

#include <windows.h>

extern "C" __declspec(dllexport) int __stdcall Add( int a , int b )
{

       return a + b;  
}


