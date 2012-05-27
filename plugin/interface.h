/*
 * plugin.h
 *
 *  Created on: May 27, 2012
 *      Author: janusz
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

class IPlugin
{
public:
  virtual ~IPlugin () {};
  virtual const char* getName () const = 0;
  virtual void processData () = 0;
};

#endif /* INTERFACE_H_ */
