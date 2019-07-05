
#include <iostream>
#include <string>

using namespace std;
#define max 100;
int stack[max];
int sp=0;
int push(int n);
int pop(int *n);

int main()
{
	char c='a';
	int n=0;
	
    //stackに積み上げる　or 取り出す
	cout<<"iを入力でデータをpush o で取り出す";
	cin>>c;
	if(c=='i' || c=='I'){
		cout<<"data---------->";
		cin>>n;
		push(n);
	}
	if(c=='o' || c=='O'){
			cout<<"data---------->";
			cin>>n;
			pop(n);
	}

	int a;
	cin >> a ;
}

//スタック
int push(int stack[],int *top, int data){
		if(*top>= max){
				printf("\n[STACK:Overflow]");
				exit(-1);
		}else{
				stack[*top]=data;
				(*top)++;
		}
}

//pop
int pop(int stack[],int *top){
		int v;
		if((*top)>0){
				v=stack[(*top)-1];
				(*top)--;
				return v;
		}else{
				printf("\n[STACK:Empty");
				return -1;
		}

}
