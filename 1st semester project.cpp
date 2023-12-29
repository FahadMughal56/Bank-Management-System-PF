#include<iostream>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>

#include<string.h>

using namespace std;
int main()
{
	
	int choice,sub_choice;
	do
	{
	cout<<"\n\n\t\t<<<<<<< Main Menu >>>>>>>>>"<<endl;
	cout<<"\t\tpress 1 to creat account"<<endl;
	cout<<"\t\tpress 2 to deposit amount"<<endl;
	cout<<"\t\tpress 3 to withdraw amount"<<endl;
	cout<<"\t\tpress 4 to balance enquiry"<<endl;
	cout<<"\t\tpress 5 to delete account"<<endl;
	cout<<"\t\tpress 6 to Exit"<<endl;
	cin>>choice;
	struct user_data
	{
		string cnic,name_f,name_l;
		double r,initial_deposit;
		
	};
	user_data a;
	

	switch(choice){
	
		
		case 1:
			{
			
		cout<<"\tEnter your  cnic : ";
		
		
		getline(cin.ignore(),a.cnic);
	
		
		cout<<"\tEnter your first Name : ";
		
		getline(cin,a.name_f);
		cout<<"\tEnter your last Name : ";
		getline(cin,a.name_l);
		cout<<"\tDeposit initial amount at least 1000 Rs : ";
		cin>>a.initial_deposit;
		if(a.initial_deposit<1000){
			cout<<"\tDeposit is less than 1000 Rupees so account will not created : ";
		}
		else {
				srand(time(0));
 	a.r= rand();
		
		
	    	
		
		cout<<"\t\tCongratulations Account created sucessfully"<<endl;
		cout<<"\t\tyour account number is "<<a.r;
		
		fstream file;
	file.open("D://data.txt",ios::out|ios::app);
	file<<" "<<a.cnic<<" "<<a.name_f<<" "<<a.name_l<<" "<<a.initial_deposit<<" "<<a.r<<"\n";
	file.close();
	
	}
		cout<<"\n\npress 1 to see main menu or 2 to exit"<<endl;
	    cin>>sub_choice;
	    if (sub_choice == 1)
	    {
	    	system("cls");
			break;
		}
		else 
		{
			choice = 6;
			break;
			
		}
		
	}
	
		case 2:
			{
			
			double search,count=0;
		fstream file,file1;	
			
		cout<<">>Welcome to deposit Funds<<"<<endl<<endl;
		cout<<"Please enter your Account no : ";
		cin>>search;
		file.open("D://data.txt",ios::in);
		file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
		while(!file.eof())
		{
			if(search==a.r)
			{
				cout<<"Cnic no. : "<<a.cnic<<endl;
				cout<<"Name customer : "<<a.name_f<<" "<<a.name_l<<endl;
				cout<<"Current Balance : "<<a.initial_deposit<<endl;
				cout<<"Account no : "<<a.r;
				count++;
				break;   // to bring controle out from whole body i.e while
			}
			file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
	   }
	   file.close(); //file close in which data was  read
	   if(count==0){
	   	cout<<"\n\n Record Not Found.....";
	   }
	   
	   
	   double increment_amount;
	   
	  
	   file1.open("D://data.txt",ios::in);
	   if(!file1){
	   	cout<<"\n\n File openning error...";  // if file not exist
	   	file1.close();
	   	goto p;
	   }
	    file.open("D://data1.txt",ios::out|ios::app);   //>>file.open <<
	    file1>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
	    while(!file1.eof())
	    {
	    	if(a.r==search){
	    		cout<<"\nEnter amount to deposit :";
	            cin>>increment_amount;
	            a.initial_deposit=a.initial_deposit+increment_amount;
	            file<<" "<<a.cnic<<" "<<a.name_f<<" "<<a.name_l<<" "<<a.initial_deposit<<" "<<a.r<<"\n";
	            cout<<"\n\n amout updated :"<<a.initial_deposit;
			}
			else{
				 file<<" "<<a.cnic<<" "<<a.name_f<<a.name_l<<" "<<" "<<a.initial_deposit<<" "<<a.r<<"\n";
			}
	    	file1>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
	       
		}
		file1.close();
		file.close();
		remove("D://data.txt");
		rename("D://data1.txt","D://data.txt");
	    p:
	    cout<<"\n\npress 1 to see main menu or 2 to exit"<<endl;
	    cin>>sub_choice;
	    if (sub_choice == 1)
	    {
	    	system("cls");
			break;
		}
		else 
		{
			choice = 6;
			break;
			
		}
	    
	}
	    case 3 :
	    {
			
	      	
	      	
			 double search,count=0;
		     fstream file,file1;	
	      	
	    cout<<">>Welcome to withdraw funds<<"<<endl<<endl;
	    
		cout<<"Please enter your Account no : ";
		cin>>search;
			file.open("D://data.txt",ios::in);
		file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
		while(!file.eof())
		{
			if(search==a.r)
			{
				cout<<"Cnic no. : "<<a.cnic<<endl;
				cout<<"Name customer : "<<a.name_f<<" "<<a.name_l<<endl;
				cout<<"Current Balance : "<<a.initial_deposit<<endl;
				cout<<"Account no : "<<a.r;
				count++;
				break;   // to bring controle out from whole body i.e while
			}
			file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
	   }
	   file.close(); //file close in which data was  read
	   if(count==0){
	   	cout<<"\n\n Record Not Found.....";
	   }
	   
	   
	   double decrement_amount;
	   
	  
	   file1.open("D://data.txt",ios::in);
	   if(!file1){
	   	cout<<"\n\n File openning error...";  // if file not exist
	   	file1.close();
	   	goto p1;
	   }
	    file.open("D://data1.txt",ios::out|ios::app);   //>>file.open <<
	    file1>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
	    while(!file1.eof())
	    {
	    	if(a.r==search){
	    		cout<<"\nEnter amount to withdraw :";
	            cin>>decrement_amount;
	            a.initial_deposit=a.initial_deposit-decrement_amount;
	            file<<" "<<a.cnic<<" "<<a.name_f<<" "<<a.name_l<<" "<<a.initial_deposit<<" "<<a.r<<"\n";
	            cout<<"\n\n amout after withdraw :"<<a.initial_deposit;
			}
			else{
				 file<<" "<<a.cnic<<" "<<a.name_f<<a.name_l<<" "<<" "<<a.initial_deposit<<" "<<a.r<<"\n";
			}
	    	file1>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
	       
		}
		file1.close();
		file.close();
		remove("D://data.txt");
		rename("D://data1.txt","D://data.txt");
	    p1:
	    	cout<<"\n\npress 1 to see main menu or 2 to exit"<<endl;
	    cin>>sub_choice;
	    if (sub_choice == 1)
	    {
	    	system("cls");
			break;
		}
		else 
		{
			choice = 6;
			break;
			
		}
	    }
		case 4:
			{
				fstream file;
				double search;
				int count=0;
				cout<<"Please enter your Account no : ";
				cin>>search;
				file.open("D://data.txt",ios::in);
				file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
				while(!file.eof())
				{
					if(search==a.r)
					{
						
						cout<<"Name customer : "<<a.name_f<<" "<<a.name_l<<endl;
						cout<<"Current Balance : "<<a.initial_deposit<<endl;
						
						count++;
						break;   // to bring controle out from whole body i.e while
					}
					file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
			   }
			   file.close(); //file close in which data was  read
			   if(count==0){
			   	cout<<"\n\n Record Not Found.....";
			   }
		    cout<<"\n\npress 1 to see main menu or 2 to exit"<<endl;
		    cin>>sub_choice;
		    if (sub_choice == 1)
		    {
		    	system("cls");
				break;
			}
			else 
			{
				choice = 6;
				break;
				
			}	
		   
		}
		case 5:
	    {
	    	fstream file,file1;
	       double search;
	       cout<<"enter acc no to delete : ";
	       cin>>search;
	       file.open("D://data.txt",ios::in);
	       if(!file)
	       {
	       	cout<<"\n\n File openning error....";
	       	file.close();
	       	goto p4;
		   }
		   file1.open("D://data1.txt",ios::out|ios::app);
		   file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
		   while(!file.eof())
		   {
		   	if(search == a.r)
		   	{
		   		cout<<"\n\n record deleted ";
			   }
			   else
			   {
			   	file1<<" "<<a.cnic<<" "<<a.name_f<<" "<<a.name_l<<" "<<a.initial_deposit<<" "<<a.r<<"\n";
			   }
		   	file>>a.cnic>>a.name_f>>a.name_l>>a.initial_deposit>>a.r;
		   	
		   }
		   file.close();
		   file1.close();
		   remove("D://data.txt");
		   rename("D://data1.txt","D://data.txt");
		   p4:
		   	cout<<"\n\npress 1 to see main menu or 2 to exit"<<endl;
		    cin>>sub_choice;
		    if (sub_choice == 1)
		    {
		    	system("cls");
				break;
			}
			else 
			{
				choice = 6;
				break;
				
			}
	    	
	   
		}
	    case 6:
	    { 	
	    	break;
		}
	    
			
	}   //switch close curly brace
			
		
				
	} while (choice !=6 );		
			
	
}
