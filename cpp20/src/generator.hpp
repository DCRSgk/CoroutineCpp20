/*****************************************************************************
FileName            : generator.hpp
Author              : DC
Version             : 
Date Of Creation    : 2023年07月29日
Description         : 一个简单的序列生成器

Others              : TODO: 添加模板版本
Function List       : 
1.  ......
Modification History: 

Author  :
Modification  :
*****************************************************************************/

#define __cpp_lib_coroutine
#include <coroutine>
#include <exception>
#include <iostream>
#include <thread>

struct Generator {

    class ExhaustedException : std::exception
    {
    };

    struct promise_type {
        int value;
        bool is_ready = false;

        std::suspend_always initial_suspend() { return {}; };

        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(int value)
        {
            this->value = value;
            is_ready = true;
            return {};
        }

        // 为了简单，这里认为序列生成器当中不会抛出异常，所以这里不做任何处理
        void unhandled_exception()
        {
            //TODO: 添加一些异常处理
        }

        Generator get_return_object()
        {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        void return_void() {}
    };

    std::coroutine_handle<promise_type> handle;

    bool has_next()
    {
        if (handle.done())
        {
            return false;
        }

        if (!handle.promise().is_ready)
        {
            handle.resume();
        }

        if (handle.done())
        {
            return false;
        } else
        {
            return true;
        }
    }

    int next()
    {
        if (has_next())
        {
            handle.promise().is_ready = false;
            return handle.promise().value;
        }
        throw ExhaustedException();
    }

    explicit Generator(std::coroutine_handle<promise_type> handle) noexcept
        : handle(handle) {}

    Generator(Generator&& generator) noexcept
        : handle(std::exchange(generator.handle, {})) {}

    Generator(Generator&) = delete;
    Generator& operator=(Generator&) = delete;

    ~Generator()
    {
        if (handle)
            handle.destroy();
    }
};
