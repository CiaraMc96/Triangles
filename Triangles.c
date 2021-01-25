#include <stdio.h>
#include <math.h>

int V = 5; //V=5 for setting matrices to be 5x5
//to call for multiplication
void multiply(int A[][V], int B[][V], int C[][V]) { 
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < V; j++) { 
            C[i][j] = 0; 
            for (int k = 0; k < V; k++) 
                C[i][j] += A[i][k]*B[k][j]; 
        } 
    } 
} 
  
//calculating the trace of the matrix
int getTrace(int graph[][V]) { 
    int trace = 0; 
    for (int i = 0; i < V; i++) 
        trace += graph[i][i]; 
    return trace; 
} 

int triangleInGraph(int graph[][V]) { 
    int mat2[V][V]; //declaring integer for mat2 which will be graph^2
    int mat3[V][V]; //declaring integer for mat3 which will be graph^3
  
    //  Initialising matrices with 0
    for (int i = 0; i < V; ++i) 
        for (int j = 0; j < V; ++j) 
            mat2[i][j] = mat3[i][j] = 0; 
  
    // calling multiply function to make mat2 graph^2
    multiply(graph, graph, mat2); 
  
    // after this multiplication mat3 is graph^3
    multiply(graph, mat2, mat3); 

    //used for printing results in main
    printf("Vertex 1 is a part of %d triangles.\n", mat3[0][0]/2);
    printf("Vertex 2 is a part of %d triangles.\n", mat3[1][1]/2);
    printf("Vertex 3 is a part of %d triangles.\n", mat3[2][2]/2);
    printf("Vertex 4 is a part of %d triangles.\n", mat3[3][3]/2);
    printf("Vertex 5 is a part of %d triangles.\n", mat3[4][4]/2);
  
    int trace = getTrace(mat3); 
    return trace / 6; 
} 

int main() {
    int arr[5][5]; //declaring an arrangement for inputting the 5x5 matrix
    printf("Enter Adjacency Matrix\n"); //text for asking user for 5x5 matrix

    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            scanf("%d", &arr[i][j]); //using scanf and for functions to read in the matrix number by number
        }
    }

    printf("Total %d triangles.\n",triangleInGraph(arr)); //printing results and calling triangleInGraph to obtain them


}
