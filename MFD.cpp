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
MFD::setLine1 ( std::string line )
{
	std::cout<<"setting line 1 to: "<<line<<std::endl;
	char * constLine = const_cast<char*>(line.c_str());
	x52_settext(hdl, 0,constLine, 16);
}

	void
MFD::setLine2 ( std::string line )
{	
	std::cout<<"setting line 2 to: "<<line<<std::endl;
	char * constLine = const_cast<char*>(line.c_str());
	x52_settext(hdl, 1,constLine, 16);
}

	void
MFD::setLine3 ( std::string line )
{
	std::cout<<"setting line 3 to: "<<line<<std::endl;
	char * constLine = const_cast<char*>(line.c_str());
	x52_settext(hdl, 2,constLine, 16);
}


	void
MFD::setPage ( MfdPage page )
{
	std::string line1(page.getLine1());
	std::string line2(page.getLine2());
	std::string line3(page.getLine3());
	MFD::setLine1(line1);
	MFD::setLine2(line2);
	MFD::setLine3(line3);
}


MfdPage::MfdPage (Msg msg)
{
	message = msg;
} 


	std::string
MfdPage::getLine1 (  )
{
	return message.title+"          ";
}	

	std::string
MfdPage::getLine2 (  )
{
	return message.actFreq0+"<>"+message.stbyFreq0;
}	

	std::string
MfdPage::getLine3 (  )
{
	return message.actFreq1+"  "+message.stbyFreq1;
}

