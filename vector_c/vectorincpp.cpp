#include <iostream>
#include <vector>

#define N 5000000

int main() {
    std::vector<int> arr;
    arr.reserve(16);  // optional: start capacity to avoid early reallocations

    for (size_t i = 0; i < N; i++) {
        arr.push_back(static_cast<int>(i));
    }

    std::cout << "std last = " << arr[N - 1] << std::endl;

    // No need to manually free memory; std::vector manages it automatically
    return 0;
}
