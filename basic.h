#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <ctime>

using namespace std;

struct node{
	string name;
	long int size;
	string time;
	node *link;
};

class list{
	private:
		node *head,*rear;
		int count;
	public:
		list(){
			head = rear = NULL;
			count=0;
		}
	void init(){
		
		node *temp = new node;
		/*temp->name = (string)NULL;
		temp->time = (string)NULL;
		temp->size  = (long int)NULL;*/
		temp->link = NULL;
		head = rear = temp;
		temp = NULL;
	}
	void insert(string name, long int size, string time){
		
		count++;
		node *temp = new node;
		temp->name = name;
		temp->size = size;
		temp->time  = time;	
		temp->link = NULL;
		
		rear->link = temp;
		rear = temp;
		
	}

	void display(){
		node *temp = head->link;
		cout<<"____________________________________________________________________"<<endl;
		cout<<"File name"<<"\t\t"<<"File size"<<"\t\t"<<"Last access time"<<endl<<endl;
		while(temp){
			cout<<temp->name<<"\t\t"<<temp->size<<"\t\t"<<temp->time<<endl;
			temp = temp->link;
		}
		//cout<<endl<<"____________________________________________________________________"<<endl;
	}

	void sort1(); 						//name
	void sort2();						//size
	void sort3();						//access time

};

list obj;

void list::sort1(){
	
	if(head->link==NULL)
    {
        cout << "Empty.\n";
        return;
    }
    
    
    for(int i=0;i<count;i++){
    	node *prev = head;
    	for(node *temp =head->link;temp->link;){
    		
    		node *temp1 = temp->link;
    		if(temp->name > temp1->name){
    		
    			prev->link = temp1;
    			temp->link = temp1->link;
    			temp1->link = temp;
    			prev = temp1;
    			temp = temp1->link;

    		}else{
    			
    			temp = temp->link;
    			prev = prev->link;
    		}
    		

    	}
    } 
    cout<<endl<<"After sorting according to FILE NAME"<<endl;
    display();         
}

void list::sort2(){
	
	if(head->link==NULL)
    {
        cout << "Empty.\n";
        return;
    }
  
    for(int i=0;i<count;i++){
    	
    	node *prev = head;
    	for(node *temp =head->link;temp->link;){
    		
    		node *temp1 = temp->link;
    		if(temp->size > temp1->size){
    			
    			prev->link = temp1;
    			temp->link = temp1->link;
    			temp1->link = temp;
    			prev = temp1;
    			temp = temp1->link;

    		}else{
    			
    			temp = temp->link;
    			prev = prev->link;
    		}
    		

    	}
    } 
    cout<<endl<<"After sorting according to FILE SIZE"<<endl;
    display();         

}

void list::sort3(){
	
	if(head->link==NULL)
    {
        cout << "Empty.\n";
        return;
    }
    
    
    for(int i=0;i<count;i++){
    	node *prev = head;
    	for(node *temp =head->link;temp->link;){
    		
    		node *temp1 = temp->link;
    		if(temp->time < temp1->time){
    			
    			prev->link = temp1;
    			temp->link = temp1->link;
    			temp1->link = temp;
    			prev = temp1;
    			temp = temp1->link;

    		}else{
    			
    			temp = temp->link;
    			prev = prev->link;
    		}
    		

    	}
    } 
    cout<<endl<<"After sorting according to LAST ACCESS TIME OF FILE "<<endl;
    display();         

}

void starting(int n){
	struct stat buf;
	
	
	obj.init();
	for(int i=0;i<n;i++){
		int status;
		char path[50]="";
		char name[20]="";
		cout<<endl<<"enter path number "<<i+1<<" :";
		cin.getline(path,50);
		//while ((getchar()) != '\n');

		if(stat(path,&buf)==0){
			
			//printf("%ld\n",buf.st_size);
			//printf(ctime(&buf.st_atime));
			int l = strlen(path);
			
			int j=0;
			for(int i=l-1;;i--){
				if(path[i]=='/')
					break;
				
				name[j]=path[i];
				
				j++;
			}
			l = strlen(name);
			//cout<<l;
			char temp;
			for(int i=0;i<l/2;i++){
				temp = name[i];
				name[i] = name[l-i-1];
				name[l-i-1] = temp;
			}
			
			//cout<<"Name is :"<<name;

			obj.insert(name,buf.st_size,ctime(&buf.st_atime));
		}
		else{
			cout<<endl<<"ERROR! NOT A VALID FILE PATH";
			return;
		}
		
	}
	/*cout<<"now displaying"<<endl;
	obj.display();
	cout<<"sort3"<<endl;
	obj.sort3();
	obj.display();*/
	
	return;
}

void sorting(int a){
	switch(a){
		case 1:
			obj.sort1();
			break;
		case 2:
			obj.sort2();
			break;
		case 3:
			obj.sort3();
			break;
		default:
			cout<<"Not a valid option"<<endl;
	}
	

}