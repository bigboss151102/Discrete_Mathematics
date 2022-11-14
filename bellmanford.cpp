#include <stdio.h>
#define Max 10000 
int n, S, F;
int c[101][101];
int d[101];
int Trance[101]; 
void input();
void init();
void FordBellman();
void PrintResult();

int main(){
	input();
	init();
	FordBellman();
	PrintResult(); 
} 

void input(){
	int n,m,u,v,S,F;
	printf("So dinh:");scanf("%d",&n);
	printf("So canh:");scanf("%d",&m);
	printf("Dinh xuat phat:");scanf("%d",&S);
	printf("Dinh ket thuc:");scanf("%d",&F); 
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			if(u==v) c[u][v]=0;
			else c[u][v]= Max;
		}
	}
	printf("\n Nhap trong so (khong am):\n");
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&c[u][v]);
	}
}

void init(){
	int i;
	for(i=1;i<=n;i++){
		d[i]=c[S][i];
		Trance[i]=S;
	}
}

void FordBellman(){
	int Stop,u,v,CoutLoop=0;
	do{
		Stop=1;
		for(u=1;u<=n;u++){
			for (v=1;v<=n;v++){
				if (d[v]>d[u]+c[u][v]){
					d[v]=d[u]+c[u][v];
					Trance[v]=u;
					Stop=0;
				}
			}
		}
		CoutLoop++;
	}
	while (Stop = 1 ||(CoutLoop >=n-2));
}

void PrintResult(){
	if(d[F]==Max) printf("Khong tim thay duong di");
	else {
		printf("Khoang cach tu dinh %d den dinh %d la:",S,F);
		while (F!=S) {
			printf("%d <-",F);
			F= Trance[F]; 
		} 
		printf("%d",S); 
	} 
}