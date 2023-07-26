#include<exception>
template<typename T>
struct Result {
    explict Result() = default;

    explict Result(T &&value) : _value(value) {}
    

}