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
 *       Filename:  MFD.hpp
 *
 *    Description:  Code for the actual communication with the MFD using the x52mfd lib
 *
 *        Created:  21.04.2014 22:32:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Sacher (ms), michael.sacher@performant.ch
 *
 * =====================================================================================
 */

#ifndef  MFD_INC
#define  MFD_INC

#include <string>
#include "MsgParser.hpp"
extern "C" {
	#include <x52pro.h> 
}


/*
 * =====================================================================================
 *        Class:  MfdPage
 *  Description:  
 * =====================================================================================
 */
class MfdPage
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		MfdPage (Msg msg);                             /* constructor */
		
		/* ====================  ACCESSORS     ======================================= */
		std::string getLine1();
		std::string getLine2();
		std::string getLine3();
		/* ====================  MUTATORS      ======================================= */
		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		Msg message;
}; /* -----  end of class MfdPage  ----- */


/*
 * =====================================================================================
 *        Class:  MFD
 *  Description:  Represents the display on the X52pro throttle
 * =====================================================================================
 */
class MFD
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		MFD ();                             /* constructor */
		~MFD ();														/* destructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */
		void setPage(MfdPage page);
		void enableUpdate();
		void disableUpdate();
		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */
		void setLine1(std::string line1, bool center);
		void setLine2(std::string line2, bool center);
		void setLine3(std::string line3, bool center);
        void setLine(int line_id, std::string line, bool center);

		/* ====================  DATA MEMBERS  ======================================= */
		std::string line1;
		std::string line2;
		std::string line3;
		struct x52 *hdl;
		bool isUpdateEnabled = true;
}; /* -----  end of class MFD  ----- */

#endif   /* ----- #ifndef MFD_INC  ----- */
