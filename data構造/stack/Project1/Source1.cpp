
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
	
    //stack�ɐςݏグ��@or ���o��
	cout<<"i����͂Ńf�[�^��push o �Ŏ��o��";
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

//�X�^�b�N
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
