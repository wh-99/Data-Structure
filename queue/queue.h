#ifndef __QUEUE_H__
#define __QUEUE_H__

#ifndef __TYPES__
#define __TYPES__
    using uint = unsigned int;
#endif

template <typename T>
class Queue {
    public:
        Queue();
        ~Queue() noexcept;

        void push(const T& _data);
        void pop();
        void clear();

        const bool isEmpty() const;
        const uint size() const;

        const T peek() const;

    private:
        template <typename U>
        struct Node {
            U data;

            Node<U>* next;
        };

        uint cnt;

        Node<T>* head;
        Node<T>* tail;
};

template <typename T> Queue<T>::Queue(): cnt{}, head{}, tail{} { }
template <typename T> Queue<T>::~Queue() noexcept { clear(); }

template <typename T> void Queue<T>::push(const T& _data) {
    Node<T>* newNode = new Node<T>;

    newNode->data = _data;
    newNode->next = nullptr;

    if (cnt)
        tail->next = newNode;

    else
        head = newNode;

    tail = newNode;

    ++cnt;
}
template <typename T> void Queue<T>::pop() {
    if (cnt) {
        Node<T>* node = head->next;

        delete head;
        head = node;

        --cnt;
    }
}
template <typename T> void Queue<T>::clear() {
    while (cnt)
        pop();
}

template <typename T> const bool Queue<T>::isEmpty() const { return (cnt == 0); }
template <typename T> const uint Queue<T>::size() const { return cnt; }

template <typename T> const T Queue<T>::peek() const {
    if (cnt)
        return head->data;
    
    return T{};
}

#endif