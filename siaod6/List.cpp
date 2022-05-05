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

bool list::is_empty()//��������  �� ������� ������
{
    return first == nullptr;//���� ������, �� ������ ����
}

void list::push_back(int w, int t, string n, double p, string d)//���������� �������� � �����
//������� ��������� � �������� ��������� ���� �������� ������
{
    node* tmp = new node(w,t,n,p,d);//�������� ������ ��������
    if (is_empty()) {//���� ������ ����, ��
        first = tmp;   //����� ������� � ������, � ���������
        last = tmp;
        return;
    }
    last->next = tmp;//�������������� ��������� �������� ����������
    tmp->prev = last;
    last = tmp;//�������������� ��������� ������� ������
}
//
//void list::push_front(int n)
//{
//    node* p = new node(n);
//    if (is_empty()) {
//        first = p;
//        last = p;
//        return;
//    }
//    p->next = first;
//    first = p;
//}

void list::push(int w, int t, string n, double p, string d, string place)
{
    if (is_empty()) {
        node* tmp = new node(w, t, n, p, d);
        first = tmp;
        last = tmp;
        return;
    }
    else {
        node* pl = find(place);
        if (pl!=nullptr && pl->next != nullptr) {
            node* tmp = new node(w, t, n, p, d, pl->next, pl);
            pl->next->prev = tmp;
            pl->next = tmp;
        }
        else if (pl!= nullptr) {
            node* tmp = new node(w, t, n, p, d,nullptr, pl);
            pl->next = tmp;
            last = tmp;
            return;
        }
        else {
            push_back(w, t, n, p, d);
        }
    }
}

void list::print()//����� ������
{
    if (is_empty()) return;//���� ����, �� ������ �������� �� �����
    node* p = first;//�������� ������ ��������
    while (p) {//���� ��� ������� �� �����
        cout << p->way << " " << p->time << " " << p->num << " " << p->price << " " << p->date << endl;//����� ���������� ��������
        p = p->next;
    }
}

void list::print_r()//����� ������
{
    if (is_empty()) return;//���� ����, �� ������ �������� �� �����
    node* p = last;//�������� ������ ��������
    while (p) {//���� ��� ������� �� �����
        cout << p->way << " " << p->time << " " << p->num << " " << p->price << " " << p->date << endl;//����� ���������� ��������
        p = p->prev;
    }
}

list::node* list::find(string n)//����� �������� � ������
//������� ��������� � �������� ��������� ���� �������� ������
{
    if (is_empty()) return nullptr;
    node* t = last;//�������� ������ ��������
    while (t != nullptr && t->num != n) t = t->prev;//�������� �� ������, ���� �� ����� ��� �� ������� �������
    if (t!=nullptr && t->num == n) return t;//���� ������� �������, ���������� ���
    else return nullptr;//���� �� �������, ���������� nullptr
}

void list::remove(string n)//�������� �������� �� �����
//������� ��������� � �������� ��������� ���� �������� ������
{
    if (is_empty()) return;//���� ����, �� ������� ������
    if (first->num == n) {//�������� ������� ��������
        node* t = first;
        first = first->next;//��������������� ������� �������� ������
        delete t;
    }
    else if (last->num == n) {//�������� ���������� ��������
        node* t = first;
        while (t->next != last) t = t->next;//������ �� �������������� ��������
        delete last;//�������� ����������
        t->next = nullptr;//��������������� ��������� �������������� ��������
        last = t;//��������������� ���������� ��������
    }
    else {//�������� � �������� ������
        node* now;
        while(true) {
            now = find(n);//������� ����� ���������
            if (now == nullptr) {//���� �� �����
                cout << n << "no more" << endl;
                return;
            }
            now->next->prev = now->prev;
            now->prev->next = now->next;
            delete now;          
        }
    }
}

int list::count_ways(string n, string dat)
{
    int c = 0;
    node* p = first;
    while (p) {
        if (p->num == n && p->date == dat) c++;
        p = p->next;
    }
    return c;
}

void list::create_list()
{
    int n;
    cout << "Enter num of elements: ";
    cin >> n;
    int w, t;
    string nm, d;
    double p;
    for (int i = 0; i < n; i++) {
        cin >> w >> t >> nm >> p >> d;
        if (find(nm)==nullptr) push_back(w, t, nm, p, d);
        else push(w, t, nm, p, d, nm);
    }
}

list::~list()//����������
{
    if (!is_empty()) {
        node* t = first;
        node* now = first->next;
        while (now != nullptr) {//���������� ������� ��������
            first = now;
            delete t;
            now = first->next;
            t = first;
        }
        delete t;
    }
}
