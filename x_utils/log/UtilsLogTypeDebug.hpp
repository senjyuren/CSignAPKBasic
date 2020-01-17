#pragma once

#ifndef XCHENGSIGNAPK_UTILSLOGTYPEDEBUG_HPP
#define XCHENGSIGNAPK_UTILSLOGTYPEDEBUG_HPP

namespace x
{

inline namespace xcheng
{

class UtilsLogTypeDebug
        : public UtilsLogTypeI
{
private:
    constexpr static Jchar LOG_FILE[] = "./app_debug.log";

    UtilsLogTypeI *mNext;

    Jbool                   mWriteMark;
    std::mutex              mWriteLock;
    std::condition_variable mWriteCond;

    Jbool                   mNotifyMark;
    std::mutex              mNotifyLock;
    std::condition_variable mNotifyCond;

    std::string mLogContent;

public:
    explicit UtilsLogTypeDebug(UtilsLogTypeI *v);

private:
    void next(UtilsLogType type, const Jchar *v, Jint vLen) override;
};

UtilsLogTypeDebug::UtilsLogTypeDebug(x::UtilsLogTypeI *v)
        : mNext{v}
          , mWriteMark{}
          , mWriteLock{}
          , mWriteCond{}
          , mNotifyMark{}
          , mNotifyLock{}
          , mNotifyCond{}
          , mLogContent{}
{
    static Jbool pass = false;

    if (pass)
        return;

    pass = true;
    std::thread([](UtilsLogTypeDebug *self) {
        std::ofstream                file;
        std::unique_lock<std::mutex> uniqueLock(self->mWriteLock);

        file.open(
                LOG_FILE,
                (static_cast<Juint>(std::ios::binary)
                 | static_cast<Juint>(std::ios::out)
                 | static_cast<Juint>(std::ios::app))
        );

        do
        {
            if (!self->mWriteMark)
                self->mWriteCond.wait(uniqueLock);

            printf("%s", self->mLogContent.c_str());
            file.write(self->mLogContent.data(), self->mLogContent.size());
            file.flush();

            self->mWriteMark  = false;
            self->mNotifyMark = false;
            self->mNotifyCond.notify_one();
        } while (true);

        file.close();
    }, this).detach();
}

void UtilsLogTypeDebug::next(UtilsLogType type, const Jchar *v, Jint vLen)
{
    std::unique_lock<std::mutex> uniqueLock(this->mNotifyLock);

    if (type != UtilsLogType::DEBUG)
    {
        if (this->mNext != nullptr)
            this->mNext->next(type, v, vLen);
    } else
    {
        while (this->mNotifyMark)
            this->mNotifyCond.wait(uniqueLock);

        this->mNotifyMark = true;
        this->mLogContent.clear();
        this->mLogContent.append(v, vLen);

        this->mWriteMark = true;
        this->mWriteCond.notify_one();
    }
}

}

}

#endif //XCHENGSIGNAPK_UTILSLOGTYPEDEBUG_HPP
