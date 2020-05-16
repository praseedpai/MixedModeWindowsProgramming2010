//////////////////////////////////////////////////////
//caller.cs
//
//	
//This C# program will call a ANSI C++ class 
//(without using Com interop )...bit ugly !
//
//
//Written by Praseed Pai K.T.
//           http://praseedp.blogspot.com
//
// @ the Visual studio command prompt
// csc caller.cs
//

using System;
using System.Runtime.InteropServices;

class Test
{
/////////////////////////////////////////
//
// call the Factory method to instantiate the 
// ANSI C++ Object
//
[DllImport("CPP_UNMANAGED.dll",
EntryPoint="?RawClassFactory@RawClass@@SAPAV1@N@Z")]
extern static IntPtr RawClassFactory(double t );

/////////////////////////////////////////////
//
// Delete the Object 
//
[DllImport("CPP_UNMANAGED.dll",
EntryPoint="?DeleteObject@RawClass@@SAXPAV1@@Z")]
extern static void DeleteObject(IntPtr obj); 

////////////////////////////////////
//
// Call the AddAndEmit method.... not the 
// ThisCall directive. When you call a C++
// method , there is a implicit this pointer
// we are passing that !.....
//
// Now you know the mechanism of this pointer....
// it is just a function call...
//
[DllImport("CPP_UNMANAGED.dll",
EntryPoint="?AddAndEmit@RawClass@@QAEXN@Z",
CallingConvention=CallingConvention.ThisCall)]
extern static void AddAndEmit(IntPtr obj,double i);


/////////////////////////////////////////////
//
// Entry Point....
//
public static void Main(String [] args )
{
	IntPtr p = RawClassFactory(10.0);
	AddAndEmit(p,2);
	DeleteObject(p);
}


}