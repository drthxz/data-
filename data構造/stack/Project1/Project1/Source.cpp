
#include <iostream>
#include <string>
using namespace std;

#define maxSize 100
//const  int Max  = 100;
int stack[maxSize];

int sp=0;
int push(int *top, int data);
int pop(int *top);
//�n�m�C�p---------
int h_stack[20][3];//�O�̖_
int h_sp[3];//�X�^�b�N�|�C���^�[
int N;//�������ړ��@ex:3���̉~��
void Stack_Make();
void hanoi_saiki(int n,int a,int b,int c);
void move(int n,int s,int d);




int main()
{
	cout<<"���I�n"<<endl;
	char c='a';
	int n=0;
	//---------------------------------
	cout<<"�~�Ղ̐���---->";
	cin>>N;
	if(N>9){
			cout<<"�����������܂�";
	//			return ;
	}

	for(int i=0;i<N;i++){
			h_stack[i][0]=N-i;//���̖_�ɏ�����
	}
	h_sp[0]=N;
	h_sp[1]=0;
	h_sp[2]=0;
	hanoi_saiki(N,0,1,2);
	//---------------------------------


    //stack�ɐςݏグ��@or ���o��
	cout<<"i����͂Ńf�[�^��push    o �Ŏ��o��";
	cin>>c;
	for(int i =0; i>maxSize; i++){
				if(c=='i' || c=='I'){
				cout<<"data---------->";
				cin>>n;
				//push(stack[i],i);
			}
			if(c=='o' || c=='O'){
					cout<<"data---------->";
					cin>>n;
					//pop(i);
			}
	
			int c;
			cin>>c;
	}


	int a;
	cin >> a ;
}

//�n�m�C�ċA�{��
void hanoi_saiki(int n,int a,int b,int c){
	if(n>0){
			hanoi_saiki(n-1,a,c,b);
			//���ʂ�\��
			move(n,a,b);
			hanoi_saiki(n-1,c,b,a);
			
	}
}

int move_sp=0;
//�~�Ղ��ړ�--------------
void move(int n,int s,int d){
			//s---->d�։~�Ղ��ړ�
			h_stack[ h_sp[d] ][d]=h_stack[ h_sp[s] -1][s];
			//sp���㉺����
			move_sp++;
			//%d �����@�@%c����
			printf("\n%d���==>%d �Ԃ̉~�Ղ� %c----->%c  �Ɉڂ�\n\n",move_sp,n,'a'+s,'a'+d);

			//�ړ��̕\��---------------------
			/* 
			3��7��
			9�� 51��
					1
					2
					3
					a   b    c

					2
					3			1
					a    b   c
			*/
			for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
							cout<<h_stack[ h_sp[d] ][i]<<"              "<<h_stack[ h_sp[d] ][d]<<"           "<<h_stack[ h_sp[d] ][d]<<endl;
					}
					
			}

			
}
//-----------------------------------
//
void Stack_Make(){
		int c=0,n=0;


}

//�X�^�b�N
//int push(int stack[],int *top, int data)
int push(int *top, int data){
		if(*top>= maxSize){
				printf("\n[STACK:Overflow]");
				exit(-1);
		}else{
				stack[*top]=data;
				(*top)++;
		}
}

//pop
//int pop(int stack[],int *top)
int pop(int *top){
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


