#include <iostream>
#include <sstream>


class HashTable{
    // Entry namespace limit
    public: 
    static const int NAMESIZE = 26;

    struct Entry
    {
        std::string Data;
        std::string currentStatus = "never used";
    };
    

    public:
        HashTable() = default;

        void Add(const std::string& name){
            bool isExist = FindString(name);

            if(isExist == true) return;    
            
            int insertIndex = getInsertedStringIndex(name);
            sizeOfEntries[insertIndex].Data = name;
            sizeOfEntries[insertIndex].currentStatus = "occupied";
        }
        void Delete(const std::string& name){
            
        }
        void Print(){
            for (int i = 0; i < NAMESIZE; ++i)
            {
                std::cout << "Name" << sizeOfEntries[i].Data << " - " << "Status: " << sizeOfEntries[i].currentStatus << std::endl;
            }
        }

    private:
    //Hash function to find the index
    int getHashIndex(const std::string& name){
       //last character of name string
       return name.back() - 'a'; // Moving the ascii char
    }   

    bool FindString(const std::string& name){
        int hashIndex = getHashIndex(name);

        while(true){

            if(sizeOfEntries[hashIndex].Data == name){ // Found the index and data is the same 
                return true;
            }
            if(sizeOfEntries[hashIndex].currentStatus == "never used"){
                   return false; 

            }     
             hashIndex =(hashIndex + 1) % NAMESIZE; // Pass to the next one 
        }

        return false;
    }

    int getInsertedStringIndex(const std::string name){
        int hashIndex = getHashIndex(name);

        while(true){
            if(sizeOfEntries[hashIndex].currentStatus == "never used" || sizeOfEntries[hashIndex].currentStatus == "tombstone"){
                return hashIndex;
            }
            hashIndex = (hashIndex + 1) % NAMESIZE;
        }

        return -1;
    }
    
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
            hTable.Add(initalName);
        } 
        else if(token[0] == 'D'){  // D means delete
            hTable.Delete(initalName);
        } 

        std::cout<< token << std::endl;

    }

    hTable.Print();
}