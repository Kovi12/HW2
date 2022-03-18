#include "Huffman.h"

void HuffmanCodes(char data[], int freq[], int size)

{

	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);


	int arr[Height], top = 0;

	printCodes(root, arr, top);
}


bool Exists(char arr[100], string s, int pos) {
    for (int i = 0; i < pos ; i++)
        if (arr[i] == s[pos])
            return 1;
        
    return 0;
}
int main()
{
    string s;
	//Read the word
    cin >> s;
	char arr1[100];
    char arr2[100];
    int size = 0;

	//Array of letters appearing one time;
    for (int i = 0; i < s.length(); i++){
        
        if(!Exists(arr1, s, i)) 
        {
            arr1[size] = s[i];
            size++;
        }
    }
        
    for (int i = 0; i < s.length(); i++)
            arr2[i] = s[i];

    int visited = -1;  
    int fr[100];
	//Calculating the frequency of each letter
    for(int i = 0; i < s.length(); i++){  
        int count = 1;  
        for(int j = i+1; j < s.length(); j++){  
            if(arr2[i] == arr2[j]){  
                count++;   
                fr[j] = visited;  
            }  
        }  
        if(fr[i] != visited)  
            fr[i] = count;  
    }  
	int freq[100] ;
    int k =0;
	//Putting  the frquencies in an array of the same size as the array of letters ( arr1 )
    for(int i = 0; i < s.length(); i++){  
            if(fr[i] != visited) {
                freq[k] = fr[i];
                k++; 
            }  
                
        } 
    //Letter: Encrypted Letter
	HuffmanCodes(arr1, freq, size);

	return 0;
}
