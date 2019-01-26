#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
  //If we are given an empty list to begin with
  if (head_->next == NULL && head_->prev == NULL){
    //Delete the head; 
    printf("deleting head");
    delete head_;
    head_ = NULL; 
    length_ = 0;
    height_ = 0;
    width_ = 0;
    printf("done deleting chain");
    return;  
  }
  else {
    //Clear all dynamically allocated data first
    printf("deleting dynamic data");
    clear();
    
    //After deleting all nodes except head.
    //delete head_->next
    delete head_-> next;
    head_->next = NULL;
    //delete the head_->prev
    delete head_-> prev;
    head_->prev = NULL;
    //delete head_
    delete head_;
    head_ = NULL;
    length_ = 0;
    height_ = 0;
    width_ = 0;

    printf("done deleting chain");  
    return;
    //Ends the function
  } 
}

/**
 * Inserts a new node at the end of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
Node* inode = new Node(ndata);
head_->prev->next = inode;
inode->prev = head_->prev;
head_->prev = inode;
inode->next = head_;
//Node* curr = head_->prev;
cout << head_->prev << endl;
cout << head_->next << endl;
cout << head_->prev->prev << endl;
length_++;
}

/**
 * Modifies the Chain by moving the subchain of len Nodes,
 * starting at position startPos, dist positions toward the
 * end of the chain.  If startPos + len - 1 + dist > length
 * then dist = length - startPos - len + 1 (to prevent gaps
 * in the new chain).
 * The subchain occupies positions (startPos + dist) through
 * (startPos + dist + len - 1) of the resulting chain.
 * The order of subchain nodes is not changed in the move.
 * You may assume that: 1 <= startPos <= length - len + 1,
 * 0 <= dist <= length, and 0 <= len <= length. 
 */
void Chain::moveBack(int startPos, int len, int dist){
  /* your code here */
}

/**
 * Rolls the current Chain by k nodes: reorders the current list
 * so that the first k nodes are the (n-k+1)th, (n-k+2)th, ... , nth
 * nodes of the original list followed by the 1st, 2nd, ..., (n-k)th
 * nodes of the original list where n is the length.
 */
void Chain::roll(int k){
  /* your code here */
}

/**
 * Modifies the current chain by reversing the sequence
 * of nodes from pos1 up to and including pos2. You may
 * assume that pos1 and pos2 exist in the given chain,
 * and pos1 <= pos2.
 * The positions are 1-based.
 */
void Chain::reverseSub(int pos1, int pos2){
  /* your code here */
}

/*
* Modifies both the current chain and the "other" chain by removing
* nodes from the other chain and adding them between the nodes
* of the current chain -- one "other" node between two current nodes --
* until one of the two chains is exhausted.  Then the rest of the
* nodes in the non-empty chain follow.
* The length of the resulting chain should be the sum of the lengths
* of current and other. The other chain should have only
* the head_ sentinel at the end of the operation.
* The weave fails and the original
* chains should be unchanged if block sizes are different.
* In that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/
void Chain::weave(Chain & other) { // leaves other empty.
  /* your code here */
}


/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class except for the sentinel head_. Sets length_
 * to zero.  After clear() the chain represents an empty chain.
 */
void Chain::clear() {
  Node* curr;
  Node* temp;
  // If there is no prev or next,
  if (head_->next == NULL && head_->prev == NULL){
    printf("empty list provided");
    //Do nothing 
    return;  
  }
  // If there is something after the head,
  if (head_->next != NULL){
    printf("list with nodes provided");
    //If curr is not head
    //This should increment it all the way until we get back
    //to the start again once we reach the last node 
    while (curr != head_){
      printf("looping to deleted a node");
      //set up temporary variable to delete stuff
      temp = curr;
      //Increment the curr to the next one
      curr = temp->next;
      //delete the ptr of temp that points to temp->prev
      temp->prev = NULL;
      //delete the ptr of temp that points to temp->next
      //the next is already retained by curr;
      temp->next = NULL;
      //delete the node of temp
      delete temp;
      //set temp to Null for cycle to repeat;
      temp = NULL;
    }
    printf("completed deletion");
    return;
    }
    else{
      printf("Oops, something went wrong");
      return;
      //do nothing
    }
  }

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const& other) {
  /* your code here */
}
