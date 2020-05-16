////////////////////////////////
// average_Cmd.cpp
// A mixed mode  C++/CLI Program to demonstrate 
// various language features...
// 
//
// Written By           Praseed Pai K.T.
//                      http://praseedp.blogspot.com
//
// @ the Visual studio command prompt..
//
// cl /clr average_cmd.cpp      
//
//


using namespace System;

///////////////////////////////////
//
// A Function which takes a double array
// as an argument (interior_ptr array)
//
//
double Average( interior_ptr<double> r , int len ) ;

///////////////////////////////////
//
// A Function which takes a ANSI C++ double array
// as an argument (to demonstrate pinning)
//
//

double Ptr_Average(double * r , int len ) ;

//////////////////////////////////////////////////
//
// User Entry Point ( Ask yourself ! - who calls main ?)
//
//
//

int main(array<String^>^ args )
{

	if ( args->Length == 0 ) {
		Console::WriteLine("No Command line parameters");
		return 1;  
	}

	int rs = args->Length;

	array<double>^ dbl_array =gcnew array<double>(rs);

	/////////////////////////////////////////////
	//
	// Collect all the command line arguments by converting 
	// into IEEE 754 floating point...

	for(int i=0; i<rs; ++i ) {

	try {
	
		dbl_array [i] = Convert::ToDouble(args[i]);
	}
	catch(Exception^ e ) {

		Console::WriteLine("Non numeric character at the cmd line");
		return -1;                 

		}	
    	}
	//////////////////////////////
	// Accumulate 
	//
	
	double sum = 0.0;
	for each(double t in dbl_array ) {
		sum +=t;
	}    

	Console::WriteLine("Sum is {0}",sum );

	//////////////////////////////////////////////
	//
	// interior_pointer....
	//

	interior_ptr<double> s = &dbl_array[0];
	double r = Average(s,rs);
	Console::WriteLine("Average is {0}",r );

	/////////////////////////////////////////////////////
	//
	//
	//
	pin_ptr<double>st = &dbl_array[0];        
	r = Average(st,rs);
	Console::WriteLine("Average is {0}",r );
 

}
/////////////////////////////////
// interior_pointer version of the average...
//
//
//

double Average(interior_ptr<double> r , int len ) 
{
         if (len == 0 )
                return 0;
         double sum = 0;  
         int tlen = len;  
         while (tlen-- )
            sum += *r++;

         Console::WriteLine("{0}",sum);  

         return sum/len;
      
}   

/////////////////////////////
//
// Native array version...
//
//
double Ptr_Average(double * r , int len ) 
{
         if (len == 0 )
                return 0;
         double sum = 0;  
         int tlen = len;  
         while (tlen-- )
            sum += *r++;

         Console::WriteLine("{0}",sum);  

         return sum/len;
      
}                     