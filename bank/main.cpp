#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

class Bank_account{
 int money_deposit;
 char type;
 int acno;
 char name[70];
public:
    void report()const;
    int retmoney_deposit()const;
    void Display_account()const;
    void dep(int);
    int retacno()const;
    void creat_bank_account();
    void updation ();
    char rettype()const;
    void draw(int);

};
void Bank_account::updation(){

cout<<"\n\tBank_account no. :"<<acno;
cout<<"\n\tupdate bank_account holder name: ";
 cin.ignore();
 cin.getline(name,50);
 cout<<"\n\tupdate type of bank_account: ";
 cin>>type;
 type=toupper(type);
 cout<<"\n\tupdate balance total money: ";
  cin>>money_deposit;

}
void Bank_account::creat_bank_account(){
system("cls");
cout<<"\n\tplease Enter the Bank_account no. :";
cin>>acno;
cout<<"\n\n\tplease Enter the name of the bank_account holder: ";
cin.ignore();
cin.getline(name,50);
cout<<"\n\tplease Enter type of the bank_account holder(c/s): ";
cin>>type;
type=toupper(type);
cout<<"\n\tplease enter the starting total money: ";
cin>>money_deposit;
cout<<"\n\tBank_account created...";

}
void Bank_account::Display_account()const{
cout<<"\n\tbank_account no.: "<<acno;
cout<<"\n\tbank_account holder name: ";
cout<<name;
cout<<"\n\ttype of bank_account: "<<type;
cout<<"\n\tbalance total money :"<<money_deposit;

}
int Bank_account::retacno()const{


return acno;
}
char Bank_account::rettype()const{


return type;

}
void Bank_account::report()const{
cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<money_deposit<<endl;

}
void Bank_account::dep(int x){

money_deposit+=x;

}
void Bank_account::draw(int x){

money_deposit-=x;

}
int Bank_account::retmoney_deposit()const{

return money_deposit;

}
void write_Bank_account();
void display_sp(int);
void display_all();
void delete_Bank_account(int);
void monet_deposit_withdraw(int,int);
void update_Bank_account(int);
int main()
{

 char ch;
 int num;

do{
 system("cls");
 cout<<"\t\tWELCOME TO COMERCIALE BANK\n";
 cout<<"\t\t :: Main menu ::\n";
 cout<<"\n\t\t1.New bank_account";
 cout<<"\n\t\t2.deposit total money";
 cout<<"\n\t\t3.withdraw total money";
 cout<<"\n\t\t4.balance enquiry";
 cout<<"\n\t\t5.all bank_account holder list";
 cout<<"\n\t\t6.close_bank_account";
 cout<<"\n\t\t7.updet_bank_account";
 cout<<"\n\t\t8.Exit";
 cout<<"\n\n\t\t select your option(1-8): ";
 cin>>ch;
 switch(ch){

 case '1':
     write_Bank_account();
     break;
 case '2':
    system("cls");
    cout<<"\n\n\tplease Enter the bank_account no.:";
    cin>>num;
    monet_deposit_withdraw(num,1);
    break;
case '3':
    system("cls");
    cout<<"\n\n\tplease Enter the bank_account no.:";
    cin>>num;
    monet_deposit_withdraw(num,2);
    break;
case '4':
    system("cls");
    cout<<"\n\n\tplease Enter the bank_account no.:";
    cin>>num;
    display_sp(num);
    break;
case'5':
    display_all();
    break;
case'6':
    system("cls");
    cout<<"\n\n\tplease Enter the bank_account no.:";
    cin>>num;
    delete_Bank_account(num);
    break;
case'7':
   system("cls");
   cout<<"\n\n\tplease Enter the bank_account no.:";
    cin>>num;
    update_Bank_account(num);
    break;
case '8':
 system("cls");
 cout<<"\n\n\t Brought to you by comercial bank ";
  break;
default:
    cout<<"\a";



 }
  cin.ignore();
  cin.get();
 }while(ch!='8');



    return 0;
}
void write_Bank_account (){

Bank_account ac;
ofstream outfile;

outfile.open("Bank_account.dat",ios :: binary | ios ::app);
ac.creat_bank_account();
outfile.write(reinterpret_cast<char*>(&ac),sizeof(Bank_account));
outfile.close();

}
void delete_Bank_account(int n){
Bank_account ac;
ifstream infile;
ofstream outfile;
infile.open("Bank_account.dat",ios::binary);
 if(!infile){

    cout<<"file could not be open !! press any key......";
    return;
 }
outfile.open ("temp.dat",ios::binary);
infile.seekg(0,ios::beg);
while(infile.read(reinterpret_cast<char*>(&ac),sizeof(Bank_account))){

    if(ac.retacno()!=n){

        outfile.write(reinterpret_cast<char*>(&ac),sizeof(Bank_account));
    }

}
infile.close();
outfile.close();
remove("Bank_account.dat");
rename("temp.dat","Bank_account.dat");
cout<<"\n\nrecord deleted....";

}
void display_sp(int n){

Bank_account ac;
bool flag=false;
ifstream infile;
infile.open("Bank_account.dat",ios::binary);

if(!infile){

    cout<<"file could not be open !! press any key......";
    return;


}
cout<<"\n\tbalance details\n";
 while(infile.read(reinterpret_cast<char*>(&ac),sizeof(Bank_account))){

if(ac.retacno()==n){

 ac.Display_account();
  flag=true;


}



}
infile.close();
if(flag==false)
    cout<<"\n\n\t bank_account number does not exist ";
}
void display_all (){

system("cls");
Bank_account ac;
ifstream infile;
infile.open("Bank_account.dat",ios::binary);

if(!infile){

    cout<<"file could not be open !! press any key......";
    return;

}
cout<<"\n\n\tbank_account holder list\n\n";
cout<<"*************************************======================================*****************************\n";
cout<<" A/c no.         Name            Type   Balance    \n  ";

  while(infile.read(reinterpret_cast<char*>(&ac),sizeof(Bank_account))){

    ac.report();



  }
  infile.close();
}

