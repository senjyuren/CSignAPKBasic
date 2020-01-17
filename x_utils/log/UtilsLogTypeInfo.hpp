#pragma once

#ifndef XCHENGSIGNAPK_UTILSLOGTYPEINFO_HPP
#define XCHENGSIGNAPK_UTILSLOGTYPEINFO_HPP

namespace x
{

inline namespace xcheng
{

class UtilsLogTypeInfo
        : public UtilsLogTypeI
{
private:
    constexpr static Jchar LOG_FILE[] = "./app_info.log";

    UtilsLogTypeI *mNext;

    Jbool                   mWirteMark;
    std::mutex              mWriteLock;
    std::condition_variable mWriteCond;

    Jbool                   mNotifyMark;
    std::mutex              mNofityLock;
    std::condition_variable mNotifyCond;

    std::string mLogContent;

public:
    explicit UtilsLogTypeInfo(UtilsLogTypeI *v);

    void next(UtilsLogType type, const Jchar *v, Jint vLen) override;
};

UtilsLogTypeInfo::UtilsLogTypeInfo(UtilsLogTypeI *v)
        : mNext{v}
          , mWirteMark{}
          , mWriteLock{}
          , mWriteCond{}
          , mNotifyMark{}
          , mNofityLock{}
          , mNotifyCond{}
          , mLogContent{}
{
    static Jbool pass = false;

    if (pass)
        return;

    pass = true;
    std::thread([](UtilsLogTypeInfo *self) {
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
            if (!self->mWirteMark)
                self->mWriteCond.wait(uniqueLock);

            printf("%s", self->mLogContent.c_str());
            file.write(self->mLogContent.data(), self->mLogContent.size());
            file.flush();

            self->mWirteMark  = false;
            self->mNotifyMark = false;
            self->mNotifyCond.notify_one();
        } while (true);

        file.close();
    }, this).detach();
}

void UtilsLogTypeInfo::next(UtilsLogType type, const Jchar *v, Jint vLen)
{
    std::unique_lock<std::mutex> uniqueLock(this->mNofityLock);

    if (type != UtilsLogType::INFO)
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

        this->mWirteMark = true;
        this->mWriteCond.notify_one();
    }
}

}

}

#endif //XCHENGSIGNAPK_UTILSLOGTYPEINFO_HPP
