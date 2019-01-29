#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
  clear();
  head_->next = NULL;
  head_->prev = NULL;
  delete head_;
  head_=NULL;
    }
  //  clear();
  // head_->next = NULL;
  // head_->prev = NULL;
  // delete head_;
  // head_ = NULL; 

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
   if ((startPos + len - 1 + dist) >= length_ ){
     dist = (length_ - startPos - len + 1);
   }
   Node* curr = walk(head_, startPos);
   Node* end = walk(head_, (startPos + len - 1));

   Node* bcurr = walk(head_, (startPos - 1));
   Node* aend = walk(head_, (startPos + len));


   Node* t1 = walk(head_, (startPos + len + dist - 1));
   Node* t2 = walk(head_, (startPos + len + dist));
  
   if (dist == 0){
        cout << "not moving, distance is zero" << endl;
   }

   else{
      curr->prev = t1;
      t1->next = curr;
      bcurr->next = aend;
      aend->prev = bcurr;
      t2->prev = end;
      end->next = t2; 
     }
}

/**
 * Rolls the current Chain by k nodes: reorders the current list
 * so that the first k nodes are the (n-k+1)th, (n-k+2)th, ... , nth
 * nodes of the original list followed by the 1st, 2nd, ..., (n-k)th
 * nodes of the original list where n is the length.
 */
void Chain::roll(int k){
  /* your code here */
 if(k == length_){
    cout << "roll entire chain" << endl;
  }
  else{
  moveBack(1,(length_- k),k);
  }
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
  Node* posi1 = walk(head_->next, (pos1 - 1));
  Node* posi2 = walk(head_->next, (pos2 - 1));

  int dist = (pos2 - pos1);
  int spos2 = pos2;
  int spos1 = pos1;
  int j = 1;
  moveBack(pos2,1,-(dist + 1));
  for(int i = 1; i <= (pos2 - pos1 -1); i++){
    moveBack((pos1 + 1),1,(dist - j));
    j++;
  }
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
void Chain::weave(Chain & other) { 
  Node* retained;
  Node* curr; // will represent the current node we are on
  curr = head_->next; // This is the first node of curr
  
  Node* oretained;
  Node* ocurr; // will represent the current of other we are on
  ocurr = other.head_->next; // This is the first node of other

  Node* temp;
  // Condition if the width or height are not right
  if (width_ != other.width_ && height_ != other.height_){
    cout << "Block sizes differ." << endl;
  }
  // this is where we will start to go through the list
  else {
     cout << "Ours is bigger" << endl;
    if (length_ >= other.length_){
       cout << "made it to for loop" << endl;
      for (int i = 0; i < other.length_ ; i++){
      retained = curr;
      curr = curr->next;

      oretained = ocurr;
      ocurr = ocurr->next;

      retained->next = oretained;
      oretained->prev = retained;
      oretained->next = curr;
      curr->prev = oretained;
      length_++;
      }
      cout << "finished for loop" << endl;
      curr->prev = oretained;
      oretained->next = curr;
      other.head_->prev = NULL;
      other.head_->next = NULL;
      length_++;
    }
    else if (length_ < other.length_){
       cout << "Other is bigger" << endl;
      for (int i = 0; i < length_; i++){
      retained = curr;
      curr = curr->next;

      oretained = ocurr;
      ocurr = ocurr->next;

      retained->next = oretained;
      oretained->prev = retained;
      oretained->next = curr;
      curr->prev = oretained;
      length_++;
      }
       cout << "finished for loop" << endl;
      temp = other.head_->prev;
      head_->prev =  temp;
      temp->next = head_;
      other.head_->prev = NULL;
      other.head_->next = NULL;
      length_ = (length_+(other.length_-length_));
    }
  }
}


/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class except for the sentinel head_. Sets length_
 * to zero.  After clear() the chain represents an empty chain.
 */
void Chain::clear() {
  Node* curr; // will represent the current node we are on
  Node* temp; // will represent the node that we need to delete

  if (head_->next == NULL && head_->prev == NULL){
    //Do nothing, we're good
  }
  else {
    curr = head_->next;
    while (curr !=head_){
      temp = curr;
      temp->prev = NULL;
      curr = temp->next;
      temp->next = NULL;

      delete temp;
      temp = NULL;
    }
  }
  length_ = 0;
    }

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const& other) {
  Node* othercurr = other.head_->next;
  Node* curr = head_;
  
  for(int i = 1; i <= other.size(); i++){
     Node* newnode = new Node(othercurr->data);
     height_ = othercurr->data.height();
     width_ = othercurr->data.width();
     curr->next = newnode;
     newnode->prev = curr;
     newnode->next = head_;
     head_->prev = newnode; 
     othercurr = othercurr->next;
     curr = curr->next;
     length_++;
  }

}
