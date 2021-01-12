#include<stdio.h>

int main()
{

      int reference_string[10], page_faults = 0, m, n, s, pages;
      int frames,t[50],i,flag=0;

      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter Total Number of Frames:\t");
      {
            scanf("%d", &frames);
      }
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &reference_string[m]);
      }
      
      int temp[frames];
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            s = 0;
            for(n = 0; n < frames; n++)
            {
                  if(reference_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;
                  }
            }
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {
                  temp[m] = reference_string[m];
            }
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
            printf("\n");
            if(m==0){
            for(i=0;i<frames;i++)
                t[i]=temp[i];
            for(n = 0; n < frames; n++)
            {
                if(temp[n]<0){
                    printf(" | | ");
                    continue;}
                  printf(" |%d| ", temp[n]);
            }}
            else
            {
            for(n=0;n<frames;n++){
            if(t[n]!=temp[n]){
            flag=1;
            break;}}
             if(flag==1){
            for(n = 0; n < frames; n++)
            {
                    t[n]=temp[n];
                if(temp[n]<0){
                    printf(" | | ");
                    continue;}
                  printf(" |%d| ", temp[n]);
            }flag=0;
            }
            else
            printf("\n");


      }}
      printf("\nTotal Page Faults:\t%d\n", page_faults);
      return 0;
}

