#pragma once

#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include <random>
#include <iostream>

using namespace std;

template <typename Container>
void Input(Container& container, int size);

template <typename Container>
void Print(const Container& container);

void Swap(int& a, int& b);

template <typename Container>
void MiddleElement(Container& container);



