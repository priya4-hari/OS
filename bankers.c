#include<stdio.h>
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10],k1=0,count1=0;
int p, r, i, j, process, count;
count = 0;
printf("OUTPUT FOR BANKER'S ALGORITHM\n");
printf("==============================\n");
printf("Enter the no of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
completed[i] = 0;

printf("\nEnter the no of resources : ");
scanf("%d", &r);

printf("\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
printf("\nFor process %d : ", i + 1);
for(j = 0; j < r; j++)
scanf("%d", &Max[i][j]);
}

printf("\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
printf("For process %d \n: ",i + 1);
for(j = 0; j < r; j++)
scanf("%d", &alloc[i][j]);
}

printf("\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
scanf("%d", &avail[i]);


for(i = 0; i < p; i++)
{
for(j = 0; j < r; j++)
need[i][j] = Max[i][j] - alloc[i][j];
}
printf("The need matrix is \n");
for(i=0;i<p;i++)
{
   printf("P[%d] ",i+1);
for(j=0;j<r;j++)
printf("%d  ",need[i][j]);
printf("\n");

}
printf("  Allocation matrix:\tNeed matrix:\tAvailable matrix:\n");
printf("    ");
for(j=0;j<3;j++)
        {
            for(i=0;i<r;i++)
                printf("R%d ",i+1);
            printf("\t\t");
        }
        printf("\n");

for(i = 0; i < p; i++)
{

printf("P[%d] ",i+1);
for( j = 0; j < r; j++)
printf("%d  ", alloc[i][j]);
printf("\t\t");
for( j = 0; j < r; j++)
printf("%d  ", need[i][j]);
printf("\t\t");
if(i==0)
{
 for(j=0;j<r;j++)
        {
                printf("%d  ",avail[j]);
        }
}
printf("\n");
}


while(count != p && process != -1)
{


process = -1;

for(i = ((k1)%p); i <= p; i++)
{
if(completed[i] == 0)
{
process = i ;
for(j = 0; j < r; j++)
{
if(avail[j] < need[i][j])
{
process = -1;
printf("\nAvailable is less than the need.So process %d doesn't takes place\n",i+1);
break;
}
}
}
if(process!=-1)
{
k1=process+1;
break;
}
}

if(process != -1)
{
safeSequence[count] = process + 1;
count++;
for(j = 0; j < r; j++)
{
avail[j] += alloc[process][j];
alloc[process][j] = 0;
need[process][j]=0;
completed[process] = 1;
}
printf("\nProcess %d runs to completion!\n", process + 1);
}
printf("  Allocation matrix:\tNeed matrix:\tAvailable matrix:\n");
printf("     ");
for(j=0;j<3;j++)
        {
            for(i=0;i<r;i++)
                printf("R%d ",i+1);
            printf("\t\t");
        }
        printf("\n");

for(i = 0; i < p; i++)
{

printf("P[%d] ",i+1);
for( j = 0; j < r; j++)
printf("%d  ", alloc[i][j]);
printf("\t\t");
for( j = 0; j < r; j++)
printf("%d  ", need[i][j]);
printf("\t\t");
if(i==0)
{
 for(j=0;j<r;j++)
        {
                printf("%d  ",avail[j]);
        }
}
printf("\n");
}

}

if(count == p)
{
printf("\nThe system is in a safe state!!\n");
printf("Safe Sequence : < ");

for( i = 0; i < p; i++)

printf("P[%d]", safeSequence[i]);
printf(">\n");


}
else
printf("\nThe system is in an unsafe state!!");
printf("\n===============================");
}

