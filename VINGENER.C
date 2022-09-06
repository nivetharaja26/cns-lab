#include<stdio.h>
#include<conio.h>
#include<string.h>

char message[100],k[20],key[100],plain[100],cipher[20];

void genkey()
{
	int i,j=0;
	for(i=0;message[i]!='\0';i++)
	{
		if(k[j]!='\0')
			key[i]=k[j++];
		else
		{
			j=0;i--;
		}
	}
	key[i]='\0';
	printf("\nThe generated key to the length of message is %s\n",key);
}
void encryption()
{
	int i=0,cip,num,k;
	while(message[i]!='\0')
	{
		num=message[i]-'a';
		k=key[i]-'a';
		cip=(num+k)%26;
		cip=cip+'a';
		cipher[i]=cip;
		i++;
	}
	cipher[i]='\0';
	printf("\nThe encrypted message is %s",cipher);

}

void decryption()
{
	int i=0,cip,num,k;
	while(cipher[i]!='\0')
	{
		num=cipher[i]-'a';
		k=key[i]-'a';
		cip=(num-k)%26;
		if(cip<0)
			cip=cip+26;
		cip=cip+'a';
		plain[i]=cip;
		i++;
	}
	plain[i]='\0';
	printf("\nThe decrypted message is %s\n",plain);
}

int main()
{
	clrscr();
	printf("Enter the plain text (only lower case letters) ");
	scanf("%s",message);
	printf("Enter the key in lower case letter ");
	scanf("%s",k);
	genkey();
	encryption(message,key);
	decryption(cipher,key);
	getch();
	return 0;

}