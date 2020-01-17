#pragma once

#ifndef XCHENGSIGNAPK_UTILSLOG_HPP
#define XCHENGSIGNAPK_UTILSLOG_HPP

#include "log/UtilsLogType.hpp"
#include "log/UtilsLogTypeI.hpp"
#include "log/UtilsLogTypeInfo.hpp"
#include "log/UtilsLogTypeError.hpp"
#include "log/UtilsLogTypeDebug.hpp"

namespace x
{

inline namespace xcheng
{

class UtilsLog
{
private:
    constexpr static Jint F_ARRAY_SIZE   = 4;
    constexpr static Jint F_TIME_SIZE    = 32;
    constexpr static Jint F_LOG_ROW_SIZE = 4096;

    constexpr static Jchar T_INFO[] = "INFO";
    constexpr static Jchar T_DBUG[] = "DBUG";
    constexpr static Jchar T_ERRO[] = "ERRO";

    constexpr static Jchar DEFAULT_ARRAY_FORMAT[] = "%02X";
    constexpr static Jchar DEFAULT_TIME_FORMAT[]  = "%04d-%02d-%02d %02d:%02d:%02d";
    constexpr static Jchar DEFAULT_LOG_FORMAT[]   = "[%s] [%s] [%s]\r\n";

    UtilsLogTypeI *mTypeInfo;
    UtilsLogTypeI *mTypeError;
    UtilsLogTypeI *mTypeDebug;

    std::mutex  mUniquePass;
    std::mutex  mUniqueArrayPass;
    std::string mContent;
    std::string mArrayContent;

    Jchar mTimeFormat[F_TIME_SIZE];
    Jchar mArrayFormat[F_ARRAY_SIZE];
    Jchar mStringFormat[F_LOG_ROW_SIZE];
    Jchar mLogRowFormat[F_LOG_ROW_SIZE];

    UtilsLog();

public:
    static UtilsLog &getInstance();

    template<typename...Args>
    static void info(const Jchar *v, Args...args);

    template<typename...Args>
    static void error(const Jchar *v, Args...args);

    template<typename...Args>
    static void debug(const Jchar *v, Args...args);

    static void infoArray(const Jbyte *v, Jint vLen);

    static void debugArray(const Jbyte *v, Jint vLen);

    static void errorArray(const Jbyte *v, Jint vLen);

    template<UtilsLogType _Type, typename... Args>
    void print(const Jchar *v, Args...args);

    template<UtilsLogType _Type>
    void printArray(const Jbyte *v, Jint vLen);

    void timeFormat();
};

UtilsLog::UtilsLog()
        : mTypeInfo{}
          , mTypeError{}
          , mTypeDebug{}
          , mUniquePass{}
          , mUniqueArrayPass{}
          , mContent{}
          , mArrayContent{}
          , mTimeFormat{}
          , mArrayFormat{}
          , mStringFormat{}
          , mLogRowFormat{}
{
    this->mTypeDebug = new UtilsLogTypeDebug(nullptr);
    this->mTypeError = new UtilsLogTypeError(this->mTypeDebug);
    this->mTypeInfo  = new UtilsLogTypeInfo(this->mTypeError);
}

UtilsLog &UtilsLog::getInstance()
{
    static UtilsLog *obj = nullptr;
    if (obj == nullptr)
        obj = new UtilsLog();
    return (*obj);
}

template<typename...Args>
void UtilsLog::info(const Jchar *v, Args...args)
{
    UtilsLog::getInstance().print<UtilsLogType::INFO>(v, args...);
}

template<typename...Args>
void UtilsLog::error(const Jchar *v, Args...args)
{
    UtilsLog::getInstance().print<UtilsLogType::ERROR>(v, args...);
}

template<typename...Args>
void UtilsLog::debug(const Jchar *v, Args...args)
{
    UtilsLog::getInstance().print<UtilsLogType::DEBUG>(v, args...);
}

void UtilsLog::infoArray(const Jbyte *v, Jint vLen)
{

    UtilsLog::getInstance().printArray<UtilsLogType::INFO>(v, vLen);
}

void UtilsLog::debugArray(const Jbyte *v, Jint vLen)
{
    UtilsLog::getInstance().printArray<UtilsLogType::DEBUG>(v, vLen);
}

void UtilsLog::errorArray(const Jbyte *v, Jint vLen)
{
    UtilsLog::getInstance().printArray<UtilsLogType::ERROR>(v, vLen);
}

template<UtilsLogType _Type, typename... Args>
void UtilsLog::print(const Jchar *v, Args...args)
{
    Jint        ret  = 0;
    const Jchar *tag = nullptr;

    std::lock_guard<std::mutex> lockGuard(this->mUniquePass);

    if (v == nullptr)
        return;

    this->timeFormat();
    ret = snprintf(this->mStringFormat, sizeof(this->mStringFormat), v, args...);
    this->mContent.clear();
    this->mContent.append(this->mStringFormat, ret);

    if (_Type == UtilsLogType::INFO)
        tag = T_INFO;
    else if (_Type == UtilsLogType::ERROR)
        tag = T_ERRO;
    else if (_Type == UtilsLogType::DEBUG)
        tag = T_DBUG;

    ret = snprintf(
            this->mLogRowFormat,
            sizeof(this->mLogRowFormat),
            DEFAULT_LOG_FORMAT,
            tag,
            this->mTimeFormat,
            this->mContent.c_str()
    );

    this->mTypeInfo->next(_Type, this->mLogRowFormat, ret);
}

template<UtilsLogType _Type>
void UtilsLog::printArray(const Jbyte *v, Jint vLen)
{
    Jint i   = 0;
    Jint ret = 0;

    std::lock_guard<std::mutex> lockGuard(this->mUniqueArrayPass);

    this->mArrayContent.clear();
    for (i = 0; i < vLen; ++i)
    {
        ret = snprintf(this->mArrayFormat, sizeof(this->mArrayFormat), DEFAULT_ARRAY_FORMAT, v[i]);
        this->mArrayContent.append(this->mArrayFormat, ret);
    }

    this->print<_Type>(this->mArrayContent.c_str());
}

void UtilsLog::timeFormat()
{
    time_t nowTime   = 0;
    tm     *nowTimeS = nullptr;

    time(&nowTime);
    nowTimeS = localtime(&nowTime);
    if (nowTimeS == nullptr)
        return;

    memset(this->mTimeFormat, 0, sizeof(this->mTimeFormat));
    snprintf(
            this->mTimeFormat,
            sizeof(this->mTimeFormat),
            DEFAULT_TIME_FORMAT,
            (nowTimeS->tm_year += 1900),
            (++nowTimeS->tm_mon),
            nowTimeS->tm_mday,
            nowTimeS->tm_hour,
            nowTimeS->tm_min,
            nowTimeS->tm_sec
    );
}

}

}

#endif //XCHENGSIGNAPK_UTILSLOG_HPP
