/*
 * plugin.h
 *
 *  Created on: May 27, 2012
 *      Author: janusz
 */

#ifndef PLUGIN_H_
#define PLUGIN_H_

#include "stdio.h"
#include "interface.h"

class Plugin1:
  public IPlugin
{
public:
    virtual ~Plugin1 ();
    virtual const char* getName () const;
    virtual void processData ();

};

extern "C"
{
  IPlugin * createPlugin ();
  void releasePlugin (IPlugin *);
}

#endif /* PLUGIN_H_ */
