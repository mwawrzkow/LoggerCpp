#ifndef LOG_HPP 
#define LOG_HPP
#include "logger.hpp"



#define _LOG(x) x: public Log::Logger
#ifdef SHOULDLOG
#define LOG(x) _LOG(x)
#define LOG_CONSTRUCTOR(x,y) :Log::Logger(x, y)
#define LOG_CONSTRUCTOR_FULL(x,y) :Log::Logger(x, y)
#define DEBUG Log::LogLevel::DEBUG
#define INFO Log::LogLevel::INFO
#define WARNING Log::LogLevel::WARNING
#define ERROR Log::LogLevel::ERROR
#define CRITICAL Log::LogLevel::CRITICAL
#else
#define LOG(x) x
#define LOG_CONSTRUCTOR(x,y)
#define LOG_CONSTRUCTOR_FULL(x,y) :
#define DEBUG 
#define INFO 
#define WARNING 
#define ERROR 
#define CRITICAL 
#endif



#ifdef SHOULDLOG
#define LOG_DEBUG(x) this->debug(x)
#define LOG_INFO(x) this->info(x)
#define LOG_WARNING(x) this->warning(x)
#define LOG_ERROR(x) this->error(x)
#define LOG_CRITICAL(x) this->critical(x)
#else
#define LOG_DEBUG(x) void()
#define LOG_INFO(x) void()
#define LOG_WARNING(x) void()
#define LOG_ERROR(x) void()
#define LOG_CRITICAL(x) void()
#endif  

#endif