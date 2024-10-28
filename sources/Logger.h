#ifndef LOGGER
#define LOGGER
#include "stdint.h"

enum class LogLevel : uint8_t
{
    LOG_TRACE = 0, 
    LOG_DEBUG = 1,
    LOG_INFO = 2,
    LOG_WARN = 3,
    LOG_ERROR = 4 
};

class Logger
{

};
#endif