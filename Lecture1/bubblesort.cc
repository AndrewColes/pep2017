#include <vector>
using std::vector;


vector<int> bubbleSort(vector<int> numbers) {
    for (int i = 0; i < numbers.size() - 1; ++i) {
        for (int j = 0; j < numbers.size() - 1 - i; ++j) {
            if (numbers[j] > numbers[j+1]) {
                //int t = numbers[j+1];
                //numbers[j+1] = numbers[j];
                //numbers[j] = t;
                
                std::swap(numbers[j], numbers[j+1]);
            }
        }
    }
    
    return numbers;
}

int main() {
    vector<int> numbers{2,10,7};
    vector<int> sorted = bubbleSort(numbers);
    for (int x : numbers) {
        cout << x << endl;
    }
}
