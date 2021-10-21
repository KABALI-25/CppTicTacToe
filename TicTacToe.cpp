#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

bool check_complete(int a[9]){
	int count=0;
	for(int i=0;i<9;i++){
		if(a[i]!=0){
			count+=1;
		}
	}
	return count==9;
}

void initiate(string s[3][3]){
	string a[3][3]={{"1","2","3"},{"4","5","6"},{"7","8","9"}};
	for(int i=0;i<3;i++){
  		for(int j=0;j<3;j++){
	  		s[i][j]=a[i][j];

	   	}
  	}
}

void print_grid(string arr[3][3]){
	for(int i=0;i<3;i++){
		cout<<"\n\t\t\t";
		for(int j=0;j<3;j++){
			
			cout<<" "<<arr[i][j]<<" |";

		}
		cout<<"\n\t\t\t";
		cout<<"___|___|___|"<<endl;
	}
}

void value_change(int position,string arr[3][3],string player,int a[9]){
	if(position<=3){
		arr[0][position-1]=player;

	}
	else if(position>=4 && position<=6){
		arr[1][position-4]=player;
	}
	else if(position>=7 && position<=9){
		arr[2][position-7]=player;
	}

}


bool check_row(string arr[3][3],string player){
	bool found=false;
	for(int j=0;j<3;j++){
		if(arr[j][0]==arr[j][1] && arr[j][1]==arr[j][2] && arr[j][0]==player){
			found=true;
		}
	}
	return found;
	
}

bool check_column(string arr[3][3],string player){
	bool found=false;
	for(int j=0;j<3;j++){
		if(arr[0][j]==arr[1][j] && arr[2][j]==arr[1][j] && arr[0][j]==player){
			found=true;
		}
	}
	return found;
}

bool check_diagonal(string arr[3][3],string player){
	bool found=false;
	if(arr[0][0]==arr[1][1] && arr[2][2]==arr[1][1] && player==arr[1][1]){
		found=true;
	}
	if(arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2] && player==arr[1][1]){
		found=true;
	}
	return found;

}

bool check_win(string arr[3][3],string player){
	if (check_row(arr, player)){
		return true;
	}
	else if(check_column(arr, player)){
		return true;
	}
	else if (check_diagonal(arr, player)){
		return true;
	}
	else{
		return false;
	}
}
void add_integer(int a[9],int index){
	a[index-1]=index;
}

bool check_integer(int a[9],int index){
	
	if(a[index-1]==0){
		return true;
	}
	
	else{
		return false;
	}
}

int take_input(int a[9],string player){
	cout<<"\n\t\t\tEnter input for player:"<<player;
	int number;
	cin>>number;
	if(check_integer(a,number)){
		return number;
	}
	else{
		
		return take_input(a,player);
		
	}
}

void game_loop(){
	system("CLS");
	cout<<"\n\n\t\tWelcome to the game!!"<<endl;
	int arr[9]={0,0,0,0,0,0,0,0,0};
	string s1="X";
	string s2="O";
	string array[3][3];
	initiate(array);
 	print_grid(array);
  while(true){
  	int number;
  	number=take_input(arr,s1);
  	add_integer(arr,number);
  	value_change(number,array,s1,arr);
  	if(check_complete(arr)){
		cout<<"NO ONE WINS"<<endl;
		break;
	}
  	if(check_win(array,s1)){
	  print_grid(array);
	  cout<<"Player one wins!!"<<endl;
	  break;
	  }
	
 	number=take_input(arr,s2);
  	add_integer(arr,number);
  	value_change(number,array,s2,arr);
	if(check_complete(arr)){
		cout<<"NO ONE WINS"<<endl;
		break;
	}
  	if(check_win(array,s2)){
  		cout<<"Player 2 wins!!"<<endl;
  		break;
	  }	
	system("CLS");
	print_grid(array);
	
  }
}

int main(){
	
cout<<"\n\n\t\tHi there!!";
cout<<"\n\n\t\tDo you want to play tic tac\n\n\t\t1)Yes\n\n\t\t2)No"<<endl;
int number;
cin>>number;
while(number==1){
	game_loop();
	cout<<"Do you want to play again"<<endl;
	cout<<"\n\n\t\t1)Play again\n\n\t\t2)Quit"<<endl;
	cin>>number;
	while(number!=2 && number!=1){
		cout<<"Enter number from the choices:"<<endl;
		cout<<"\n\n\t\t1)Play again\n\n\t\t2)Quit"<<endl ;
		cin>>number;
}
}
cout<<"Thank you !!";

}
