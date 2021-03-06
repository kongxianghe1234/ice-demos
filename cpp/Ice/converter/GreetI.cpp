// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <GreetI.h>

using namespace std;

string decodeString(const string& str)
{
    ostringstream result;
    for(string::const_iterator p = str.begin(); p != str.end(); ++p)
    {
        if(*p >= 32 && *p <= 126)
        {
            result << *p;
        }
        else
        {
            result << "\\"
                   << oct << static_cast<unsigned int>(static_cast<unsigned char>(*p));
        }
    }
    return result.str();
}

string
GreetI::exchangeGreeting(const std::string& msg, const Ice::Current&)
{
    cout << "Received (UTF-8): \"" << decodeString(msg) << '\"' << endl;
    return "Bonne journ\303\251e";
}

void
GreetI::shutdown(const Ice::Current& c)
{
    cout << "Shutting down..." << endl;
    c.adapter->getCommunicator()->shutdown();
}
