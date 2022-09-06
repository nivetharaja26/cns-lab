#include<stdio.h>
#include<conio.h>
#include<string.h>

char message[100],mes[10][100],plain[100],cipher[100];
int key;

void transpose()
{
	int i=0,j=-1,k=0;
	while(message[i]!='\0')
	{
		j++;
		while(j<key)
		{
			if(message[i]!='\0')
				mes[j++][k++]=message[i++];
			else
				break;

		}
		j--;
		while(j>0)
		{
			if(message[i]!='\0')
				mes[--j][k++]=message[i++];
			else
				break;
		}
	}
	printf("\nThe transpose matrix is \n");
	for(i=0;i<key;i++)
	{
		for(j=0;message[j]!='\0';j++)
			printf("%c",mes[i][j]);
		printf("\n");
	}
}
void encryption()
{
	int i,j,k=0;
	transpose();
	for(i=0;i<key;i++)
	{
		for(j=0;message[j]!='\0';j++)
			if(mes[i][j]>='a'&&mes[i][j]<='z')
				cipher[k++]=mes[i][j];

	}
	cipher[k]='\0';
	printf("\nThe encrypted message is %s\n",cipher);

}
int main()
{
	int i,j;
	clrscr();
	printf("Enter the plain text (onlt lower case letter): ");
	scanf("%s",message);
	printf("Enter the key in number ");
	scanf("%d",&key);
	encryption();
	getch();
	return 0;
}