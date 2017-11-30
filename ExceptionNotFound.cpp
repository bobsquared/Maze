/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 

#include "ExceptionNotFound.h"  

ExceptionNotFound::ExceptionNotFound(const string& message): 
logic_error("Data Not Found Exception: " + message)
{
}  // end constructor

// End of implementation file.