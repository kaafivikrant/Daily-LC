#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <stack>
#define ll long long
#define dd double
#include <stack>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

int main(){

    /*  https://leetcode.com/discuss/interview-question/988051/Microsoft-or-OA  */

    /*
        https://leetcode.com/problems/fizz-buzz/
     */
    int n = 6;
    vector<string> finalFB;
    for(int i=1;i<=n;i++){
        if(i % 3 == 0 && i % 5 == 0){
            finalFB.emplace_back("FizzBuzz");
        }else if(i % 3 == 0){
            finalFB.emplace_back("Fizz");
        }else if(i % 5 == 0){
            finalFB.emplace_back("Buzz");
        }else{
            string d = to_string(i);
            finalFB.push_back(d);
        }
    }
    for(const auto& k: finalFB){
        cout<<k<<" ";
    }

    /*
        Given a string S with both lowercase and uppercase letters, return the biggest (sorted alphabetically) letter that appears both in lowercase and uppercase. The returned letter must be in uppercase. If there is no such letter, return 'NO'.
        Examples:
        'aaacbAbCd', return 'C'
        'aA', return 'A'
        'abcdE', return 'NO'
        'a', return 'NO'
     */

    map<pair<char,char>,bool> final;
    string temp = "abcdE";

    for(int i =0; i< temp.size() ; i++){
        char x = temp[i];
        char y = x-32;
        bool possible;
        for(string::iterator it=temp.begin(); it!=temp.end(); ++it){
            if(*it == y){
                possible = true;
                auto rep = make_pair(x,y);
                final.insert({rep,possible});
            }
        }
    }

    char max = 'A';
    for(auto d: final){
        if(d.first.second > max){
            max = d.first.second;
        }
    }

    final.empty()?cout<<"No":cout<<max;

    /*
        Maximum possible value by inserting '5'
        Examples:
        input: 1234 -> output: 51234
        input: 7643 -> output 76543
        input: 0 -> output 50
        input: -661 -> output -5661

        Location: Seattle
        Position: Software Eng
     */

    int insertingValue = 5;
    int current = 7643;
    int maximum = INT16_MIN;

    //int sizeofCurrent = floor(log10(current)+1); it will not work for negative digits

    int sizeofCurrent = to_string(current).size();
    string tempstr = to_string(current);

    vector<int> findingMax;

    for(int i= 0;i<= sizeofCurrent; i++){
        //tempstr.erase(tempstr.begin(),tempstr.end()-sizeofCurrent+i);
        //cout<<tempstr<<endl;

        //cout<<tempstr.substr(0,i)<<" "<<tempstr.substr(i,sizeofCurrent)<<endl;

        /*
         * 1234
         * 234
         * 34
         * 4
         * */
        string temps = tempstr.substr(0,i)+"5"+tempstr.substr(i,sizeofCurrent);
        int tempint = stoi(temps);
        findingMax.push_back(tempint);
    }

    cout<<*max_element(findingMax.begin(),findingMax.end());

    return 0;
}