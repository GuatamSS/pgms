#include<stdio.h>
#include<stdbool.h>


struct node{
	struct node *input[50];
	bool isfinal;
	bool isstart;
} node;

struct t{
	int input;
	int tostate[10][10];
};
struct State{
	char name[20];
	struct t trans[50];
};

struct State states[50];

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


	for(i=0;i<n1;i++){
		//Create state;
		strcpy(states[i].name,"q0");
	}
	//
	for (i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			int k=0;int l=0;int *q;
			do{
				printf("q%d----%s--->",i,inputsymbols[j]);
				int *q=states[i].trans[j].tostate[k++][l++];
				scanf("%d",&q);
				//printf("%d",q);
			}while(q!=-1);
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
			int k=0;
			printf("%d\t",states[i].trans[j].tostate[k++][0]);
		}
		printf("\n");
	}
}
	

