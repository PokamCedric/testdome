/* ----Archive
A customer has complained that their archive application still occupies a big chunk of memory although they have removed all the records from it.

Fix the problem.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

class Archive
{
    class Record
    {
    public:
        Record(std::string title, std::string content)
        {
            this->title = title;
            this->content = content;
        }

        std::string title;
        std::string content;
    };


public:
    ~Archive()
    {
    }

    void add(int id, std::string title, std::string content)
    {
        records[id] = std::make_shared<Record>(title, content);
    }

    void remove(int id, std::string& title, std::string& content)
    {
        std::unordered_map<int, std::shared_ptr<Record>>::iterator it = records.find(id);

        std::shared_ptr<Record> doc = it->second;
        title = doc->title;
        content = doc->content;

        records.erase(it);
    }

    void clear()
    {
        records.clear();
    }

private:
    std::unordered_map<int, std::shared_ptr<Record>> records;
};

#ifndef RunTests
int main()
{
    Archive archive;
    archive.add(123456, "Hamlet", "Hamlet, Prince of Denmark.");
    archive.add(123457, "Othello", "Othello, the Moore of Venice.");

    std::string title, content;
    archive.remove(123456, title, content);

    std::cout << title << '\n';
    std::cout << content;

    archive.clear();
}
#endif