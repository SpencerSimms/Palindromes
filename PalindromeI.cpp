#include "PalindromeI.hpp"

struct stackNode {  // struct for stackNode
   char value;
   stackNode* next;
   stackNode(char nodeVal) {  // constructor for stackNode
        value = nodeVal;  // initializes value to given character passed as argument
        next = nullptr;
   }
};

class stack {
private:
    stackNode* top;
public:
    stack(const std::string& s);
    ~stack();
    void push(char);
    char pop();
    bool isEmpty();
};

stack::stack(const std::string& s) {
    top = nullptr;
    for (int i = 0; i < s.length(); i++) {
        push(s[i]);
    }
}

stack::~stack() {  // stack destructor
    stackNode* nodePtr;
    stackNode* nextNode;
    nodePtr = top;
    while(nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void stack::push(char newVal) {
    stackNode* newNode = new stackNode(newVal);
    if (isEmpty()) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

char stack::pop() {
    stackNode* temp = nullptr;
    if (isEmpty())
        throw "Stack is empty\n";
    else {
        char val = top->value;
        temp = top->next;
        delete top;
        top = temp;
        return val;
    }
}

bool stack::isEmpty() {
    if (top == nullptr)
        return true;
    else
        return false;
}

class queue {
private:
    char* queueArray;
    int qSize;
    int f, r;
    int numItems;
public:
    queue(int, const std::string&);
    ~queue();
    void enqueue(char);
    char dequeue();
    bool isEmpty();
    int getSize();
};

queue::queue(int sLength, const std::string& s) {
    queueArray = new char[sLength];
    qSize = sLength;
    f = 0;
    r = 0;
    numItems = 0;
    for (int i = 0; i < sLength; i++) {
        enqueue(s[i]);
    }
}

queue::~queue() {
    delete [] queueArray;
}

void queue::enqueue(char newVal) {
    if (numItems < qSize) {
        queueArray[r] = newVal;
        r = (r + 1) % qSize;
        numItems++;
    } else {
        throw "Queue is full\n";
    }
}

char queue::dequeue() {
    if (isEmpty()) {
        throw "Queue is empty\n";
    } else {
        char val = queueArray[f];
        f = (f + 1) % qSize;
        numItems--;
        return val;
    }
}

bool queue::isEmpty() {
    if (numItems == 0) {
        return true;
    } else {
        return false;
    }
}

int queue::getSize() {
    return qSize;
}

int PalindromeI::test_string(const std::string& s) {
    int matchCount = 0;
    stack wordStack(s);
    queue wordQueue(s.length(), s);
    for (int i = 0; i < s.length(); i++) {
        if (wordStack.pop() == wordQueue.dequeue()) {
            matchCount++;
        } else {
            return matchCount;
        }
    }
    return -1;
}