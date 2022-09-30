#include <iostream>
using namespace std;
#include <string>
#include <cmath>
unsigned long long int get_really_any_hexadecimal(){
    string input;
    unsigned long long int res = 0;
    getline(cin, input);
    int counter = 0;
    for(auto k = 0u; k < input.length(); k++){
        auto i = input.length() - k - 1;
        if((input[i] <= '9' && input[i] >= '0') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f') ) {
            int n;
            if(input[i] == 'A' || input[i] == 'a') {
                n = 10;
            } else if (input[i] == 'B' || input[i] == 'b') {
                n = 11;
            } else if (input[i] == 'C' || input[i] == 'c') {
                n = 12;
            } else if (input[i] == 'D' || input[i] == 'd') {
                n = 13;
            } else if (input[i] == 'E' || input[i] == 'e') {
                n = 14;
            } else if (input[i] == 'F' || input[i] == 'f') {
                n = 15;
            } else{
                n = (input[i] - '0');
            }
            res += (n * pow(16, counter));
            counter++;
        }
    }
    return res;
}
int main()
{
    cout << get_really_any_hexadecimal() << endl;
    return 0;
}




#include <iostream>
using namespace std;
struct Crystal
{
    double length;            // длина кристалла
    double width;             // характерная толщина кристалла
    unsigned int facets;      // количество граней
    unsigned long int color;  // код цвета
    unsigned int defects;     // количество дефектов
};
struct Category
{
    char name[100];                          // название категории
    double length_min, length_max;           // допустимая длина кристалла
    double width_min, width_max;             // допустимая характерная толщина кристалла
    unsigned int facets_min, facets_max;     // допустимое количество граней
    unsigned long int colors[5];             // допустимые коды цвета
    unsigned int defects_min, defects_max;   // допустимое количество дефектов
};
Category categories[10];
int determine_category(Crystal crystal){
    for(int i = 0; i < 10; i++){
        if(!((crystal.length - categories[i].length_min > -0.001) && (categories[i].length_max - crystal.length > -0.001)))
            continue;
        if(!((crystal.width - categories[i].width_min > -0.001) && (categories[i].width_max - crystal.width > -0.001)))
            continue;
        if(!((crystal.facets >= categories[i].facets_min) && (crystal.facets <= categories[i].facets_max)))
            continue;
        int count = 0;
        for(int j = 0; j < 5; j++){
            if(crystal.color == categories[i].colors[j])
                count = 1;
        }
        if(count != 1)
            continue;
        if(!((crystal.defects >= categories[i].defects_min) && (crystal.defects <= categories[i].defects_max)))
            continue;
        return i;
    }
    return -1;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> categories[i].name >> categories[i].length_min >> categories[i].length_max >> categories[i].width_min >> categories[i].width_max >> categories[i].facets_min >> categories[i].facets_max;
        for (int j = 0; j < 5; j++)
            cin >> categories[i].colors[j];
        cin >> categories[i].defects_min >> categories[i].defects_max;
    }
    int n;
    cin >> n;
    int quantities[10] = {0};
    for (int i = 0; i < n; i++)
    {
        Crystal crystal;
        cin >> crystal.length >> crystal.width >> crystal.facets >> crystal.color >> crystal.defects;
        int category = determine_category(crystal);
        if (category < 0 || category > 9)
            continue;
        quantities[category]++;
    }
    for (int i = 0; i < 10; i++)
        cout << quantities[i] << " ";
    cout << endl;
    return 0;
}

if(i == 0 && array[index][3]!= 0){
std::cout << "NO";
for(int k = 0; k < n; k++)
delete[] array[k];
delete[] indicies;
delete[] array;
return 0;
}


#include <iostream>

int main() {
    int n;
    std::cin >> n;
    long long** array = new long long *[n];
    for(int i = 0; i < n; i++){
        array[i] = new long long[4];
        std::cin >> array[i][0] >> array[i][1] >> array[i][2] >> array[i][3];
    }
    long long need;
    std::cin >> need;
    int* indicies = new int[n];
    int counter = 0;
    int needCounter = 0;
    for(int i = 0; i < n; i++){
        if(array[i][0] == need){
            needCounter++;
        }
    }
    auto includes = [&indicies](int item, int count){
        for(int i = 0; i < count; i++){
            if(indicies[i] == item){
                return true;
            }
        }
        return false;
    };

    auto min = [&n, &includes, &indicies, &counter](auto ** arr, int item, int count){
        auto minTime = 10000000000;
        auto index = -1;
        for(int i = 0; i < count; i++){
            if(arr[i][2] < minTime && !includes(i, counter) && arr[i][0] == item){
                minTime = arr[i][2];
                index = i;
            }
        }
        indicies[counter++] = index;
        return index;
    };
    int move = 0;
    for(int i = 0; i < needCounter; i++){
        auto index = min(array, need, n);
        if(array[index][3] != move){
            std::cout << "NO";
            for(int k = 0; k < n; k++)
                delete[] array[k];
            delete[] indicies;
            delete[] array;
            return 0;
        }
        if(move < 3){
            move++;
        } else{move = 0;}
    }
    std::cout << "YES";
    for(int k = 0; k < n; k++)
        delete[] array[k];
    delete[] indicies;
    delete[] array;
}


#include <iostream>

int main() {
    int n;
    std::cin >> n;
    float** data = new float*[n];
    float* persons = new float[n];
    for(int i = 0; i < n; i++){
        data[i] = new float[7];
        for(int j = 0; j < 7; j++)
            std::cin >> data[i][j];
    }
    auto minMax = [](float**arr, float person, int count){
        float mM[2] = {1000000.0, -1.0};
        for(int i = 0; i < count; i++){
            if(arr[i][1] == person){
                if(arr[i][5] < mM[0])
                    mM[0] = arr[i][5];
                if(arr[i][5] > mM[1])
                    mM[1] = arr[i][5];
            }
        }
        return mM[1] - mM[0];
    };

    auto includes = [](float* arr, float item, int count){
        for(int i = 0; i < count; i++){
            if(arr[i] == item){
                return true;
            }
        }
        return false;
    };

    auto counting = [](float** arr, float person, int count){
        int out = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i][1] == person)
                out++;
        }
        return out;
    };

    int count = 0;
    int salon = -1;
    float minMinmax = 10000000;
    for(int i = 0; i < n; i++){
        if(!includes(persons, data[i][1], n)){
            if(counting(data, data[i][1], n) != 1) {
                float res = minMax(data, data[i][1], n);
                if(res < minMinmax){
                    minMinmax = res;
                    salon = int(data[i][1]);
                }
            }
        }
        persons[count++] = data[i][1];
    }
    std::cout << salon;
    for (int i = 0; i < n; i++)
        delete[] data[i];
    delete[] data;
    delete[] persons;
    return 0;
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