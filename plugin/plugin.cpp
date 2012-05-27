/*
 * plugin.h
 *
 *  Created on: May 27, 2012
 *      Author: janusz
 */
#include "stdio.h"
#include "plugin.h"

Plugin1::~Plugin1 ()
{
  printf ("Plugin1::~Plugin1 %s\n", getName ());
}

const char *
Plugin1::getName () const
{
  return "Plugin1";
}


void
Plugin1::processData ()
{
  for (int i = 0; i < 3; i++)
      printf ("Plugin1::processData %s...\n", getName ());
}


extern "C"
{
  IPlugin *
  createPlugin ()
  {
    return new Plugin1 ();
  }

  void
  releasePlugin (IPlugin * p_plugin)
  {
    delete p_plugin;
  }
}

