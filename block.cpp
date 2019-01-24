#include "block.h"


// PA1 functions


// Builds a vertical strip of image pixels starting from the upper left corner at the specified position with specified width
void Block::build(PNG & im, int column, int width){
  for (unsigned y = 0; y < im.height(); y++){
    vector<HSLAPixel> horizontal;
    for(int x = column; x < (width + column); x++){
      HSLAPixel* pixel = im.getPixel(x,y);
      horizontal.push_back(*pixel);
    }
    data.push_back(horizontal);
  }
}


// Returns height of the block
int Block::height() const{
  return data.size();
}

// Returns width of the block
int Block::width() const{
  if(height() > 0){
  return data[0].size();
  }
  return 0;
}

// Changes the image to grey
void Block::greyscale(){
  for(int i = 0; i < height(); i++){
    for(int j = 0; j < width(); j++){
    data[i][j].s = 0;
    }
  }
  cout << "greyscale done" << endl;
}

// Places the block on the image
void Block::render(PNG & img, int column) const{
  for(unsigned y = 0; y < height(); y++){
    for(int x = column; x < (column+ width()); x++){
      HSLAPixel* pixel = img.getPixel(x,y);
      pixel->s = data[y][x - column].s;
    }
  }
}