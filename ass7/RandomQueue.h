//
// Created by Ilya Rudyak on 5/11/16.
//

#ifndef ASS7_RANDOMQUEUE_H
#define ASS7_RANDOMQUEUE_H

#include <vector>
using namespace std;

template <typename T> class RandomQueue {

public:
    RandomQueue() = default;
    void enqueue(T t);
    T dequeue();
    size_t size();
    void show();

private:
    vector<int> queue;


};

template <typename T> void RandomQueue<T>::enqueue(T t) {
    queue.push_back(t);
}
template <typename T> T RandomQueue<T>::dequeue() {
    size_t index = rand() % size();
    T temp = queue[index];
    cout << "index=" << index << " removed=" << *(queue.begin() + index) << " ";
    queue.erase(queue.begin() + index);
    return temp;
}

template <typename T> size_t RandomQueue<T>::size() {
    return queue.size();
}

template <typename T> void RandomQueue<T>::show() {
    for (int i = 0; i < queue.size(); ++i) {
        cout << queue[i] << " ";
    }
    cout << endl;
}


#endif //ASS7_RANDOMQUEUE_H
















