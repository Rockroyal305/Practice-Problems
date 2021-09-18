#include <stdio.h>
int main(void){
      FILE *fin  = fopen ("crossroad.in", "r");
      FILE *fout = fopen ("crossroad.out", "w");
      int n;
      fscanf (fin,"%i",&n);
      int b[11];
      int a[11];
      int crossings = 0;
      for(int i = 0; i < 11; i++){
            b[i] = 0;
      }
      for(int i = 1; i <= n; i++){
            int cow,side;
            fscanf (fin,"%i %i",&cow,&side);
            if(b[cow] == 0){
                  b[cow] = 1;
                  a[cow] = side;
            }else{
                  if(a[cow] != side){
                        crossings++;
                        a[cow] = side;
                  }
            }
      }
      fprintf (fout,"%i\n",crossings);
}

