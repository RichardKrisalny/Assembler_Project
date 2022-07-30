#include "data.h"
#include "dataAms.h"
#include <stdio.h>
/*
This function that receives the file after exiting a macro and goes through it line by line. In every line you check Heim, this is a response, an empty line, a directive or an instruction.
And also is there a label.
The activity is divided into 2 options:
There is a label or there is no label
If there is, then the function checks with helper functions whether it is a prompt or an instruction and adds the label to the appropriate array. In addition, the machine codes the command or instruction and records it in a new file and adds the coding set in the memory to the label array (DATA labels have an additional coding array).
If there is no label then the function simply adds the encoding of the operation to the new file.
Next to each function there is a description of the activity.
*/
char* firstChack(FILE* file,char* nameOfFile)
{
char readingString[81];
int i=0;
int m=0;
int caunt=0;
char Buff[15];
int Cmd=-1;
int Data=-1;
char* NameOfTitel ;
char* NameOfTitelData ;
DA=0;
t=0;
ERRORS=0;
EN=0;
d=0;
strcpy(titelCode,"\0") ;
strcpy(titelCode2,"\0") ;
E=0;
DC=100;
IC=100;
strcpy(newF,nameOfFile);
strcpy(buffOfNameFile,nameOfFile);
strcat(buffOfNameFile,".first");
 newFile = fopen (buffOfNameFile, "a+");
DCs = (int*) malloc( sizeof(int));
EXarry = (char **) malloc( sizeof(char*));
ENarry = (char **) malloc( sizeof(char*));
titels = (char **) malloc( sizeof(char*));
titelsData = (char **) malloc( sizeof(char*));
datas = (char **) malloc(sizeof(char*));


NameOfTitel = (char*) malloc(sizeof(char* ));
NameOfTitelData = (char*) malloc(sizeof(char* ));
fgets(readingString,81,file);
	while (!feof(file))
	{
		i=spaces(readingString,i);
		if (readingString[i]==';'||readingString[i]=='\n')
		fgets(readingString,81,file);
			if ((isTitel(readingString,i,NameOfTitel))>0)
			{
			isTatelFlag=1;
				m=i;
				i=isTitel(readingString,i,NameOfTitel)+1;
				if (isTatelOf2(readingString)[0]!='-'||isTatelOf(readingString)[0]!='-')
				{
				ERRORS++;
				printf("the titel name is Catch in line:\n%s",readingString);
				}
				i=spaces(readingString,i);
				if (isComand(readingString,i)>=0&&isTatelFlag==1)
				{
					PdecimalToBinary(IC,Buff,8);
					strcat(Buff,"-10\n");
					strcat(NameOfTitel,Buff);
					addToTitelsArry (NameOfTitel, t);
					t++;	
					Cmd=isComand(readingString,i);
					towOp(Cmd,readingString,i+3);
					fgets(readingString,81,file);
				}
				else
				i=m;
				i=isTitel(readingString,i,NameOfTitelData)+1;
				i=spaces(readingString,i);
				 if (isData(readingString,i)>=0&&isTatelFlag==1)
				{
	
					addToTitelsDataArry (NameOfTitelData, d);
					DCs= (int*) realloc(DCs, (d+1)*sizeof(int));
					DCs[d] = DC;				
					d++;
					Data=isData(readingString,i);
					while(readingString[i]!=' '&&readingString[i]!='	')
					i++;
					i=spaces(readingString,i);
					dataCode(Data,readingString,i);
					fgets(readingString,81,file);	
				}
			
			isTatelFlag=0;
			}
			else if (isComand(readingString,i)>=0&&isTatelFlag==0)
			{
			
			Cmd=isComand(readingString,i);
			towOp(Cmd,readingString,i+3);
			fgets(readingString,81,file);
			}
			else if (isData(readingString,i)>=0&&isTatelFlag==0)
			{
				Data=isData(readingString,i);
				while(readingString[i]!=' '&&readingString[i]!='	')
				i++;
				i=spaces(readingString,i);
				dataCode(Data,readingString,i);
				fgets(readingString,81,file);	
			}
else
{
printf("iligal coomand in line \n%s\n",readingString);
ERRORS++;
		fgets(readingString,81,file);
}
		i=0;
	}
fputs("\n", newFile);
DCs[0]--;
while(caunt<DA)
{
fputs(datas[caunt], newFile);
caunt++;
}
caunt=0;
while(caunt<d)
{
DCs[caunt]=DCs[caunt]+(IC-98);
caunt++;
}
if(ERRORS>0)

fclose(file);
fclose(newFile);
return buffOfNameFile;
}
/*---------------------------------------------------------------------------------------------*/
 void dataCode(int noOfData,char* str, int plase)
{
/*This function receives a DATA input and adds the encoding of the operation to the data set
The function is divided into several data options and works for each data type as much as needed according to the instructions.*/
int num;
int a;
int numy=0;
int j=0;
int NF=0;
int i=plase;
char buff[10];
char buffy[10];
char buffS[10];
strcpy(buff,"\0");
strcpy(buffy,"\0");
strcpy(buffS,"\0");
num = noOfData;
switch (num)
{
case 0:
		while(i<strlen(str))
		{
			if (str[i]=='-')
			{
			NF=1;
			i++;
			}
			if (str[i]=='+')
			{
			NF=0;
			i++;
			}
	                while(str[i]!=' '&&str[i]!='	'&&str[i]!=','&&str[i]!='\n')
			{
			buff[j]=str[i];
			j++;
			i++;
			}
			buff[j]='\0';
			numy=atoi(buff);
			if (NF==0)
			PdecimalToBinary(numy,buffy, 10);
			if (NF==1)
			NdecimalToBinary(numy,buffy, 10);
			buffy[10]='\0';
			addToDatasArry (buffy, DA);
			j=0;
			DA++;
	                while(str[i]==' '||str[i]=='	'||str[i]==','||str[i]=='\n')
			{
			i++;
			}
			DC++;
			NF=0;
		}
break;
case 1:

		if (str[i]!='"')
		{
                printf("the string need start at \" ");
		ERRORS++;
		}
		else
		{
		i++;
			while(str[i]!='"')
			{
			a=(int)str[i];
			PdecimalToBinary(a,buffS,10);
			buffS[10]='\0';
			addToDatasArry (buffS, DA);
			i++;
			DA++;
			DC++;
			
			}
			addToDatasArry ("0000000000", DA);
			DA++;
		}
break;
case 2:

			if (str[i]=='-')
			{
			NF=1;
			i++;
			}
			if (str[i]=='+')
			{
			NF=0;
			i++;
			}
	                while(str[i]!=' '&&str[i]!='	'&&str[i]!=','&&str[i]!='\n')
			{
			buff[j]=str[i];
			j++;
			i++;
			}
			buff[j]='\0';
			numy=atoi(buff);
			if (NF==0)
			PdecimalToBinary(numy,buffy, 10);
			if (NF==1)
			NdecimalToBinary(numy,buffy, 10);
			buffy[10]='\0';
			addToDatasArry (buffy, DA);
			j=0;
			DA++;
	                while(str[i]!='"')
			{
			i++;
			}
			i++;
			while(str[i]!='"'&&str[i]!=' '&&str[i]!='	')
			{
			a=(int)str[i];
			PdecimalToBinary(a,buffS,10);
			buffS[10]='\0';
			addToDatasArry (buffS, DA);
			DA++;
			DC++;
			i++;
			}
			addToDatasArry ("0000000000", DA);
			DA++;
			DC++;
break;
case 3:
if (isTatelFlag==1)
 printf("labale in entern is unuseful\n");
	               while(str[i]!=' '&&str[i]!='	'&&str[i]!=','&&str[i]!='\n')
			{
			buff[j]=str[i];
			j++;
			i++;
			}
			buff[j]='\0';
			addToENarryArry (buff, EN);
			EN++;	
break;
case 4:
if (isTatelFlag==1)
printf("labale in extern is unuseful\n");
	             while(str[i]!=' '&&str[i]!='	'&&str[i]!=','&&str[i]!='\n')
			{
			buff[j]=str[i];
			j++;
			i++;
			}
			buff[j]='\0';
			addToEXarryArry (buff, E);
			E++;	
break;
default:
return;
break;
}
return;
}
/*-------------------------------------------------------------------------------------------*/
int isComand (char* str , int position)
{
/*This function checks if the word we are reading now is a command*/
int i=0;
int j=0;
int k=position;
while(i<numOfComands)
{
	while(j<strlen(comands[i]))
	{
		if (str[k]!=comands[i][j])
		{
			i++;
			if (i==numOfComands)
			return -1;
			j=0;
			k=position;
		}
		if (str[k]==comands[i][j])
		{
			j++;
			k++;
		}
	}
return i;
}
return -1;
}
/*----------------------------------------------------------------------------------*/
int isData (char* str , int position)
{
/*This function checks if the word we are reading now is a data*/
int i=0;
int j=0;
int k=position;
while(i<numOfDirectives)
{
	while(j<strlen(directive[i]))
	{
		if (str[k]!=directive[i][j])
		{
			i++;
			if (i==numOfDirectives)
			return -1;
			j=0;
			k=position;
		}
		if (str[k]==directive[i][j])
		{
			j++;
			k++;
		}
	}
return i;
}
return -1;
}
/*---------------------------------------------------------------------------------*/
int isTitel (char* str , int position, char* titel)
{
/*This function checks if the word we are reading now is a titel*/
int l=0;
int o=0;
int h=0;
int p=position;
while (p<strlen(str))
{
if (str[p]==':')
h=p;
p++;
}
if (h==0)
return 0;
l=h;
while (str[h]!=' '&&str[h]!='	'&&h>0)
{
h--;
}
if (h>0)
h++;
while (h<=l)
{
titel[o]=str[h];
h++;
o++;
}
titel[o-1]='\0';
return l;
}
/*---------------------------------------------------------------------------------*/
 void towOp(int noOfComand,char* str, int plase)
{
/*This function receives the line we read and its command number and performs coding of the operation according to the instructions.
For each type of operation, the number of words in memory is coded according to the number of operands, and of course errors are reported.*/
int opstruct=0;
int z=0;
int OP=0;
int strcName=0;
int sb=0;
char firstWord [15];
char forWord [15];
char secondWord [15];
char thirdWord [15];
char fiveWord [15];
char stractBuff[81];
int i=spaces(str,plase);
strcpy(stractBuff,"\0");
strcpy(firstWord,"\0");
strcpy(secondWord,"\0");
strcpy(thirdWord,"\0");
strcpy(forWord,"\0");
strcpy(fiveWord,"\0");

if(noOfComand==14||noOfComand==15)
{
strcpy(firstWord, comandCode[noOfComand]);
strcat(firstWord,"00-00-00");
fputs(firstWord, newFile);
return;
}
if (i==plase)
{
printf(" in line \n %s you need riad space after comand %s\n",str,comands[noOfComand]);
ERRORS++;
}
if (i!=plase)
{
IC++;
strcpy(firstWord, comandCode[noOfComand]);
if(noOfComand>=5&&noOfComand<=13)
{strcat(firstWord, "-00");}
while(i<strlen(str))
{
switch(str[i])
	{
case '#':
		IC++;
		if (OP>0&&noOfComand!=1)
		{
		printf("in this line \n%s the comand can't get # in second operand\n",str);
		ERRORS++;
		i++;
		}
		if (OP==0&&noOfComand==4)
		{
		printf("in this line \n%s the comand can't get # in first operand\n",str);
		ERRORS++;
		i++;
		}
		else
		{
		miunOO ( i,str ,firstWord , secondWord, thirdWord,OP,forWord);
		strcat(firstWord,"-00");
		OP++;
		while(str[i]!=' '&&str[i]!='	'&&str[i]!='\n'&&str[i]!=',')
		{i++;}
		i++;
		}
		break;	
case 'r':
if (isalpha(str[i+1]))
{
break;
}
		if(OP==0)
		IC++;
		z =str[i+1]-'0';
			if (z>7||(str[i+2]!=' '&&str[i+2]!='	'&&str[i+2]!='\n'&&str[i+2]!=','))
			{
			printf("rigister not find in line \n%s",str);
			ERRORS++;
			}
			if (z>=0&&z<=7&&OP==0)
			{	
			if(noOfComand==4)
			{
			printf("in this line \n%s the comand can't get r in first operand\n",str);
			ERRORS++;
			}
			strcat(firstWord,"-11");
				if (noOfComand>=5&&noOfComand<=13)
				{
				strcat(secondWord,"0000");
				strcat(secondWord,registersCode[z]);
				strcat(secondWord,"-00");
				OP++;
				}
			else
			{
				strcat(secondWord,registersCode[z]);
				OP++;
			}
			while(str[i]!=' '&&str[i]!='	'&&str[i]!='\n'&&str[i]!=',')
			{i++;}
			}
			else if(OP==1)
			{	
				if(strlen(secondWord)==4)
				{
				strcat(secondWord,registersCode[z]);
				strcat(secondWord,"-00");
				strcat(firstWord,"-11-00");
				OP++;
				while(str[i]!=' '&&str[i]!='	'&&str[i]!='\n'&&str[i]!=',')
				{i++;}
				i++;
				}
			else
			{	
			IC++;	
			strcat(firstWord,"-11-00");
			if (opstruct==0)
			{
			strcat(thirdWord,"0000");
			strcat(thirdWord,registersCode[z]);
			strcat(thirdWord,"-00");
			}
			if (opstruct==1)
			{
			strcat(forWord,"0000");
			strcat(forWord,registersCode[z]);
			strcat(forWord,"-00");
			}
			OP++;
			while(str[i]!=' '&&str[i]!='	'&&str[i]!='\n'&&str[i]!=',')
			{i++;}
			i++;
			}
			}
		else
		i++;
		break;
default:
if(isStrucr(str,i)=='1')
{
strcat(firstWord,"-10");
		if (OP==0)
		{
		strcName=i;
		sb=0;
			while(str[strcName]!='.')
			{
			stractBuff[sb]=str[strcName];
			strcName++;
			sb++;
			}
		stractBuff[sb]='\0';
		strcpy(secondWord,stractBuff);
		strcpy(stractBuff,"\0");
		strcpy(thirdWord,"00000001-00");
		}
		else 
		{
			strcName=i;
			while(str[strcName]==' '||str[strcName]=='	'||str[strcName]==',')
			strcName++;
			sb=0;
			while(str[strcName]!='.')
			{
			stractBuff[sb]=str[strcName];
			strcName++;
			sb++;
			}
			stractBuff[sb]='\0';
		
		 	if (opstruct==0)
			{
			strcpy(thirdWord,stractBuff);
			strcpy(stractBuff,"\0");
			strcpy(forWord,"00000001-00");
			strcat(firstWord,"-00");
			i=spaces(str,i);
			}
			else
			{
			strcpy(forWord,stractBuff);
			strcpy(stractBuff,"\0");
			strcpy(fiveWord,"00000001-00");
			strcat(firstWord,"-00");
			i=spaces(str,i);
			}
		}		
		IC=IC+2;
		OP++;
		while(str[i]!=' '&&str[i]!='	'&&str[i]!=','&&str[i]!='\n')
		i++;
		opstruct++;
		i=spaces(str,i);
}
if(isStrucr(str,i)=='2')
{
	strcat(firstWord,"-10");
	if (OP==0)
	{
			strcName=i;
			sb=0;
			while(str[strcName]!='.')
			{
			stractBuff[sb]=str[strcName];
			strcName++;
			sb++;
			}
			stractBuff[sb]='\0';
			strcpy(secondWord,stractBuff);
			strcpy(stractBuff,"\0");
			strcpy(thirdWord,"00000010-00");
	}
	else 
		{

			strcName=i;
			sb=0;
			while(str[strcName]==' '||str[strcName]=='	'||str[strcName]==',')
			strcName++;
			while(str[strcName]!='.')
			{
			stractBuff[sb]=str[strcName];
			strcName++;
			sb++;
			}
			stractBuff[sb]='\0';
			 if (opstruct==0)
			{
			strcpy(thirdWord,stractBuff);
			strcpy(stractBuff,"\0");
			strcpy(forWord,"00000010-00");
			strcat(firstWord,"-00");
			i=spaces(str,i);
			}
			else
			{
			strcpy(forWord,stractBuff);
			strcpy(stractBuff,"\0");
			strcpy(fiveWord,"00000010-00");
			strcat(firstWord,"-00");
			i=spaces(str,i);
			}
		}		
		IC=IC+2;
		OP++;
		while(str[i]!=' '&&str[i]!='	'&&str[i]!=','&&str[i]!='\n')
		i++;
		opstruct++;
		i=spaces(str,i);
}
		}/*switch*/
if (str[i]!=' '&&str[i]!='	'&&str[i]!='\n'&&str[i]!=','&&str[i]!='r'&&str[i]!='#'&&str[i]!='\0'&&isStrucr(str,i)!='1'&&isStrucr(str,i)!='2')
{
if (str[i-1]=='r')
i--;
strcat(firstWord,"-01");
sb=0;
while(str[i]!=' '&&str[i]!='	'&&str[i]!='\n'&&str[i]!=',')
{
stractBuff[sb]=str[i];
sb++;
i++;
}
stractBuff[sb]='\0';
if (OP==0)
strcpy(secondWord,stractBuff);
else if (OP!=0)
{
	if (opstruct==0)
		strcpy(thirdWord,stractBuff);
	else
		strcpy(forWord,stractBuff);
}
strcpy(stractBuff,"\0");
IC++;
OP++;
}
i++;
	}/*while*/
}/*if*/
if (OP==2&&noOfComand>=5&&noOfComand<=13)
{
printf("in line %s the comand need get 1 operands\n",str);
ERRORS++;
}
if (OP==1&&noOfComand>=0&&noOfComand<=4)
{
printf("in line %s the comand need get 2 operands\n",str);
ERRORS++;
}
if (strlen(secondWord)==4&&isdigit(secondWord[0]))
	strcat(secondWord,"0000-00");
if (strlen(firstWord)==10)
	strcat(firstWord,"-00");
if (strlen(firstWord)==7)
	strcat(firstWord,"-00-00");
strcat(firstWord,"\n");
strcat(secondWord,"\n");
strcat(thirdWord,"\n");
strcat(forWord,"\n");
strcat(fiveWord,"\n");
if (ERRORS==0)
{
if (strlen(firstWord)>1)
fputs(firstWord, newFile);
if (strlen(secondWord)>1)
fputs(secondWord, newFile);
if (strlen(thirdWord)>1)
fputs(thirdWord, newFile);
if (strlen(forWord)>1)
fputs(forWord, newFile);
if (strlen(fiveWord)>1)
fputs(fiveWord, newFile);
}
}
/*-------------------------------------------------------------------------------------*/
int spaces(char* str,int i)
{
/*This function skips white characters*/
while(str[i]==' '||str[i]=='	')
i++;
return i;
}
/*-----------------------------------------------------------------------------------------*/
char* PdecimalToBinary(int num,char* binaryNum, int length) 
{   
/*This function converts a number from base 10 to base 2 with desired amount of bits*/
  int q=length-1;
char* buffl;
buffl = (char*) malloc( length);
   while(q>= 0)
	{
		if(num % 2==0||num<=0)
		{
	       buffl[q] ='0';
	        num /= 2;
		q--;
		}
		else 
		{
		buffl[q] ='1';
	        num /= 2;
		q--;
		}
	}
buffl[length]='\0';
strcpy(binaryNum,buffl);
free(buffl);
return binaryNum;
}
/*-------------------------------------------------------------------------------------------*/
char* NdecimalToBinary(int num,char* binaryNum ,int length) 
{   
/*This function converts a negative number from base 10 to base 2 desired amount of bits*/
char* buffl;
   int i=length-1;
buffl = (char*) malloc( length);
strcpy(buffl,PdecimalToBinary(num, binaryNum,length));

   while(buffl[i]== '0')
	{
	i--;
	}
i--;
	while(i>= 0)
	{
		if(buffl[i]== '0')
		{
		buffl[i]= '1';
		i--;
		}
		else
		{
		buffl[i]= '0';
		i--;
		}
	}
buffl[length]='\0';
strcpy(binaryNum,buffl);
free(buffl);
return binaryNum;
}
/*-----------------------------------------------------------------------------------------------*/
void miunOO (int i,char* str ,char* firstWord ,char* secondWord, char* thirdWord,int a,char* forWord)
{
/*This function encodes the commands with the # operand.
Checks whether a number is negative or positive.
and adds memory words to me the previous operands.*/
int negativFlag=0;
int buffPlace=0;
char intBuff [10];
int NumOperand=0;
char binaryNum [10]; 
strcpy(binaryNum,"\0");
strcpy(intBuff,"\0");
		i++;
			if (str[i]=='-')
			{
			negativFlag=1;
			i++;
			}
			if (str[i]=='+')
			{
			negativFlag=0;
			i++;
			}
			while(str[i]!=' '&&str[i]!='	'&&str[i]!=',')
			{		
			intBuff[buffPlace]=str[i];
			buffPlace++;
			i++;
			}
		NumOperand=atoi(intBuff);
		if (NumOperand>127)
		{printf("the number %d is to big for 8 biats \n",NumOperand);
		ERRORS++;
		NumOperand=0;}
if (a>0)
{
	if (strlen(thirdWord)>0)
	{
		if(negativFlag==0)
		{
		strcpy(forWord,PdecimalToBinary(NumOperand,binaryNum,8));
		}
		if(negativFlag==1)
		{
		strcpy(forWord,NdecimalToBinary		(NumOperand,binaryNum,8));
		}
	strcat(forWord,"-00");
	strcat(firstWord,"-00");
	
	}
else
	{
		if(negativFlag==0)
		{
		strcpy(thirdWord ,PdecimalToBinary(NumOperand,binaryNum,8));
		}
		if(negativFlag==1)
		{
		strcpy(thirdWord ,NdecimalToBinary		(NumOperand,binaryNum,8));
		}
	strcat(thirdWord ,"-00");
	strcat(firstWord,"-00");
	}
}
else
{
	if(negativFlag==0)
	{
	strcpy(secondWord,PdecimalToBinary(NumOperand,binaryNum,8));
	}
	if(negativFlag==1)
	{
	strcpy(secondWord,NdecimalToBinary(NumOperand,binaryNum,8));
	}
strcat(secondWord,"-00");
}
}
/*------------------------------------------------------------------------------------*/
char isStrucr(char* str,int i)
{
/*This function checks if it is a STRUCT type operation*/
int j=i;
while(i<strlen(str))
{
if (str[j]=='.')
return str[j+1];
j++;
}
return '0';
}
/*-------------------------------------------------------------------------------------*/
/*The following 5 functions add value to dynamic arrays*/
void addToEXarryArry (char* writeString,int v)
{
EXarry = (char **) realloc(EXarry, (v+1)*sizeof(char*));
EXarry[v] = malloc(strlen(writeString)*sizeof(char));
strcpy(EXarry[v] ,writeString);
strcat(EXarry[v] ,"\n");
}
/*----------------------------------------------------------------------------------*/
void addToDatasArry (char* writeString,int v)
{
datas = (char **) realloc(datas, (v+1)*sizeof(char*));
datas[v] = malloc(strlen(writeString)*sizeof(char));
strcpy(datas[v] ,writeString);
strcat(datas[v] ,"\n");
}
/*-------------------------------------------------------------------------------------*/
void addToENarryArry (char* writeString,int v)
{
ENarry = (char **) realloc(ENarry, (v+1)*sizeof(char*));
ENarry[v] = malloc(strlen(writeString)*sizeof(char));
strcpy(ENarry[v] ,writeString);
strcat(ENarry[v] ,"\n");
}
/*-------------------------------------------------------------------------------------*/
void addToTitelsArry (char* writeString,int v)
{
titels = (char **) realloc(titels, (v+1)*sizeof(char*));
titels[v] = malloc(strlen(writeString)*sizeof(char));
strcpy(titels[v] ,writeString);
strcat(titels[v] ,"\n");
}
/*-------------------------------------------------------------------------------------*/
void addToTitelsDataArry (char* writeString,int v)
{
titelsData = (char **) realloc(titelsData, (v+1)*sizeof(char*));
titelsData[v] = malloc(strlen(writeString)*sizeof(char));
strcpy(titelsData[v] ,writeString);
strcat(titelsData[v] ,"\n");
}
/*--------------------------------------------------------------------------------------*/
/*The following 3 functions check what type of label we encountered in the second read (in which of the arrays does the label exist)*/
char* isTatelOf (char* str)
{
int i=0;
int j=0;
int k=0;

while(i<d)
{
	while((k<strlen(str)&&j<strlen(titelsData[i]))&&str[k]!=':')
	{
	while(str[k]==' '||str[k]=='	')
	k++;
		if (str[k]!=titelsData[i][j])
		{
			i++;
			if (i==d)
			{
			return "-";
			}
			j=0;
			k=0;
		}
		if (str[k]==titelsData[i][j])
		{
			j++;
			k++;
		}
	}
 PdecimalToBinary(DCs[i],titelCode,8);
strcat(titelCode,"-10");
return titelCode;
}
return "-";
}
/*----------------------------------------------------------------------------------------*/
char* isTatelOf2 (char* str)
{
int i=0;
int j=0;
int k=0;
int e=0;
int w=0;
while(i<t)
{
	while(k<strlen(str)||!isdigit(titels[i][j]))
	{
	while(titels[i][j]==' ')
	j++;
	while(str[k]==' '||str[k]=='	')
	k++;
		if (str[k]!=titels[i][j])
		{
			
			i++;
			if (i==t)
			{
			return "-";
			}
			j=0;
			k=0;
		}
		if (str[k]==titels[i][j])
		{
			j++;
			if(isdigit(titels[i][j]))
			k=strlen(str);
			k++;
		}
	}
while(!isdigit(titels[i][w]))
w++;
while(w<strlen(titels[i]))
{
titelCode2[e]=titels[i][w];
e++;
w++;
}
titelCode2[e-1]='\0';
return titelCode2;
}
return "-";
}
/*----------------------------------------------------------------------------------------*/
int isTatelOf3 (char* str)
{
int i=0;
int j=0;
int k=0;
while(i<E)
{
	while(k<strlen(str))
	{
	while(EXarry[i][j]==' ')
	j++;
		if (str[k]!=EXarry[i][j])
		{
			i++;
			if (i==E)
			{
			return -1;
			}
			j=0;
			k=0;
		}
		if (str[k]==EXarry[i][j])
		{
			j++;
			k++;
		}
	}
return 1;
}
return -1;
}





