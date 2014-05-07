/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#ifndef __conversion_h__
#define __conversion_h__

#include <Fabric/EDK/EDK.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace Fabric::EDK;

template<class A, class B>
inline bool conv_from_baseType(const A & a, B & b)
{
  b = a;
  return true;
}

template<class B, class A>
inline bool conv_to_baseType(const A & a, B & b)
{
  b = a;
  return true;
}

inline bool conv_from_String(const KL::String & a, std::string & b)
{
  if(a.data() == NULL)
    b = "";
  else
    b = a.data();
  return true;
}

inline bool conv_to_String(const std::string & a, KL::String & b)
{
  if(a.length() == 0)
    b = "";
  else
    b = a.c_str();
  return true;
}

template<class A, class B>
inline bool conv_from_StdC(const A & a, B * & b)
{
  if(!a.isValid())
    return false;
  b = (B*)a->handle;
  return b != NULL;
}

template<class B, class A>
inline bool conv_to_StdC(const A * a, B & b, bool owned = false)
{
  if(!b.isValid())
    b = B::Create();
  if(b->handle != NULL)
    delete((A*)b->handle);
  b->handle = (void*)a;
  return true;
}

#endif
