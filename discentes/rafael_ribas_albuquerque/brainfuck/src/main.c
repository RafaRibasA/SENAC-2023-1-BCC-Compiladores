#include <stdio.h>

#define TAMANHODATA 1001
void brainfuck (char *texto, char *comeco) {

	char comandos;

	int i;

	char dados[TAMANHODATA] = {0};

	char *ponteiro;

	ponteiro = &dados[TAMANHODATA / 2]; //iniciar o ponteiro na metade do vetor, assim consigo ir tanto pra direita quanto ppara esquerda 


		while (comandos = *texto++)
	
			switch (comandos) {
				
	    case '>':
	      // printf("chegou >");
				ponteiro++;
	      break;
	    
			case '<':   
	    // printf("chegou <");
				ponteiro--;
	      break;
	    
			case '+':  
	    	// printf("chegou +");
				(*ponteiro)++;
	      break;
	    
			case '-':  
	    	// printf("chegou -");
				(*ponteiro)--;
	      break;
	    case '.':   
	    // printf("chegou .");
				printf("%c", *ponteiro);
	      break;
	    
			case ',':  
				printf("chegou ,");
	      *ponteiro = *comeco++;
	      break;

			case '[':
				// printf("chegou [");
				if (!*ponteiro){

					//procura até a outra chave e faz seu loop
					for (i = 1; i; texto++){

						if (*texto == '['){
							i++;
						}
						else if(*texto == ']'){
							i--;
						}
					}
				}
				break;

			case ']':
// printf("chegou ]");
				if (*ponteiro){

					texto -= 2;

					for (i = 1; i; texto--) 

						if(*texto == ']') {
							i++;
						}
						else if (*texto == '[') {
							i--;
						}
						texto++;
				}
				break;
		}
	
			printf("\n");
}


int main() {
  
	char *olaMundo= "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>>+++++++++++.---.-----------.<<++.>>++++++++++++.++++++++.-------.----------.+++++++++++.";
  
	char *start = "";
  
	brainfuck(olaMundo, start);
  
	return 0;

}