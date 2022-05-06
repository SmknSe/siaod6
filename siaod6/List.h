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
    list();//�����������
    bool is_empty();//�������� �� ������� ������
    void push_back(int, int, string, double, string);//������� � ����� ������
    void push(int,int,string,double,string,string);//������� �������� � ������ � ���������������
    void print();//����� ������
    void print_r();//����� ������ � �����
    node* find(string);//����� �������� �� �����
    void remove(string);//�������� �������� ������ �� �����
    int count_ways(string, string, int);
    void create_list();
    ~list();//����������
};

