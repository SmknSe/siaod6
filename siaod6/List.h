#pragma once
#include <iostream>
#include<string>
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
    list();//�����������
    bool is_empty();//�������� �� ������� ������
    void push_back(int, int, string, double, string);//������� � ����� ������
    //void push_front(int);//������� � ������ ������
    void push(int,int,string,double,string,string);//������� �������� � ������ � ���������������
    void print();//����� ������
    void print_r();//����� ������ � �����
    node* find(string);//����� �������� �� �����
    void remove(string);//�������� �������� ������ �� �����
    //void remove_on_position(int);//�������� �������� �� �������
    int count_ways(string, string);
    void create_list();
    ~list();//����������
};

