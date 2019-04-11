# CPSC221-PA1-2018WT2
C++ Programming Assignment Authorized Release

A Linked List is a dynamic linear structure designed to hold any type of data. In this exercise, we develop and use a linked list to manipulate blocks of pixels from an image.

We have broken the image below into 6 Blocks.
![](https://www.ugrad.cs.ubc.ca/~cs221/2018W2/mps/p1/PA1pic1.png)

Each Block is placed into a Node of a Chain, as shown here
![](https://www.ugrad.cs.ubc.ca/~cs221/2018W2/mps/p1/PA1pic2.png)

The Chain can be rearranged, and the image reassembled to create fascinating visual results.

We have provided a starting point for achieving this functionality. It is your task to complete and expand on our implementation.

Specifications for each function you write are contained in the given code. The list of functions here should serve as a checklist for completing the exercise.

# In block.cpp
- int width() const; Returns the width of the current block.
- int height() const; Returns the height of the current block.
- void build(PNG & im, int column, int width); From im, grabs the vertical strip of pixels whose upper left corner is at position (column,0), and whose width is width.
- void render(PNG & im, int column ) const; Draws the current block at position (column,0) in im.
- void greyscale(); This function changes the saturation of every pixel in the block to 0, which removes the color, leaving grey.
# In chain.cpp
- void clear(); Helper function for destructor and assignment operator.
- void copy(const Chain & other); Helper function for copy constructor and assignment operator.
- ~Chain(); Destructor.
- void insertBack(const Block & ndata); Insert a new node at the end of the Chain.
- void moveBack(int startPos, int len, int dist); Move len nodes from startPos toward the end of the Chain, shifting by dist positions.
- void roll(int k); Move k nodes from the end of the Chain to the front. Their order does not change.
- void reverseSub(int pos1, int pos2); Reverses the order of the nodes in the chain from pos1 to pos2, inclusive.
- void weave(Chain & other); consumes the nodes in other placing them in alternating positions in the current Chain. In the final chain, the original Chain will occupy the odd nodes, and the nodes from other will be in the even positions.
- Implementation Constraints and Advice
