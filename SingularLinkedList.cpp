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

    LinkedList();

    void add_first(int data);
    void add(int data);
    void add(int data, int index);

    int get_first();
    void print();
};

LinkedList::LinkedList(void)
{
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::add_first(int data)
{
    Node *node = new Node(data);
    node->next = this->head;
    this->head = node;
}
void LinkedList::add(int data)
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

void LinkedList::add(int data, int index)
{
    Node *node = new Node(data);
    int i = 1;
    Node *n = this->head;
    while (i < index)
    {
        n = n->next;
        i++;
    }
    node->next = n->next;
    n->next = node;
}

int LinkedList::get_first()
{
    return this->head->data;
}

void LinkedList::print()
{
    Node *temp = this->head;
    while (this->head)
    {
        std::cout << this->head->data << '\n';
        this->head = this->head->next;
    }
    this->head = temp;
}

int main()
{
    LinkedList *llist = new LinkedList();
    llist->add(1);
    llist->add(2);
    llist->add(4);
    llist->add(5);
    llist->add(6);
    llist->add(3, 2);
    llist->add_first(0);
    llist->print();
    int first = llist->get_first();
    std::cout << first << '\n';
}