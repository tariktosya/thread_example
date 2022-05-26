#include<stdio.h> 
#include<pthread.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include <sys/time.h>
    
     
void *mult(void* arg) 
{ 
    int *veri=(int *)arg;
    int top=0,i;
    for(i=1;i<=veri[0];i++)
    	top+=veri[i]*veri[i+veri[0]];	
    int *p = (int*)malloc(sizeof(int)); 
         *p = top;
	
	pthread_exit(p); 
} 
 
int main(int argc,char * argv[]) 
{        float delta;
  	struct timeval time1, time2;
	int row1=atoi(argv[1]),colon1=atoi(argv[2]),row2=atoi(argv[3]),colon2=atoi(argv[4]),i,j,k; 
	int A[row1][colon1]; 
	int B[row2][colon2]; 
	int *C[row1][colon2]; 
	int max = row1*colon2;
	gettimeofday(&time1, 0); 
	 if(colon1!=row2){
	printf("Carpma Islemi Yapilamaz. A matrisinin sutunu ile B matrisinin satiri esit degil \n");
	}
	else if(max!=atoi(argv[5])){
		printf("Thread Sayisini Yanlis Girdiniz. Olmasi gereken = %d",max);	
	}  
	
	else{
    
    for (i = 0; i < row1; i++)  
            for (j = 0; j < colon1; j++)  
                   A[i][j] = rand() % 11;  
             
    for (i = 0; i < row2; i++)  
            for (j = 0; j < colon2; j++)  
                   B[i][j] = rand() % 11;  
         
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
            
  
          
       
    pthread_t *threads; 
    threads = (pthread_t*)malloc(max*sizeof(pthread_t)); 
      
    int count = 0; 
    int* veri = NULL; 
	
    for (i = 0; i < row1; i++) 
        for (j = 0; j < colon2; j++) 
               {  
                 
           	 veri = (int *)malloc((30)*sizeof(int)); 
           	 veri[0] = colon1;
      		
            for (k = 0; k < colon1; k++) 
                veri[k+1] = A[i][k]; 
      
            for (k = 0; k < row2; k++) 
                veri[k+colon1+1] = B[k][j]; 
               
            
             pthread_create(&threads[count++], NULL, mult, (void*)(veri)); 
                  
                    }   
	int r=0,c=0;   
    
	printf("CARPIM SONUCU \n"); 
    for (i = 0; i < max; i++)  
    { 
      void *top;  
      pthread_join(threads[i], &top);        
          
	C[r][c]= (int *)top;
	printf("%d ",*C[r][c]); 
	
      c++;
      if ((i + 1) % colon2 == 0) {
		r+=1;
		c=0;
		printf("\n"); 
         }
			 
    } 
    
    }
	gettimeofday (&time2, 0);
    delta = (float)((1000000*time2.tv_sec + time2.tv_usec) -
                   (1000000*time1.tv_sec + time1.tv_usec))/1000000;
   printf("Toplam Gecen Sure = %f seconds\n", delta);
  return 0; 
} 
