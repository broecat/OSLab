#include <stdio.h>
#include<string.h>
#include<ctype.h>



int main(void) {
	int t,m,n,w;
    int R[8]={0,1,1,1,0,-1,-1,-1};
    int C[8]={1,1,0,-1,-1,-1,0,1};
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
        char grid[51][51];
		scanf("%d %d",&m,&n);
		for(int k=0;k<m;k++)
		{
		scanf("%s",grid[k]);
		}
		scanf("%d",&w);
		for(int k=0;k<w;k++)
		{
           
			char word[51];
			scanf("%s",word);
            int found=0;
            for(int r=0;r<m;r++)
            {
                for(int c=0;c<n;c++)
                {
                    for(int l=0;l<8;l++)
                    {
                        int tempr=r;
                        int tempc=c;
                        for(int z=0;z<strlen(word);z++)
                        {
                            if(tempr>=m||tempr<0||tempc>=n||tempc<0||tolower(word[z])!=tolower(grid[tempr][tempc]))break;
                            if(z==strlen(word)-1){found=1;}
                            tempr+=R[l];
                            tempc+=C[l];

                        }
                        if(found)break;
                    }
                   
                    if(found){
                    printf("%d %d\n",r+1,c+1);
                    break;
                    }
                }
                if(found)break;
            }
		}
	}
	return 0;
}