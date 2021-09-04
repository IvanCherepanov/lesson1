// lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//bitset: это специальный класс-контейнер, который предназначен для хранения битовых значений
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>
using namespace std;

void t2_a()
{
    // Сортировка неповторяющихся (не более 8ми) чисел в диапозоне от 0 до 7
    // с помощью битового массива
    
    
}

int main()
{
    /*
    unsigned char x = 111;
    unsigned char y = 100;

    unsigned char i = (x & y);
    unsigned char p = (x ^ y);
    unsigned char z = ~y;
    cout <<(int) z;
    */

    /*cout << "Hello World!\n";
    int o = 28;
    cout << "o=" << o << "\n";
    o = o >>1;
    cout << "o=" << o;
    */

    //1.a
    /*
    unsigned char x = 255; //8-разрядное двоичное число 11111111
    cout << "x=" <<(int) x << "\n";
    unsigned char maska = 1; //1=00000001 – 8-разрядная маска
    x = x & (~(maska << 4)); //результат x=239
    cout << "x=" << (int)x << "\n";
    */

    //1.б
   /*
   unsigned char x = 3; //8-разрядное двоичное число 00000011
   cout << "x=" <<(int) x << "\n";
   unsigned char maska = 1; //1=00000001 – 8-разрядная маска
   x = x |(maska<<7); //результат x=131; сдвиг вправо на 7 и поразрядное или
   cout << "x=" << (int)x << "\n";
   */
    
   //1.в
    /*
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   unsigned int x = 25;
   const int n = sizeof(int) * 8;
   unsigned maska = (1 << (n - 1));
   cout << "Начальный вид числа: " << bitset<n>(x)<<endl;
   cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
   cout << "Результат : ";
   for (int i = 1; i <= n; i++)
   {
       //cout << (x & maska)<<"++";
       //cout << (x & maska);
       cout << ((x & maska) >> (n - i));
       //cout << " ";
       maska = maska >> 1;//маска сдвигается на разряд вправо
   }
   cout << endl;
   system("pause");
   return 0;
   */

    //2.а
  /*
    int n = 0, input = 0;
    unsigned int x = 0; //8-разрядное двоичное число 11111111
    cout << "x=" << (int)x << "\n";
    unsigned char maska = 1 << 7; //1=00000001 – 8-разрядная маска
    cout << int(maska) << endl;

    cin >> n; // Количество вводимых чисел

    for (int i = 0; i < n; i++) {
        cin >> input;
        x = x | ((maska >> input));
    }
    //x = x & ((maska << 4)); //результат x=239
    cout << "x=" << (int)x << "\n";
    cout << "Новое число: " << bitset<8>(x) << endl;
    cout << "Новое: " << bitset<8>(x)[4] << endl;

    for (int i = 7; i >= 0; i--)
    {
        if (bitset<8>(x)[i] != 0) {
            cout << 7-i << ' '; // Вывод осортированной последовательности

        }

    }
*/
    
    //2.б
    /*
    int n = 0, input = 0;
    unsigned long long int x = 0; //8-разрядное двоичное число 11111111
    cout << "x=" << (int)x << "\n";
    unsigned long long int one = 1;
    unsigned long long int maska = one<<63; //1=00000001 – 8-разрядная маска
    
    //cout << (maska) << endl;

    cin >> n; // Количество вводимых чисел

    for (int i = 0; i < n; i++) {
        cin >> input;
        x = x | ((maska >> input));
    }
    //x = x & ((maska << 4)); //результат x=239
    cout << "x=" << (int)x << "\n";
    cout << "Новое число: " << bitset<64>(x) << endl;
    cout << "Новое: " << bitset<64>(x)[4] << endl;

    for (int i = 63; i >= 0; i--)
    {
        if (bitset<64>(x)[i] != 0) {
            cout << 63 - i << ' '; // Вывод осортированной последовательности

        }

    }
    */

    //2.в
    /*
    unsigned char x[8]="";
    
    int n = 0, input = 0;
    //unsigned long long int x = 0; //8-разрядное двоичное число 11111111
    cout << "x=" << (int)x << "\n";
    unsigned char one = 1;
    unsigned char maska = one << 7; //1=00000001 – 8-разрядная маска

    cout << bitset<8>(maska) << endl;
    cout << endl << bitset<8>(maska >> 3);

    cin >> n; // Количество вводимых чисел

    for (int i = 0; i < n; i++) {
        cin >> input;
        int help_ost = input % 8;
        int help_whole_part = input / 8;
        x[help_whole_part] = x[help_whole_part] | ((maska >> help_ost));
    }
    int i = 0, j = 0;
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << bitset<8>(x[i]);
    }
    cout << endl;
    for (i = 0; i < 8; i++) {
        for (int j = 7; j >0; j--)
        {
            if (bitset<8>(x[i])[j] != 0) {
                cout << 8 * i + (7-j) << ' '; // Вывод осортированной последовательности

            }

        }
    }
*/

    //3
    
   
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
