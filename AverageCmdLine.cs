//////////////////////////////////////
// CmdLineDump.cs
//
// A Program to dump the command line 
// arguments @ the console
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
// csc CmdLineDump.cs
// CmdLineDump.cs    
//
//
//
using System;

class DevConDemo {

  public static void Main(String [] args ) {
 
        if ( args.Length == 0 )
        {
           Console.WriteLine("Hello World....");
           return;
        } 

        int cmd = args.Length;

        for(int i=0;i<cmd;++i )
        {
             Console.WriteLine("{0}",args[i]);
             
        }

        

  }


}