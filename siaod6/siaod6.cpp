#include <iostream>
#include <algorithm>
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
            //else {//выбрана автоматическая генерация
            //    int a[7] = { 23, 15, 64, 1, 88, 32, 90 };
            //    cout << "Preset elements: ";
            //    for (int i = 0; i < 7; i++)
            //    {
            //        cout << a[i] << " ";
            //        l1.push(a[i]);
            //    }
            //    cout << "\nList generated\n";
            //}
            length = 1;
            cout << "Input command:\nPrint list - 1\nReverse print list - 2\
                \nRemove values by key - 3\nPush element - 4\
                \nCount times - 5\nPush element back - 6\nExit - 0\n";
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
            case 5://вызов функции проверки l2 на упорядоченность по возрастанию
                
                break;
            case 6://вызов функции добаления элемента в конец
                /*cout << "Enter element: "; cin >> k;
                if (c == 1) l1.push_back(k);
                else if (c == 2) l2.push_back(k);*/
                break;
            case 7://вызов функции добавления элемента в начало
                
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