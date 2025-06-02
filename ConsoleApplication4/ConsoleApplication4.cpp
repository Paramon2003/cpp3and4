#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Queue {
private:
    vector<T> arr;
public:  
    void enqueue(const T& el) {
        arr.push_back(el);
    }

    void dequeue() {
        if (!empty()) {
            arr.erase(arr.begin());
        }
        else {
            cerr << "Очередь пуста.\n";
        }
    }

    T front() const {
        if (!empty()) {
            return arr[0];
        }
        else {
            throw out_of_range("Очередь пуста. Нет первого элемента.");
        }
    }

    bool empty() const {
        return arr.empty();
    }

    T back() const {
        if (!empty()) {
            return arr[arr.size() - 1];
        }
        else {
            throw out_of_range("Очередь пуста. Нет последнего элемента.");
        }
    }

    void pop() {
        if (!empty()) {
            arr.erase(arr.begin());
        }
        else {
            cerr << "Очередь пуста.\n";
        }
    }

    size_t size() const {
        return arr.size();
    }

    void print() const {
        for (const T& item : arr) {
            cout << item << " ";
        }
        cout << "\n";
    }

};

int main() {
    setlocale(LC_ALL, "");
    std::wcout.imbue(std::locale(""));

    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    cout << "Очередь из чисел: ";
    intQueue.print();
    intQueue.dequeue();
    cout << "После dequeue: ";
    intQueue.print();
    cout << "Первый элемент: " << intQueue.front() << "\n";
    cout << "Последний элемент: " << intQueue.back() << "\n";
    intQueue.pop();
    intQueue.print();
    cout << "Размер: " << intQueue.size() << "\n";

    Queue<string> stringQueue;
    stringQueue.enqueue("A");
    stringQueue.enqueue("B");
    stringQueue.enqueue("C");
    stringQueue.enqueue("D");
    stringQueue.enqueue("E");
    stringQueue.enqueue("F");
    cout << "Очередь из строк: ";
    stringQueue.print();
    stringQueue.dequeue();
    cout << "После dequeue: ";
    stringQueue.print();
    cout << "Первый элемент: " << stringQueue.front() << "\n";
    cout << "Последний элемент: " << stringQueue.back() << "\n";
    stringQueue.pop();
    stringQueue.print();
    cout << "Размер: " << stringQueue.size() << "\n";
}