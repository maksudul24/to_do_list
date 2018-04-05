#include <bits/stdc++.h>
#define ll long long
#define c1(X) cout<<X<<endl;
using namespace std;

struct tasks
{
    //structure for holding task information
    ll day,month,year;
    char description[100];
};
void update();
void display();
vector <tasks> lists;
int main(void)
{
    char name[100],action,date[100];
    ll day,month,year,k;
    tasks temp;
    printf("Enter your name:\n");
    gets(name);
    printf("\n\nWELCOME %s !!\nWhat do you want to do now?\n\n\n",name);
    printf("Enter U for organizing your ToDo list,Q for accessing your ToDo list,R for reset,& G for exit\n\n\n");
    while(1){
        printf("Enter action\n\n");
        scanf(" %c",&action);        //input for query,i.e updating list,viewing list,reset,and exit
        if(action == 'E'){
            printf("Take Care!!\n");
            break;
        }
        if(action == 'U'){
            printf("Enter task date in dd.mm.yy format or press 'G' to exit\n");
            update();
        }
        else if(action == 'Q')display();
        else{
            printf("Your ToDo list is cleared!!\n");
            lists.clear();
        }
    }
    return 0;
}
void update(void)            //function for updating task list
{
    tasks temp;
    char date[100];
    while(1){
        scanf("%s",&date);        //taking task date input
        if(date[0] == 'G')break;
        sscanf(date,"%lld%*c%lld%*c%lld",&temp.day,&temp.month,&temp.year);
        getchar();
        gets(temp.description);     //taking task information
        lists.push_back(temp);
    }
    return;
}
void display(void)            //function for displaying the task list
{
    sort(lists.begin(),lists.end());
    if(lists.empty())printf("List is empty\n");
    else{
        for(int i = 0 ; i < lists.size() ; i++){
            printf("%lld.%lld.%lld   %s\n\n\n",lists[i].day,lists[i].month,lists[i].year,lists[i].description);
        }
    }
    return;
}

