#include <iostream>
#include <sstream>


class HashTable{
    // Entry namespace limit
    public: 
    struct Entry
    {
        std::string Data;
        std::string currentStatus = "never used";
    };
        static const int NAMESIZE = 26;

    public:
        HashTable() = default;
        

        void Print(){
            for (int i = 0; i < NAMESIZE; ++i)
            {
                std::cout << "Name" << sizeOfEntries[i].Data << " - " << "Status: " << sizeOfEntries[i].currentStatus << std::endl;
            }
            
        }

    private:
        Entry sizeOfEntries[NAMESIZE];
};


int main(){
    // Input configuration

    std::string input;
    getline(std::cin, input);
    // Seperate each input string to the token
    std::stringstream ss(input);
    HashTable hTable;

    while(ss.good()){
        std::string token;
        // Token value will be the each string added via cin
        ss >> token;

        std::string initalName = token.substr(1); 
        if(token[0]== 'A'){ // A means Add
            
        } 
        else if(token[0] == 'D'){  // D means delete

        } 

        std::cout<< token << std::endl;

    }

    hTable.Print();
}