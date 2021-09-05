// lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//bitset: это специальный класс-контейнер, который предназначен для хранения битовых значений
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <bitset>
#include <fstream>
#include <string> 
using namespace std;

 //1.a
// как установить 5-й бит произвольного целого числа в 0 
void task1_a()
{
   
    unsigned char x = 255; //8-разрядное двоичное число 11111111
    cout << "x=" <<(int) x << "\n";
    unsigned char maska = 1; //1=00000001 – 8-разрядная маска
    x = x & (~(maska << 4)); //результат x=239
    cout << "x=" << (int)x << "\n"; 
}

 //1.b
 //установкf 7-го бита числа в 1.
void task1_b() {
   
  unsigned char x = 3; //8-разрядное двоичное число 00000011
  cout << "x=" <<(int) x << "\n";
  unsigned char maska = 1; //1=00000001 – 8-разрядная маска
  x = x |(maska<<7); //результат x=131; сдвиг вправо на 7 и поразрядное или
  cout << "x=" << (int)x << "\n";
}

//1.в
//получаем битовое представление в 32-разрядной сетке
void task1_c() {
   unsigned int x = 125;
   const int n = sizeof(int) * 8;//маска в представление битовом
   unsigned maska = (1 << n - 1);//свдигаем 1 в начало
   cout << "Начальный вид числа: " << bitset<n>(x)<<endl;
   cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
   cout << "Результат : ";
   for (int i = 1; i <= n; i++)
   {
       cout << ((x & maska) >> (n - i));//выполняем поразрядное "и"->сдвигаем до одной позиции->получаем бит числа
       maska = maska >> 1;//маска сдвигается на разряд слева направо
   }
   cout << endl;
   system("pause");
  
}

//2.а
//Сортировка последовательности чисел с помощью битового массива набора 8-ми чисел
void task2_a() {
   int n = 0, input = 0;
   unsigned int x = 0; //8-разрядное двоичное число 00000000
   //cout << "x=" << (int)x << "\n";
   unsigned char maska = 1 << 7; //1=10000000 – 8-разрядная маска
   //cout << int(maska) << endl;

   cin >> n; // Количество вводимых чисел

   for (int i = 0; i < n; i++) {
       cin >> input;
       x = x | ((maska >> input));
   }

   //cout << "x=" << (int)x << "\n";
   //cout << "Новое число: " << bitset<8>(x) << endl;
   //cout << "Новое: " << bitset<8>(x)[4] << endl;

   for (int i = 7; i >= 0; i--)
   {
       if (bitset<8>(x)[i] != 0) {
           cout << 7-i << ' '; // Вывод осортированной последовательности
       }
   }
}

//2.б
//Сортировка последовательности чисел с помощью битового массива набора 64-x чисел
void task2_b() {

    int n = 0, input = 0;
    unsigned long long int x = 0; //8-разрядное двоичное число 00000000
    //cout << "x=" << (int)x << "\n";
    unsigned long long int one = 1;
    unsigned long long int maska = one<<63; //1=10000000000000000000000000000000000000000000000000000000000000000 – 64-разрядная маска

    cin >> n; // Количество вводимых чисел

    for (int i = 0; i < n; i++) {
        cin >> input;
        x = x | ((maska >> input));
    }
    //cout << "x=" << (int)x << "\n";
    //cout << "Новое число: " << bitset<64>(x) << endl;
    //cout << "Новое: " << bitset<64>(x)[4] << endl;

    for (int i = 63; i >= 0; i--)
    {
        if (bitset<64>(x)[i] != 0) {
            cout << 63 - i << ' '; // Вывод осортированной последовательности

        }

    }
}

//2.в
void task2_c() {
   
    unsigned char x[8]="";
    int n = 0, input = 0;
    //unsigned long long int x = 0; //8-разрядное двоичное число 11111111
    //cout << "x=" << (int)x << "\n";
    unsigned char one = 1;
    unsigned char maska = one << 7; //1=10000000 – 8-разрядная маска

    //cout << bitset<8>(maska) << endl;
    //cout << endl << bitset<8>(maska >> 3);

    cin >> n; // Количество вводимых чисел

    for (int i = 0; i < n; i++) {
        cin >> input;
        int help_ost = input % 8;
        int help_whole_part = input / 8;
        x[help_whole_part] = x[help_whole_part] | ((maska >> help_ost));
    }
    int i = 0, j = 0;
    //cout << endl;
    /*for (int i = 0; i < 8; i++)
    {
        cout << bitset<8>(x[i]);
    }*/
   // cout << endl;
    for (i = 0; i < 8; i++) {
        for (int j = 7; j >0; j--)
        {
            if (bitset<8>(x[i])[j] != 0) {
                cout << 8 * i + (7-j) << ' '; // Вывод осортированной последовательности

            }

        }
    }
}

//3
//сортировкa числового файла битовым массивом
int task3() {
    

    unsigned long long int  x[140625] = {0};
    unsigned long long int one = 1;
    unsigned long long int maska = one << 63;
    //ifstream fin("Numbers.txt");// открыли файл для чтения
    ifstream fin("number.txt");// открыли файл для чтения
    if (!fin) {
        cout << "Error";
        return 0;
    }
    ofstream fout("results.txt");
    string s;
    while(getline(fin,s))
    {
        int res = stoi(s)-1000000;
        int help_ost = res % 64;
        int help_whole_part = res / 64;
        x[help_whole_part] = x[help_whole_part] | ((maska >> help_ost));
    }
    fin.close(); // закрываем файл чтения
    
    /*for (int i = 0; i < 140625; i++)
    //for (int i = 0; i < 20; i++)
    {
        cout << bitset<64>(x[i]);
    }*/
    
    cout << endl;
    for (int i = 0; i < 140625; i++) {
        for (int j = 63; j > 0; j--)
        {
            if (bitset<64>(x[i])[j] != 0) {
                //cout << 64 * i + (63 - j) + 1000000 << ' '; // Вывод осортированной последовательности
                fout << 64 * i + (63 - j) +1000000<< '\n';
            }

        }
    }
    return 0;
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char cmd = 'y';
    cout << "Task practical 1"<<endl;
    while (cmd != 'n')
    {
        cout << endl << "Choose the number of the function, which you need to testing:";
        cout << endl << "1: 1а - установить 5-й бит произвольного целого числа в 0";
        cout << endl << "2: 1b - установки 7-го бита числа в 1.";
        cout << endl << "3: 1c -Реализация кода";
        cout << endl << "4: 2a - пример с вводом произвольного набора 8-ми чисел (со значениями от 0 до 7) и его сортировкой с помощью битового массива.";
        cout << endl << "5: 2b - Адаптация для 64-х чисел";
        cout << endl << "6: 2c - линейный массив чисел типа unsigned char";
        cout << endl << "7: 3 - Быстрая сортировка числового файла с помощью битового массива.";
        cout << endl << ">>";
        cin >> cmd;
        switch (cmd)
        {
        case '1':
            task1_a();
            break;
        case '2':
            task1_b();
            break;
        case '3':
            task1_c();
            break;
        case '4':
            task2_a();
            break;
        case '5':
            task2_b();
            break;
        case '6':
            task2_c();
            break;
        case '7':
            task3();
            break;
        default:
            cout << "You may write the correct number of the function";
            break;
        }
        cout << endl << endl << "Do you want to continue testing?(y/n)" << endl << ">>";
        cin >> cmd;
    }
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
