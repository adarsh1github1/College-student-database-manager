#include<iostream>
#include<fstream>
#include<string.h>
#include <stdio.h>
using namespace std;

char data[15];
int count_n=0;
char proctor[1];
void enroll(int count_n){
	string inital = "00";
	int n;
	cout<<"Enter number of Students to enroll : ";
	cin>>n;
	count_n += n;
	int i;
	for(i=0;i<n;i++){
		ofstream myfile;
		myfile.open("database.txt", ios::app);
		cout<<"*Enter Registration Number : ";
		cin>>data;
		int len = strlen(data);
		while(len < 15){
			data[len] = ' ';
			len += 1; 
		}
		myfile << data << "\t";
		cout<<"*Enter your full name : ";
		cin>>data;
		len = strlen(data);
		while(len < 15){
			data[len] = ' ';
			len += 1; 
		}
		myfile << data << "\t";
		myfile << inital <<"\t";
		myfile << inital <<"\t";
		myfile << inital <<"\t";

		cout<<"Registraiton under which admin : ";
		cin>>proctor;

		myfile << proctor << endl;

	}

}

void student_login(int count_n){
	char reg_no[15];
	cout << "Enter you registration number : ";
	cin >> reg_no;
	ifstream infile;
	int check = 0;
	infile.open("database.txt", ios::in);

	while(infile >> data){
		if(strcmp(reg_no,data) == 0){
			cout << "Registration Number : " << data << endl;
			
			infile >> data;
			cout << "Name : " << data << endl;
			
			infile >> data;
			cout << "Marks in CSE1 : " << data << endl;

			infile >> data;
			cout << "Marks in CSE2 : " << data <<endl;

			infile >> data;
			cout << "Marks in CSE3 : " << data <<endl;

			infile >> data;
			cout << "Registered under admin: " << data <<endl;

			infile.close();
			check = 1;  
		}

	}
	if(check == 0)
			cout<<"Student record not found. Register if not done or contact your admin. \n"<< endl;
}

void faculty_login(int count_n){
	char subcode[4];
	cout<<"Enter the course code : ";
	cin >> subcode;

	string code1 = "CSE1", code2 = "CSE2", code3 = "CSE3";
    string mark = "";
    ifstream infile;
    int check = 0;

    cout<<"Available options : \n1. Add Marks\n2. View Marks\n";
    cout<<"Enter option : ";
    int opt;
    cin>>opt;

    if(opt == 1){
    	cout << "All marks must be added for all students"<<endl;
    	
    	for(int i=0; i <count_n;i++){

    		fstream file("database.txt");

    		if(strcmp(subcode,code1.c_str()) == 0){
    			file.seekp(32 + 43*i, std::ios_base::beg);
    			cout<<"Enter the marks for student #"<<(i+1)<<" : ";
    			cin >> mark;

    			file.write(mark.c_str(),2);
    		}
    		if(strcmp(subcode,code2.c_str()) == 0){
    			file.seekp(35 + 43*i, std::ios_base::beg);
    			cout<<"Enter the marks for student #"<<(i+1)<<" : ";
    			cin >> mark;

    			file.write(mark.c_str(),2);
    		}

    		if(strcmp(subcode,code3.c_str()) == 0){
    			file.seekp(38 + 43*i, std::ios_base::beg);
    			cout<<"Enter the marks for student #"<<(i+1)<<" : ";
    			cin >> mark;

    			file.write(mark.c_str(),2);
    		}
    		file.close();
    	}
    }

    else if(opt == 2){
    	infile.open("database.txt", ios::in);
    	if(strcmp(subcode,code1.c_str()) == 0){
    		cout<<"Registration number - Marks\n"<<endl;
    	

    	    while(infile >>  data){
    		   cout<< data;
    		   infile >> data;
    		   infile >> data;
    		   cout << "- " << data <<endl;
    		   infile >> data;
    		   infile >> data;
    		   infile >> data;
    		   check = 1;
    	    }
    	
    	}
    	infile.close();
    	infile.open("database.txt", ios::in);
    	if(strcmp(subcode,code2.c_str()) == 0){
    		cout<<"Registration number - Marks\n"<<endl;
    	

    	while(infile >>  data){
    		cout<< data;
    		infile >> data;
    		infile >> data;
    		infile >> data;
    		cout << "- " << data <<endl;
    		infile >> data;
    		infile >> data;
    		check = 1;
    	}
    	
        }

        infile.close();
    	infile.open("database.txt", ios::in);
    	if(strcmp(subcode,code3.c_str()) == 0){
    		cout<<"Registration number - Marks\n"<<endl;
    	

    	while(infile >>  data){
    		cout<< data;
    		infile >> data;
    		infile >> data;
    		infile >> data;
    		infile >> data;
    		cout << "- " << data <<endl;
    		infile >> data;
    		check = 1;
    	}
        }
        infile.close();
    	if(check == 0){
    		cout << "No such course found!"<<endl;
    	}

    }
    

}

void admin(int count_n){
	char password[25];
	cout<<"Enter Password : ";
	cin>>password;

	string admin_pass = "crazy_admin";
	if(strcmp(password,admin_pass.c_str()) == 0){
		cout<<"Reg No. \tName\tCSE1\tCSE2\tCSE3\tAdmin id"<<endl;
	    cout<<"___________________________________________________"<<endl;
	    ifstream infile;
	    infile.open("database.txt",ios::in);
	    char data[20];
	    while(infile >> data){
	    	cout << data << "\t";
	    	infile >> data;
	    	cout << data << "\t";
	    	infile >> data;
	    	cout << data << "\t";
	    	infile >> data;
	    	cout << data << "\t";
	    	infile >> data;
	    	cout << data << "\t";
	    	infile >> data;
	    	cout << data <<endl;
	    }
	    infile.close();
	}
	else
		cout<<"Wrong Password!\n";

}

int main(){
    string line;
    ifstream g("database.txt");
    for(int i=0; std::getline(g,line); ++i){
    	count_n++;
    }
    bool finish = true;
    cout<<"\t\t\t\t";
    cout<<"MENU"<<endl;
    cout<<"% % % % % % % % % % % % % % %% % % % % % % % % % % %% % %% % %"<<endl;
    do {
    	
    cout<<"\nAvailable Options : "<<endl;
    cout<<"1. Enroll\n";
    cout<<"2. Student Login\n";
    cout<<"3. Faculty Login\n";
    cout<<"4. Admin\n";
    cout<<"5. Quit\n";
    cout<<"Enter Option: \n";
    int option;  cin>>option;
    switch(option){
    	case 1: enroll(count_n); break;
    	case 2: student_login(count_n); break;
    	case 3: faculty_login(count_n); break;
    	case 4: admin(count_n);
    	case 5: finish = false; break;

    	default: cout<<"Incorrect option....Retry";
    }

    }while(finish);
    cout<<"Thank you, logging you out .....";
    cout<<"Press Any Key to exit";
    return 0;
}