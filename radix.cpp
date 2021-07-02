#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXZNAK 254

char **taba,**tabb;


void czytaj(char **taba, int n){
 char slowo[MAXZNAK];
 int i=0;
 for (i=0;i<n; i++){
    cin >> slowo ;
  taba[i] = (char*) malloc(sizeof(char)*MAXZNAK);     //allokacja drugiej przestrzeni
  strcpy(taba[i],slowo);
 }
}

  void countingsort(char **taba, char **tabb, int temp[], int n, int x){
     for(int i=0;i<MAXZNAK;i++ )
        temp[i] = 0;

      for(int i =0 ; i<n;i++){

        temp[taba[i][x]] ++;
      }

      for(int i=1; i<MAXZNAK;i++){
          temp[i]=temp[i]+temp[i-1];
      }




      for(int i=n-1;i>=0;i--){
        tabb[temp[taba[i][x]]-1]=taba[i];  //przepisanie w odpowiedniej kolejnosci
           temp[taba[i][x]]--;
         }


        for(int i=0;i<n;i++){
          taba[i]=tabb[i];



         }
  }

  int Max(char **tab, int n) {
    int max = 0;
    for (int i = 0; i < n; i++){
      if (strlen(tab[i]) > max)
        max = strlen(tab[i]);
      //  cout << max << endl ;
      }
    return max;
  }

  void radixsort(char **taba,char **tabb,int temp[],int n)
  {
    for(int i = (Max(taba,n-1)-1);i>=0;i--)
    {
      countingsort(taba,tabb,temp,n,i);
    }
  }

  void lowercase(char **taba, int n){
    for(int i =0;i<n;i++)
      for (int j = sizeof(taba[i]); j>=0; j--) {
        if(taba[i][j] >= 'A' && taba[i][j] <= 'Z') {
          taba[i][j] = taba[i][j] + 32;
        }
      }
  }


int main()
{
  int n=4;
  int temp[MAXZNAK];
  cout << "Podaj slowa:" << endl;
  taba=(char**) malloc(n*sizeof(char*));    //allokacja pierwszej przestrzeni
  tabb=(char**) malloc(n*sizeof(char*));
  czytaj(taba,n);


  lowercase(taba,n);
  radixsort(taba,tabb,temp,n);
  //countingsort(taba,tabb,temp,n,0);

  cout << "\n\n";
cout << "Tab A:" << endl;
  for(int i =0 ; i<n;i++)
  {
    cout << *(taba+i) << endl;
  }

  cout << "\n\n";
cout << "Tab B:" << endl;
  for(int i =0 ; i<n;i++)
  {
    cout << *(tabb+i) << endl;
  }







  return 0;
}
