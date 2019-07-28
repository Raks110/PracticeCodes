#include <iostream>
#include <vector>

/*

  This code is written and tested by Rakshit GL.
  © Rakshit GL 2019

*/

using namespace std;

class subset{

    private:
        vector<int> vec;
        int reqSum;

    public:
        subset(){};
        void init();
        void findSum();
};

void subset::init(){

    cout<<"Start entering the set: enter -1 to stop entering.\n";

    while(1){

        int temp;
        cin>>temp;

        if(temp == -1)
            break;

        vec.push_back(temp);
    }

    cout<<"\nThe sum you are looking for is?\n";

    int temp;
    cin>>temp;

    reqSum = temp;
}

void subset::findSum(){

    int currSum = 0;

    for(int i=0;i<vec.size();i++){

        currSum = vec[i];

        for(int j=i+1;j<vec.size();j++){

            currSum += vec[j];
            if(currSum > reqSum){

                break;
            }
            else if(currSum == reqSum){

                cout<<"The subset that adds up to "<<reqSum<<" is: ";

                for(int k=i;k<=j;k++){

                    cout<<vec[k]<<" ";
                }

                cout<<"\n\n";
                return;
            }
        }
    }
}

int main(){

    subset s;
    s.init();
    s.findSum();
}
