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
