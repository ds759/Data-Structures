#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        this->data = new_data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void add_node(int data)
    {
        Node *node = new Node(data);
        if (this->head == nullptr)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }
        this->tail = node;
    }

    void print()
    {
        while (this->head)
        {
            std::cout << this->head->data << '\n';
            this->head = this->head->next;
        }
    }
};

int main()
{
    LinkedList *llist = new LinkedList();
    llist->add_node(1);
    llist->add_node(2);
    llist->add_node(3);
    llist->add_node(4);
    llist->add_node(5);
    llist->print();
}