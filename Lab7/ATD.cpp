#include <iostream>
#include "ATD.hpp"

using namespace std;

void list::push(int evalue)
{
    node *newnode = new node;

    newnode->value = evalue;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else 
    {
        node *current = head;
        
        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = newnode;
    }
}

void list::pop()
{ 
    node *tmp = head;

    try
    {
        if (tmp->next == NULL || tmp == NULL)
        {
            throw 1;
        }
    }
    catch(int i)
    {
        cout << "\nКритический случай " << i << ": удаление несуществующих элементов списка."<< endl;
        head = NULL;
        return;
    }

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NULL;
}

void list::print()
{
    node *current = head;
    int count = 0;

    cout << "Информация о списке" << endl;

    if (current != NULL)
    {
        while (current != NULL)
        {
            cout << current->value << " -> ";
            current = current->next;
            count++;
        }

        cout << endl;
    }

    cout << "Количество элементов в списке: " << count << endl << endl;
}

void list::deleting()
{
    node *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        delete head;
        head = tmp;
    }

    head = NULL;
    delete head;
}

void stack::push(int evalue)
{
    node *newnode = new node;

    newnode->value = evalue;
    newnode->next = head;
    head = newnode;
}

void stack::pop()
{
    head = head->next;
}

void stack::print()
{
    node *current = head;
    int count = 0;

    cout << "Информация о стеке" << endl;

    if (current != NULL)
    {
        while (current != NULL)
        {
            cout << current->value << " -> ";
            current = current->next;
            count++;
        }

        cout << endl;
    }

    cout << "Количество элементов в стеке: " << count << endl << endl;
}

void queue::push(int evalue)
{
    node *newnode = new node;

    newnode->value = evalue;
    newnode->next = head;
    head = newnode;
}

void queue::pop()
{
    node *tmp = head;

    try
    {
        if (tmp->next == NULL || tmp == NULL)
        {
            throw 2;
        }
    }
    catch(int i)
    {
        cout << "\nКритический случай " << i << ": удаление несуществующих элементов очереди."<< endl;
        head = NULL;
        return;
    }

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NULL;
}

void queue::print()
{
    node *current = head;
    int count = 0;

    cout << "Информация об очереди" << endl;

    if (current != NULL)
    {
        while (current != NULL)
        {
            cout << current->value << " -> ";
            current = current->next;
            count++;
        }

        cout << endl;
    }

    cout << "Количество элементов в очереди: " << count << endl << endl;
}