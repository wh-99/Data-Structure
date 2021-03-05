#ifndef __DEQUE_H__
#define __DEQUE_H__

#ifndef __TYPES__
#define __TYPES__
    using uint = unsigned int;
#endif

template <typename T>
class Deque {
    public:
        Deque(const Deque<T>&)     = delete;
        Deque(Deque<T>&&) noexcept = delete;

        Deque<T>& operator=(const Deque<T>&)     = delete;
        Deque<T>& operator=(Deque<T>&&) noexcept = delete;

        Deque();
        ~Deque() noexcept;

        void push_front(const T& _data);
        void push_back(const T& _data);

        void pop_front();
        void pop_back();
        void clear();

        const T front() const;
        const T back() const;

        const bool isEmpty() const;
        const uint size() const;

    private:
        template <typename U>
        struct Node {
            U data;

            Node<U>* next;
            Node<U>* prev;
        };

        uint cnt;

        Node<T>* head;
        Node<T>* tail;
};

template <typename T> Deque<T>::Deque(): cnt{}, head{}, tail{} { }
template <typename T> Deque<T>::~Deque() noexcept { clear(); }

template <typename T> void Deque<T>::push_front(const T& _data) {
    Node<T>* newNode = new Node<T>;

    newNode->data = _data;
    newNode->prev = { };
    newNode->next = head;

    if (cnt)
        head->prev = newNode;

    else
        tail = newNode;
    
    head = newNode;

    ++cnt;
}
template <typename T> void Deque<T>::push_back(const T& _data) {
    Node<T>* newNode = new Node<T>;

    newNode->data = _data;
    newNode->prev = tail;
    newNode->next = { };

    if (cnt)
        tail->next = newNode;

    else
        head = newNode;
    
    tail = newNode;

    ++cnt;
}

template <typename T> void Deque<T>::pop_front() {
    if (cnt) {
        Node<T>* newHead = head->next;

        delete head;
        head = newHead;

        --cnt;
    }
}
template <typename T> void Deque<T>::pop_back() {
    if (cnt) {
        Node<T>* newTail = tail->prev;

        delete tail;
        tail = newTail;

        --cnt;
    }
}   
template <typename T> void Deque<T>::clear() {
    while(cnt)
        pop_front();
}

template <typename T> const T Deque<T>::front() const {
    if (cnt)
        return head->data;
    
    return T{};
}
template <typename T> const T Deque<T>::back() const {
    if (cnt)
        return tail->data;
    
    return T{};
}

template <typename T> const bool Deque<T>::isEmpty() const { return (cnt == 0); }
template <typename T> const uint Deque<T>::size() const { return cnt; }

#endif