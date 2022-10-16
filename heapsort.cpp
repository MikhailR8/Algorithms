#include <iostream>
#include <vector>


void replace(int index1, int index2, std::vector<int>& array) {
    array[index1] = array[index1] + array[index2];
    array[index2] = array[index1] - array[index2];
    array[index1] = array[index1] - array[index2];
}

std::vector<int> siftingUp(std::vector<int> array, int index) {
    std::vector<int> out = array;
    for (int i = index; i > 0;) {
        if (out[i] <= out[(i - 1) / 2]) return out;
        else {
            replace(out[i], out[(i - 1) / 2], out);
            i = (i - 1) / 2;
        }
    }
    return out;
}

std::vector<int> siftingDown(std::vector<int> array, int index) {
    std::vector<int> out = array;
    for (int i = 0;;) {
        if ((2*i + 1) > index) return out;
        else if ((2 * i + 2) > index) {
            if (out[i] < out[2 * i + 1]) {
                replace(out[i], out[2*i+1], out);
            }
            return out;
        }
        if (out[i] >= out[2*i+1] && out[i] >= out[2*i + 2]) return out;
        else {
            if (out[2 * i + 1] > out[2 * i + 2]) {
                replace(out[i], out[(2 * i + 1)], out);
                i = 2 * i + 1;
            }
            else {
                replace(out[i], out[2 * i + 2], out);
                i = 2 * i + 2;
            }
        }
    }
    return out;
}

std::vector<int> heapsort(std::vector<int> array) {
    std::vector<int> sorted;
    auto lastElement = array.size() - 1;
    for (auto i = 0; i < array.size(); i++) {
        sorted.push_back(array[i]);
        sorted = siftingUp(sorted, i);
    }
    for (auto i = 0; i < array.size(); i++) {
        replace(sorted[0], sorted[lastElement], sorted);
        lastElement--;
        sorted = siftingDown(sorted, lastElement);
    }
    return sorted;

}
int main() {
    std::vector<int> arr = { 24, 48, 87, 78, 12, 120 };
    arr = heapsort(arr);
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    return 0;
}