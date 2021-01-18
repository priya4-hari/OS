#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i,jqueue[100], queue2[100], q_size, head, seek=0, temp;
  float avg;

  printf("%s\n", "SSTF Disk Scheduling Algorithm");
  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);
  printf("%s\n", "Enter queue elements");
  for( i=0; i<q_size; i++){
    scanf("%d",&queue[i]);
  }
  printf("%s\n","Enter initial head position");
  scanf("%d", &head);
  for(i=0; i<q_size; i++){
    queue2[i] = abs(head-queue[i]);
  }
  for(i=0; i<q_size; i++){
      for(j=i+1; j<q_size;j++){

        if(queue2[i]>queue2[j]){
            temp = queue2[i];
            queue2[i]=queue[j];
            queue2[j]=temp;

            temp=queue[i];
            queue[i]=queue[j];
            queue[j]=temp;
        }
    }

  }

  for(i=1; i<q_size; i++){
    seek = seek+abs(head-queue[i]);
    head = queue[i];
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);

  return 0;
}


