/////////////////////////////
//CmdLineDump.cpp
//
//A ANSI C/C++ program to dump the command
//line arguments....
//
//
//Written by Praseed Pai K.T.
//           http://praseedp.blogspot.com
//
//cl CmdLineDump.cpp
//CmdLineDump.cpp
//
#include <stdio.h>

int main(int argc , char **argv )
{
        if ( argc == 1 ) {
            printf("%s\n","No command line arguments");
            return 0;
        }

        int cmd = argc;

        for(int i=1; i<cmd; ++i )
        {
           printf("%s\n",argv[i]);
        } 


}