#pragma once

#ifndef XCHENGSIGNAPK_UTILSLOGTYPEERROR_HPP
#define XCHENGSIGNAPK_UTILSLOGTYPEERROR_HPP

namespace x
{

inline namespace xcheng
{

class UtilsLogTypeError
        : public UtilsLogTypeI
{
private:
    constexpr static Jchar LOG_FILE[] = "./app_error.log";

    UtilsLogTypeI *mNext;

    Jbool                   mWriteMark;
    std::mutex              mWriteLock;
    std::condition_variable mWriteCond;

    Jbool                   mNotifyMark;
    std::mutex              mNotifyLock;
    std::condition_variable mNotifyCond;

    std::string mLogContent;

public:
    explicit UtilsLogTypeError(UtilsLogTypeI *v);

    void next(UtilsLogType type, const Jchar *v, Jint vLen) override;
};

UtilsLogTypeError::UtilsLogTypeError(UtilsLogTypeI *v)
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
    std::thread([](UtilsLogTypeError *self) {
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

void UtilsLogTypeError::next(UtilsLogType type, const Jchar *v, Jint vLen)
{
    std::unique_lock<std::mutex> uniqueLock(this->mNotifyLock);

    if (type != UtilsLogType::ERROR)
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

#endif //XCHENGSIGNAPK_UTILSLOGTYPEERROR_HPP
