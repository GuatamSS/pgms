#include <stdio.h>
#include <string.h>

char prod[10][10];

int recursive_parser(char *sentence,int n,int start_symbol_index,int input_sentence_index,int production_no){
	//base case
	if(input_sentence_index==strlen(sentence)){
		return 1;
	}

	//case where the terminal matches
	if(islower(prod[production_no][start_symbol_index])){
		if(sentence[input_sentence_index]==prod[production_no][start_symbol_index]){
			input_sentence_index++;
			start_symbol_index++;
			if(start_symbol_index<=strlen(prod[production_no])-1){ 			
				return recursive_parser(sentence,n,start_symbol_index,input_sentence_index,production_no);
			}			
			else{
				return 1;
			}
		}
		else{			
			return 0;
		}
	}
	else{
		//case when there is a non terminal
		char non_terminal = prod[production_no][start_symbol_index];
		int i;
		//check all productions having non_terminal 
		for(i=1;i<n;i++){
			if(prod[i][0]==non_terminal){
				if(recursive_parser(sentence,n,2,input_sentence_index,i)){
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	char ch;
	int n,i;
	printf("Enter the no. of productions:\n");
	scanf("%d",&n);
	printf("Enter the productions:\n");
	for(i=0;i<n;i++)
		scanf("%s%c",prod[i],&ch);

	printf("Enter the input sentence:\n");
	char sentence[100];
	scanf("%s",sentence);

	if(recursive_parser(sentence,n,2,0,0)){
		printf("SUCCESSFULLY PARSED\n");
	}
	else{
		printf("PARSING FAILED\n");
	}
	return 0;
}
