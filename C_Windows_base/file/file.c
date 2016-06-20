#include <stdio.h>
int main()
{
	FILE *fp;
	char str[11];
	if((fp=fopen("x.txt","rt"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
	fgets(str,11,fp);
	printf("%s",str);
	fclose(fp);
}