#include <iostream>
#include <string>

#include "Worker.h"

int main() {
    Worker worker;

    const auto lambda1 = [](int k) {
        k += 69;
        return k;
    };

    const auto lambda2 = [](std::string s) {
        s.append(" appended str");
        return s;
    };

    auto fut1 = worker.startAsync(lambda1, 1);
    auto fut2 = worker.startAsync(lambda2, "Str");

    auto res1 = fut1.get();
    auto res2 = fut2.get();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    return 0;
}
