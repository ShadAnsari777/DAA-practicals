#include <iostream>
#include <algorithm>
#include <vector>

void bucketSort(std::vector<int>& arr, int numBuckets) {
    // Determine minimum and maximum values in the array
    int minValue = arr[0];
    int maxValue = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        else if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Determine the range of each bucket
    double range = (double)(maxValue - minValue + 1) / numBuckets;

    // Create the buckets and distribute the elements
    std::vector<std::vector<int>> buckets(numBuckets);
    for (int i = 0; i < arr.size(); i++) {
        int bucketIndex = (int)((arr[i] - minValue) / range);
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < numBuckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Merge the sorted buckets into the final sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // Example usage
    std::vector<int> arr = { 3, 6, 1, 8, 4, 9, 2, 5, 7 };
    int numBuckets = 3;
    bucketSort(arr, numBuckets);

    // Print the sorted array
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
