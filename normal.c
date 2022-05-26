#include<stdio.h> 
#include<pthread.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include <sys/time.h>
int main(int argc,char * argv[]) 
{       
	float delta;
  	struct timeval time1, time2;
	int row1=atoi(argv[1]),colon1=atoi(argv[2]),row2=atoi(argv[3]),colon2=atoi(argv[4]),i,j,k,toplam=0; 
	int A[row1][colon1]; 
	int B[row2][colon2]; 
	int C[row1][colon2];  
	gettimeofday(&time1, 0);
	if(colon1!=row2){
	printf("Carpma Islemi Yapilamaz. A matrisinin sutunu ile B matrisinin satiri esit degil \n");
	}
	else{
    for (i = 0; i < row1; i++)  
            for (j = 0; j < colon1; j++)  
                   A[i][j] = rand() % 10;  
             
    for (i = 0; i < row2; i++)  
            for (j = 0; j < colon2; j++)  
                   B[i][j] = rand() % 10;  
         
	printf("MATRIS A\n");      
    for (i = 0; i < row1; i++){ 
        for(j = 0; j < colon1; j++) 
            printf("%d ",A[i][j]); 
        printf("\n"); 
    }    
	printf("MATRIS B\n");                 
    for (i = 0; i < row2; i++){ 
        for(j = 0; j < colon2; j++) 
            printf("%d ",B[i][j]); 
        printf("\n");     
    }          
	int r=0,c=0;   
    
	printf("CARPIM SONUCU \n"); 
	for(i=0; i<row1; i++){  
        for(j=0; j<colon2; j++){
            for(k=0; k<colon1; k++){
                toplam += A[i][k] * B[k][j]; 
            }
            C[i][j] = toplam;  
            toplam = 0;   
            printf("%d ", C[i][j]); 
        }
        printf("\n");
    }
    }
	gettimeofday (&time2, 0);
    delta = (float)((1000000*time2.tv_sec + time2.tv_usec) -
                   (1000000*time1.tv_sec + time1.tv_usec))/1000000;
   printf("Toplam Gecen Sure = %f seconds\n", delta);
  return 0; 
} 
