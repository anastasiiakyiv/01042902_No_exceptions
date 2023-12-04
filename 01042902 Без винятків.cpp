/*
Переробіть програму так, щоб вона видавала по суті той самий результат але без використання винятків.

#include <iostream>
#include <ctime>
using namespace std;
class MyArray
{
private:

public:
    int row;
  int col;
  int **arr;
  MyArray (int row, int col)
  {
    this->row=row;
    this->col=col;
    arr=new int*[row];
    for (int i=0; i<row; i++)
    {
      arr[i]=new int[col];
    }
    for (int i=0; i<row; i++)
    {
      for (int j=0; j<col; j++)
      {
        arr[i][j]=rand()%90+10;
      }
    }
  }
  ~MyArray()
  {
    for (int i=0; i<row; i++)
    {
      delete [] arr[i];
            cout << "Звільнено пам'ять для рядка !" << endl;
    }
    delete [] arr;
        cout << "Звільнено пам'ять для масива вказівників !" << endl;
  }
  void show_arr()
  {
    for (int i=0; i<row; i++)
    {
      for (int j=0; j<col; j++)
      {
        cout << arr[i][j] << "\t";
      }
      cout << endl;
    }
    cout << endl;
  }
  friend void show_result(MyArray a1, MyArray a2);
};
void show_result(MyArray *a1, MyArray *a2)
{
  for (int i=0; i<a1->row; i++)
  {
    for (int j=0; j<a1->col; j++)
    {
      cout << a1->arr[i][j]+a2->arr[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}
int main() {
  srand(time(nullptr));
  int r1, r2, c1, c2;
  do
  {
      cout << "Кількість рядків першої матриці: ";
      cin >> r1;
      cout << "Кількість стовпців першої матриці: ";
      cin >> c1;
      cout << "Кількість рядків другої матриці: ";
      cin >> r2;
      cout << "Кількість стовпців другої матриці: ";
      cin >> c2;
      cout << endl;
    try
    {
      MyArray a1(r1, c1);
      a1.show_arr();
      MyArray a2(r2, c2);
      a2.show_arr();
      if(r1!=r2)
            {throw 1;}
      if(c1!=c2)
            {throw 2;}
      show_result(&a1, &a2);
      cout << "Матриці додано !" << endl;
    }
    catch(int ex)
    {
      if (ex==1)
        cout << "Помилка. Кількість рядків матриці нерівна !" << endl << endl;
      if (ex==2)
        cout << "Помилка. Кількість стовпців матриці нерівна !" << endl << endl;
    }
  }  while (r1!=r2 || c1!=c2);
    cout << "Закінчення головної програми" << endl;
  return 0;
}
*/

#include <iostream>
#include <ctime>
using namespace std;
class MyArray
{
private:

public:
    int row;
    int col;
    int** arr;
    MyArray(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new int* [row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = rand() % 90 + 10;
            }
        }
    }
    ~MyArray()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
            cout << "Звільнено пам'ять для рядка !" << endl;
        }
        delete[] arr;
        cout << "Звільнено пам'ять для масива вказівників !" << endl;
    }
    void show_arr()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    friend void show_result(MyArray a1, MyArray a2);
};
void show_result(MyArray* a1, MyArray* a2)
{
    for (int i = 0; i < a1->row; i++)
    {
        for (int j = 0; j < a1->col; j++)
        {
            cout << a1->arr[i][j] + a2->arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    system("chcp 1251>null");
    srand(time(nullptr));
    int r1, r2, c1, c2;
    do
    {
        cout << "Кількість рядків першої матриці: ";
        cin >> r1;
        cout << "Кількість стовпців першої матриці: ";
        cin >> c1;
        cout << "Кількість рядків другої матриці: ";
        cin >> r2;
        cout << "Кількість стовпців другої матриці: ";
        cin >> c2;
        cout << endl;
        MyArray a1(r1, c1);
        a1.show_arr();
        MyArray a2(r2, c2);
        a2.show_arr();
        if (r1 != r2)
        {
            cout << "Помилка. Кількість рядків матриці нерівна !" << endl;
        }
        else if (c1 != c2)
        {
            cout << "Помилка. Кількість стовпців матриці нерівна !" << endl;
        }
        else
        {
            show_result(&a1, &a2);
            cout << "Матриці додано !" << endl;
        }
    } while (r1 != r2 || c1 != c2);
    cout << "Закінчення головної програми" << endl;
    return 0;
}