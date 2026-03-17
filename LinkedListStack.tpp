template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (top != nullptr) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    length = 0;
    //testong
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy
    if (copyObj.top == nullptr) {
        top = nullptr;
        length = 0;
        return;
    }

    Node<T>* src = copyObj.top;
    Node<T>* prev = nullptr;

    while (src != nullptr) {
        Node<T>* newNode = new Node<T>(src->data);

        if (prev == nullptr) {
            top = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
        src = src->next;
    }

    length = copyObj.length;
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    T return_val;
    (!isEmpty()) ? return_val = top->data : throw std::runtime_error("Empty stack");
    //original works, testing ternary variation
    return return_val;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) {
        throw std::runtime_error("Empty stack");
    }
    Node<T>* temp = top;
    top = top->next;
    delete temp;
    this->length--;
    //testing altered copilot suggested implementation
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    length++;
    //testing copilot suggested implementation
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty()) {
        return; // No rotation needed for an empty stack
    } //ai suggested implementation, testing
    if (dir == Stack<T>::RIGHT) {
        Node<T>* prev = nullptr;
        Node<T>* curr = top;

        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        if (prev != nullptr) {
            prev->next = nullptr; // Detach the last node
            curr->next = top; // Move the last node to the front
            top = curr; // Update the top pointer
        }
    } else if (dir == Stack<T>::LEFT) {
        Node<T>* first = top;
        top = top->next; // Move the top pointer to the second node

        if (top != nullptr) {
            first->next = nullptr; // Detach the first node

            Node<T>* curr = top;
            while (curr->next != nullptr) {
                curr = curr->next; // Traverse to the end of the stack
            }
            curr->next = first; // Move the first node to the end
        }
    }
    //testing ai suggested implementation

}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
