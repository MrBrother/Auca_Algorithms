#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){

  unordered_set<string> names;

  auto hf = names.hash_function();

  string line;
  while(getline(cin, line)){
    istringstream sinp(line);

    string cmd; sinp >> cmd;
    if(cmd == "#"){
      cout << "Number of Buckets: " << names.bucket_count() << endl;
      for(size_t i = 0; i < names.bucket_count(); i++){
        cout << setw(4) << i << ": ";
        for(auto it = numbers.begin(i); it!=numbers.end(i);it++){
          cout << *it << " ";
        }
        cout << endl;
      }
    }else if(cmf == "+"){

    }else if(cmf == "-"){

    }else if(cmf == "?"){

    }

  }

  return 0;
}
