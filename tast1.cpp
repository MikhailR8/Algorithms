#include <iostream>

int main() {
    int n;
    std::cin >> n;
    float** data = new float*[n];
    for(int i = 0; i < n; i++){
        data[i] = new float[7];
        for(int j = 0; j < 7; j++)
            std::cin >> data[i][j];
    }
    auto minMax = [](float**arr, float person, int count){
        float min = 1000000.0, max = -1.0;
        for(int i = 0; i < count; i++){
            if(arr[i][1] == person){
                if(arr[i][5] < min)
                    min = arr[i][5];
                if(arr[i][5] > max)
                    max = arr[i][5];
            }
        }
        return max - min;
    };

    auto counting = [](float** arr, float person, int count){
        int out = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i][1] == person)
                out++;
        }
        return out;
    };

    int salon = -1;
    float minMinmax = 10000000;
    for(int i = 0; i < n; i++){
        if(counting(data, data[i][1], n) != 1) {
            float res = minMax(data, data[i][1], n);
            if(res < minMinmax){
                minMinmax = res;
                salon = int(data[i][1]);
            }
        }
    }
    std::cout << salon;
    for (int i = 0; i < n; i++)
        delete[] data[i];
    delete[] data;
    return 0;
}