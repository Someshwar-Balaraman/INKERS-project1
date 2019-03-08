#include <iostream>
#include <stdio.h>
#include "basic.h"

int main(){
	int n;
	cout<<endl<<"Enter the number of file paths you want to sort: ";
	cin>>n;
	while ((getchar()) != '\n');
	starting(n);
	for(;;){
		cout<<"____________________________________________________________________"<<endl;

		cout<<endl<<"How do you want to sort it?"<<endl<<"Enter 1. Sort by File name"<<endl<<"Enter 2. Sort by File size"<< endl<<"Enter 3. Sort according to recent File acces time"<<endl<<"Enter 4.Exit"<<endl;;
		int a;
		cin>>a;
		if(a==4)
			break;
		sorting(a);
		cout<<"____________________________________________________________________"<<endl;
		cout<<"Do you want to sort again?"<<endl<<"1. YES"<<endl<<"2. NO"<<endl;
		int b;
		cin>>b;
		if(b==2)
			break;
	}
	

	return 0;
}