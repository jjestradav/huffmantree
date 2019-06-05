
#include <stdio.h> 
#include <stdlib.h> 
#include"../Client/ldf.c"
#define MAX_TREE_HT 255 

struct MinHeapNode node; 
void printInorder(node* root );  
struct MinHeapNode { 
    char data; 
    unsigned freq; 
    struct MinHeapNode *left, *right; 
}; 

struct MinHeap { 
    unsigned size; 
    unsigned capacity; 
    struct MinHeapNode** array; 
}; 

struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
    struct MinHeapNode* temp 
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode)); 
  
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
  
    return temp; 
} 

struct MinHeap* createMinHeap(unsigned capacity) 
  
{ 
  
    struct MinHeap* minHeap 
        = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 

    minHeap->size = 0; 
  
    minHeap->capacity = capacity; 
  
    minHeap->array 
        = (struct MinHeapNode**)malloc(minHeap-> 
capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 

void swapMinHeapNode(struct MinHeapNode** a, 
                     struct MinHeapNode** b) 
  
{ 
  
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 
  

void minHeapify(struct MinHeap* minHeap, int idx) 
  
{ 
  
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]-> 
freq < minHeap->array[smallest]->freq) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]-> 
freq < minHeap->array[smallest]->freq) 
        smallest = right; 
  
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], 
                        &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
} 
  

int isSizeOne(struct MinHeap* minHeap) 
{ 
  
    return (minHeap->size == 1); 
} 

struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
  
{ 
  
    struct MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] 
        = minHeap->array[minHeap->size - 1]; 
  
    --minHeap->size; 
    minHeapify(minHeap, 0); 
  
    return temp; 
} 

void insertMinHeap(struct MinHeap* minHeap, 
                   struct MinHeapNode* minHeapNode) 
  
{ 
  
    ++minHeap->size; 
    int i = minHeap->size - 1; 
  
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
  
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    minHeap->array[i] = minHeapNode; 
} 
  

void buildMinHeap(struct MinHeap* minHeap) 
  
{ 
  
    int n = minHeap->size - 1; 
    int i; 
  
    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
} 
  

void printArr(int arr[], int n, FILE * file) 
{ 
    int i; 
    for (i = 0; i < n; i++){
        if(i==n-1){
        fprintf(file,"%d\n",arr[i]);
        }
        else{
            fprintf(file,"%d",arr[i]);
        }

    }
           
  

     
        
    printf("\n"); 
} 
  

int isLeaf(struct MinHeapNode* root) 
  
{ 
  
    return !(root->left) && !(root->right); 
} 

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) 
  
{ 
  
    struct MinHeap* minHeap = createMinHeap(size); 
  
    for (int i = 0; i < size; i++) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
  
    minHeap->size = size; 
    buildMinHeap(minHeap); 
  
    return minHeap; 
} 
  

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
  
{ 
    struct MinHeapNode *left, *right, *top; 
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 

    while (!isSizeOne(minHeap)) { 
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
        top = newNode('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        insertMinHeap(minHeap, top); 
    } 

    return extractMin(minHeap); 
} 

void printCodes(struct MinHeapNode* root, int arr[], int top, FILE * file) 
  
{ 
  

    if (root->left) { 
  
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1,file); 
    } 
  

    if (root->right) { 
  
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1,file); 
    } 

    if (isLeaf(root)) { 
        
        if(root->freq>0){
          fprintf(file,"%d\t", root->data); 
          printArr(arr, top,file); 
        }
        
    } 
} 
  
void HuffmanCodes(char data[], int freq[], int size, FILE * file) 
  
{ 
    struct MinHeapNode* root 
        = buildHuffmanTree(data, freq, size); 
  
 
    int arr[MAX_TREE_HT], top = 0; 
  
    printCodes(root, arr, top,file);

} 
typedef struct MinHeapNode node;
void printInorder(node* root ) 
{ 
     if (root == NULL) 
          return; 

    printInorder(root->left); 
     printf("%c ", root->data); 
       printInorder(root->right);
    
} 

int main(){
    char aux[255];
    for(int i=0; i<255; i++)
            aux[i]=i;

    FILE* file;
    int * frecuencias=malloc(255*sizeof(*frecuencias));
    cuentafrecuencia(frecuencias,file,"../files/abcd.txt");

   FILE * fp;
   fp = fopen ("file.txt", "w");

    HuffmanCodes(aux,frecuencias,255,fp);
    fclose(fp);
    fclose(file);

    return 0;
}