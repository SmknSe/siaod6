#include "List.h"

list::node::node(int w, int t, string n, double p, string d, node* nxt, node* pr)
{
    way = w;
    time = t;
    num = n;
    price = p;
    date = d;
    next = nxt;
    prev = pr;
}

list::list()
{
    first = nullptr;
    last = nullptr;
}

bool list::is_empty()//порверка  на пустоту списка
{
    return first == nullptr;//если истина, то список пуст
}

void list::push_back(int w, int t, string n, double p, string d)//добавление элемента в конец
//функция принимает в качестве параметра ключ элемента списка
{
    node* tmp = new node(w,t,n,p,d);//создание нового элемента
    if (is_empty()) {//если список пуст, то
        first = tmp;   //новый элемент и первый, и последний
        last = tmp;
        return;
    }
    last->next = tmp;//переопределяем указатель прошлого последнего
    tmp->prev = last;
    last = tmp;//переопределяем последний элемент списка
}

void list::push(int w, int t, string n, double p, string d, string place)
{//вставка элемента в список после последнего с заданным номером
    if (is_empty()) {//если пусто
        node* tmp = new node(w, t, n, p, d);
        first = tmp;//созданный элемент и первый, и последний
        last = tmp;
        return;
    }
    else {
        node* pl = find(place);//ищем в списке эелемент с таким же номером
        if (pl!=nullptr && pl->next != nullptr) {//если элемент нашелся и не последний
            node* tmp = new node(w, t, n, p, d, pl->next, pl);
            pl->next->prev = tmp;//связываем указатели
            pl->next = tmp;
        }
        else if (pl!= nullptr) {//если нашелся и последний
            node* tmp = new node(w, t, n, p, d,nullptr, pl);
            pl->next = tmp;//связываем указатели
            last = tmp;
            return;
        }
        else {//если не нашелся
            push_back(w, t, n, p, d);//вставляем в конец
        }
    }
}

void list::print()//вывод списка
{
    if (is_empty()) return;//если пуст, то ничего печатать не нужно
    node* p = first;//создание нового элемента
    cout << setw(10) << left << "way " << setw(10) << "time " << setw(10) << "num " << setw(10) << "price " << setw(10) << "date " << endl;
    while (p) {//цикл для прохода по циклу
        cout << setw(10) << p->way << setw(10) << p->time << setw(10) << p->num << setw(10) << p->price << setw(10) << p->date << endl;//вывод очередного элемента
        p = p->next;
    }
}

void list::print_r()//вывод списка с конца
{
    if (is_empty()) return;//если пуст, то ничего печатать не нужно
    node* p = last;//создание нового элемента
    cout << setw(10) << left <<  "way " << setw(10) << "time " << setw(10) << "num " << setw(10) << "price " << setw(10) << "date " << endl;
    while (p) {//цикл для прохода по циклу
        cout << setw(10) << left << p->way << setw(10) << p->time << setw(10) << p->num << setw(10) << p->price << setw(10) << p->date << endl;//вывод очередного элемента
        p = p->prev;
    }
}

list::node* list::find(string n)//поиск элемента в списке
//функция принимает в качестве параметра ключ элемента списка
{
    if (is_empty()) return nullptr;
    node* t = last;//создание нового элемента
    while (t != nullptr && t->num != n) t = t->prev;//проходим по списку, пока не конец или не искомый элемент
    if (t!=nullptr && t->num == n) return t;//если элемент нашелся, возвращаем его
    else return nullptr;//если не нашелся, возвращаем nullptr
}

void list::remove(string n)//удаление элемента по ключу
//функция принимает в качестве параметра ключ элемента списка
{
    if (is_empty()) return;//если пуст, то удалять нечего
    while (true) {
        if (first->num == n) {//удаление первого элемента
            node* t = first;
            first->next->prev = nullptr;
            first = first->next;//переопределение первого элемента списка
            delete t;
        }
        else if (last->num == n) {//удаление последнего элемента
            node* t = first;
            while (t->next != last) t = t->next;//проход до предпоследнего элемента
            delete last;//удаление последнего
            t->next = nullptr;//переопределение указателя предпоследнего элемента
            last = t;//переопределение последнего элемента
        }
        else {//удаление в чередине списка
            node* now;
            now = find(n);//элемент перед удаляемым
            if (now == nullptr) {//если не нашли
                cout << "All elements with key " << n << " deleted" << endl;
                return;
            }
            now->next->prev = now->prev;
            now->prev->next = now->next;
            delete now;
        }
    }
}

int list::count_ways(string n, string dat, int w)
{//функция подсчета количества выходов автобуса 
    //на маршрут в течение заданного дня
    int c = 0;
    node* p = first;
    while (p) {//цикл для прохода по списку
        if (p->num == n && p->date == dat && p->way == w) c++;//если поля совпали с заданными, наакапливаем количесвто
        p = p->next;
    }
    return c;
}

void list::create_list()
{//функция ручного создания списка
    int n;
    cout << "Enter num of elements: ";
    cin >> n;//ввод количества элементов
    int w, t;
    string nm, d;
    double p;
    for (int i = 0; i < n; i++) {//цикл для ввода элементов
        cin >> w >> t >> nm >> p >> d;//ввод соответствующих элементов
        push(w, t, nm, p, d, nm);//вставка элемента в список
    }
}

list::~list()//деструктор
{
    if (!is_empty()) {
        node* t = first;
        node* now = first->next;
        while (now != nullptr) {//поочередно удаляем элементы
            first = now;
            delete t;
            now = first->next;
            t = first;
        }
        delete t;
    }
}
