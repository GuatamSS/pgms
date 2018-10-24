#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int isKeyword(char buffer[],int idc)
{
	int i,flag=0;
	char temp[20];
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
	
	for(i=0;i<idc;i++)
		temp[i]=buffer[i];
	//printf("\nBUffer:%s\n",buffer);
	for(i=0;i<32;i++)
	{
		if(strcmp(keywords[i], temp) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
			
							
}



void main()
{
	FILE *fp = fopen ( "program.txt", "r" );
	char line [ 128 ]; 
	int len;
	char ch,a;
	char identi[10],dig[10],eq[2];
	int i,j,state,counter,k;
	int digc,idc;
	int final[]={2,3,4,6,7,21,9,11,13,14,16,17,18,19,20,23};	
	fp = fopen("program.txt", "r");
    if (fp == NULL)
        	printf("Error");
	printf("\n\n");
	while ( fgets ( line, sizeof line, fp ) != NULL ) 
    {
		len=strlen(line);
		
		state=0;
		counter=0;
		
		for(i=0;i<=len-1;i++)
		{
			if(line[i]=='<')
			{
				state=1;
				if(line[i+1]=='=')
				{
					state=2;
					i=i+1;
					counter=i+1;
				}
				else
				if(line[i+1]=='>')
				{
					state=3;
					i=i+1;
					counter=i+1;
				}
				else if(line[i+1]!='=' && line[i+1]!='>')
				{
					state=4;
					counter=i+1;
				}
					
				
				if(state==2)
				{
				
					printf("<= :->");
					printf("LE");
					printf("\t");
				}	
				else if(state==3)
				{
						
					printf("<> :->");
					printf("NE");
					printf("\t");
				}
				else if(state==4)
				{
					printf("< :->");
					printf("LT");
					printf("\t");
				}
				
			}
			else if(line[i]=='>')
			{
				state=5;
				if(line[i+1]=='=')
				{
					state=6;
					i=i+1;
					counter=i+1;
				}
				
				else if(line[i+1]!='=')
				{
					state=7;
					counter=i+1;
				}
				if(state==6)
				{
				
					printf(">= :->");
					printf("GE");
					printf("\t\t");
				}	
				else if(state==7)
				{
						
					printf("> :->");
					printf("GT");
					printf("\t\t");
				}
					
			}
			
			else if(line[i]=='+')
			{
				state=12;
				if(line[i+1]=='+')
				{
					state=13;
					i=i+1;
					counter=i+1;
				}
				else if(line[i+1]!='+')
				{
					state=14;
					counter=i+1;
				}
				if(state==13)
				{
				
					printf("++ :->");
					printf("Increment");
					printf("\t\t");
				}	
				else if(state==14)
				{
						
					printf("+ :->");
					printf("PLUS");
					printf("\t\t");
				}
					
				
			}
			
			else if(line[i]=='-')
			{
				state=15;
				if(line[i+1]=='-')
				{
					state=16;
					i=i+1;
					counter=i+1;
				}
				else if(line[i+1]!='-')
				{
					state=17;
					counter=i+1;
				}
				if(state==16)
				{
				
					printf("-- :->");
					printf("Decrement");
					printf("\t\t");
				}	
				else if(state==17)
				{
						
					printf("- :->");
					printf("MINUS");
					printf("\t\t");
				}
					
				
			}
			
			else if(line[i]=='*')
			{
				state=18;
				printf("*:->");
				printf("MUL");
				printf("\t\t");
			}
			
			else if(line[i]=='/')
			{
				state=19;
				printf("/:->");
				printf("DIV");
				printf("\t\t");
			}
			else if(line[i]=='%')
			{
				state=20;
				printf("%%:->");
				printf("MOD");
				printf("\t\t");
			}
			
			
			
			
			else if(line[i]=='=')
			{
				state=8;
				if(line[i+1]=='=')
				{
					state=9;
					i=i+1;
					counter=i+1;
				}
				else
				if(line[i+1]!='=')
				{
					state=21;
					counter=i+1;
				}
					
				
				if(state==9)
				{
				
					printf("== :->");
					printf("EQ");
					printf("\t\t");
				}	
				else if(state==21)
				{
						
					printf("= :->");
					printf("Assignment");
					printf("\t\t");
				}
					
			}
			
			
			else if(isalpha(line[i]))
			{	
				idc=0;
				identi[idc++]=line[i];
				state=10;
				for(j=i+1;j<=len;j++)
				{
					
					if(isalpha(line[j])|| isdigit(line[j]))
					{
						identi[idc++]=line[j];
						state=10;
						counter++;
						i=counter;
						j=i;
						
					}	
					else
					{
						state=11;
						break;
					}	
					
					
				}	
				if(state==11)
				{
					
					
						
					for(k=0;k<idc;k++)
					{
						printf("%c",identi[k]);
					}
					
					printf(" :->");
					
					if(isKeyword(identi,idc))
						printf("Keyword");
					else
						printf("Identifier");	
					printf("\t\t");
				}					
			}	
			else if(isdigit(line[i]))
			{
				state=22;
				digc=0;
				dig[digc++]=line[i];
				for(j=i+1;j<=len;j++)
				{
					if(isdigit(line[j]))
					{
						dig[digc++]=line[j];
						state=22;
						counter++;
						i=counter;
						j=i;
					}
					else
					{
						
						state=23;
						break;
					}
					
				}
				if(state==23)
				{
					
					for(k=0;k<digc;k++)
					{
						printf("%c",dig[k]);
					}
					
					
					printf(":->");
					printf("Digit");	
					printf("\t");
				}
			}
			else
			{
				if(line[i]==' ')
					counter=counter+2;
				if(line[i]=='"')
					counter=counter+1;
				if(line[i]=='[')
					counter=counter+3;
				if(line[i]==',')
					counter=counter+3;
			}
			
			
		}
		printf("\n\n");
	}

}
