/*
Francesca Ramunno
Comp 2130, TRU
Winter 2016 senester
*/

#include <stdio.h>
#include <stdlib.h>

// this function prints a 100 x 3 array of integers in the format P*** = X, Y, Z
void print(int array[100][3]){
    int i, j, k;
    for(i=0;i<100;i++){
        printf("P%03d", i+1);
        printf(" = ");
        for(j=0;j<2;j++){
        printf("%d, ", array[i][j]);
       }
        for(k=2;k<3;k++){
        printf("%d ", array[i][j]);
       }
       printf("\n");
    }
}

// sorts the columns of each row (ascending) of a 100 x 3 array using bubble sort
void sort(int array[100][3]){
    int i, j, r, a;
    for(r=0;r<100;r++){ // rows
        for (i=0;i<3;i++){ // columns
            for(j=i+1;j<3;++j){ // columns of the next row
                if(*(*(array+r)+i) > *(*(array+r)+j)){ // if the values of the current row are greater than the next, swap them
	            // the swap
                    a = *(*(array+r)+i);
                    *(*(array+r)+i) = *(*(array+r)+j);
                    *(*(array+r)+j) = a;
                }    
            }
        }
    }
}

// prints the new, 20 x 5 arrays with added format of Group ID = *, F = *
void printNew(int array[20][5]){
        int i, j, k;
        for(i=0;i<20;i++){
            printf("P%02d", i+1);
            printf(" = ");
            for(j=0;j<2;j++){
                printf("%d, ", array[i][j]);
       }
        for(k=2;k<3;k++){
            printf("%d ", array[i][j]);
       }
       printf("Group ID = %d", array[i][3]);
       printf(" F = %d", array[i][4]);
       printf("\n");
    }
}

// sorts the 20 x 5 arrays based on fitness value, F using bubble sort
void sortF(int array[20][5]){
     int i, j, x, temp;
     for(i=0;i<20;i++){ // rows
       for(j=i+1;j<20;j++){ // next row
         if(array[i][4] > array[j][4]){ // if current row F value is greater than the next, swap the rows
            for(x=0;x<5;x++){ // to swap all 5 columns 
		   temp=array[i][x];
		   array[i][x]=array[j][x];
		   array[j][x]=temp;
             }
	  }
       }
    }
}

// calculates and returns the fitness value
int getFValue(int x, int y, int z) {
      int fValue;
      fValue = (x*x)+(3*(y*y*y))+(2*(z*z));
      return fValue;
}


int main (int argc, char *argv[])
{
    int max_x = atoi(argv[1]); // user input representing the max value for X
    int max_y = atoi(argv[2]); // user input representing the max value for Y
    int max_z = atoi(argv[3]); // user input representing the max value for Z

    int frogs[100][3]; // the population of frogs; a 100 x 3 array

    
    int i;
    for (i=0; i<100; i++){

       int xrand = rand() % max_x; // random X value between 0 and the user provided max value for X 
       int yrand = rand() % max_y; // random Y value between 0 and the user provided max value for Y 
       int zrand = rand() % max_z; // random Z value between 0 and the user provided max value for Z 
       
       // fill the array
       frogs[i][0] = xrand;
       frogs[i][1] = yrand;
       frogs[i][2] = zrand;
       
       }
       
    sort(frogs);
    print(frogs);

    // create 5 new arrays
    int new1[20][5];
    int new2[20][5];
    int new3[20][5];
    int new4[20][5];
    int new5[20][5];
    
    int j;
    i=0;
	
    // fill the new arrays
    for(j=0;j<100;j+=5){

        new1[i][0]=frogs[j][0];
        new1[i][1]=frogs[j][1];
        new1[i][2]=frogs[j][2];
        new1[i][3]=1; // this is the group ID
	new1[i][4]=getFValue(new1[i][0], new1[i][1], new1[i][2]); // the fitness value
        
        new2[i][0]=frogs[j+1][0];
        new2[i][1]=frogs[j+1][1];
        new2[i][2]=frogs[j+1][2];
        new2[i][3]=2;
        new2[i][4]= getFValue(new2[i][0], new2[i][1], new2[i][2]);
        
        new3[i][0]=frogs[j+2][0];
        new3[i][1]=frogs[j+2][1];
        new3[i][2]=frogs[j+2][2];
        new3[i][3]=3;
        new3[i][4]= getFValue(new3[i][0], new3[i][1], new3[i][2]);
        
        new4[i][0]=frogs[j+3][0];
        new4[i][1]=frogs[j+3][1];
        new4[i][2]=frogs[j+3][2];
        new4[i][3]=4;
        new4[i][4]= getFValue(new4[i][0], new4[i][1], new4[i][2]);
        
        new5[i][0]=frogs[j+4][0];
        new5[i][1]=frogs[j+4][1];
        new5[i][2]=frogs[j+4][2];
        new5[i][3]=5;
        new5[i][4]= getFValue(new5[i][0], new5[i][1], new5[i][2]);

	i++;
     }

    // sort the new arrays
    sortF(new1);
    sortF(new2);
    sortF(new3);
    sortF(new4);
    sortF(new5);
    
    // print the new arrays
    printf("\n");
    printNew(new1);
    printf("\n");
    printNew(new2);
    printf("\n");
    printNew(new3);
    printf("\n");
    printNew(new4);
    printf("\n");
    printNew(new5);
    printf("\n");

    // create an array with each of the frogs with the lowest F value in each group
    int golden[5] = {new1[0][4], new2[0][4], new3[0][4], new4[0][4], new5[0][4]};
    int smallest;
	
    // find the smallest F value	
    for(i=0;i<5;i++){
	if(golden[i] < smallest){
          smallest = golden[i];
       }
     }
	
     if(new1[0][4] == smallest){
	printf("Golden frog:X=%d,Y=%d,Z=%d, Group ID=%d Fitness Value=%d\n", new1[0][0], new1[0][1], new1[0][2], new1[0][3], new1[0][4]);
     }

     else if(new2[0][4] == smallest){
	printf("Golden frog:X=%d,Y=%d,Z=%d, Group ID=%d Fitness Value=%d\n", new2[0][0], new2[0][1], new2[0][2], new2[0][3], new2[0][4]);
     }

     else if(new3[0][4] == smallest){
	printf("Golden frog:X=%d,Y=%d,Z=%d, Group ID=%d Fitness Value=%d\n", new3[0][0], new3[0][1], new3[0][2], new3[0][3], new3[0][4]);
     }

     else if(new4[0][4] == smallest){
	printf("Golden frog:X=%d,Y=%d,Z=%d, Group ID=%d Fitness Value=%d\n", new4[0][0], new4[0][1], new4[0][2], new4[0][3], new4[0][4]);
     }

     else {
	printf("Golden frog:X=%d,Y=%d,Z=%d, Group ID=%d Fitness Value=%d\n", new5[0][0], new5[0][1], new5[0][2], new5[0][3], new5[0][4]);
     }     

return 0;
}

