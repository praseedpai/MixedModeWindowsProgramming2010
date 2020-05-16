//////////////////////////////////////////////////////
//
//
// First.cs
//
// On Windows
// -----------
// csc First.cs
//
// on Linux/MAC OS X
// -----------------
// mcs First.cs (in ubuntu, it is gmcs First.cs )
//
//
// When executing , make sure that libMonoWindows.dll 
// (under windows ) is in the current directory or 
// in the path
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com 
//
//

#define WINDOWS  //  MAC_OS_X | GNU_LINUX


using System; 

using System.Text;

using System.Runtime.InteropServices;






////////////////////////////////
//
// C# mapping of C/C++ structure...
//
//

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]

public struct EventData
{

	public int I;
    
	public string Message;

}







public class Test

{
 

///////////////////////////////////
//
// Declare a delegate which is a mapping
// to function pointer expected by 
// ListOfSquares method....
//
//
public  delegate long CallBack( int i );




////////////////////////////////////////
//
// This method will be called from C++
//
//
public static long SpitConsole(int i ) {

          Console.WriteLine( "Printing from C# {0}",i*i);

          return i*i;

    
}




#if MAC_OS_X 

  //MONO

[DllImport ("./libMonoMac.so")]
 
private static extern int Add (int a, int b);


[DllImport ("./libMonoMac.so")]
  
private static extern long ListOfSquares ( CallBack a );


[DllImport ("./libMonoMac.so")]
    
private static extern bool StringCopy( StringBuilder dest , String src );
[DllImport ("./libMonoMac.so")]
 
private static extern bool PutEventData( ref EventData r );



#elif GNU_LINUX   // MONO 


[DllImport ("./libMonoLinux.so")]
  
private static extern int Add (int a, int b);


[DllImport ("./libMonoLinux.so")]
  
private static extern long ListOfSquares ( CallBack a );


[DllImport ("./libMonoLinux.so")]
   
private static extern bool StringCopy( StringBuilder dest , String src );
[DllImport ("./libMonoLinux.so")]

private static extern bool PutEventData( ref EventData r );




#else
    // WINDOWS , MS C#

[DllImport ("libMonoWindows.dll")]

private static extern int Add (int a, int b);



[DllImport ("libMonoWindows.dll")]

private static extern long ListOfSquares ( CallBack a );


[DllImport ("libMonoWindows.dll")]

private static extern bool StringCopy( StringBuilder dest , String src );


[DllImport ("libMonoWindows.dll")]
  
private static extern bool PutEventData( ref EventData r );



#endif
   




public  static void Main() 
{
   
	////////////////////////////////////////////////////
	//
	// Call the Add method from the DLL
	//
	Console.WriteLine("Hello DevCon 2010....{0}",Add(2,3));


	///////////////////////////////////////////
	//
	// Call StringCopy

	StringBuilder sb = new StringBuilder(256);

     	StringCopy(sb,"Hello World...");

     	Console.WriteLine(sb.ToString());


	/////////////////////////////////////////////////// 
	//

        // This demonstrates how to pass structure to C++
        // 
  


     	EventData rt = new EventData();

     	rt.I = 13;
        
     	rt.Message = "I might be from MONO or Visual C# ........!";

    	PutEventData(ref rt);



	/////////////////////////////
	// CallBack Demo
	//
    	ListOfSquares(SpitConsole);
 }


}



