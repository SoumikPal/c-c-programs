#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *a,char *b)
{
	char t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	char str[100];
	scanf("%s",str);
	int l=strlen(str);
	int i;
	if(l==1)
		printf("Not Possible\n");
	else{
	for( i=l-2;i>=0;i--)
	{
		if(str[i]>=str[i+1])
			continue;
		else
			break;
	}
	if(i==-1)
		printf("Not Possible\n");
	else
	{
		int j;
		for(j=l-1;j>i;j--)
		{
			if(str[j]>str[i])
			{
				break;
			}
		}
		swap(&str[i],&str[j]);
		i++;
		j=l-1;
		while(i<j)
		{
			swap(&str[i++],&str[j--]);
		}
		printf("%s\n",str);
	}
}

}
