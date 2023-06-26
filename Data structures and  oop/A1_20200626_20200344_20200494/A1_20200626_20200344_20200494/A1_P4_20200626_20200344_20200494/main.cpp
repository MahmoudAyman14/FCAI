#include <iostream>
#include <set>
using namespace std;


void RecPermute(string soFar, string rest)
{

set <string> unique_arr;

if (rest == "") // No more characters
cout << soFar << endl; // Print the word
else // Still more chars
// For each remaining char
for (int i = 0; i < rest.length(); i++) {
string next = soFar + rest[i]; // Glue next char
string remaining = rest.substr(0, i)+ rest.substr(i+1);

int num;
num = unique_arr.size();
unique_arr.insert(next);
if(unique_arr.size() > num)
    RecPermute(next, remaining);

}

}
// "wrapper" function
void ListPermutations(string s) {
RecPermute("", s);
}



int main()
{
    //RecPermute ("walid","say");
    ListPermutations("aal");
    return 0;
}
