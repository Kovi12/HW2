For exercise 1 i supposed that the problem comes down to finding an eulerian path in a directed graph
in which the letters are the vertices ,the word becoming the edge between the first and last letter.
But i couldn't make an algorithm that goes thourgh each possible order of words.   


For exercise 2 the output will be the total distance of the cargo without using the afterburners because of the fact that 
the way i wrote the code is very unnefficient and with many unnecessary things, and at some point it was too unreadable.
More details are in the comments.


For exercise 3  I assumed that the problem comes down to the Huffman coding which uses min heaps . 
The idea was to build a min heap of each individual character (based on their frequencies) and then extract
two nodes from the heap ( the two nodes with the smaller frequencies ).Next build an internal 
node (noted phi in the pdf , i used # ) which has the sum of the frquencies of the two extracted nodes , then 
make the first node its left child and the second one its right child. Next add this node to the min heap and repeat this
until the heap contains only one node. Now traversing the tree from the top to get to the character which you want the code of.
Each time you go to the right child it will add a 1 to that specific charachter's array and 0 if you go the left child .

  