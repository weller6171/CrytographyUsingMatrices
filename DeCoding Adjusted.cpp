#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k;
	int a,b,c,d;
	float securematrix[10][10];
	float matrixcode[10][10];
	float adj[10][10];
	float invcode[10][10];
	float decode[10][10];
	float det;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			decode[i][j]=0;
	printf("Please enter info for encrypted code : ");
	printf("\nPlease enter number of row >> \n");
	scanf("%d",&a);
	printf("Please enter number of column >> \n");
	scanf("%d",&b);
	
	printf("Please enter %d*%d matrix element : \n",a,b);
	for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
			printf("A%d%d :",i+1,j+1);
			scanf("%f",&securematrix[i][j]);
			}
		}
	//printting//
	printf("\nMatrix entered are : \n");
	for (i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
			printf("%.f\t\t",securematrix[i][j]);
			}
			printf("\n");
		}
	// Getting code needed for decrypting //
	printf("\nPlease enter info for encoding matrix:	");
	printf("\nPlease enter number of row >> \n");
	scanf("%d",&c);
	printf("Please enter number of column >> \n");
	scanf("%d",&d);
	
	printf("Please enter %d*%d matrix element : \n",c,d);
	for (i=0;i<c;i++)
		{
			for(j=0;j<d;j++)
			{
			printf("A%d%d :",i+1,j+1);
			scanf("%f",&matrixcode[i][j]);
			}
		}
		
		
	//printting//
	printf("\nMatrix entered are : \n");
	for (i=0;i<c;i++)
		{
			for(j=0;j<d;j++)
			{
			printf("%.f\t\t",matrixcode[i][j]);
			}
			printf("\n");
		}

//determinant //
det =(matrixcode[0][0] * (matrixcode[1][1]*matrixcode[2][2]-matrixcode[1][2]*matrixcode[2][1])) - (matrixcode[0][1] * (matrixcode[1][0]*matrixcode[2][2]-matrixcode[1][2]*matrixcode[2][0])) + (matrixcode[0][2] * (matrixcode[1][0]*matrixcode[2][1]-matrixcode[1][1]*matrixcode[2][0]));

		if(det==0)
			printf("Determinant is 0.\nInverse matrix does not exist.");
		else
		{	
		printf("Determinant is not 0.\n Determinant = %d.\nInverse matrix exists.",det);
	
	// Inverse matrix //
	for(i=0;i<c;i++){
      for(j=0;j<d;j++){
    	adj[i][j]=(((matrixcode[(i+1)%3][(j+1)%3] * matrixcode[(i+2)%3][(j+2)%3]) - (matrixcode[(i+1)%3][(j+2)%3]*matrixcode[(i+2)%3][(j+1)%3]))/det);
   	}
   } 
   
   for (i=0;i<c;i++){
   	for (j=0;j<d;j++){
   		invcode[i][j]=adj[j][i];
	   }
   }
}
	//Multiplication //
if (b==c)
	{
		for(i=0;i<a;i++)
			{
				for(j=0;j<d;j++)
					{
						for(k=0;k<b;k++)
							decode[i][j]+=(securematrix[i][k] * invcode[k][j]);
					}
			}
printf("\nResult of multiplication = \n");
		for (i=0;i<a;i++)
			{
				for(j=0;j<d;j++)
				{
				printf("%.f\t",decode[i][j]);
				}
				printf("\n");
			}
	}
	else 
		printf("Multiplication is not possible.");

	
	float num[28];
	char character[28];
	FILE *pt;
	pt=fopen("Code.txt","r");
	// Scanning for Code translation //
	for(i=0;i<27;i++)
	{
	fscanf(pt,"%f %c",&num[i],&character[i]);
	}
	
	// Start translating //
printf("\nMessage translated :\n");
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<d;j++)
		{
			for(k=0;k<27;k++)
			{	
			if(decode[i][j]==num[k])
				printf("%.f  ",num[k]);
			}
		}
	}
	printf("\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<d;j++)
		{
			for(k=0;k<27;k++)
			{	
			if(decode[i][j]==num[k])
				printf("%c",character[k]);
			}}
	}
	
	getch();
}
