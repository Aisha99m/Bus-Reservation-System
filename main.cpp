#include <iostream>
#include<fstream>
#include<string.h>
void choice();
using namespace std;
struct bus{
char busnum[6];
char tarrif[20];
char source[20];
char destination[20];
char startingTime[20];

}b;

void createbus()   //function definition
{
    ofstream ofile;
    ofile.open("busRecord.txt", ios::app); //append the text ,adding data to bus record.txt
    if(ofile.fail()){
        cout<<"failed to open the file";
    }
    else{
        cout<<"please Enter Bus Information "<<endl;
        cout<<" Enter Bus Number: ";
        cin>>b.busnum;
        cout<<" Enter Tarrif: ";
        cin>>b.tarrif;
        cout<<" Enter Source: ";            // enter the whole information
        cin>>b.source;
        cout<<" Enter Destination: ";
        cin>>b.destination;
        cout<<" Enter Starting Time: ";
        cin>>b.startingTime;
        ofile.write((char*)&b, sizeof(b));
        cout<<"Bus record added successfully!!!";
        ofile.close();

    }
    choice();  // calling function 1
}
void readallbusrecord(){     //function definition 2
ifstream sfile;
//open text file
sfile.open("busRecord.txt", ios::in);
if(sfile.fail()){
    cout<<"Cannot open the file";

}
else {
    cout<<"Bus Record"<<endl;
    cout<<"[Bus Number]\t[Tariff]\t[Source]\t[Destination]\t[Starting Time]\n";
    cout<<"==========================================================================\n";
    while(sfile.read((char*)&b,sizeof(b))) {
        cout<<b.busnum<<"\t\t"<<b.tarrif<<"\t\t"<<b.source<<"\t\t"<<b.destination<<"\t\t"<<b.startingTime<<endl;
    }
    sfile.close();
}
choice();   //calling function 2
}
void searchBus(){ // function definition 3
    char ch[6];
    int a=0;
    ifstream sfile;
    sfile.open("busRecord.txt", ios::in);
    if(sfile.fail()){
        cout<<"Error in opening the file";
    }
    else{
        cout<<"Enter bus number that you are looking for \n";
        cin>>ch;                                                //enter the value again and again
        while(sfile.read((char*)&b, sizeof(b))){
            if(!strcmp(b.busnum,ch)){
                cout<<"The bus information that you are looking for is \n";
                cout<<"Bus Number "<<b.busnum;
                cout<<" Tarrif:"<<b.tarrif;
                cout<<" Source: "<<b.source;
                cout<<"Destination: "<<b.destination;
                cout<<"Starting Time: "<<b.startingTime;
                a=1;
            }

        }
        if(a==0){
            cout<<" Sorry the bus record is not found";
        }
        sfile.close();
    }
choice(); // calling function 3
}
void modifyBusRecord(){    //
char ch[6];
int found=0;
cout<<"Enter bus number to be modified\n";
cin>>ch;
fstream file;
file.open("busRecord.txt", ios::out|ios::in);
if(file.fail()){
    cout<<"Error in opening the file";
}
else {
    while (file.read((char*)&b,sizeof(b))&& found==0){ // algebagnm
        if(strcmp(b.busnum,ch)){
            cout<<"Enter the new details of the bus\n";
            cout<<" Enter the new bus number: ";
            cin>>b.busnum;
            cout<<" Enter the new tarrif: ";
            cin>>b.tarrif;
            cout<<" Enter the new source: ";
            cin>>b.source;
            cout<<"Enter te new destination: ";
            cin>>b.destination;
            cout<<"Enter the new starting time: ";
            cin>>b.startingTime;

            int back=-1*sizeof(b);
            file.seekp(back,ios::cur);
            file.write((char*)&b, sizeof(b));
            found=1;
            cout<<"modified successfully\n";

        }
    }
    if(found==0){
        cout<<"bus record not found";
    }
}
file.close();
choice();  //calling function 4
}
void deleteBusRecord(){
char ch[6];
cout<<"enter bus number that you want to delete\n";
cin>>ch;
ifstream sfile;
sfile.open("busRecord.txt");
ofstream ofile;
ofile.open("temp.txt");
while(sfile.read((char*)&b, sizeof(b))){
    if(strcmp(b.busnum,ch)){
        ofile.write((char*)&b,sizeof(b));
    }

}
sfile.close();
ofile.close();
remove("busRecord.txt");
rename("temp.txt","busRecord.txt");
cout<<"bus recored deleted successfully!!";
choice(); //calling function 5
}
void choice(){
    int ch;
cout<<"=================================================================\n";
cout<<"            WELCOME TO BUS RESERVATION SYSTEM                      |\n";
cout<<"            PRESS [1] TO CREATE BUS RECORD                         |\n";
cout<<"            PRESS [2] TO DISPLAY ALL BUS RECORD                    |\n";
cout<<"            PRESS [3] TO SEARCH SPECIFIC BUS RECORD                |\n";
cout<<"            PRESS [4] TO MODIFY BUS RECORD                         |\n";
cout<<"            PRESS [5] TO DELETE BUS RECORD                         |\n";
cout<<"            PLEASE ENTER YOUR CHOICE (1-5)                         |\n";
cout<<"=================================================================\n";
tryagain:
cin>>ch;
switch(ch){
case 1:
    createbus();
    break;
case 2:
    readallbusrecord();
    break;
case 3:
    searchBus();
    break;
case 4:
    modifyBusRecord();
    break;
case 5:
    deleteBusRecord();
    break;
default:
    cout<<"you entered invlaid number \n";
 goto tryagain;
    break;
}
}
int main()
{
    choice();
return 0;
}
