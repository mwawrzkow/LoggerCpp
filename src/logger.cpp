#include "logger.hpp"
#include <chrono>
#define _saveToFile(x, y) (x >= this->_FileLogLevel) ? this->_fileLog(y) : void()

namespace Log
{
#ifndef USE_THREADS
#ifdef SAVE_TO_FILE
    Logger::Logger(LogLevel level, const char *file)
        : logFile(file),
          _logLevel(level)
    {
    }
    void Logger::setLogFile(const char *file)
    {
        logFile.open(file);
    }
    void Logger::saveToFile(bool save)
    {
        SaveToFile = save;
    }
    void Logger::saveToFileLogLevel(LogLevel level)
    {
        _FileLogLevel = level;
    }
    void Logger::_fileLog(std::string_view message)
    {
        logFile << message << std::endl;
    }
#endif
    Logger::~Logger()
    {
#ifdef SAVE_TO_FILE
        logFile.close();
#endif
    }
    void Logger::setLogLevel(LogLevel level)
    {
        _logLevel = level;
    }
    void Logger::debug(std::string_view message)
    {
        if (_logLevel <= LogLevel::DEBUG)
            _log(this->_logColors[0], std::string_view(message));
        _saveToFile(LogLevel::DEBUG, message);
    }
    void Logger::info(std::string_view message)
    {
        if (_logLevel <= LogLevel::INFO)
            _log(this->_logColors[1], std::string_view(message));
        _saveToFile(LogLevel::INFO, message);
    }
    void Logger::warning(std::string_view message)
    {
        if (_logLevel <= LogLevel::WARNING)
            _log(this->_logColors[2], std::string_view(message));
        _saveToFile(LogLevel::WARNING, message);
    }
    void Logger::error(std::string_view message)
    {
        if (_logLevel <= LogLevel::ERROR)
            _log(this->_logColors[3], std::string_view(message));
        _saveToFile(LogLevel::ERROR, message);
    }
    void Logger::critical(std::string_view message)
    {
        if (_logLevel <= LogLevel::CRITICAL)
            _log(this->_logColors[4], std::string_view(message));
        _saveToFile(LogLevel::CRITICAL, message);
    }

    void Logger::_log(std::string_view color, std::string_view message)
    {
        std::cout << color << message << ENDCOLOR << std::endl;
    }
#else

#endif
}