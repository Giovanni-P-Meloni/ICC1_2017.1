#include <stdio.h>
#include <stdlib.h>



//void EOM(char* string){
	




//}


int main(int argc, char* argv[]){
	
	char* sent=NULL; 
	char c;
	int count=0;

	do {
	c = fgetc(stdin);
	sent = realloc(sent, sizeof(char)*(count+1));
	sent[count] = c; 
	count++;
	
	} while (c != '\n');

	sent[count-1] = '\0';
	//*(sent + sizeof(char)*(count) = '\0'; 
	printf("%s\n", sent);





free (sent);
}
