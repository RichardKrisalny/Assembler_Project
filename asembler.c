#include "data.h"
#include <stdio.h>
int main (int argc, char*argv[])
{

/*
This is the main program.
It reads from the command line the names of the files one after the other and to one of them it adds the appropriate extension and sends to the functions in order to translate the file into machine language. And at the end of each round it releases the memories we have allotted to the dynamic arrays.
Functions:
1. macroChack
Returns a file after the macro
2.firstChack
Returns a file with command codes at base 2 and in place of labels the name of the label.
3.secondChack
Returns the output files: .ob, .ext, .ent
*/
char buffMacroName[81];
char* afterFirst;
char str[81];
int i=1;
char* as=".as";
char afterMacro []=".am" ;
ERRORS=0;
	while(i<argc)
	{
FILE * original;
	strcpy(str, argv[i]);
	strcat(str,as);
 	original = fopen (str, "a+");
	strcpy(buffMacroName,argv[i]);
 	macroChack(original , buffMacroName);
 	fclose(original);
	strcpy(str, argv[i]);
	strcat(str,afterMacro);
	original = fopen (str, "a+");
	afterFirst=firstChack(original,argv[i]);
if (ERRORS==0)
{
	original = fopen(afterFirst,"r+");
	secondChack(original);
	fclose(original);
}
	afterFirst="\0";
if(ERRORS>0)
printf("%d errors\n",ERRORS);

	free(titels);
	free(titelsData);
	free(ENarry);
	free(EXarry);
	free(datas);
	free(DCs);
ERRORS=0;
	i++;

	}
return 0;
}
