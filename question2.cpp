#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> data;

    void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] > data[parent]) {
                int t = data[index];
                data[index] = data[parent];
                data[parent] = t;
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() {}

    void Add(int value) {
        data.push_back(value);
        bubbleUp(data.size() - 1);
    }

    void Print() {
        for (size_t i = 0; i < data.size(); i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

// exampale of adding elements, to see if the answer is correct
int main() {
    MaxHeap h;
    h.Add(10);
    h.Add(4);
    h.Add(15);
    h.Add(7);
    h.Add(20);
    h.Add(1);

    h.Print();

    return 0;
}
