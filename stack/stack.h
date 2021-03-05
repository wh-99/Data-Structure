#ifndef __STACK_H__
#define __STACK_H__

#ifndef __TYPES__
#define __TYPES__
    using uint = unsigned int;
#endif

template <typename T>
class Stack {
    public:
        Stack(const Stack<T>&)     = delete;
        Stack(Stack<T>&&) noexcept = delete;

        Stack<T>& operator=(const Stack<T>&)     = delete;
        Stack<T>& operator=(Stack<T>&&) noexcept = delete;

        Stack();
        ~Stack() noexcept;

        void push(const T& _data);
        
        void pop();
        void clear();

        const T peek() const;

        const bool isEmpty() const;
        const uint size() const;

    private:
        template <typename U>
        struct Node {
            U data;

            Node<U>* prev;
        };

        uint cnt;

        Node<T>* tail;
};

template <typename T> Stack<T>::Stack(): cnt{}, tail{} { }
template <typename T> Stack<T>::~Stack() noexcept { clear(); }

template <typename T> void Stack<T>::push(const T& _data) {
    Node<T>* newNode = new Node<T>;

    newNode->data = _data;
    newNode->prev = tail;

    tail = newNode;

    ++cnt;
}
template <typename T> void Stack<T>::pop() {
    if (cnt) {
        Node<T>* node = tail->prev;

        delete tail;
        tail = node;

        --cnt;
    }
}
template <typename T> void Stack<T>::clear() {
    while (cnt)
        pop();
}

template <typename T> const T Stack<T>::peek() const {
    if (cnt)
        return tail->data;

    return T{};
}

template <typename T> const bool Stack<T>::isEmpty() const { return (cnt == 0); }
template <typename T> const uint Stack<T>::size() const { return cnt; }

#endif