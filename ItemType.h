#ifndef _ITYPE
#define _ITYPE

#include <string>
using namespace std;

class ItemType {

 public:
  // Enumerations for comparisons

  ItemType();
  
  int getValue() const;
  void initialize(int num);
  enum Comparison{GREATER,LESS,EQUAL};
  Comparison compareTo(ItemType item);
 private:
  int value;
};






#endif
