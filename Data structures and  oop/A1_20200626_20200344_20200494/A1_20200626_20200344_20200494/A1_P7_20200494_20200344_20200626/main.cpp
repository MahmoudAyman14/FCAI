#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


void BiasedSort (vector<string>& v , int n) {

  cout<<"----Untitled----"<<endl;

    for (int i = 0; i < n - 1; i++) {

       for (int j = n - 1; j > i; --j){

		        if (v [j] < v [j-1]){

                    swap (v [j], v [j - 1]);
		        }
       }

    }

       }

int main()
{

int n;
string MusicName;
vector<string> music;

cout<<"Enter your music numbers: "<<endl;

cin >> n;

cout<<"Enter their names :"<<endl;

for(int i=0 ; i<n ; i++){

        cin >>MusicName;
        music.push_back(MusicName);
}

cout<<" "<<endl<<"Loading.."<<endl;

cout<<" "<<endl;


    BiasedSort(music,music.size());



  for (int i = 0; i < music.size(); i++)
        cout << music[i] <<endl;







     return 0;
}
