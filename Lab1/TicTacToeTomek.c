#include <stdio.h>

int winner(char play,char arr[4][5] )
{
	int count =0;
	//Check rows
	for(int i=0;i<4;i++)
	{	
		for(int j=0;j<4;j++)
		{
			if(arr[i][j]==play){count++;}
			else if(arr[i][j]=='T'){count++;}
		}
		if(count==4){return 1;}
		count=0;
	}
	

	//Check rows
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(arr[j][i]==play){count++;}
			else if(arr[j][i]=='T'){count++;}
		}
		if(count==4){return 1;}
		count=0;
	}
	

	//Diagonal 1
	for(int i=0;i<4;i++)
	{	
			if(arr[i][i]==play){count++;}
			else if(arr[i][i]=='T'){count++;}
	}
	if(count==4){return 1;}
	count=0;

	//Diagonal 2
	for(int i=0,j=3;i<4;i++,j--)
	{
		if(arr[i][j]==play){count++;}
		else if(arr[i][j]=='T'){count++;}
	}
	if(count==4){return 1;}
	return 0;
}

int tied(char arr[4][5])
{
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(arr[i][j]=='.'){return 0;}
		}
	}
	return 1;
}

int main(void) {

	char grid[4][5];
	int input;
	FILE *ofp;
	ofp = fopen("out.out","w");

	scanf("%d",&input);

	for(int i=1;i<=input;i++)
	{	
		for(int k=0;k<4;k++)
		{
			scanf("%s",grid[k]);
		}
		//printf("%s",grid[0]);
		if(winner('X',grid)){fprintf(ofp,"Case #%d: X won\n",i);}
		else if(winner('O',grid)){fprintf(ofp,"Case #%d: O won\n",i);}
		else if(tied(grid)){fprintf(ofp,"Case #%d: Draw\n",i);}
		else{fprintf(ofp,"Case #%d: Game has not completed\n",i);}


	}


	return 0;
}
