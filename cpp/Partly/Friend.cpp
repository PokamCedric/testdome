/*
Given a data structure representing a social network, implement method canBeConnected on class Friend.

The method should check if a connection to the given member exists, efficiently with respect to time used. That should be either a direct friendship or a chain of members between them who are mutual friends.

For example, if A and B are friends and B and C are friends, then A.canBeConnected(C) should return true, since C is a friend of B and B is a friend of A.
*/

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

class Friend
{
public:
    std::vector<Friend*> friends;

    Friend(std::string email)
    {
        this->email = email;
    }
    std::string getEmail() const {
        return email;
    }
    
    void addFriendship(Friend* target)
    {
        friends.push_back(target);
        target->friends.push_back(this);
    }
    
    bool canBeConnected(Friend* target)
    {
        bool canConnected = false;
        for(auto myFriend : this->friends){

            for(auto aFriend : target->friends){

                if(myFriend->getEmail() == aFriend->getEmail()){
                    canConnected = true;
                }
            }
        }
        return canConnected;
    }

private:
    std::string email;
};

#ifndef RunTests
int main()
{
    Friend a("A");
    Friend b("B");
    Friend c("C");
    
    a.addFriendship(&b);
    b.addFriendship(&c);
    
    std::cout << std::boolalpha << a.canBeConnected(&c);
}
#endif


####------ unordered_map

#include <unordered_map>
#include <string>
#include <stdexcept>
#include <iostream>

class Friend
{
public:

    Friend(std::string email)
    {
        this->email = email;
    }
    std::string getEmail() const {
        return email;
    }

    std::unordered_map<std::string, Friend*> friends;


    void addFriendship(Friend* target)
    {
        std::unordered_map<std::string, Friend*>::iterator search = friends.find(target->getEmail());
        if (search == friends.end())
        {
            std::pair<std::string, Friend*> keyValue(target->getEmail(), target);
            friends.insert(keyValue);
            std::pair<std::string, Friend*> keyValue2(this->getEmail(), this);
            target->friends.insert(keyValue2);
        }

    }

    bool searchConnection(Friend* target, Friend* source)
    {
        bool canConnected = false;
        if (target == nullptr)
            return false;

        for (std::unordered_map<std::string, Friend*>::iterator it = target->friends.begin(); it != target->friends.end(); it++) {
            std::unordered_map<std::string, Friend*>::iterator search = it->second->friends.find(this->getEmail());

            if (search == it->second->friends.end()) {
                if (it->second->getEmail() != source->getEmail()) {
                    canConnected = this->searchConnection(it->second, target);
                }
            }
            else {
                canConnected = true;
                break;
            }
        }

        return canConnected;
    }

    bool canBeConnected(Friend* target)
    {
        return searchConnection(target, this);
    }

private:
    std::string email;

};

#ifndef RunTests
int main()
{
    Friend a("A");
    Friend b("B");
    Friend c("C");
    Friend d("D");
    Friend e("E");
    Friend f("F");

    a.addFriendship(&b);
    b.addFriendship(&c);
    c.addFriendship(&d);
    e.addFriendship(&f);

    std::cout << std::boolalpha << a.canBeConnected(&f);
}
#endif
####---- unordered_set

#include <vector>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include <iostream>

class Friend
{
public:

    std::unordered_set<std::string> friends;
    Friend(std::string email)
    {
        this->email = email;
    }
    std::string getEmail() const {
        return email;
    }



    void addFriendship(Friend* target)
    {
        std::unordered_set<std::string>::iterator search = friends.find(target->getEmail());
        if (search == friends.end())
        {
            friends.insert(target->getEmail());
            target->friends.insert(this->getEmail());
        }

    }

    bool canBeConnected(Friend* target)
    {
        bool canConnected = false;
        for (std::unordered_set<std::string>::iterator it = target->friends.begin(); it != target->friends.end(); it++) {
            std::unordered_set<std::string>::iterator search = friends.find(*it);
            if (search == friends.end()) {
                //Do nothing
            }
            else {
                canConnected = true;
                break;
            }
        }

        return canConnected;
    }

private:
    std::string email;

};

#ifndef RunTests
int main()
{
    Friend a("A");
    Friend b("B");
    Friend c("C");

    a.addFriendship(&b);
    b.addFriendship(&c);

    std::cout << std::boolalpha << a.canBeConnected(&c);
}
#endif