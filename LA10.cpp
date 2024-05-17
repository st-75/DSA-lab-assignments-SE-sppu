/*
Read the marks obtained by students of second year in an online
examination of particular subject. Find out maximum and minimum marks
obtained in that subject. Use heap data structure. Analyze the algorithm.
*/

#include <iostream>
using namespace std;

class hp
{
   int heap[20], heap1[20], x, n1, i;

public:
   hp()
   {
      heap[0] = 0;
      heap1[0] = 0;
   }
   void insert(int heap[], int);
   void upadjust(int heap[], int);
   void insert1(int heap1[], int);
   void upadjust1(int heap1[], int);
   void getdata();
   void minmax();
};

void hp::insert(int heap[20], int x)
{
   int n;
   n = heap[0];
   heap[n + 1] = x;
   heap[0] = n + 1;

   upadjust(heap, n + 1);
}

void hp::upadjust(int heap[20], int i)   //to sort in decending order
{
   int temp;
   while (i > 1 && heap[i] > heap[i / 2])
   {
      temp = heap[i];
      heap[i] = heap[i / 2];
      heap[i / 2] = temp;
      i = i / 2;
   }
}

void hp::insert1(int heap1[20], int x)   //to sort in acending order
{
   int n;
   n = heap1[0];
   heap1[n + 1] = x;
   heap1[0] = n + 1;

   upadjust1(heap1, n + 1);
}

void hp::upadjust1(int heap1[20], int i)
{
   int temp1;
   while (i > 1 && heap1[i] < heap1[i / 2])
   {
      temp1 = heap1[i];
      heap1[i] = heap1[i / 2];
      heap1[i / 2] = temp1;
      i = i / 2;
   }
}

void hp::getdata()
{
   cout << "\nEnter the no. of students: ";
   cin >> n1;
   for (i = 0; i < n1; i++)
   {
      cout << "\nEnter the marks of student " << i + 1 << " :";
      cin >> x;
      insert(heap, x);
      insert1(heap1, x);
   }
}

void hp::minmax()
{
   cout << "\n***************************************" << endl;
   cout << "\nMax marks: " << heap[1];
   cout << endl<< "Marks in Decending order:";
   for (i = 0; i <= n1; i++)
   {
      cout << "\n"<< heap[i];
   }
   cout << "\n***************************************" << endl;
   cout << "\nMin marks: " << heap1[1];
   cout << endl<< "Marks in Acending order:";
   for (i = 0; i <= n1; i++)
   {
      cout << "\n"<< heap1[i];
   }
}

int main()
{
   hp h;
   h.getdata();
   h.minmax();
   return 0;
}