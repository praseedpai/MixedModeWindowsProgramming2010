///////////////////////
//
//
//  On MS Windows

//  -------------

//  cl /c /D_WINDOWS DllSave.cpp

//  link /out:libMonoWindows.dll /DLL /DEF:libMonoWindows.def DllSave.obj
//

//  On GNU/Linux

//  ------------

//

//  g++ -c fPIC DllSave.cpp

//  g++ -shared -o libMonoLinux.so DllSave.o 

//

//  On MAC OS X

//  ------------

//  g++ -c -fPIC DllSave.cpp

//  g++ -dynamiclib -o libMonoMac.so DllSave.o

//

//

//  Written by Praseed Pai K.T.
//             http://praseedp.blogspot.com
// 




#include <stdio.h>

#include <math.h>

#include <stdio.h>

#include <string.h>



////////////////////////////////
//
// .NET follows __stdcall calling convention
// 
//   
//

#ifdef _WINDOWS

#define EXPORT_FUNC __declspec(dllexport)
#define CALL_CONV   __stdcall

#else

//---------------------- MAC OS X | LINUX 

#define EXPORT_FUNC 
#define CALL_CONV   


#endif





//////////////////////////////////////////////////////
//
//
//  A Simple Function to Add two numbers
//
//
//


extern "C" EXPORT_FUNC int CALL_CONV Add(int a, int b ) 

{

   
	return a + b; 


}





////////
//
//
//
//
//

//
// A Function to demonstrate CallBacks
//
// The function calls a C# method via delegate
//
// (remember cyclic definition of delgate ? )
//
// What is a delegate ?
// Delegates are function Pointers....!
// 
// What are function pointers ?
// I told you,it is equivalent to a delegate 
//
//
//

extern "C" EXPORT_FUNC void CALL_CONV ListOfSquares( 
	long (CALL_CONV *square_callback) (int rs) 
)

{


	for(int i=0; i<10; ++i ) 
	{


		double ret = (*square_callback)(i);
  
		printf("Printing from C++ ... %g\n",ret);
	}


}




////////////////////
//
//
//
//
//

//
// a clone of lstrcpy WIN API function...
//
//
extern "C" EXPORT_FUNC bool CALL_CONV StringCopy( char *t ,
	const char *src )
{

 
	if ( t == 0 || src == 0 )
		return false;



	if (*src == 0 )

		return false;

 

	strcpy(t,src);



	return true;


}



///////////////////////////////////

// 
// This structure will be passed between 
// C# and C++ 
//
//

struct EventData
{
    
	int I;

	char * Message;

};



extern "C" EXPORT_FUNC  bool CALL_CONV PutEventData( 
		EventData *ptr )
{


   
   printf("%s\n",ptr->Message);
   
      printf("%d\n",ptr->I);
      return false;  


 

}
