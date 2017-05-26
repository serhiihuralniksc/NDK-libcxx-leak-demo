#include <cstdio>
#include <cstdlib>
#include <memory>
#include <functional>

#define LOGI(fmt, ...) ((void) std::printf(fmt "\n", ## __VA_ARGS__))

void * operator new (std::size_t sz) {
    void *ret = std::malloc(sz);
    LOGI("%s: %zu bytes %p", __func__, sz, ret);
    return ret;
}

void * operator new[] (std::size_t sz) {
    void *ret = std::malloc(sz);
    LOGI("%s: %zu bytes %p", __func__, sz, ret);
    return ret;
}

void operator delete (void *ptr) noexcept {
    LOGI("%s: %p", __func__, ptr);
    std::free(ptr);
}

void operator delete[] (void *ptr) noexcept {
    LOGI("%s: %p", __func__, ptr);
    std::free(ptr);
}

class Foo : public std::enable_shared_from_this<Foo> {
};

int main(int, char**) {
    LOGI("begin");
    {
        Foo *p = new Foo;
        for (int i = 0; i < 5; i++) {
            auto nullDeleter = [](Foo*) { /* no-op */ }; 
            std::shared_ptr<Foo> sp(p, nullDeleter);
        }
        delete p;
    }
    LOGI("end");
}

