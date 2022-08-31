#include <iostream>
#include <memory> 

struct ListNode {
    using pointer = std::unique_ptr<ListNode>;

    int val_;
    pointer next = {};

    ListNode() : val_(0){};
    ListNode(int val) : val_(std::move(val)){};
};

class LinkedList {
    using link_pointer = typename ListNode::pointer;

private:
    link_pointer head = {};
    ListNode *tail;

public:
    LinkedList() : tail(nullptr){};
    ~LinkedList() = default;

    void printList() const;
    void push(int val);
    void reverse();
};