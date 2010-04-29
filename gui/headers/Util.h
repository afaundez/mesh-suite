#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

namespace Util
{
    static unsigned int DEBUG = 1;

    static void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
    {
        std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        std::string::size_type pos     = str.find_first_of(delimiters, lastPos);
        while (std::string::npos != pos || std::string::npos != lastPos)
        {
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            lastPos = str.find_first_not_of(delimiters, pos);
            pos = str.find_first_of(delimiters, lastPos);
        }
    }

    static int isDebugging()
    {
        return DEBUG;
    }

    static void dlog(const char * format, ...)
    {
        if ( isDebugging() )
        {
            va_list args;
            va_start (args, format);
            vprintf (format, args);
            va_end (args);
        }
        return;
    }
}

#endif // UTIL_H
