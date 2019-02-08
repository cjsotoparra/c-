#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
  std::vector<int> foo = {-5,89,75,110,67, 97};
  std::vector<int> bar (foo.size());

  // copy only numbers 0-100:
  auto it = std::copy_if (foo.begin(), foo.end(), bar.begin(), [](int i){return (i>0 and i < 100);} );
  bar.resize(std::distance(bar.begin(),it));  // shrink container to new size

  std::cout << "bar contains:";
  for (int& x: bar) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
