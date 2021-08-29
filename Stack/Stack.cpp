// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class stack {
private:
    int size;
    int *arr;
    int top;
public:
    stack(int size) {
        this->top = -1;
        this->size = size;
        arr = new int(this->size);
        for (int i = 0; i < size; i++) {
            this->arr[i] = 0;
        }


    }

    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (top == size - 1)
            return true;
        else
            return false;
    }

    void push(int element) {
        if (!isFull()) {
            top++;
            arr[top] = element;
        }
        else {
            std::cout << "Stack is full";
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty";
            return -1;

        }
        else {
            int poppedEle = arr[top];
            arr[top] = 0;
            top--;
            return poppedEle;
        }
    }

    int getElement(int pos) {
        if (isEmpty()) {
            return -1;
        }
        else {
            if (pos <= top) {
                return arr[pos - 1];
            }
        }
    }

    int count() {
        return top + 1;
    }

    void change(int pos, int element) {
        if (isFull()) {
            std::cout << "Stack is full";
            return;
        }

        arr[pos - 1] = element;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.";
            return;
        }
        std::cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
    }

};

int main()
{
    int size;
    std::cout << "What size of stack you want to create: ";
    std::cin >> size;
    stack s1(size);
    int option, element, pos;

    do {
        std::cout << "\n\nWhat operations do you want to perform.\nEnter operation number. Enter 0 to exit\n";
        std::cout << "1.Push()\n";
        std::cout << "2.Pop()\n";
        std::cout << "3.isEmpty()\n";
        std::cout << "4.isFull()\n";
        std::cout << "5.getElement()\n";
        std::cout << "6.Count()\n";
        std::cout << "7.Change()\n";
        std::cout << "8.Display()\n";
        std::cout << "9.Clear Screen()\n";

        std::cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            std::cout << "\nEnter element to push into stack: ";
            std::cin >> element;
            s1.push(element);
            std::cout << "\nElement pushed successfully!";
            break;
        case 2:
            if (s1.isEmpty()) {
                std::cout << "\nStack is empty";
            }
            else {
                std::cout << "\nPopped element is: " << s1.pop();

            }
            break;
        case 3:
            if (s1.isEmpty()) {
                std::cout << "\nStack is empty";
            }
            else {
                std::cout << "\nStack is not empty";
            }
            break;
        case 4:
            if (s1.isFull()) {
                std::cout << "\nStack is full";
            }
            else {
                std::cout << "\nStack is not full";
            }
            break;
        case 5:
            std::cout << "\nEnter position of element you want to access: ";
            std::cin >> pos;
            std::cout << "\nElement at " << pos << " is:" << s1.getElement(pos);
            break;
        case 6:
            std::cout << "\nThere are " << s1.count() << " elements in stack";
            break;
        case 7:
            std::cout << "\nEnter positio of element and element to be change: ";
            std::cin >> pos >> element;
            s1.change(pos, element);
            std::cout << "\nElement added successfully!";
            break;
        case 8:
            s1.display();
            break;
        case 9:
            system("cls");
        }

    } while (option != 0);
}



