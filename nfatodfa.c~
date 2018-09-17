#include<stdio.h>
#include<stdbool.h>


struct node{
	struct node *input[50];
	bool isfinal;
	bool isstart;
} node;

char table[50][50];
int n1,n2,i,j;
char inputsymbols[5][20];
	
int main(){

	printf("Enter the number of states\n");
	scanf("%d",&n1);

	printf("Enter the number of input symbols\n");
	scanf("%d",&n2);

	//Read input symbols
	for(i=0;i<n2;i++){
		printf("Enter the input %d",i+1);
		scanf("%s",inputsymbols[i]);
	}

	//
	for (i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			printf("q%d----%s--->",i,inputsymbols[j]);
			scanf(" %c",&table[i][j]);
		}

	}
	printtable();
}

printtable(){
	printf("States\t");
	for (i=0;i<n2;i++){
		printf("%s\t",inputsymbols[i]);
	}
	printf("\n");	
	for (i=0;i<n1;i++){
		printf("%d\t",i);
		for(j=0;j<n2;j++){
			printf("%c\t",table[i][j]);
		}
		printf("\n");
	}
}
	

