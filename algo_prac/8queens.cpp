#include<iostream>
#include<stdio.h>

using namespace std;
//Размерность доски NхN (Количество ферзей - N)
   const int N=8;  int X[N];  int Count;

  bool P(int X[N],int k,int y) // Поиск позиции для ферзя
  { int i=0;
   while ((i<k)&&(y!=X[i])&&(abs(k-i)!=abs(y-X[i]))) {i++;}
	 if(i==k)
	 return true;
	 else return false;  }

  void Backtracking(int k) // Поиск с возвратом позиций
  { int i,y;
     for (y=0;y<N;y++)
       if (P(X,k,y))
	    {  X[k]=y;
		   if (k==N-1)   {
			   for (i=0;i<N;i++){cout<<char('A'+i)<<X[i]+1<<" ";}
			   cout<<endl;
			   Count++;  }
		   Backtracking(k+1); 
		}  
  }
 int main()
 { for(int i=0;i<N;i++)X[i]=0;
   Count=0;
   cout<<"Arrangement of "<<N<<" queens:"<<endl;
   cout<<"On board "<<N<<" x "<<N<<endl;
   Backtracking(0);
   cout<<"All Arrangement count: "<<Count<<endl;
   system("pause"); }