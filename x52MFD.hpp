/*
 * Copyright 2014 Michael Sacher
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * =====================================================================================
 *
 *       Filename:  x52MFD.hpp
 *
 *    Description:  This is the main module for the x52MFD project
 *
 *        Created:  26.04.2014 10:01:58
 *       Revision:  none
 *       Compiler:	gcc
 *
 *         Author:  Michael Sacher (ms), michael.sacher@performant.ch
 *
 * =====================================================================================
 */
#ifndef  x52MFD_INC
#define  x52MFD_INC

#include	<stdlib.h>
#include "MsgParser.hpp"
#include "MFD.hpp"
#include "UdpServer.hpp"
class x52MFD;
#include "Joystick.hpp"
#include <math.h>
#include <iostream>
#include <string>




/* =====================================================================================
 *        Class:  X52MFD
 *  Description:  
 * =====================================================================================
*/
enum Mode {COM,NAV,ADF,DME};
class X52MFD
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		X52MFD ();                             /* constructor */
		~X52MFD ();														 /* destructor */

		/* ====================  ACCESSORS     ======================================= */
		void main();
		/* ====================  MUTATORS      ======================================= */
		void prevMode();
		void nextMode();
		void switchLine(int linenr, Mode mode);
		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		MsgParser parser;
		Msg mymsg;
		UdpServer inbound;
		UdpClient outbound;
		MfdPage page;
		MFD mfd;
		Mode mode = COM;
		Joystick *js;
}; /* -----  end of class X52MFD  ----- */

#endif   /* ----- #ifndef x52MFD_INC  ----- */
