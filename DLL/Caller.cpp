////////////////////////////////////
// Caller.cpp
// 
// A Program to call Add routine from
// DllSrc.dll 
//
// We are going to statically link to the DLL
//
// cl Caller.cpp DllSrc.lib
// Caller.exe
//
// Written by Praseed Pai K.T. 
//            http://praseedp.blogspot.com
//
//
//
//

#include <windows.h>
#include <stdio.h>

extern "C" int __stdcall Add(int , int );


int main( int argc , char **argv )
{

	printf("%d\n",Add(2,3));
}



