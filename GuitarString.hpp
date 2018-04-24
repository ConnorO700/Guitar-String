// Copyright 3/27/2018 <Connor O'Brien>
#pragma once
#include "RingBuffer.hpp"
#include <vector>
#include <SFML/System.hpp>
class GuitarString{
  public:
  GuitarString(double freq);
  GuitarString(std::vector<sf::Int16> init);
  ~GuitarString();
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();

  private:
  RingBuffer* rb;
  int tik;

};
