/*
Sam Dosi
09/22/2021
treehouse
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxHouses 16

typedef struct point{
    int x;
    int y;
}point;

// function prototype
void getpoints (int numberoftrees, point* ptr);
double calculatePoints (point ptr1, point ptr2);
void max_distance(double t_distance[][maxHouses],point* distance, int num_tree);
double CalculateTotalDist(int arr[], double dist[][maxHouses], int numberoftrees);
double perm(int array[], int used[], int numTree, double distance[][maxHouses], int k);
void intialToZero(int used[maxHouses]);

int main() {
    int testcase, i, numberOfTrees, used[maxHouses];
    double dist[maxHouses][maxHouses];
    double res=0 ;
    scanf("%d", &testcase) ;
    for(i=0; i<testcase; i++)
    {
        scanf("%d", &numberOfTrees);
        numberOfTrees=numberOfTrees*2;
        point* ptr= (point*)malloc(sizeof(point)* numberOfTrees);
        // getting the points and save them to the structure
        getpoints(numberOfTrees, ptr);
        // finding the max distance and store them to the array
        max_distance(dist,ptr,numberOfTrees);
        // initialling the used array to zero
        intialToZero(used);
        int arr[numberOfTrees];
        used[0]=0;
        // permutations function
        res=perm(arr, used, numberOfTrees, dist, 1);
        printf("%.3lf\n",res);
        free(ptr);
    }

    return 0;
    
}
void getpoints (int numberoftrees, point* ptr)
{
    int i;
    for(i=0; i<numberoftrees; i++){
        scanf("%d %d", &ptr[i].x, &ptr[i].y);
    }
}
double calculatePoints (point ptr1, point ptr2)
{

    double res=0;

        res= pow((ptr1.x-ptr2.x), 2);
        res+=pow((ptr1.y-ptr2.y), 2);
        res= sqrt(res);
    return res;
}
double CalculateTotalDist(int arr[], double dist[][maxHouses], int numberoftrees)
{
    double total=0;
    for(int i=0;i<numberoftrees;i++)
    {
        total+=dist[arr[i-1]][arr[i]];
    }
    return total;
}
double perm(int array[], int used[], int numTree, double distance[][maxHouses], int k)
{
    array[0]=0;
  if(k==numTree){
    return CalculateTotalDist(array, distance, numTree);
  }
    
  double res =100000;
  for(int i=0; i<numTree; i++){
    if(!used[i]){
        // check for even
      if(k%2==0 && (i>array[k-2]))
      {
        used[i]=1;
        array[k]=i;
          double sectest;
          sectest=perm(array, used, numTree, distance, k+1);
        if(res >sectest)
        {
          res = sectest;
        }
      }
      else
      {
        if(i>array[k-1]){
          used[i]=1;
          array[k]=i;
            double sectest;
            sectest=perm(array, used, numTree, distance, k+1);
          if(res >sectest)
          {
            res = sectest;
          }
        }
      }

    }

  }
  return res;
}
void max_distance(double t_distance[][maxHouses],point* distance, int num_tree){
   for(int i=0; i<num_tree; i++){
     for(int j=i+1; j<num_tree*2; j++){
         t_distance[i][j]=calculatePoints(distance[i], distance[j]) ;
       
     }
   }
 }
void intialToZero(int used[maxHouses] )
{
    int i=0;
    for(i=0; i<maxHouses; i++)
    {
        used[i]=0;
    }
}

