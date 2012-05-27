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
   void * (*creaPlugin) ();
   void (*removePlugin) (IPlugin *);
   IPlugin * dllObject;
   char *error;

   handle = dlopen ("../../plugin/Release/libplugin.so", RTLD_LAZY);
   returnIfError ();

   creaPlugin = (void * (*) ()) (dlsym (handle, "createPlugin"));
   returnIfError ();

   dllObject = (IPlugin *) (*creaPlugin) ();
   dllObject -> processData ();

   removePlugin = (void (*) (IPlugin *)) (dlsym (handle, "releasePlugin"));
   returnIfError ();

   (*removePlugin) (dllObject);

   dlclose (handle);
   returnIfError ();

   return 0;
}
