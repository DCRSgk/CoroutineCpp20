# CoroutineCpp20
> 协程相关学习笔记 附相关demo辅助学习用
## 参考链接:

> -  cppreference:https://en.cppreference.com/w/cpp/language/coroutines
> -  BennyHuo的专栏渡劫C++协程:https://www.bennyhuo.com/book/cpp-coroutines/00-foreword.html





## How to use

- 确保gcc版本在10或者更高
    > - sudo apt install software-properties-common
    > - sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    > - sudo apt update
    > - sudo apt install gcc-11 g++-11
    > - sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 60 --slave /usr/bin/g++ g++ /usr/bin/g++-11
- 自行安装cmake、clang-format
- 编译: 执行: `build20.sh` 
- 进入 /cpp20/build/
- ./cpp20 执行

TODO: 
- 测试协程和普通线程切换的消耗
- 
