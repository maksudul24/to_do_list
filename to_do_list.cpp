#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
char data[60000];
char File_name[12];
char next_line='\n';
void get_data();
void time();
void write_data();
void output();
void date_input();
int main()
{
    using namespace std;

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
void time()
{
    int length,ind;
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
