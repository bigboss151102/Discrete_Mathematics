#include<iostream>
using namespace std;
int n, k, i, vt;

void display(int *a, int k)
{
	for(i=0; i<k; i++){
		cout << a[i];
	}
	cout << endl;
}


void replace(int *a, int k, int vt){
	for(i=vt; i<k; i++){
		a[i] = 1;
	}
}


void nexstring(int *a, int n, int k)
{
	i= k - 1;
	while(i>0)
	{
		if(a[i] == n){
		   i--; 
		}
		if(a[i]<n)
		  {
		    a[i]++;
		    replace(a,k,i+1);
		    display(a, k);
		    i = k - 1;
		}
	}
}

int main()
{
	cout << "Nhap vao n, k:";
	cin >> n >> k;
	int *a = new int[n];
	for(i=0; i < k; i++)
	{
		a[i] = 1;
	}
	display(a, k);
	nexstring(a, n, k);
	system("Pause");
	return 0;
}