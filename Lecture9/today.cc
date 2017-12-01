#include <iostream>

using std::cout;
using std::endl;

#include <algorithm>
using std::max;
using std::max_element;

#include <numeric>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

class Person {
  
private:
    
    int awesomeness;
    int height;
    
public:
    
    Person(const int a, const int h)
        : awesomeness(a), height(h) {}
    
    int getAwesomeness() const {
        return awesomeness;
    }
    
    int getHeight() const {
        return height;
    }
};

template<typename Itr, typename Data>
Itr find(Itr begin, Itr end, const Data & d) {
   while (begin != end) {
       if (*begin == d) {
            // ^_^
           return begin;
       }
       ++begin;
   }
   return end;
}

template<typename Itr, typename Matcher>
Itr find_if(Itr begin, Itr end, Matcher m) {
   while (begin != end) {
       if (m(*begin)) {
           return begin;
       }
       ++begin;
   }
   return end;
}

string combineWords(const vector<string> & someWords) {
 
    auto answer = std::accumulate(
                                  someWords.begin(),
                                  someWords.end(),
                                  string(),
                                  [](const string & soFar, const string & next) {
                                     if (soFar.empty()) {
                                         return next;
                                     } else {
                                         return soFar + " " + next;
                                     }
                                      
                                      
                                  });
 
    return answer;
}
        

int main() {

    Person a(100,60);
    Person b(90,70);

    auto ltByHeight = [](const Person & left,
                         const Person & right) {
                            return left.getHeight() < right.getHeight();
                        };
    
    Person tallest = max(a,b,ltByHeight);

    cout << "The tallest person has height " << tallest.getHeight() << "\n";
    
    
    vector<Person> people{a,b,Person(110,130)};
    
    auto tallestItr = max_element(people.begin(), people.end(),
                                  ltByHeight);
    
    cout << "The tallest person in the vector has height "
         << tallestItr->getHeight() << " and awesomeness "
         << tallestItr->getAwesomeness() << "\n";
         
    int totalHeight = std::accumulate(people.begin(),
                                      people.end(),
                                      0,
                                      [](const int x, const Person & p) {
                                          return x + p.getHeight();
                                      });
    
    cout << "In total they are " << totalHeight << " tall\n";
    
    vector<string> words{"Never", "Gonna", "Give", "You", "Up"};
    
    auto combined = combineWords(words);
    
    cout << combined << ", Never Gonna Let You Down\n";
    
    
    vector<int> numbers{1,2,3,4,5};
    vector<int> doubled(5);
    
    std::transform(numbers.begin(), numbers.end(),
                   doubled.begin(),
                   [](const int i) {
                       return i * 2;
                   });
    
    list<Person> roomForThree;
    
    std::transform(people.begin(),people.end(),
                   std::back_inserter(roomForThree),
                   [](const Person & p) {
                       return Person(p.getAwesomeness() + 10,
                                     p.getHeight());
                   });
};
