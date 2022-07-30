#include "data.h"
#include <stdio.h>
/*------------------------------------------------------------------------------*/
void macroChack(FILE* original, char* originalName)
{
/*
This function gets from the main program a pointer to the original file and the name of the file without an extension. The function opens a new file with the original name with the extension ".am" and registers the original file in this
 file after the macros are deployed. For this purpose, an array of dynamically assigned strings has been defined into which we write the macro body in each organ (everything that is found in the main file between "macro" and "endmacro").
We will check that the macro name is not a command name. Continue reading the file and in each line check if the first word is in the array then replace that word with the content in the organ in the array (without the name) and all the other lines copy to the new file unchanged. And so after calling the function we get a new file containing the original program after the macro retires.
For this we used the following auxiliary functions:
1.addToMacrosArry (assigns memory to array macros and adds string to it)
2.isMacroName (checks if the word is initially in the ival in the macro array i.e. the name of a macro
 (returns 1 if 0 then if not).
3.isWord (gets a place in the string and checks the islands is equal to the word it received).
4.isLigal (checks whether a word is equal to one of the commands).
5.isMacroNow (checks if the word is macro).
*/

char** macross;
char changed []=".am" ;
int q=0;
char* macroString;
int caunt =0;
char readingString[81];
int isStringNow=0;
FILE * fileAfterMacroChange;
ERRORS=0;
macross = (char **) malloc( sizeof(char*));
strcat(originalName,changed);
fileAfterMacroChange = fopen (originalName, "a+");
macroString = (char*) malloc(sizeof(char* ));
strcpy(macroString,"\0");
fgets(readingString,81,original);
 	while (!feof(original))
        {
		if (isMacroNow(readingString)==1)
		isStringNow=1;
		if (isStringNow==1)
			{
					macroString = (char *) realloc(macroString,((strlen(macroString))+strlen(readingString))*sizeof (char*));
				strcat(macroString, readingString);
        			fgets(readingString,81,original);
			}
			if (isWord(readingString,"endmacro")==1)
			{
			addToMacrosArry (macroString,caunt,macross);
			strcpy(macroString ,"\0");
			caunt++;
        		isStringNow=0;
			fgets(readingString,81,original);
			}
			if (isStringNow==0)
			{
			q=isMacroName(readingString,macross,caunt);
			if (q==0)
			{
        		fputs(readingString, fileAfterMacroChange);
        		fgets(readingString,81,original);
			}
		else
		{
		int z=0;
			while(macross[q-1][z]!='\n')
			{
			z++;
			}z++;
			while(z<strlen(macross[q-1])-1)
			{
			fputc(macross[q-1][z], fileAfterMacroChange);
			z++;
			}
			fputc('\n',fileAfterMacroChange);
        	        fgets(readingString,81,original);	
			}
		}
       }

free(macross);
if(isStringNow==1)
printf("yore macro not end or you put somthing befor or after (endmacro)");
fclose(fileAfterMacroChange);
}

/*--------------------------------------------------------------------------------------*/

void addToMacrosArry (char* writeString,int i,char**macros)
{
macros = (char **) realloc(macros, (i+1)*sizeof(char*));
macros[i] = malloc(strlen(writeString)*sizeof(char));
strcpy(macros[i] ,writeString);
}

/*---------------------------------------------------------------------------------------*/

int isMacroName(char*chackString,char**MacrosArry,int count)
{
int l=0;
int k=6;
int i=0;
int j=0;
if (count==0)
return 0;
while(i<=count)
{
	while(j<strlen(chackString)&&k<strlen(MacrosArry[i]))
		{

			while(chackString[j]==' '||chackString[j]=='	')
			{j++;}
			while(MacrosArry[i][l]==' '||MacrosArry[i][l]=='	')
			{l++;}
			while(MacrosArry[i][l+k]==' '||MacrosArry[i][l+k]=='	')
			{k++;}
			if (chackString[j]!=MacrosArry[i][k+l])
			{
			if((MacrosArry[i][k+l]==' '||MacrosArry[i][k+l]=='	'||MacrosArry[i][k+l]=='\n')&&(chackString[j]==' '||chackString[j]=='	'||chackString[j]=='\n'))
return i+1;
				i++;
				if (i==count)
				return 0;
				j=0;
				k=6;
				l=0;
			}
			if (chackString[j]==MacrosArry[i][k+l])
			{
			j++;
			k++;
			}
		}
	if(isLigal(chackString)==0)
	return 0;
	return i+1;
	}
return 0;
}

/*------------------------------------------------------------------------------------*/

 int isWord(char* pociant,char* str1)
{
int i=0;
int j=0;
int l2=strlen(str1);
int k=strlen(pociant)-1;
while(pociant[i]==' '||pociant[i]=='	')
i++;
while(pociant[k]==' '||pociant[k]=='	'||pociant[k]=='\n')
k--;
if ((k-i+1)!=l2)
{return 0;}
	while(j<strlen(str1)&&i<strlen(pociant)&&pociant[i]!=' '&&pociant[i]!='	'&&pociant[i]!='\n'&&str1[i]!='\n')
	{
		if (pociant[i]!=str1[j])
		return 0;
		i++;
		j++;
	}
return 1;
}

/*----------------------------------------------------------------------------------*/
int isLigal(char* str)
{
int x=0;
x=x+isWord(str,".data\n");
x=x+isWord(str,".string\n");
x=x+isWord(str,".struct\n");
x=x+isWord(str,".entry\n");
x=x+isWord(str,".extern\n");
x=x+isWord(str,"mov\n");
x=x+isWord(str,"cmp\n");
x=x+isWord(str,"add\n");
x=x+isWord(str,"sub\n");
x=x+isWord(str,"not\n");
x=x+isWord(str,"clr\n");
x=x+isWord(str,"lea\n");
x=x+isWord(str,"inc\n");
x=x+isWord(str,"dec\n");
x=x+isWord(str,"jmp\n");
x=x+isWord(str,"bne\n");
x=x+isWord(str,"get\n");
x=x+isWord(str,"prn\n");
x=x+isWord(str,"jsr\n");
x=x+isWord(str,"rts\n");
x=x+isWord(str,"hlt\n");
if (x==0)
return 1;
printf("\n\nthe macro name \n%sis iligal\n%d\n",str,x);
ERRORS++;
return 0;
}

/*---------------------------------------------------------------------------------*/

int isMacroNow(char *str2)
{
char str1[]="macro";
int i=0;
int j=0;
while(str2[i]==' '||str2[i]=='	')
i++;
	while(j<strlen(str1))
	{
		if (str2[i]!=str1[j])
		return 0;
		i++;
		j++;
	}
if (str2[i]!=' '&&str2[i]!='	')
{
printf("you need put space betwin macro and mane of macro in line: \n %s",str2);
ERRORS++;
return 0;
}
return 1;
}

















