// Copyright 3/27/2018 <Connor O'Brien>
#include "GuitarString.hpp"
#include <stdlib.h>
#include <cmath>
#include <iostream>
GuitarString::GuitarString(double freq){
  rb= new RingBuffer(ceil(44100/freq));
}
GuitarString::GuitarString(std::vector<sf::Int16> init){
  rb= new RingBuffer(init.size());
  for(unsigned int i=0;i<=init.size();i++){
    rb->enqueue(init[i]);
  }

}
GuitarString::~GuitarString(){
  for(unsigned int i=0;i<=rb->size();i++){
    rb->dequeue(); 
  }
  delete rb; 
}
void GuitarString::pluck(){
  while(!(rb->isFull())){
    //double ra = (((static_cast<double>(rand() % 1000))/1000)-0.5); 
    double ra = rand(); 
    //std::cout << ra << std::endl;
    rb->enqueue(ra);
  }
}
void GuitarString::tic(){
  tik =tik+1; 
  double temp = rb->dequeue();
  double look = rb->peek();
  rb->enqueue(0.996*((temp+look)/2));
  //(*rb).
}
sf::Int16 GuitarString::sample(){
  return rb->peek();
}
int GuitarString::time(){
  return tik; 
}
