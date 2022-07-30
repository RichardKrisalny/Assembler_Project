#include "data.h"
#include <stdio.h>

void secondChack(FILE* file)
{
/*
This function receives a file after the first reading that contains the code from the prefix of the commands and actions and in places of a label there is a name of the label (.FIRST file).
The function opens a new file with an .ob extension and records the data in it as follows:
1. If the line in the file is a code (numbers), write down its amount in memory at base 32 and convert it to base 32 and write to the new file.
2. If the line is a label, check which of the arrays it is in:
a. Set of command labels: add to the new file the location of the label at base 32 and copy the code after the label name will convert it to base 32 and add to the new file.
b. Data Label Array: Add to the new file the location of the label at base 32 and access the data code set at the same location of the label and write the code at base 32 in the new file.
c. External label array: Copy to the new file the location in memory and the code of an external label in base 32. And in addition you will write the name of the label and its location in a new file if an .ext extension.
In addition you will go through the array of internal labels and copy their names and their location in memory at base 32 into a new file with the .ent extension.
There are 2 auxiliary functions which massage the conversions from base 2 to 10 and 32.
*/
char buffExplase [3];
char buffExtern[81];
char writingString[15];
int caunt=100;
int m=0;
int n=0;
char stt[10];
char TTNum[2];
char buff[81];
int q=0;
char buffEN[81];
char readingString[81];
FILE * final;
FILE * Extern;
FILE * ENtern;
strcpy(buff,newF);
strcat(buff,".ob");

final = fopen (buff, "a+");
strcpy(buff,newF);
strcat(buff,".ext");
strcpy(buffEN,newF);
strcat(buffEN,".ent");
fgets(readingString,81,file);
strcpy(writingString,convert(IC-99,TTNum));
strcat(writingString," ");
strcat(writingString,convert(DC-98,TTNum));
writingString[5]='\n';
writingString[6]='\0';
fputs(writingString, final);
strcpy(writingString,"\0");
strcpy(TTNum,"\0");
strcpy(stt,"\0");
	while (!feof(file))
	{
	if (readingString[0]=='\n')
	fgets(readingString,81,file);
		if (isdigit(readingString[0]))
			{
				while(n<10)
				{
				if (isdigit(readingString[m]))
					{
					stt[n]=readingString[m];
					m++;
					n++;
					}
				else
				m++;
				}
			convert(caunt,writingString);
			strcat(writingString,"    ");
			strcat(writingString,convert(convertTOdecimal(stt),TTNum));
			fputs(writingString, final);
			strcpy(stt,"\0");
			strcpy(TTNum,"\0");
			strcpy(writingString,"\0");
			m=0;
			n=0;
			caunt++;
			fgets(readingString,81,file);
			fputs("\n", final);

			}
			else if (isTatelOf(readingString)[0]!='-'&&readingString[0]!='-')
			{
				while(n<10)
				{
				if (isdigit(isTatelOf(readingString)[m]))
					{
					stt[n]=isTatelOf(readingString)[m];
					m++;
					n++;
					}
				else
				m++;
				}
			convert(caunt,writingString);
			strcat(writingString,"    ");
			strcat(writingString,convert(convertTOdecimal(stt),TTNum));
			fputs(writingString, final);
			strcpy(stt,"\0");
			strcpy(TTNum,"\0");
			strcpy(writingString,"\0");
			m=0;
			n=0;
			caunt++;
			fgets(readingString,81,file);
			fputs("\n", final);
			}

			else if (isTatelOf3(readingString)==1)
			{
			Extern = fopen (buff, "a+");
			strcpy(buffExtern,readingString);
			buffExtern[strlen(readingString)-1]='\0';
			strcat(buffExtern,"    ");
			convert(caunt,buffExplase);
			strcat(buffExtern,buffExplase);
			fputs(buffExtern, Extern);
			fputs("\n", Extern);
			strcpy(buffExtern,"\0");
			strcpy(buffExplase,"\0");
			strcpy(stt,"0000000001");
			convert(caunt,writingString);
			strcat(writingString,"    ");
			strcat(writingString,convert(convertTOdecimal(stt),TTNum));
			fputs(writingString, final);
			strcpy(stt,"\0");
			strcpy(TTNum,"\0");
			strcpy(writingString,"\0");
			m=0;
			n=0;
			caunt++;
			fgets(readingString,81,file);
			fputs("\n", final);
			fclose(Extern);
			}

			else if (isTatelOf(readingString)[0]=='-'&&readingString[0]!='-'&&isTatelOf2(readingString)[0]!='-')
			{
				while(n<10)
				{
				if (isdigit(isTatelOf2(readingString)[m]))
					{
					stt[n]=isTatelOf2(readingString)[m];
					m++;
					n++;
					}
				else
				m++;
				}
			convert(caunt,writingString);
			strcat(writingString,"    ");
			strcat(writingString,convert(convertTOdecimal(stt),TTNum));
			fputs(writingString, final);
			strcpy(stt,"\0");
			strcpy(TTNum,"\0");
			strcpy(writingString,"\0");
			m=0;
			n=0;
			caunt++;
			fgets(readingString,81,file);
			fputs("\n", final);
			}
	else
	{
	printf("the titel %snot faund\n",readingString);
	ERRORS++;
	fgets(readingString,81,file);
	}
	}
if (E>0)
{
ENtern = fopen (buffEN, "a+");
	while(q<E)
	{
	if (isTatelOf2(ENarry[q])[0]!='-')
	{
				while(n<10)
				{
				if (isdigit(isTatelOf2(ENarry[q])[m]))
					{
					stt[n]=isTatelOf2(ENarry[q])[m];
					m++;
					n++;
					}
				else
				m++;
				}
			stt[8]='\0';
			strcpy(writingString,ENarry[q]);
			writingString[strlen(ENarry[q])-1]='\0';
			strcat(writingString,"    ");
			strcat(writingString,convert(convertTOdecimal(stt),TTNum));
			fputs(writingString, ENtern);
			strcpy(stt,"\0");
			strcpy(TTNum,"\0");
			strcpy(writingString,"\0");
			m=0;
			n=0;
			fputs("\n",ENtern);
	q++;
	}
	 if (isTatelOf(ENarry[q])[0]!='-')
	{
				while(n<10)
				{
				if (isdigit(isTatelOf(ENarry[q])[m]))
					{
					stt[n]=isTatelOf(ENarry[q])[m];
					m++;
					n++;
					}
				else
				m++;
				}
			stt[8]='\0';
			strcpy(writingString,ENarry[q]);
			writingString[strlen(ENarry[q])-1]='\0';
			strcat(writingString,"    ");
			strcat(writingString,convert(convertTOdecimal(stt),TTNum));
			fputs(writingString, ENtern);
			strcpy(stt,"\0");
			strcpy(TTNum,"\0");
			strcpy(writingString,"\0");
			m=0;
			n=0;
			fputs("\n",ENtern);
	q++;
	}
	q++;
	}
}
}
/*--------------------------------------------------------------------------------------------------------------*/
char* convert (int a,char* TTNum)
{
char decimalToThortyTow[32]=
{
'!','@','#','$','%','^','&','*','<','>','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v'
};
char buffl[2];
buffl[1]=decimalToThortyTow[a%32];
a =a/32;
buffl[0]=decimalToThortyTow[a%32];
buffl[2]='\0';
strcpy(TTNum,buffl);
return TTNum;
}
/*-----------------------------------------------------------------------------*/
int convertTOdecimal(char* str) 
{
int n=atoi(str);
 int dec = 0, i = 0, rem;
  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  return dec;
}
