#include <stdio.h>
#include <stdlib.h>

unsigned char out[4]={0,0,0,6}
unsigned char i;

int main()
{
  for(out[1]=1;out[1]<5,out[1]++)
    for(out[2]=out[1]+1;out[2]<6,out[2]++)
    {
      for(i=0;i<4;i++)
        print("%hhu ",out[i]);
      printf("\n");
    }
  return 0;
}
