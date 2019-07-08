
#include <iostream>
#include <string>
using namespace std;

#define maxSize 100
//const  int Max  = 100;
int stack[maxSize];

int top=0;
int push(int stack[], int *top, int data);
int pop(int stack[], int *top);
//�n�m�C�p---------
int h_stack[3][20];//�O�̖_   3����MAX20--->h_stack[0][20]  h_stack[1][20] ...
int h_top[3];//�X�^�b�N�|�C���^�[
int N;//�������ړ��@ex:3���̉~��

void hanoi_saiki(int n,int a,int b,int c);
void move(int n,int s,int d);




int main()
{
	cout<<"5B���I�n"<<endl;
	
	//---------------------------------
	cout<<"�~�Ղ̐���---->";
	cin>>N;
	//h_stack[0][N]=

	if(N>9){
		cout<<"�����������܂�";
//			return ;
	}
	
	
	for (int i = 0; i < N; i++) {
		h_stack[0][i] = N - i;//���̖_�ɏ�����
	}

	h_top[0] = N;
	h_top[1] = 0;
	h_top[2] = 0;
	hanoi_saiki(N, 0, 1, 2);
	//---------------------------------

	char c = 'a';
	int data = 0;
	while(maxSize){
    //stack�ɐςݏグ��@or ���o��
	cout<<"i����͂Ńf�[�^��push    o �Ŏ��o��----->";
	cin>>c;
	
	
		if(c=='i' || c=='I'){
			cout<<"data---------->";
			cin>>data;
			push(stack, &top, data);//&top=�ʒu
		}
		if(c=='o' || c=='O'){
			data = pop(stack, &top);
			cout << "pop---->" << data << endl;
		}
	

	}


	int a;
	cin >> a ;
}

//�n�m�C�ċA�{��
void hanoi_saiki(int n,int a,int b,int c){//n�Վq�C��A�׋N�n���C��B�זڕW���C��C�׎b����
	if(n>0){
		
		hanoi_saiki(n-1,a,c,b);
		
		//���ʂ�\��
		move(n,a,b);
		hanoi_saiki(n-1,c,b,a);

	}
}

int move_no=0;
//�~�Ղ��ړ�--------------
void move(int n,int s,int d){

	//s---->d�։~�Ղ��ړ�
	int temp = pop(h_stack[s], &h_top[s]);
	push(h_stack[d], &h_top[d], temp);
	//h_stack[ d ][h_top[d]]=h_stack[ s][h_top[s] - 1];

	//sp���㉺����
	move_no++;
	
	//%d �����@�@%c����
	printf("\n%d���==>%d �Ԃ̉~�Ղ� %c----->%c  �Ɉڂ�\n\n",move_no,n,'a'+s,'a'+d);
	

	for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j <3; j++) {
			
			if (h_stack[j][i] == 0) {
				cout << "\t";
			}
			else {
				cout << h_stack[j][i]<< "\t" ;
			}
			
		}
		cout << endl;
	}
	cout << "A\tB\tC" << endl;		
	//�ړ��̕\��---------------------
	
	/* 
	3��7��
	9�� 511��
			1
			2
			3
			a   b    c
	1���==>1 �Ԃ̉~�Ղ� a----->b  �Ɉڂ�
			2
			3		 1
			a    b   c
	*/
	
			
}
//-----------------------------------

//�X�^�b�N------------------
int push(int stack[], int *top, int data) {
	if(*top>= maxSize){
		printf("\n[STACK:Overflow]");
		exit(-1);
	}else{
		stack[*top]=data;
		(*top)++; //*=top�̒l
	}
}

//pop
int pop(int stack[], int *top) {
	int v;
	if((*top)>0){
		v=stack[(*top)-1];
		stack[(*top) - 1] = 0;
		(*top)--;
		return v;
	}else{
		printf("\n[STACK:Empty");
		return -1;
	}

}
//�X�^�b�N------------------

