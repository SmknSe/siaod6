#pragma once
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class list {
    class node {
    public:
        int way;
        int time;
        string num;
        double price;
        string date;
        node* next;
        node* prev;
        node(int, int, string, double, string, node* = nullptr, node* = nullptr);
    };
    node* first;
    node* last;
public:
    list();//конструктор
    bool is_empty();//проверка на пустоту списка
    void push_back(int, int, string, double, string);//вставка в конец списка
    void push(int,int,string,double,string,string);//вставка элемента в список с упорядочиванием
    void print();//вывод списка
    void print_r();//вывод списка с конца
    node* find(string);//поиск элемента по ключу
    void remove(string);//удаление элемента списка по ключу
    int count_ways(string, string, int);
    void create_list();
    ~list();//деструктор
};

