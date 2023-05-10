#include <iostream>
#include <vector>

void radixSort(std::vector<int>& arr) {
    int maxDigits = 0;
    for (int num : arr) {
        int digits = 0;
        while (num > 0) {
            num /= 10;
            digits++;
        }
        maxDigits = std::max(maxDigits, digits);
    }

    std::vector<int> temp(arr.size());
    int exp = 1;
    for (int i = 0; i < maxDigits; i++) {
        std::vector<int> count(10);

        for (int num : arr) {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }

        for (int j = arr.size() - 1; j >= 0; j--) {
            int digit = (arr[j] / exp) % 10;
            temp[count[digit] - 1] = arr[j];
            count[digit]--;
        }

        for (int j = 0; j < arr.size(); j++) {
            arr[j] = temp[j];
        }

        exp *= 10;
    }
}

int main() {
    // Example usage
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    radixSort(arr);

    // Print the sorted array
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
