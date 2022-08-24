#include<stdio.h>
#include<math.h>
#include<string.h>

char message[20],key[10],encrypt[20],decrypt[20];
int ke[2][2],sp[10][2],e[10][2],length;
int in[2][2],adj[2][2],d[10][2],esp[10][2];

void encryption();
void decryption();
void getKeyMessage();
void inverse();
void splitmessage();
void splitcipher();
void main()
{
	clrscr();
	getKeyMessage();
	encryption();
	inverse();
	getch();

}

void encryption()
{
	int i=0,j,k;
	splitmessage();
	for(i=0;i<length;i++)
	for(j=0;j<2;j++)
		e[i][j]=0;
	for(i=0;i<length;i++)
		for(j=0;j<2;j++)
		{
			for(k=0;k<2;k++)
				e[i][j]=e[i][j]+ke[j][k]*sp[i][k];
			e[i][j]=e[i][j]%26;

		}
	printf("\nEncrypted String is :");
	k=0;
	for(i=0;i<length;i++)
	for(j=0;j<2;j++)
		encrypt[k++]=e[i][j]+97;
	encrypt[k]='\0';
	printf("%s",encrypt);
}
void decryption()
{
	int i=0,j,k;
	splitcipher();
	for(i=0;i<length;i++)
	for(j=0;j<2;j++)
		d[i][j]=0;
	for(i=0;i<length;i++)
	for(j=0;j<2;j++)
	{
		for(k=0;k<2;k++)
			d[i][j]=d[i][j]+in[j][k]*esp[i][k];
		d[i][j]=d[i][j]%26;

	}
	printf("\nDecrypted String is : ");
	k=0;
	for(i=0;i<length;i++)
	for(j=0;j<2;j++)
		decrypt[k++]=d[i][j]+97;
	encrypt[k]='\0';
	printf("%s",decrypt);
}

void getKeyMessage()
{
	int i,j=0,k=0;
	printf("Enter key only 4 characters in small letters :  \n");
	scanf("%s",key);

	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		ke[i][j]=key[k++]-97;
	printf("\nKey in 2*2 matrix \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d\t",ke[i][j]);
		printf("\n");

	}
	printf("\n Enter the message in even character: ");
	scanf("%s",message);
}

void splitmessage()
{
	int i=0,k=0,j=0;
	while(message[i]!='\0')
	{
		sp[j][k]=message[i++]-97;
		k=(k+1)%2;
		if(k==0)
			j++;

	}
	length=j;
}

void splitcipher()
{
	int i=0,j=0,k=0;
	while(encrypt[i]!='\0')
	{
		esp[j][k]=encrypt[i++]-97;
		k=(k+1)%2;
		if(k==0)
			j++;

	}
}

void inverse()
{
	int i,j,k,det,idet=0;
	det=((ke[0][0]*ke[1][1])-(ke[0][1]*ke[1][0])%26);
	if(det==0)
	{
		printf("Determinent cannot be ZERO");

	}
	else
	{
		if(det<0)
			det=det+26;
		printf("\nThe determinent is %d\t",det);

		adj[0][0]=ke[1][1];
		adj[1][1]=ke[0][0];
		adj[0][1]=-ke[0][1]+26;
		adj[1][0]=-ke[1][0]+26;

		for(i=1;i<26;i++)
		if(((det*i)%26)==1)
		{
			idet=i;
			printf("\nThe inverse of determinent is %d\n",idet);
			break;
		}
		if(idet==0)
			printf("SORRY, Inverse is not possible");
		else
		{
			printf("\nInverse key is \n");
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					in[i][j]=(adj[i][j]*idet)%26;
					printf("%d\t",in[i][j]);
				}
				printf("\n");
			}
			decryption();
		}
	}
}