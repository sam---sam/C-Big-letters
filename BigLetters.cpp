//display big letters 
#include <iostream>
#include <string>

using namespace std;

enum letters{
space=10,
A=4536650,
B=12925230,
C=13124108,
D=12921164,
E=32010782,
F=32010768,
G=15224366,
H=19495506,
I=4329604,
J=2165324





};


//This function will return the value of the string very basic compression ...
int getTheNumb (string str){
int key=0,bin=16777216;
for (int i=0;i<str.length();i++){
if (str.at(i)=='*')
key+=bin;
bin/=2;
}
return key;
}


//builder of char matrix , takes key number return a matrix of booleans
bool ** show(int key){
int bin=16777216;
//making a 2d array 
bool **a = new bool * [5];
for (int i=0;i<5;i++)
a[i] =  new bool [5];

for (int i=0;i<5;i++)
for (int ii=0;ii<5;ii++){
if (key < bin)
a[i][ii]=0;
else{
a[i][ii]=1;
key-=bin;
}
bin/=2;
}

return a;
}

//
string toBig(string str){
int lgh =str.length();
letters Char=A;//

//tempo matrix 
bool ** tmpArray= new bool *[5];
for (int i=0;i<5;i++)
tmpArray [i]= new bool [5]; 

//


bool ** array= new bool *[5];
for (int i=0;i<5;i++)
array [i]= new bool [5*lgh]; 



for (int i=0;i<lgh;i++){


if (str.at(i)=='A' || str.at(i)=='a')
Char=A;
else if (str.at(i)=='B' || str.at(i)=='b')
Char=B;
else if (str.at(i)=='C' || str.at(i)=='c')
Char=C;
else if (str.at(i)=='D' || str.at(i)=='d')
Char=D;
else if (str.at(i)=='E' || str.at(i)=='e')
Char=E;
else if (str.at(i)=='F' || str.at(i)=='f')
Char=F;
else if (str.at(i)=='G' || str.at(i)=='g')
Char=G;
else if (str.at(i)=='H' || str.at(i)=='h')
Char=H;
else if (str.at(i)=='I' || str.at(i)=='i')
Char=I;
else if (str.at(i)=='J' || str.at(i)=='j')
Char=J;



tmpArray=show(Char);

//add
for (int i1=0;i1<5;i1++)
for (int i2=0;i2<5;i2++)
array[i1][i2+5*i]=tmpArray[i1][i2];
}

string out;
// disp
for (int i=0;i<5;i++){
for (int ii=0;ii<5*lgh;ii++)
if (array[i][ii])
out +="#";
else
out +=" ";
out +="\n";
}

delete array , tmpArray ; 

return out;
}


//
//
//



void wrapper(string str){
int lgh = str.length();
for (int i=0;i<lgh;i++)
cout <<"*";
cout <<endl;
}

void print(string str , int col=37 , bool wr=false){

if (wr)
wrapper(str);
int i=col+30;
cout << "\033[0;" << i << "m"<<str<<"\033[0m" ;
if (wr)
wrapper(str);

}



//
//

int main (){

cout <<"   * "<<endl;
cout <<"   * "<<endl;
cout <<"   * "<<endl;
cout <<"*  * "<<endl;
cout <<" **  "<<endl;

int val=getTheNumb("   *    *    * *  *  **  ");
cout <<val<<endl;




string str;

cout << "\nEnter your name : ";
cin >> str;
cout <<endl;

print(toBig(str),6,true);




return 0;
}


