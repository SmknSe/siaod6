#include <iostream>
#include <algorithm>
#include<iomanip>
#include "List.h"

using namespace std;

int main()
{
    list l1;
    int length = 0,c;
    string k;
    int w, t;
    double p;
    string nm, d;
    bool fill = 1;
    while (true) {
        if (length == 0) {//первый ввод
            cout << "Input list generation command (1-input,2-auto generation):" << endl;
            cin >> c;
            if (c == 1) {//выюран ручной ввод
                l1.create_list();
            }
            else {//выбрана автоматическая генерация
                int way[7] = { 23, 15, 64, 1, 88, 32, 23 };
                int time[7] = { 1, 2, 3, 4, 5, 6, 7 };
                string num[7] = { "a123aa","b234bb","c345cc","d456dd","e567ee","f678ff","a123aa" };
                double price[7] = { 10, 20, 30, 40, 50, 60, 70 };
                string date[7] = { "mn","tu","wd","th","fr","str","mn"};
                cout << "Preset elements: \n";
                cout << setw(10) << left << "way " << setw(10) << "time " << setw(10) << "num " << setw(10) << "price " << setw(10) << "date " << endl;
                bool f = true;
                for (int i = 0; i < 7; i++)
                {
                    cout << setw(10) << way[i] << setw(10) << time[i] << setw(10) << num[i] << setw(10) << price[i] << setw(10) << date[i] << endl;
                    if (f) l1.push_back(way[i],time[i],num[i],price[i],date[i]);
                    else l1.push(way[i], time[i], num[i], price[i], date[i],num[i]);
                }
                cout << "\nList generated\n";
            }
            length = 1;
            cout << "Input command:\nPrint list - 1\nReverse print list - 2\
                \nRemove values by key - 3\nPush element - 4\
                \nCount times - 5\nExit - 0\n";
        }
        else {
            cout << "Command: "; cin >> c;
            switch (c)
            {
            case 1://вызов функции вывода
                l1.print();
                break;
            case 2://вызов функции вывода с конца
                l1.print_r();
                break;
            case 3://вызов функции удаления элементов по ключу
                cout << "Enter key: "; cin >> k;
                l1.remove(k);
                break;
            case 4://вызов функции вставки элемента в список
                cout << "Input element: ";
                cin >> w >> t >> nm >> p >> d;
                l1.push(w, t, nm, p, d, nm);
                break;
            case 5://вызов функции подсечта выходов на маршрут
                cout << "Enter key: "; cin >> k;
                cout << "Enter date: "; cin >> d;
                cout << "Enter way (int): "; cin >> w;
                cout << "Bus has gone: " << l1.count_ways(k, d, w) << " times" << endl;
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "Incorrect value\n";
                break;
            }
        }
    }
    return 0;
}