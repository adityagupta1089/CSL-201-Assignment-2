# CSL-201-Assignment-2

* To Build:
  * All problems:
    ```
    make all
    ```
  * Individual Problem (e.g. #2):
    ```
    make prob2
    ```

* To Run (e.g. #2):
  ```
  ./prob2
  ```

# Questions:
  1. **[10 marks]** In a correct C++ program, each opening group symbol should have a matching closing group symbol. For example a possible correct order of grouping symbols is `[{(){()}}]`, while an incorrect order is `[{(){(})}]`. In addition to the traditional symbols, the C++ version we are using has one more delimiting symbol, `$`, which is used to print value of an expression. We call this version EC++. For example,
  
  ```
  int main(){
  //some code
  $5*(6+4/(3+2))$
  //some code
  }
  ```
  
  Note that the grouping symbol should be balanced between two delimiting symbols. Write a program that takes input a EC++ file and returns true if all grouping and delimiting symbols are matching otherwise returns false. [Hint: can use two stacks].
  
  2. **[10 marks]** Consider the fo llowing problem: Given an input sequence a<sub>0</sub>, ∙ ∙ ∙ , a<sub>n−1</sub> of n positive numbers, output a sequence b<sub>0</sub>,∙∙∙ ,b<sub>n−1</sub> where for any `i in {0,∙∙∙ ,n − 1}`, b<sub>i</sub> is the rightmost number to the left of ai that is bigger than ai in the given sequence. If no number to the left of ai is b igger than ai, then bi is defined to be `−1`. Thus b<sub>0</sub> is always −1 because there is no number to the left of a<sub>0</sub>. For instance, if `n = 7` and the input sequence is `7, 2, 5, 3, 6, 9, 1`, then the output sequence is `−1, 7, 7, 5, 7, −1, 9`.
  Give an algorithm for computing the output sequence from the input sequence in linear (i.e., `O(n)`) time. [Hint: Use a Stack].

  3. **[10 marks]** We define range of an integer array as the tuple of minimum and maximum elements. For example, the range of array `[ 2, 5 , 7, 3, 6, 4, 8]` is `(2, 8)`. Given a large array of size n, find range of each contiguous subarray of size k and store in a vector. For example, the subarray range vector for k = 3 and given array would be: Subarray range vector = `(2, 7), (3, 7), (3, 7), (3, 6), (4, 8)`. Design and implement an algorithm to obtain subarray range vector for given `k` in `O(n)` time. [Hint: use queue/deque].

  4. **[20 marks]** Read a randomly ordered sequence of integers and store them in a doubly linked list. Use inplace insertion sort to sort the elements of the linked list. Now convert this list into a binary search tree with minimum height possible. Write another program to test whether a given tree is BST or not. Use this program to test the correctness of your previous program, i.e., whether or not the binary tree you have constructed is a BST.
