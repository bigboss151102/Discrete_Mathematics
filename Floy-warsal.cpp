#include<iostream>

#include<conio.h>

using namespace std;

#define MAX 10000 
#define TRUE 1 
#define FALSE  0 

int A[50][50];// ma tran trong so cua di thi 
int D[50][50];//la mang chua cac gia tri khoan cach ngan nhat tu i den j
int S[50][50];//S la mang chua gia tri phan tu ngay sau cua i tren duong di ngan nhat tu i->j */
int n;//so dinh cua do thi
int u;//dinh dau cua do thi
int v;//dinh cuoi cua do thi

void Init(void){
    freopen("D://FLOYD.txt", "r", stdin);
    cin>>n>>u>>v;
    cout<<"So dinh cua do thi: "<< n <<endl;
    //nhap ma tran trong so ?
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
             cin>>A[i][j];
                if (i != j && A[i][j] == 0)
                    A[i][j] = MAX;
        }
    }
}

void Result(void){
	 if (D[u][v] >= MAX) {
	  cout<<"Khong co duong di";
	 }

	 else {
	  cout<<"Duong di ngan nhat tu "<<(char)(u+'A'-1)<<" den "<<(char)(v + 'A' -1)<< " co do dai la "<<D[u][v]<<endl;
	  cout<<"Duong di: "<<(char)(u + 'A' - 1);
	  while (u != v) {
	   cout<<"->"<<(char)(S[u][v] +'A' -1);
	   u = S[u][v];
	  }
	 }
	}

void Floy(void){
    int i, j, k, found;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            D[i][j] = A[i][j];
            if (D[i][j] == MAX) S[i][j] = 0;
            else S[i][j] = j;
        }
 }
 /* Mang D[i,j] la mang chua cac gia tri khoan cach ngan nhat tu i den j

 Mang S la mang chua gia tri phan tu ngay sau cua i tren duong di

 ngan nhat tu i->j */

for (k = 1; k <= n; k++){
	  for (i = 1; i <= n; i++){
	   for (j = 1; j <= n; j++){
	    if (D[i][k] != MAX && D[i][j] > (D[i][k] + D[k][j])){
	     // Tim D[i,j] nho nhat co the co 
	     D[i][j] = D[i][k] + D[k][j];
	     S[i][j] = S[i][k];
	     //ung voi no la gia tri cua phan tu ngay sau i 
	    }
	   }
	  }
	 }
	}

int main(void){

	 Init();
	 Floy();
	 Result();
	 getch();

}