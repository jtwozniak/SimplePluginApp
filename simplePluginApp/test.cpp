/*
 * plugin.h
 *
 *  Created on: May 27, 2012
 *      Author: janusz
 */
#include <stdio.h>
#include <dlfcn.h>
#include "interface.h"

#define returnIfError()                 \
  if ((error = dlerror ()) != NULL)     \
  {                                     \
       fprintf (stderr, "%s\n", error); \
       return 1;                        \
  }



int main(int argc, char **argv)
{
   void * handle;
   void (*removePlugin) (IPlugin *);
   IPlugin * (*cretaPlugin) ();
   IPlugin * dllObject;
   char *error;

   handle = dlopen ("../../plugin/Release/libplugin.so", RTLD_LAZY);
   returnIfError ();

   cretaPlugin = (IPlugin * (*) ()) (dlsym (handle, "createPlugin"));
   returnIfError ();

   dllObject = (*cretaPlugin) ();
   dllObject -> processData ();

   removePlugin = (void (*) (IPlugin *)) (dlsym (handle, "releasePlugin"));
   returnIfError ();

   (*removePlugin) (dllObject);

   dlclose (handle);
   returnIfError ();

   return 0;
}
