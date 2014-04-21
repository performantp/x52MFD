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
 *       Filename:  MsgParser.hpp
 *
 *    Description:  Code for parsing the strings coming from the generic flightgear protocol
 *
 *        Created:  01/05/2013 07:14:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Sacher (ms), michael.sacher@performant.ch
 *
 * =====================================================================================
 */

#ifndef  MsgParser_INC
#define  MsgParser_INC

#include <iostream>
#include <stdlib.h>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;

typedef struct Msg {
	string title;
	string actFreq0,stbyFreq0;
	string actFreq1,stbyFreq1;
} Msg; 

/*
 * =====================================================================================
 *        Class:  MsgParser
 *  Description:  MessageParser to parse the Strings coming from the generic flightgear protocol
 * =====================================================================================
 */
class MsgParser
{
	public:
			
		vector<Msg> parse(std::string msgString );

		/* ====================  LIFECYCLE     ======================================= */
		MsgParser ();                             /* constructor      */
		MsgParser ( const MsgParser &other );   /* copy constructor */
		~MsgParser ();                            /* destructor       */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

		const MsgParser& operator = ( const MsgParser &other ); /* assignment operator */

		/* ====================  DATA MEMBERS  ======================================= */
	protected:

	private:

}; /* -----  end of class MsgParser  ----- */

#endif   /* ----- #ifndef MsgParser_INC  ----- */
