#include "ThreadPool.h"

int compute_ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return compute_ackermann(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return compute_ackermann(m - 1, compute_ackermann(m, n - 1));
    }

    return -1;
}

int main() {
    ThreadPool pool(5);
    auto af1 = pool.enqueueTask(compute_ackermann, -1, 7);
    auto af2 = pool.enqueueTask(compute_ackermann, 1, 5);
    auto af3 = pool.enqueueTask(compute_ackermann, 2, 3);
    auto af4 = pool.enqueueTask(compute_ackermann, 3, 10);

    const auto a5 = compute_ackermann(1, 5);
    const auto a1 = af1.get();
    const auto a2 = af2.get();
    const auto a3 = af3.get();
    const auto a4 = af4.get();

    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
    std::cout << a4 << std::endl;
    std::cout << a5 << std::endl;

    return 0;
}
