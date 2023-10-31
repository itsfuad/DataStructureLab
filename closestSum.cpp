#include <iostream>
#include <cmath>

int main() {
    const int arraySize = 10;
    int arr[arraySize];

    std::cout << "Enter 10 elements for the array:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    int closestSum = arr[0] + arr[1];
    int element1 = arr[0];
    int element2 = arr[1];

    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            int currentSum = arr[i] + arr[j];
            if (std::abs(currentSum) < std::abs(closestSum)) {
                closestSum = currentSum;
                element1 = arr[i];
                element2 = arr[j];
            }
        }
    }

    std::cout << "The two elements with the sum closest to zero are: " << element1 << " and " << element2 << std::endl;

    return 0;
}
