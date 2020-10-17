#include "ItemType.h"
#include <iostream>
#include <ostream>

using namespace std;


ItemType::ItemType () {
  value = 0;
}

ItemType::Comparison ItemType::compareTo(ItemType item) {
  if (this -> value > item.getValue()) {
    return GREATER;
  } else if (this -> value < item.getValue()) {
    return LESS;
  } else
    return EQUAL;
  
}

int ItemType::getValue() const {
  return value;
}

void ItemType::initialize(int num) {
  //ItemType type;
  value = num;
}
