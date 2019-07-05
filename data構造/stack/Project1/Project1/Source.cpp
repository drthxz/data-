
#include <iostream>
#include <string>
using namespace std;

#define maxSize 100
//const  int Max  = 100;
int stack[maxSize];

int sp=0;
int push(int *top, int data);
int pop(int *top);
//ハノイ用---------
int h_stack[20][3];//三つの棒
int h_sp[3];//スタックポインター
int N;//何枚を移動　ex:3枚の円盤
void Stack_Make();
void hanoi_saiki(int n,int a,int b,int c);
void move(int n,int s,int d);




int main()
{
	cout<<"許巧穎"<<endl;
	char c='a';
	int n=0;
	//---------------------------------
	cout<<"円盤の数は---->";
	cin>>N;
	if(N>9){
			cout<<"数が多すぎます";
	//			return ;
	}

	for(int i=0;i<N;i++){
			h_stack[i][0]=N-i;//左の棒に初期化
	}
	h_sp[0]=N;
	h_sp[1]=0;
	h_sp[2]=0;
	hanoi_saiki(N,0,1,2);
	//---------------------------------


    //stackに積み上げる　or 取り出す
	cout<<"iを入力でデータをpush    o で取り出す";
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

//ハノイ再帰本体
void hanoi_saiki(int n,int a,int b,int c){
	if(n>0){
			hanoi_saiki(n-1,a,c,b);
			//結果を表示
			move(n,a,b);
			hanoi_saiki(n-1,c,b,a);
			
	}
}

int move_sp=0;
//円盤を移動--------------
void move(int n,int s,int d){
			//s---->dへ円盤を移動
			h_stack[ h_sp[d] ][d]=h_stack[ h_sp[s] -1][s];
			//spを上下する
			move_sp++;
			//%d 数字　　%c文字
			printf("\n%d回目==>%d 番の円盤を %c----->%c  に移す\n\n",move_sp,n,'a'+s,'a'+d);

			//移動の表示---------------------
			/* 
			3枚7回
			9枚 51回
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

//スタック
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


