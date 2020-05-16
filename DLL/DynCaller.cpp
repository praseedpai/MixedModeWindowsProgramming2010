////////////////////////////////////
// DynCaller.cpp
// 
// A Program to call Add routine from
// DllSrc.dll 
//
// We are going to dynamically link to the DLL
// (Not an Oxymoron ! ..PINVOKE works like this )
//
// cl DynCaller.cpp 
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




int main( int argc , char **argv )
{
	HMODULE handle =(HMODULE)LoadLibrary("DllSrc.dll");
	
	if ( handle == 0 )
	{
		printf("failed to load the DLL\n");
		return -1;
	}

	int (*AddFunPtr)(int,int)  = 
		( int (*)(int,int))GetProcAddress(handle,"Add");

	if ( AddFunPtr == 0 )
	{
		printf("Could not retrieve the function pointer...\n");
		return -2;
	}	

	printf("%d\n",(*AddFunPtr)(2,3));

	FreeLibrary(handle);
}



