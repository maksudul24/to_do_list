#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
using namespace std;
char data[60000];
char File_name[12];
void get_data();
void time();
void write_data();
void output();
void date_input();
int main()
{

    char work[6000];
    int i,length,command;
    cin>>command;
    if(command==1){
        gets(work);
    	get_data();
    	strcat(data,work);
    	length=strlen(data);
    	data[length]='\n';
    	write_data();
    	getchar();
    }
    else if(command==2) output();
    return 0;
}
void get_data()
{
    time();
    ifstream print(File_name,ios::in |ios::binary);
    if(!print){
        cout<<"Data is not present\n";
        date_input();
        return;
    }
    print.read((char *) &data,sizeof(data));
    print.close();
}
void time()
{
    int i,length,ind;
    time_t get_date;
    struct tm *temp;
    time(&get_date);
    temp=localtime(&get_date);

    strftime(File_name,11,"%x",temp);
    length=strlen(File_name);
    for(ind=0;ind<length;ind++){
        if(File_name[ind]=='/') File_name[ind]=' ';
    }
}
void output()
{
    time();
    ifstream print(File_name,ios::in |ios::binary);
    if(!print){
        cout<<"Data is not present\n";
        return;
    }
    print.read((char *) &data,sizeof(data));
    printf("%s",data);
    print.close();
}
void write_data()
{
    int length;
    time();
    ofstream file(File_name,ios::out | ios::binary);
    if(!file){
        cout<<"Can't open output file\n";
        return;
    }
    file.write((char *) data,sizeof(data));
    file.close();
}
void date_input()
{
    int ind,length;
    time();
    ofstream file(File_name,ios::out | ios::binary);
    if(!file){
        cout<<"Can't open output file\n";
        return;
    }
    length=strlen(File_name);
    File_name[length]='\n';
    file.write((char *) File_name,sizeof(File_name));
    file.close();
    get_data();

}
