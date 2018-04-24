// Copyright 3/22/2018 <Connor O'Brien>
#pragma once
#include <SFML/System.hpp>
#include <stdint.h>
#include <string>
#include <vector>
class RingBuffer{
  public:
  explicit RingBuffer(int cap);
  unsigned int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
  void printRB();
  private:
  std::vector<double> buffer;
  unsigned int cap;
  unsigned int elements;
  int first;
  int last;
};