void update_Bank_account(int n){

bool found=false;
Bank_account ac;
fstream file;
file.open("Bank_account.dat",ios::binary|ios::in|ios::out);

if(!file){

    cout<<"file could not be open !! press any key......";
    return;
}
while(!file.eof()&& found==false){

    file.read(reinterpret_cast<char*>(&ac),sizeof(Bank_account));
    if(ac.retacno()==n){
        ac.Display_account();
        cout<<"\n\n\tplease Enter the new details of bank_account"<<endl;
        ac.updation();
        int pos=(-1)*
    static_cast<int>(sizeof(Bank_account));
    file.seekp(pos,ios::cur);
    file.write(reinterpret_cast<char*>(&ac),sizeof(Bank_account));
    cout<<"\n\n\t record updated";
    found=true;
    }
}
    file.close();
    if(found==false)
        cout<<"\n\n\t record not found ";


}
 void monet_deposit_withdraw(int n, int option){
 int amt;
 bool found=false;
 Bank_account ac;
 fstream file;
 file.open("Bank_account.dat",ios::binary|ios::in|ios::out);

 if(!file){

    cout<<"file could not be open !! press any key......";
    return;

 }

  while(!file.eof()&& found==false){

    file.read(reinterpret_cast<char*>(&ac),sizeof(Bank_account));
    if(ac.retacno()==n){
        ac.Display_account();
        if(option==1){
            cout<<"\n\n\tto money_deposits total money ";
            cout<<"\n\n\tplease Enter the total money to be money deposited: ";
            cin>>amt;
            ac.dep(amt);
        }
        if(option==2){
           cout<<"\n\n\tto withdraw total money ";
            cout<<"\n\n\tplease Enter the total money to withdraw: ";
            cin>>amt;
            int bal=ac.retmoney_deposit()-amt;
            if(bal<0)
                cout<<"insufficience balance ";
            else
                ac.draw(amt);


        }
   int pos=(-1)*
     static_cast<int>(sizeof(Bank_account));
    file.seekp(pos,ios::cur);
    file.write(reinterpret_cast<char*>(&ac),sizeof(Bank_account));
    cout<<"\n\n\t record updated";
    found=true;

 }
  }
  file.close();
  if(found==false)
    cout<<"\n\n\trecord not found ";


 }
