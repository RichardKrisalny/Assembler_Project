#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <math.h>
int IC;
int DC;
int ERRORS;
char newF [81];
char buffOfNameFile[81];
void macroChack(FILE* ,char[]);
void secondChack(FILE* );
char* firstChack(FILE*,char* );
void addToMacrosArry (char*,int,char**);
int isMacroName(char*,char**,int);
int isWord(char* ,char*);
int isLigal(char* str);
int isMacroNow(char* str2);
int isComand (char* str , int position);
void towOp(int noOfComand,char* str, int plase);
int spaces(char* str,int i);
char* PdecimalToBinary(int num,char*,int);
char* NdecimalToBinary(int num,char*,int);
void miunOO (int i,char* str ,char* firstWord, char* secondWord ,char* thirdWord,int,char* );
char isStrucr(char* str,int i);
int isTitel (char* str , int position, char* titel);
void addToTitelsArry (char* writeString,int i);
int isData (char* str , int position);
void dataCode(int noOfData,char* str, int plase);
void addToDatasArry (char* writeString,int i);
void addToENarryArry (char* writeString,int i);
void addToTitelsDataArry (char* writeString,int i);
void addToEXarryArry(char* writeString,int i);
char* isTatelOf (char* str);
char* isTatelOf2 (char* str);
char* convert (int, char* TTNum);
int convertTOdecimal(char* str);
int isTatelOf3 /*C36B0AC*/(char* str);
char** titels;
char** ENarry;
char** EXarry;
char** titelsData;
char** datas;
int *DCs;
int E;









