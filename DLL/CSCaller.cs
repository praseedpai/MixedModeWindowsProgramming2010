//////////////////////////////////////////
// CSCaller.cs
//
// A C# program to Call Windows native DLL
// (DllSrc.dll )
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com  
//
// @ the Visual studio command prompt
// 
// csc CSCCaller.cs
//

using System;
using System.Runtime.InteropServices;

public class Test {

	[DllImport("DllSrc.dll", EntryPoint="Add")]
	static extern int Add(int a , int b ); 


	public static void Main(String [] args ) {

		Console.WriteLine("{0}",Add(100,101));

	}


}