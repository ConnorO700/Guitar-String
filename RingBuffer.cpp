// Copyright 3/22/2018 <Connor O'Brien>
#include <iostream>
#include "RingBuffer.hpp"
RingBuffer::RingBuffer(int Ccap) {  // done
  if (Ccap <= 1) {
    throw std::invalid_argument("RB constructor: cap > 1");
  }
  for (int i = 0; i < Ccap; i++) {
    buffer.push_back(-1);
  }
  first = 0;
  cap = Ccap;
  last = 0;
  elements = 0;
}
unsigned int RingBuffer::size() {  // done
  return elements;
}
bool RingBuffer::isEmpty() {  // done
  if (elements == 0) {
    return true;
  }
  return false;
}
bool RingBuffer::isFull() {  // done
  if (this->size() == cap) {
    return true;
  }
  return false;
}
void RingBuffer::enqueue(int16_t x) {  // done
  //std::cout << x << std::endl;
  if (this->isFull()) {
    std::runtime_error("enqueue: can't enqueue to a full ring.");
  } else {  // buffer not full
    buffer[last] = x;  // set last position to new element
    last = (last+1)%cap;  // increase last position
    elements = elements +1;  // increase total elements
  }
}
int16_t RingBuffer::dequeue() {  // done
  if (this->isEmpty()) {
    throw std::runtime_error("dequeue: no first node in an empty ring.");
  } else {
    int16_t re = buffer[first];
    first = (first +1)%cap;  // move first right or wrap around
    elements = elements -1;  // decrease total elements
    return re;
  }
  return -1;
}
int16_t RingBuffer::peek() {  // done
  if (this->isEmpty()) {
    throw std::runtime_error("peek: no first node in an empty ring.");
  } else {
    return buffer[first];
  }
  return -1;
}
void RingBuffer::printRB() {
  for (unsigned int i = 0; i < cap; i++) {
    std::cout << "[" << buffer[(i+first)%cap] << "]" <<std::endl;
  }
}
