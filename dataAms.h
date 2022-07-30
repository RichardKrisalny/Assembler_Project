
int DA=0;
int t=0;

int EN=0;
int d=0;
FILE * newFile;

int *DCs;
char titelCode[15];
char titelCode2[15];
char** titels;
char** ENarry;
char** EXarry;
char** titelsData;
char** datas;
int isTatelFlag=0;
int numOfDirectives=5;
int numOfComands=16;
char directive[5][10]=
{
".data",".string",".struct",".entry",".extern"
};
char comands[16][10]=
{
"mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","get","prn","jsr","rts","hlt"
};
char comandCode[16][5]=
{
"0000","0001","0010","0011","0110","0101","0100","0111","1000","1001","1010","1011","1100","1101","1110","1111"
};
char registers[8][3]=
{
"r0","r1","r2","r3","r4","r5","r6","r7"
};
char registersCode[8][5]=
{
"0000","0001","0010","0011","0100","0101","0110","0111"
};
