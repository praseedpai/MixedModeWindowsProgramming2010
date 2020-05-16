////////////////////////////////
// Dump_Cmd.cpp
// A C++/CLI Hello World...program
// to dump the command line arguments 
// to the screen... 
// 
//
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
// @ the visual studio command prompt
// 
// cl /clr Dump_cmd.cpp
// Dump_cmd 1 2 3 
//

using namespace System;

///////////////////////////////////
//
//
// User entry point....
//
//
//

int main(array<String^>^ args )
{
    /////////////////////////////////////////
    //
    // in a ANSI C/C++ program ,command line parameters 
    // are of the type char ** (char **argv or char *argv[])
    // and by default argv[0] is the executable name..
    //  
    // C++/CLI ( and C# ) won't give the executable name as 
    // the first parameter

    if ( args->Length == 0 ) {
          Console::WriteLine("No Command line parameters");
          return 0;  
    }
    

    int rs = args->Length;
    for(int i=0; i<rs; ++i ) {
             Console::WriteLine("{0} ",args[i]->ToUpper() );
    }

}

