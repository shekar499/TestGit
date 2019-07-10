#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#define DEBUG
/*struct class{
int classes[5];
int feeze[5];
};*/
#define ROW 5
#define COL 10
struct student{
int srollno;
char sname[20];
int sclass;
int smarks[6];
int sfeeze[3];
};
long tclass[ROW][COL];
int *pclass[5];
struct student svar[10];

void hidePassword(char* ch);
int login(char*,char*);
int resetPassword();
void admin();
int feezeCal(int,char*);
int registration();
void markavg(int sum,int avg,int status);
void dummy();

int passCount=0;
char user_name[20];
char password[20];
char Adm_user[]="shekar";
char Adm_pwd[]="shekar12";

int main()
{
      int select_dept;

    printf("***********************************************\n");
    printf("*   Name      :ZPH School Thatlwai            *\n");
    printf("*   Address   :Thatwai, Raikal, Karimnager    *\n");
    printf("*   Principle :Gangaiah K                     *\n");
    printf("*   Since     :2007                           *\n");
    printf("***********************************************\n");
    printf("\n");
    printf("     WELCOME TO ZPH SCHOOL THATLAWAI    \n\n");



   while(1){
         printf("Please Select Department below...\n");
         printf(" 1.Administration Department \n 2.Examination Department \n 3.Social Department \n 4.exit\n");
         scanf("%d",&select_dept);
    switch(select_dept)
    {

        case 1:

                if(login(user_name,password)){
                    printf("Login success\n");
                    int status=1;
                    do{
                    admin();
                    printf("\n Do you want update other student feeze? if Yes enter 1, No enter 0 \n");
                    scanf("%d",&status);
                    }while(status);
                    }

                    else{
                        printf("Reset your password..\n");
                        // printf("%s before Password reset \n",Adm_pwd);
                        if(resetPassword()){
                        printf("\n %s Password reset done Sucessfully,Please login....\n",Adm_pwd);
                        }
                    }


                    break;
        case 2:
                    if(login(user_name,password))
                    {
                    printf("Login success\n");
                    int status=1;
                    do{

                    registration();
                    printf("\n Do you want update other student marks? if yes enter 1,No enter 0 \n");
                    scanf("%d",&status);
                    }while(status);

                    }
                    else{
                        printf("Reset your password..\n");
                        if(resetPassword())
                        {
                        printf("\n %s Password reset done Sucessfully,Please login.... \n\n",Adm_pwd);
                        }
                    }
                    break;
        case 3:printf("Implementations are going on Social Department..\n \n");
                    break;
        case 4:exit(1);
        default:printf("OOPS Invalid selection.For valid  \n \n");
                break;

    }

   }//while

    return 0;
}

void hidePassword(char* ch)
{
     #ifdef DEBUG
    printf("\n inside hidePassword function..\n");
    #endif // DEBUG
    int pi;
    char pch;
        for(pi=0;pi<8;pi++)
            {
                        pch=getch();
                        ch[pi]=pch;
                        pch='*';
                        printf("%c",pch);
             }
                    ch[pi]='\0';
                    printf("\n");

}

int login(char* user_name,char* password){
    #ifdef DEBUG
    printf("\n inside login function..\n");
    #endif // DEBUG
        int flag=0;

        printf("Enter UserName ....\n");
        scanf("%s",user_name);
        printf("Enter the password of 8 characters>: \n ");
        hidePassword(password);
        #ifdef DEBUG
        printf("\n %s  %s username and password in login fun  \n:",user_name,password);

        printf("\n %s  %s change username and password in login fun  \n:",Adm_user,Adm_pwd);
        #endif // DEBUG
                if( (strcmp(user_name,Adm_user)==0) && (strcmp(password,Adm_pwd)==0))
                    {
                    flag=1;
                    }
                    else {
                       ++passCount;
                      if(passCount==3)
                        return flag;

                      login(user_name,password);

                    }
                    return flag;

}
/* Password reset function */
int resetPassword(){
    #ifdef DEBUG
    printf("\n inside resetPassword function..\n");
    #endif // DEBUG
    char ch[10];
    printf("\nEnter your New Password..It should be exact 8 characters..\n");
    scanf("%s",ch);
    strcpy(Adm_pwd,ch);
    /*printf("\n inside reset fun  :%s",Adm_pwd);*/
    passCount=0;
    return 1;
}
/* admin function..*/

