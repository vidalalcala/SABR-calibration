// Author: Jose V. Alcala-Burgos
// QlTesting.cpp : Defines the entry point for the console application.
#include "stdafx.h"

#include <ql/quantlib.hpp>
using namespace QuantLib;

#include "LazyObject3.h"

int main(int argc, char *argv[])
{
	try{

testingLazyObject1();

	} catch (std::exception& e) {
        std::cout << e.what() << std::endl;
		    return 1;
    } catch (...) {
        std::cout << "unknown error" << std::endl;
	       return 1;
    }


	return 0;
}




