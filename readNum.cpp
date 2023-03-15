#include<iostream>
#include<math.h>
using namespace std;
string table(char s){
int n=int(s);
switch (n){
case 0:
return "zero";
case 1:
return "one" ;
case 2:
return "two";
case 3:
return "three";
case 4:
return "four";
case 5:
return "five";
case 6:
return "six";
case 7:
return "seven";
case 8 :
return "eight";
case 9:
return "nine";
}

}


string convert(string x,bool *teen=new bool){
int len=x.length();
int l=len;
string result="";
string rank[6]={
"bilion",/*10-12*/
"milion",/*7-9*/
"thousand",/*4-6*/
"hundred",/*3*/
"ty",/*2*/
/*1*/""

};
/*100000000 */
for(int i=0;i<len;i++){
 int g=l-i;
if(x.length()>1&&x[i]=='0')
continue;
switch (g){
*teen=0;
case 10 ... 12:

if(g==10)
result+=table(x[i]-'0')+" "+rank[0]+" ";
else{
bool tt=0;
string d=x.substr(i,g-9);
result+=convert(d,&tt)+rank[0]+" ";
i+=2;
}
break;
case 7 ... 9:
if(g==7)
result+=table(x[i]-'0')+" "+rank[1]+" ";
else{
bool tt=0;
string d=x.substr(i,g-6);
result+=convert(d,&tt)+rank[1]+" ";
i+=2;
}
break;
case 4 ... 6:
if(g==4)
result+=table(x[i]-'0')+" "+rank[2]+" ";
else{
bool tt=0;
string d=x.substr(i,g-3);
string t=convert(d,&tt);
result+=t+rank[2]+" ";
if(tt&&g==5)
i+=1;
else
i+=2;
}
break;
case 3:
if(x.length()>3)
result+="and ";
result+=table(x[i]-'0')+" "+rank[3]+" ";
break;
case 2:{
string num=table(x[i]-'0');

if(num=="one"){
if(x[i+1]=='1')
result+="eleven ";
else if(x[i+1]=='2')
result+="twelve ";
else if(x[i+1]=='3')
result+="thirteen ";
else if(x[i+1]=='0')
result+="ten ";
else{
result+=table(x[i])+"teen ";
}
i++;
*teen=1;
break;
}
else if(num=="two"){
num="twen";}
else if(num=="three"){
num="thir";
}
result+=num+rank[4]+" ";
*teen=1;
break ;
}
case 1:
result+=table(x[i]-'0')+" "+rank[5]+" ";
break;
}


}
return result;
}
int main()
{
    string x;
    cout<<"Enter A Number: ";
    cin>>x;
    cout<<convert(x)    ;
    return 0;
}
