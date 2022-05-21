#include<bits/stdc++.h>
using namespace std;

int main();

class acc// accounts class with various functionalities...
{
    public: 
    void add_loan();
    void delete_loan();
    void list_borr();
    string ID;
    acc(string id)// constructor to define and store user ID
    {
        ID=id;
    }
};

void acc:: add_loan()// used to add borrowed money from accounts database.
{
    string tt,am;
    cout<<"Enter Lender's ID"<<endl;
    cin.ignore();
    getline(cin,tt);
    // cout<<"Enter your ID\n";
    // getline(cin,au);
    cout<<"Enter Amount to be borrowed"<<endl;
    getline(cin,am);
    fstream fout;
    fout.open("acc.csv",ios::out | ios::app);
    fout<<tt<<","<<ID<<","<<am<<"\n";
    cout<<"Amount successfully borrowed!"<<endl;  
}

void acc::delete_loan()// used to remove borrowed money from accounts database.
{
    string tt,am;
    string tt1,au1,am1;
    cout<<"Enter Lender's ID"<<endl;
    cin.ignore();
    getline(cin,tt);
    // cout<<"Enter your ID\n";
    // getline(cin,au);
    cout<<"Enter Amount to be borrowed"<<endl;
    getline(cin,am);
    fstream fout;
    fout.open("temp.csv",ios::out | ios::app);
    string fname="acc.csv";
    vector<vector<string>> content;
	vector<string> row;
	string line, word; 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear(); 
			stringstream str(line); 
			while(getline(str, word, ','))
			row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        tt1=content[i][0];  
        au1=content[i][1];
        am1=content[i][2];
        if(tt==tt1 && au1==ID && am1==am)
        {
            continue;cout<<"Borrowed Amount returned!"<<endl;
        }
        fout<<tt1<<","<<au1<<","<<am1<<"\n";	
	}
    file.close();
    fout.close();
    remove("acc.csv");
    rename("temp.csv","acc.csv");
    
}

void acc::list_borr()// display all the borrowers that have taken money from a particular lender.
{
    string tt1,au,am,tt;
    cin.ignore();
    // cout<<"Enter your ID\n";
    // getline(cin,tt1);
    string fname="acc.csv";
    vector<vector<string>> content;
	vector<string> row;
	string line, word; 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear(); 
			stringstream str(line); 
			while(getline(str, word, ','))
			row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        tt=content[i][0];  
        au=content[i][1];
        am=content[i][2];
        if(tt==ID)
        {        
            cout<<"Borrower's ID:"<<au<<endl;                      
            cout<<"Amount :"<<am<<"\n\n"<<endl;
        }
	}
    cout<<"-----End of List-----"<<endl;
}

void reg()// register as a lender or borrower.
{
    string user,pass,des,id;int f=0;
    cin.ignore();
    fstream fout;
    fout.open("temp1.csv",ios::out | ios::app);
    string fname="user.csv";
    vector<vector<string>> content;
	vector<string> row;
	string line, word; 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear(); 
			stringstream str(line); 
			while(getline(str, word, ','))
			row.push_back(word);
			content.push_back(row);
		}
	}
	//else
		//cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        user=content[i][0];  
        pass=content[i][1];
        id=content[i][2];
        des=content[i][3];
        fout<<user<<","<<pass<<","<<id<<","<<des<<"\n";	
	}
    cout<<"Enter Designation:\n1 for Lender\n2 for Borrower"<<endl;
    getline(cin,des);
    cout<<"Enter Username\n";
    getline(cin,user);
    cout<<"Enter ID"<<endl;
    getline(cin,id);
    cout<<"Enter Password"<<endl;
    getline(cin,pass);
    fout<<user<<","<<pass<<","<<id<<","<<des<<"\n";
    
    file.close();
    fout.close();
    remove("user.csv");
    rename("temp1.csv","user.csv");
    cout<<"Registration Successful!"<<endl;    
    main();
}

void lenn(string y) 
{
    int n,f=1;
    cout<<"Enter 1 to see the list of your borrowers"<<endl;
    cout<<"Enter any other no. to logout"<<endl;
    cin>>n;
    acc s(y);
    if(n==1)
    {
        s.list_borr();
    }
    else
    {
        main();f=0;       
    }
    if(f!=0)
    lenn(y);
}

void borr(string y)
{
    int n,f=1;
    cout<<"Enter 1 to borrow"<<endl;
    cout<<"Enter 2 to return borrowed money"<<endl;
    cout<<"Enter any other no. to logout"<<endl;
    cin>>n;
    acc s2(y);
    if(n==1)
    {
        s2.add_loan();
    }
    else if(n==2)
    {
        s2.delete_loan();
    }
    else
    {
        main();f=0;        
    }
    if(f!=0)
    borr(y);
}

void login()// login using username and password and search the database to find the user. Call borrower or lender based on designation
{
    string us,ps;
    int flag=0;
    cout<<"Enter Username"<<endl;
    cin.ignore();
    getline(cin,us);
    cout<<"Enter Password"<<endl;
    getline(cin,ps);
    string fname="user.csv";
	vector<vector<string>> content;
	vector<string> row;
	string line, word; 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
			row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size();i++)
	{
        if(us==content[i][0] && ps==content[i][1])
        {
            cout<<"Login Successful!"<<endl; flag=1;
            int u=stoi(content[i][3]);
            switch(u)
            {
                case 1:
                {
                    lenn(content[i][2]);break;
                }
                case 2:
                {
                    borr(content[i][2]);break;
                }
                default:
                {
                    cout<<"Invalid Designation!"<<endl;
                }
            }
            break;
        }        	
	}
    if(flag!=1)
    {
        cout<<"Login Error! Try Again..."<<endl;
        main();    
    }
}

int main()// displays the front page
{
    int c;
    cout<<"------WELCOME------"<<endl;
    cout<<"Press 1 to Register"<<endl;
    cout<<"Press 2 to Login"<<endl;
    cout<<"Press 3 to Exit"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
        {
            reg();break;
        }
        case 2:
        {
            login();break;
        }
        case 3:
        {
            return 0;break;
        }
        default:
        {
            cout<<"Enter a correct no."<<endl;
            main();break;
        }
    }
return 0;
}