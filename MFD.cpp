#include "MFD.hpp"

MFD::MFD ()
{
	hdl = x52_init();
	x52_setbri(hdl,1,100);
}

MFD::~MFD ()
{
	x52_close(hdl);
}


	void
MFD::setLine1 ( std::string line, bool center )
{
    setLine(0,line,center);
}

	void
MFD::setLine2 ( std::string line, bool center )
{
    setLine(1,line,center);
}

	void
MFD::setLine3 ( std::string line, bool center)
{
    setLine(2,line,center);
}

    void
MFD::setLine(int line_id, std::string line, bool center)
{
    // pad with spaces to center text
    if (center) {
        int spaceCount = (16-line.length())/2;

        for (int i=0; i<spaceCount; i++) {
            line = " "+line;
        };
    }

    std::cout<<"setting line 1 to: "<<line<<std::endl;
    char * constLine = const_cast<char*>(line.c_str());
    x52_settext(hdl,line_id,constLine, strlen(constLine));
}

	void
MFD::setPage ( MfdPage page )
{
	std::string line1(page.getLine1());
	std::string line2(page.getLine2());
	std::string line3(page.getLine3());
	MFD::setLine1(line1, true);
	MFD::setLine2(line2, true);
	MFD::setLine3(line3, true);
}


MfdPage::MfdPage (Msg msg)
{
	message = msg;
} 


	std::string
MfdPage::getLine1 (  )
{
	return message.title;
}	

	std::string
MfdPage::getLine2 (  )
{
	return message.actFreq0+"<>"+message.stbyFreq0;
}	

	std::string
MfdPage::getLine3 (  )
{
	return message.actFreq1+"<>"+message.stbyFreq1;
}

