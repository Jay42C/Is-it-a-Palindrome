
#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int top;
public:
    Stack() : top(-1) {}
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }
    void push(char item) {
        if (!isFull())
            data[++top] = item;
        else
            std::cerr << "Stack overflow!\n";
    }
    char pop() {
        if (!isEmpty())
            return data[top--];
        else {
            std::cerr << "Stack underflow!\n";
            return '\0'; 
        }
    }
};

class Queue {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int front, back;
public:
    Queue() : front(0), back(0) {}
    bool isEmpty() const {
        return front == back;
    }
    bool isFull() const {
        return (back + 1) % (MAX_SIZE + 1) == front;
    }
    void enqueue(char item) {
        if (!isFull()) {
            data[back] = item;
            back = (back + 1) % (MAX_SIZE + 1);
        } else
            std::cerr << "Queue is full!\n";
    }
    char dequeue() {
        if (!isEmpty()) {
            char item = data[front];
            front = (front + 1) % (MAX_SIZE + 1);
            return item;
        } else {
            std::cerr << "Queue is empty!\n";
            return '\0'; 
        }
    }
};

bool isPalindrome(const std::string& is_pali) {
    Stack stack;
    Queue queue;

    for (char c : is_pali) {
        stack.push(c);
        queue.enqueue(c);
    }

    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.pop() != queue.dequeue())
            return false;
    }

    return true;
}

int main() {
    std::string is_pali;
    std::cout << "Please enter a string and I will check if it is a palindrome:\n" ;
    std::cin >> is_pali;

    if (isPalindrome(is_pali))
        std::cout << is_pali << " is a palindrome. Great job! \n";
    else
        std::cout <<"Sorry " << is_pali << " is not a palindrome.\n";

    return 0;
}


/*
Please enter a string and I will check if it is a palindrome:
chicken
Sorry chicken is not a palindrome.

Please enter a string and I will check if it is a palindrome:
wow
wow is a palindrome. Great job! 


*/