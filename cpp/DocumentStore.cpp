/*
The DocumentStore class is used to model a document store. It needs to satisfy the following conditions:

    The getDocuments() property should return the contents of the store.
    The addDocument(document) method should add a new document to the store. If the store is full, std::logic_error should be thrown.
    The getDescription() method should return the document store's description. If the document store is full, it should return "Document store is full"; otherwise, it should return a message in the format "Document store: number of documents/capacity". For example, if the capacity of the document store is two and one document is added, it should return: "Document store: 1/2".

Fix the bugs!
*/

#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>

class DocumentStore
{
public:
    DocumentStore(int cap)
    {
        capacity = cap;
    }

    int getCapacity() const
    {
        return capacity;
    }

    const std::vector<std::string>& getDocuments() const
    {
        return documents;
    }

    void addDocument(std::string document)
    {
        if (documents.size() < capacity){
            documents.push_back(document);
            std::cout << getCapacity()<< " size: " << documents.size() << std::endl;
        } else{
             throw std::logic_error("Overfilled");
        }


    }

    std::string getDescription()
    {
        if (capacity == documents.size())
            return "Document store is full";

        else
            return "Document store: " + std::to_string(documents.size()) +"/" +std::to_string(capacity);
        
    }


private:
    std::vector<std::string> documents;
    int capacity;
};

#ifndef RunTests
int main()
{
    DocumentStore documentStore(2);
    documentStore.addDocument("Item");
    std::cout << documentStore.getDescription();
}
#endif