#include "MsgParser.hpp"

using namespace std;
using namespace boost; //using boost to split the string

vector<Msg> MsgParser::parse(std::string msgString) {

	vector<string> lines;
	vector<Msg> messages;

	boost::split( lines, msgString, is_any_of( "\n" ) );
	lines.pop_back(); //the last line is always just empty - we don't need it

	for(std::vector<string>::iterator line_it = lines.begin(); line_it != lines.end(); ++line_it) { //iterate over each line

		Msg msg;

		vector<string> fields;
		split( fields, *line_it, is_any_of( "\t" ) );

		msg.title = fields[0];
		msg.actFreq0 = fields[1];
		msg.stbyFreq0 = fields[2];
		msg.actFreq1 = (const string) fields[3];
		msg.stbyFreq1 = (const string) fields[4];

		messages.push_back(msg);

	}	

	return messages;

}


MsgParser::MsgParser ()
{
}

MsgParser::MsgParser ( const MsgParser &other )
{
}

MsgParser::~MsgParser ()
{
} 

