
#include <iostream>
#include <string>
using namespace std;

#define maxSize 100
//const  int Max  = 100;
int stack[maxSize];

int top=0;
int push(int stack[], int *top, int data);
int pop(int stack[], int *top);
//ハノイ用---------
int h_stack[3][20];//三つの棒   3中のMAX20--->h_stack[0][20]  h_stack[1][20] ...
int h_top[3];//スタックポインター
int N;//何枚を移動　ex:3枚の円盤

void hanoi_saiki(int n,int a,int b,int c);
void move(int n,int s,int d);




int main()
{
	cout<<"5B許巧穎"<<endl;
	
	//---------------------------------
	cout<<"円盤の数は---->";
	cin>>N;
	//h_stack[0][N]=

	if(N>9){
		cout<<"数が多すぎます";
//			return ;
	}
	
	
	for (int i = 0; i < N; i++) {
		h_stack[0][i] = N - i;//左の棒に初期化
	}

	h_top[0] = N;
	h_top[1] = 0;
	h_top[2] = 0;
	hanoi_saiki(N, 0, 1, 2);
	//---------------------------------

	char c = 'a';
	int data = 0;
	while(maxSize){
    //stackに積み上げる　or 取り出す
	cout<<"iを入力でデータをpush    o で取り出す----->";
	cin>>c;
	
	
		if(c=='i' || c=='I'){
			cout<<"data---------->";
			cin>>data;
			push(stack, &top, data);//&top=位置
		}
		if(c=='o' || c=='O'){
			data = pop(stack, &top);
			cout << "pop---->" << data << endl;
		}
	

	}


	int a;
	cin >> a ;
}

//ハノイ再帰本体
void hanoi_saiki(int n,int a,int b,int c){//n個盤子，以A為起始柱，以B為目標柱，以C為暫存柱
	if(n>0){
		
		hanoi_saiki(n-1,a,c,b);
		
		//結果を表示
		move(n,a,b);
		hanoi_saiki(n-1,c,b,a);

	}
}

int move_no=0;
//円盤を移動--------------
void move(int n,int s,int d){

	//s---->dへ円盤を移動
	int temp = pop(h_stack[s], &h_top[s]);
	push(h_stack[d], &h_top[d], temp);
	//h_stack[ d ][h_top[d]]=h_stack[ s][h_top[s] - 1];

	//spを上下する
	move_no++;
	
	//%d 数字　　%c文字
	printf("\n%d回目==>%d 番の円盤を %c----->%c  に移す\n\n",move_no,n,'a'+s,'a'+d);
	

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
	//移動の表示---------------------
	
	/* 
	3枚7回
	9枚 511回
			1
			2
			3
			a   b    c
	1回目==>1 番の円盤を a----->b  に移す
			2
			3		 1
			a    b   c
	*/
	
			
}
//-----------------------------------

//スタック------------------
int push(int stack[], int *top, int data) {
	if(*top>= maxSize){
		printf("\n[STACK:Overflow]");
		exit(-1);
	}else{
		stack[*top]=data;
		(*top)++; //*=topの値
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
//スタック------------------

