///////////////////////////////////////////////
//
// CPP_UNMANAGED.cpp 
//
// A Simple C++ which will be exported from a 
// DLL. The class will be instantiated from 
// a C# module
//
// @ the Visual C++ command prompt:-
//
// cl /LD CPP_UNMANAGED.cpp
// 	
// Written by Praseed Pai K.T.
//	      http://praseedp.blogspot.com
//	
//
//
//

#include <stdio.h>

class __declspec(dllexport) RawClass
{

	private:
		double _val;
	public:
		RawClass( double p=0 ) {
			_val = p;
		}

		void AddAndEmit(double slack ) {
			printf("%d\n",(int)(_val+slack) );

		}

		static RawClass *RawClassFactory(double t) {
			return new RawClass(t);
		}

		static void DeleteObject(RawClass *r ) {
			delete r;
		}

};

