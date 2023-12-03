#include "ATD.hpp"

using namespace std;

void info(list first, stack second, queue third)
{
    first.print();

    second.print();

    third.print();
}

int main()
{
    list spisok = list();
    stack stek = stack();
    queue mem = queue();

    for (int i = 1; i < 6; i++) // Вставка элементов
    {
        spisok.push(i);
        stek.push(i);
        mem.push(i);
    }

    info(spisok, stek, mem);

    for (int i = 0; i < 3; i++) // Удаление
    {
        spisok.pop();
        stek.pop();
        mem.pop();
    }

    cout << "\nУдаление элементов произошло\n" << endl;

    info(spisok, stek, mem);

    cout << "\nУдаление произошло\n" << endl;

    spisok.deleting();
    stek.deleting();
    mem.deleting();

    info(spisok, stek, mem);
    
    return 0;
}