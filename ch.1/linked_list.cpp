#include "linked_list.h"

using std::move;

void LinkedList::printList() const
{
    auto cur = head.get();

    while (cur)
    {
        std::cout << cur->val_ << " ";
        cur = cur->next.get();
    }
}

void LinkedList::push(int val)
{
    auto newNode = new ListNode(val);

    tail ? tail->next.reset(newNode) : head.reset(newNode);
    tail = newNode;
}

void LinkedList::reverse()
{
    if (!head)
        return;

    link_pointer prev = {},
                 next = {};

    while (head)
    {
        next = move(head->next);
        head->next = move(prev);
        prev = move(head);
        head = move(next);
    }
    head = move(prev);
}