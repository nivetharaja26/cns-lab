#include<stdio.h>
#include<conio.h>
#include<string.h>

char message[100],ke[20],mes[10][10],plain[100],cipher[20];
int key[20],length,len;

void transpose()
{
	int i=0,j=0,k=0,len1;
	len1=strlen(ke);
	while(message[i]!='\0')
	{
		for(k=0;ke[k]!='\0';k++)
			if(message[i]!='\0')
				mes[j][k]=message[i++];
			else
				break;
			j++;
	}
	j--;
	while(ke[k]!='\0')
		mes[j][k++]='x';
	len=j+1;
	printf("\nThe message in matrix format");
	printf("%s",ke);
	for(i=0;i<len;i++)
	{
		printf("\n");
		for(j=0;j<len1;j++)
			printf("%c\t",mes[i][j]);

	}
}
void encryption()
{
	int i,j,k,l;
	transpose();
	i=1,k=0;
	for(i=1;i<=length;i++)
	{
		for(j=0;j<length;j++)
			if(i==key[j])
				break;
		for(l=0;l<len;l++)
			cipher[k++]=mes[l][j];
	}
	cipher[k]='\0';
	printf("\nThe encrypted message is %s \n",cipher);

}
int main()
{
	int i,j;
	clrscr();
	printf("Enter the plain text (only lower case letter) : ");
	scanf("%s",message);
	printf("Enter the key in lower case letter");
	scanf("%s",ke);
	for(i=0;ke[i]!='\0';i++)
	{
		key[i]=ke[i]-'0';
		printf("\nKey[%d]=%d",i,key[i]);
	}
	length=i;
	encryption(message,key);
	getch();
	return 0;
}