void admin(){
     #ifdef DEBUG
    printf("\n inside admin function..\n");
    #endif // DEBUG
int clazz, rollno;
char name[20];

            printf("\n ...ClassWize Fee structure.....");
            printf("\n Class -----------------> Fee");
            printf("\n 1st Class -------------> 5000");
            printf("\n 2nd Class -------------> 6000");
            printf("\n 3rd Class -------------> 7000");
            printf("\n 4th Class -------------> 8000");
            printf("\n 5th Class -------------> 9000");
            printf("\n");
            printf("---------------------------------");
            printf("\n Please enter Name,RollNo,Class\n");
            scanf("%s %d %d",name,&rollno,&clazz);
                strcpy(svar[rollno-1].sname,name);
                svar[rollno-1].srollno=rollno;
                svar[rollno-1].sclass=clazz;

                feezeCal(clazz,name);

}
int feezeCal(int clazz,char *name){
     #ifdef DEBUG
    printf("\n inside feezeCal function..\n");
    #endif // DEBUG
float fclass[5]={5000,6000,7000,8000,9000};
float iamount,sum;
int icount=1;int statuz=1;
    printf("\n %s have to pay %f ",name,fclass[clazz-1]);
    printf("\n For 3 Installment %f each time you need to pay",fclass[clazz-1]/3.0);
    printf("\n");
    do{
    printf("\n enter the amount :\n");
    scanf("%f",&iamount);
        if((fclass[clazz-1])>iamount){
        sum=(fclass[clazz-1])-iamount;
        fclass[clazz-1]=sum;
        printf("\n %d. installment paid successfully.\n",icount);
        printf("\n Remaing Due is :%f",fclass[clazz-1]);
        icount++;
        printf("\n Do You want Pay again? if yes Press 1, No press 0 \n \n");
        scanf("%d",&statuz);
        }
        else{
            printf("\n %s, You paid total amount...\n",name);
            break;
            }
    }while(statuz);
}

/* student registration....*/
int registration(){
    #ifdef DEBUG
    printf("\n inside the registration function..\n");
    #endif // DEBUG
        char name[20];
        int rollno;
        int clazz;
        int mark,i;
        //int k,l;
        int sum=0, avg=0;
     //struct student svar[10];
     int flag=1,status=1;
     printf("\n enter student Name rollno Class \n ");
     scanf("%s%d%d",name,&rollno,&clazz);
     svar[rollno-1].srollno=rollno;
     strcpy(svar[rollno-1].sname,name);
     svar[rollno-1].sclass=clazz;

        if((clazz<=3) && (1<=clazz)){
                printf("\n enter 3 subject marks \n");
            for(i=0;i<3;i++){
                scanf("%d",&mark);
                if(mark<=100){
                        if(mark<35){
                             status=0;
                        }
                svar[rollno-1].smarks[i]=mark;
                sum=sum+mark;
                }else if(mark<0){
                printf("\n Enter marks between 0 to 100");
                }
            }
        }else if((clazz==4) || (clazz==5)){
            printf("\n enter 6 subject marks \n");
            for(i=0;i<6;i++){
                scanf("%d",&mark);
                if((mark<=100)){
                        if(mark<35){
                             status=0;
                        }
                svar[rollno-1].smarks[i]=mark;
                sum=sum+mark;
                }else if(mark<0){
                printf("\n Enter marks between 0 to 100");
                }
            }
        }
        avg=sum/i;
   tclass[clazz-1][rollno-1]=&svar[rollno-1];

        /*
        printf("\ndetails name:%s Roll:%d class:%d:",svar[rollno-1].sname,svar[rollno-1].srollno,svar[rollno-1].sclass);
        printf("marks");
        for(k=0;k<i-1;k++){
            printf("%d ",svar[rollno-1].smarks[k]);
            }
            printf("\n ...stuct  %d:",&tclass[clazz-1][rollno-1]);
        */
    marksavg(sum,avg,status);
    return flag;
}


void marksavg(int sum,int avg,int status){
     #ifdef DEBUG
    printf("\n inside marksavg function..\n");
    #endif // DEBUG

if(status==1){
    if((avg>80)&&(avg<100))
    printf("\nTotalMarks :%d  Avg  :%d  First Class With Distiction.\n \n",sum,avg);

    else if(((avg>70)&&(avg<80)))
    printf("\nTotalMarks :%d  Avg  :%d  First Class \n \n",sum,avg);
    else if(((avg>50)&&(avg<70)))
    printf("\nTotalMarks :%d  Avg  :%d  Second Class \n \n",sum,avg);
    else if(((avg>35)&&(avg<50)))
    printf("\nTotalMarks :%d  Avg  :%d  Third Class \n \n ",sum,avg);
   /* else
    printf("\nTotalMarks :%d  Avg  :%d  Failed.. \n  \n",sum,avg);*/
    }
    else{
    printf("\nTotalMarks :%d  Avg  :%d  Failed.. \n  \n",sum,avg);

    }
}

void dummy(){
}



