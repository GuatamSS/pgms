#include<stdio.h>
#include<stdbool.h>
#include<string.h>


struct node{
	struct node *input[50];
	bool isfinal;
	bool isstart;
} node;

struct t{
	int input;
	int tostate[10];
	int number_of_trans;
};
struct State{
	char name[20];
	struct t trans[50];
};

struct State states[50];

char table[50][50];
int n1,n2,i,j,k;
char inputsymbols[5][20];


//Stack operations
int top1,top2;
int stack1 [50],stack2[50];

void push1(int n){
	if(top1<50)
		stack1[top1++]=n;
}
void push2(int n){
	if(top2<50)
		stack2[top2++]=n;
}

int pop1(){
	int t;
	t=stack1[top1--];
	return t;
}
int pop2(){
	int t;
	t=stack2[top2--];
	return t;
}

int* move(int s,int input){
	int k;
	int* r=malloc(sizeof(int)*10);
	for(k=0;k<states[s].trans[input].number_of_trans;k++){
		r[k]=states[s].trans[input].tostate[k];
	}
	return r;
}
	

/*
struct State * epsilon_closure(struct State k){
	int i;
	struct State p[50];
	for(i=0;i<n1;i++){
		push1(i);
	}
	while(top1!=-1){
		
	
    Stack P.addAll(S) #a stack containing all states in S
    Set C.addAll(S)   #the closure initially contains the states in S

    while ! P.empty() do
         s = P.pop()
         for r in m(s, epsilon) do
            # m(s, epsilon) is a set of states
            if r not in C then
                P.push(r)
                C.add(r)
            end if
        end for

    end while
    return C
}
*/


int main(){

	printf("Enter the number of states\n");
	scanf("%d",&n1);

	printf("Enter the number of input symbols\n");
	scanf("%d",&n2);

	//Read input symbols
	i=0;
	while(i<n2){
		printf("Enter the input %d",i+1);
		scanf("%s",inputsymbols[i]);
		i++;
	}
	n2++;
	strcpy(inputsymbols[i],"e");



	for(i=0;i<n1;i++){
		//Create state;
		strcpy(states[i].name,"q0");
	}
	//
	for (i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			int k=0;int l=0;int q;
			do{
				printf("q%d----%s--->",i,inputsymbols[j]);
				q=states[i].trans[j].tostate[k];
				scanf("%d",&q);
				printf("%d\n",q);
				if(q!=-1){
					states[i].trans[j].tostate[k]=q;
					k++;
				}
			}while(q!=-1);
			states[i].trans[j].number_of_trans=k;
		}

	}
	printtable();
	printf("\n-------------------\n");
	int p=0;
	for(p=0;p<states[0].trans[2].number_of_trans;p++){
		printf("%d--",move(0,2)[p]);
	}
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
			for(k=0;k<states[i].trans[j].number_of_trans;k++){
				printf("%d,",states[i].trans[j].tostate[k]);
			}
			printf("\t");
		}
		printf("\n");
	}
}

