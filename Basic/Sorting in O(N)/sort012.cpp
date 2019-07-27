#include <iostream>
#include <vector>

/*

  This code is written and tested by Rakshit GL.
  © Rakshit GL 2019

*/

using namespace std;

class sort_in_n{

    private:
        vector<int> vector_to_sort;
        int index_for_one;

    public:
        sort_in_n(){}
        void initialize_vector();
        void sort_vector();
        void output_vector();
};

//Takes the vector as input from user until -1 pressed.

void sort_in_n::initialize_vector(){

    while(1){

        int temp;
        cin>>temp;

        if(temp == -1)
            break;

        else
            vector_to_sort.push_back(temp);
    }

    index_for_one = 0;
}

//Sorts vector in O(n)

void sort_in_n::sort_vector(){

    vector<int> sorted_vector;

    for(int i=0;i<vector_to_sort.size();i++){

        if(vector_to_sort[i] == 0){
            sorted_vector.insert(sorted_vector.begin(),0);
            index_for_one++;
        }
        else if(vector_to_sort[i] == 1){
            sorted_vector.insert(sorted_vector.begin() + index_for_one, 1);
        }
        else if(vector_to_sort[i] == 2){
            sorted_vector.push_back(2);
        }
    }

    vector_to_sort = sorted_vector;
}

//Outputs sorted vector

void sort_in_n::output_vector(){

    for(int i=0;i<vector_to_sort.size();i++){

        cout<<vector_to_sort[i]<<" ";
    }
}

int main(){

    sort_in_n sorting;
    sorting.initialize_vector();
    sorting.sort_vector();
    sorting.output_vector();
}
