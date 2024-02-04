#pragma once

class AppCore
{
public:
    static AppCore& instance();
    int add(int a, int b);

private:
    AppCore() = default;
    ~AppCore() = default;
    AppCore(const AppCore& other) = delete;
    AppCore& operator=(const AppCore& other) = delete;
    AppCore(const AppCore&& other) = delete;
    AppCore& operator=(const AppCore&& other) = delete;
};

