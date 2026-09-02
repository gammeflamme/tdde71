#include <iostream>
#include <vector>

// What do you have to change if you omit "using namespace std;" ?
using namespace std;

int main()
{
  // A vector may store any datatype (vector<double>, vector<string>, ...)
  vector<int> v{9,8,7,6,5,4,3,2,1};

  // Why do we use "unsigned int" instead of "int" ?
  for (unsigned int i{}; i < v.size() - 1; ++i)
  {
    for (unsigned int j{}; j < v.size() - i - 1; ++j)
    {
      if (v.at(j) > v.at(j + 1))
      {
        // Swap will exchange the given values. How would you implement it?
        // (A standard implementation exist that will just work.)
        swap(v.at(j), v.at(j + 1));
      }
    }
  }

  for (unsigned int i{}; i < v.size(); ++i)
  {
    // What is the difference between "v.at(i)" and "v[i]" ?
    cout << v[i] << " ";
  }
  cout << endl;
  
  return 0;
}
