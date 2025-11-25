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

    void bubbleDown(int index) {
        int size = data.size();
        while (true) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int largest = index;

            if (left < size && data[left] > data[largest])
                largest = left;
            if (right < size && data[right] > data[largest])
                largest = right;

            if (largest != index) {
                int t = data[index];
                data[index] = data[largest];
                data[largest] = t;
                index = largest;
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

    int RemoveMax() {
        if (data.empty())
            return -1;

        int maxValue = data[0];
        data[0] = data[data.size() - 1];
        data.pop_back();

        if (!data.empty())
            bubbleDown(0);   

        return maxValue;
    }

    void Print() {
        for (size_t i = 0; i < data.size(); i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

// Add the <remove the element> part, to see if the largest element is removed successfully
int main() {
    MaxHeap h;
    h.Add(10);
    h.Add(4);
    h.Add(15);
    h.Add(7);
    h.Add(20);
    h.Add(1);

    h.Print();

    cout << "Removed max: " << h.RemoveMax() << endl; // New function. I removed the largest element
    h.Print();

    return 0;
}
