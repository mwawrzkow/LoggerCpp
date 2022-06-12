#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string_view>
#include <iostream>
#include <fstream>
#include <chrono>
#include <array>

// Color definitions
#define DEBUGCOLOR "\033[1;34m"
#define INFOCOLOR "\033[1;32m"
#define WARNINGCOLOR "\033[1;33m"
#define ERRORCOLOR "\033[1;31m"
#define CRITICALCOLOR "\033[1;35m"
#define ENDCOLOR "\033[0m"

#ifdef USE_THREADS
#include <thread>
#endif

namespace Log
{
    enum class LogLevel
    {
        DEBUG = 0,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };
#ifndef USE_THREADS
    class Logger
    {
    private:
        const char **_logColors = new const char *[5]
        {
            DEBUGCOLOR,
                INFOCOLOR,
                WARNINGCOLOR,
                ERRORCOLOR,
                CRITICALCOLOR
        };
#ifdef SAVE_TO_FILE
        bool SaveToFile = true;
#endif
    public:
        Logger() = default;
#ifdef SAVE_TO_FILE
        Logger(LogLevel level, const char *file);
        void setLogFile(const char *file);
        void saveToFile(bool);
        void saveToFileLogLevel(LogLevel);
#endif
        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;
        ~Logger();
        void debug(std::string_view message);
        void info(std::string_view message);
        void warning(std::string_view message);
        void error(std::string_view message);
        void critical(std::string_view message);
        void setLogLevel(LogLevel level);

    private:
#ifdef SAVE_TO_FILE
        std::ofstream logFile;
        LogLevel _FileLogLevel = LogLevel::DEBUG;
        void _fileLog(std::string_view message);
#endif
        LogLevel _logLevel = LogLevel::WARNING;
        void _log(std::string_view color, std::string_view message);
    };

#else
    class LoggerThread
    {
    };
#endif
#endif
};