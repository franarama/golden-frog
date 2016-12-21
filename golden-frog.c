#include <stdio.h>
#include <stdlib.h>


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

void sort(int array[100][3]){
    int i, j, r, a;
    for(r=0;r<100;r++){
        for (i=0;i<3;i++){
            for(j=i+1;j<3;++j){
                if(*(*(array+r)+i) > *(*(array+r)+j)){
                    a = *(*(array+r)+i);
                    *(*(array+r)+i) = *(*(array+r)+j);
                    *(*(array+r)+j) = a;
                }    
            }
        }
    }
}

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

void sortF(int array[20][5]){
     int i, j, x, temp;
     for(i=0;i<20;i++){
       for(j=i+1;j<20;j++){
         if(array[i][4] > array[j][4]){
         for(x=0;x<5;x++){
		temp=array[i][x];
		array[i][x]=array[j][x];
		array[j][x]=temp;
		}
	      }
	   }
	}
     }


int main (int argc, char *argv[])
{
    int max_x = atoi(argv[1]);
    int max_y = atoi(argv[2]);
    int max_z = atoi(argv[3]);

    int frogs[100][3];

    
    int i;
    for (i=0; i<100; i++){

       int xrand = rand() % max_x;
       int yrand = rand() % max_y;
       int zrand = rand() % max_z;
       
       frogs[i][0] = xrand;
       frogs[i][1] = yrand;
       frogs[i][2] = zrand;
       
       }
       
    sort(frogs);
    print(frogs);

    /*create 5 new arrays*/
    int new1[20][5];
    int new2[20][5];
    int new3[20][5];
    int new4[20][5];
    int new5[20][5];
    
    int j;
    i=0;

    for(j=0;j<100;j+=5){

        new1[i][0]=frogs[j][0];
        new1[i][1]=frogs[j][1];
        new1[i][2]=frogs[j][2];
        new1[i][3]=1;
        new1[i][4]= new1[i][0]*new1[i][0]+3*new1[i][1]*new1[i][1]*new1[i][1]-2*new1[i][2]*new1[i][2];
        
        new2[i][0]=frogs[j+1][0];
        new2[i][1]=frogs[j+1][1];
        new2[i][2]=frogs[j+1][2];
        new2[i][3]=2;
        new2[i][4]= (new2[i][0]*new2[i][0])+(3*(new2[i][1]*new2[i][1]*new2[i][1]))-(2*(new2[i][2]*new2[i][2]));
        
        new3[i][0]=frogs[j+2][0];
        new3[i][1]=frogs[j+2][1];
        new3[i][2]=frogs[j+2][2];
        new3[i][3]=3;
        new3[i][4]= (new3[i][0]*new3[i][0])+(3*(new3[i][1]*new3[i][1]*new3[i][1]))-(2*(new3[i][2]*new3[i][2]));
        
        new4[i][0]=frogs[j+3][0];
        new4[i][1]=frogs[j+3][1];
        new4[i][2]=frogs[j+3][2];
        new4[i][3]=4;
        new4[i][4]= (new4[i][0]*new4[i][0])+(3*(new4[i][1]*new4[i][1]*new4[i][1]))-(2*(new4[i][2]*new4[i][2]));
        
        new5[i][0]=frogs[j+4][0];
        new5[i][1]=frogs[j+4][1];
        new5[i][2]=frogs[j+4][2];
        new5[i][3]=5;
        new5[i][4]= (new5[i][0]*new5[i][0])+(3*(new5[i][1]*new5[i][1]*new5[i][1]))-(2*(new5[i][2]*new5[i][2]));

	i++;
     }

    sortF(new1);
    sortF(new2);
    sortF(new3);
    sortF(new4);
    sortF(new5);

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


    int golden[5] = {new1[0][4], new2[0][4], new3[0][4], new4[0][4], new5[0][4]};
    int smallest;
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

