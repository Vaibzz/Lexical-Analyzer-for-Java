//lexical Analyzer for java
//authors@ Vaibhav & Dvyanshi

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

char keywords[50][15]={"abstract","assert","boolean","break",
"byte","catch","case","char","const",
"continue","class","default","do",
"double","else","enum","extends",
"final","finally","float","for",
"goto","if","import","implements",
"int","interface","insatnceof","long",
"native","new","package","private",
"public","protected","return","short",
"static","switch","strictfp","super",
"synchronized","this","throw","throws","transient",
"try","volatile","void","while"};
int i=0,count_identifier=0,count_keyword=0,count_number=0,count_operator=0,count_separators=0;
void check_key(char *p)
{
    int k,flag=0;
    for(k=0;k<=48;k++)
    {
        if(strcmp(keywords[k],p)==0)
        {
            printf("%s :- KEYWORD \n",p); //for checking if given character is keyword...
            Sleep(50);
            count_keyword++;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(isdigit(p[0]))
        {
            printf("%s :- NUMERIC LITERAL \n",p); //for checking if given character is Numeric Literal...
            Sleep(50);
            count_number++;
        }
        else
        {
            if(p[0]!='\0')
            {
                printf("%s :- IDENTIFIER\n",p); //for checking if given character is identifier...
                Sleep(50);
                count_identifier++;
            }
        }
    }
    i=-1;
}
int main()
{
    int j;
    char filename[50];
    char chr,ckeck_str[25],separators[20]="\n\t,;:(){}[]#\"<>",oprators[20]="!%^&*-+=~|.<>/?";
    FILE *f1;
    cout<<"Welcome.. This is Lexical Analysis..\n\nKindly Enter the JAVA file location: (drive:\\folder\\filename) \n";
    cin>>ws;
    cin.getline(filename,50);
    f1 = fopen(filename,"r");
    if(f1==NULL)
    {
        cout<<"OOPS! File not found...! ";
        exit(0);
    }
    cout<<"\n\nAnalysing...";
    cout<<filename<<"\nPlease wait...\n\n";
    Sleep(1000);
    cout<<"Identifying tokens...\n";
    Sleep(1000);
    cout<<"Identifying identifiers...\n";
    Sleep(1000);
    cout<<"Identifying operators...\n";
    Sleep(1000);
    cout<<"Identifying numeric literals...\n";
    Sleep(1000);
    cout<<"File scan Completed Successfully...\a\n";
    Sleep(600);
    cout<<"Displaying all tokens...\n\n\a";
    Sleep(1000);
    cout<<"******************************************\n";
    while((chr=fgetc(f1))!=EOF)
    {
        for(j=0;j<=14;j++)
        {
            if(chr==oprators[j]) //for checking if given character is operator...
            {
                cout<<chr<<" :- OPERATOR \n";
                Sleep(50);
                count_operator++;
                ckeck_str[i]='\0';
                check_key(ckeck_str);
            }
        }
        for(j=0;j<=14;j++)
        {
            if(i==-1)
                break;
            if(chr==separators[j]) //for checking if given character is separator...
            {
                if(chr==';'||chr==','||chr=='<'||chr=='>'||chr=='{'||chr=='}'||chr=='('||chr==')'|| chr==':')
                {
                    cout<<chr<<" :- SEPARATOR\n";
                    count_separators++;
                    Sleep(50);
                }
                if(chr=='#')
                {
                    while(chr!='>')
                    {
                        printf("%c",chr);
                        chr=fgetc(f1);
                    }
                    i=-1;
                    break;
                }
                if(chr=='"')
                {
                    do
                    {
                        chr=fgetc(f1);
                        printf("%c",chr);
                    }while(chr!='"');
                    cout<<"\b"<<" :- ARGUMENT \n"; //for checking if given character is argument to a function...
                    Sleep(50);
                    i=-1;
                    break;
                }
                ckeck_str[i]='\0';
                check_key(ckeck_str);
            }
        }
        if(i!=-1)
        {
            ckeck_str[i]=chr;
            i++;
        }
        else
            i=0;
    }
    cout<<"______________________________________________________\n";
    cout<<"\nOverall Statistics of given JAVA program.\a\n";
    cout<<"\n\n*********\nNo. of Keywords in JAVA file are: "<<count_keyword;
    cout<<"\nNo. of Identifiers in JAVA file are: "<<count_identifier;
    cout<<"\nNo. of Operators in JAVA file are: "<<count_operator;
    cout<<"\nNo. of Numeric literals in JAVA file are: "<<count_number;
    cout<<"\nNo. of Separators in JAVA file are: "<<count_separators;
    cout<<"\n*********\n";
    return 0;
}
