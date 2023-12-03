#include <iostream>

using namespace std;

typedef struct node
{
    int value;
    node *next;
} node;

class list
{
    protected:
        node *head;
    public:
        list(): head(NULL)
        {
    
        }
        virtual void push(int evalue);
        virtual void pop();
        virtual void print();
        void size();
        void deleting(); 
};

class stack: public list
{
    public:
        stack(): list()
        {   

        }
        virtual void push(int evalue);
        virtual void pop();
        virtual void print();
};

class queue: public list
{
    public:
        queue(): list()
        {

        }
        virtual void push(int evalue);
        virtual void pop();
        virtual void print();
};
