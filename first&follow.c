#include<stdio.h>
#include<string.h>

char p[10][10];
char first(char a[]){
	if(islower(a)){
		return a;
	}
	for(i=0;i<num;i++){
		if(a==p[i][0]){
			if(islower(p[i][2]){
				//Add to first(a)
			}else{
				//calculate first(A) add it to First a
			}
		}
	}
}

char getFirstSymbol(){
}

int main(){
	int num,i;
	printf("Enter the number of production\n");
	scanf("%d",&num);
	
	printf("Enter the productions\n");
	for(i=0;i<num;i++){
		scanf("%s",p[i]);
	}

	
	return 1;
}

