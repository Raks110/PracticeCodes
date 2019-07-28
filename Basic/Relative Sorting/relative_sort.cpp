#include <vector>
#include <iostream>
#include <algorithm>

/*

  This code is written and tested by Rakshit GL.
  © Rakshit GL 2019

*/

using namespace std;

class holder{

    private:
        char letter;
        int value;
        int index;

    public:
        holder(){}

        holder(char letter, int value){

            this->letter = letter;
            this->index = 0;
            this->value = value;
        }

        bool isValueTaken(){

            return this->value > 0;
        }

        void incrementIndex(){

            this->index++;
        }

        int getIndex(){

            return this->index;
        }

        void setValue(int value){

            this->value = value;
        }

        int getValue(){

            return this->value;
        }
};

class relative_sorter{

    private:
        vector<char> vector_to_sort;
        vector<char> main_vector;
        holder *indexed;

    public:
        relative_sorter(){}
        void init();
        void incrementAllGreater(int value);
        void relative_sort();
        void output();
};

void relative_sorter::init(){

    cout<<"Enter string to be sorted: ";

    while(cin.peek() != '\n'){

        char temp;
        cin>>temp;

        vector_to_sort.push_back(temp);
    }

    indexed = new holder[26];

    for(int i=0;i<26;i++){
        indexed[i] = holder('a' + i, 0);
    }

    cout<<"\nEnter main string: ";

    do{

        char temp;
        cin>>temp;

        main_vector.push_back(temp);

        if(!indexed[temp-'a'].isValueTaken()){

            indexed[temp-'a'].setValue(main_vector.size());
        }
    }while(cin.peek() != '\n');
}

void relative_sorter::incrementAllGreater(int value){

    for(int i=0;i<26;i++){

        if(indexed[i].getValue() > value){

            indexed[i].incrementIndex();
        }
    }
}

void relative_sorter::relative_sort(){

    vector<char> sorted;
    int lastIndex = 0;

    for(int i=0;i<vector_to_sort.size();i++){

        char considered = vector_to_sort[i];

        if(indexed[considered-'a'].isValueTaken()){

            lastIndex++;

            sorted.insert(sorted.begin() + indexed[considered-'a'].getIndex(), considered);
            incrementAllGreater(indexed[considered-'a'].getValue());
        }
        else{
            sorted.insert(sorted.begin() + lastIndex, considered);
        }
    }

    sort(sorted.begin() + lastIndex, sorted.end());
    vector_to_sort = sorted;
}

void relative_sorter::output(){

    cout<<"\nOutput: ";

    for(int i=0;i<vector_to_sort.size();i++)
        cout<<vector_to_sort[i];

    cout<<"\n";
}

int main(){

    relative_sorter r;
    r.init();
    r.relative_sort();
    r.output();
}
