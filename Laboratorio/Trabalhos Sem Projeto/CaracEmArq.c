#include <stdio.h>
#include <stdlib.h>



void NomeArq(char** NomeArq){ 
	char c;
	int count=0;
	char* sent=NULL;

	do {
	c = fgetc(stdin);
	sent = realloc(sent, sizeof(char)*(count+1));
	sent[count] = c; 
	count++;
	
	} while (c != '\n');
	sent[count-1] = '\0';
	*NomeArq = sent;
}


int main(){

	char* Arq=NULL;
	NomeArq(&Arq);
	FILE* FilePtr = fopen(Arq, "r");
	fseek(FilePtr, 0, SEEK_END);
	printf("%ld", ftell(FilePtr));
	return 0;
}
