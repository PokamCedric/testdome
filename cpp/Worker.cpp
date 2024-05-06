/*
After client complaints, it is observed that the memory usage of the Worker component constantly increases, even if the memory is supposedly released by the Worker.

Fix the issue without changing the public API of TaskResource and Worker.
*/

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>


class TaskResource
{
public:
    TaskResource(int id)
    {
        this->id = id;
    }

    void doTask(std::string task)
    {
        taskVector.push_back(task);
    }

    size_t countTasks() const
    {
        return taskVector.size();
    }

    std::string getTask(int index) const
    {
        return taskVector.at(index);
    }

private:
    std::vector<std::string> taskVector;
    int id;
};

class Worker
{
public:
    ~Worker()
    {
        for (std::unordered_map<int, TaskResource*>::iterator it = resourceMap.begin(); it != resourceMap.end(); ++it)
            delete it->second;
    }

    TaskResource* acquireTaskResource(int id)
    {
        std::unordered_map<int, TaskResource*>::iterator search = resourceMap.find(id);
        if (search == resourceMap.end())
        {
            TaskResource* taskResource = new TaskResource(id);
            std::pair<int, TaskResource*> keyValue(id, taskResource);
            resourceMap.insert(keyValue);
            return taskResource;
        }
        else
        {
            return search->second;
        }
    }

    void releaseTaskResource(int id)
    {
        std::unordered_map<int, TaskResource*>::iterator it = resourceMap.find(id);
        delete it->second;
        resourceMap.erase(id);
    }

private:
    std::unordered_map<int, TaskResource*> resourceMap;
};

#ifndef RunTests
void printTaskResource(const TaskResource& taskResource)
{
    for (size_t i = 0; i < taskResource.countTasks(); i++)
    {
        if (i != 0)
        {
            std::cout << ", ";
        }

        std::cout << taskResource.getTask(i);
    }
    std::cout << '\n';
}

int main()
{
    Worker d;

    d.acquireTaskResource(1)->doTask("Task11");
    d.acquireTaskResource(2)->doTask("Task21");
    printTaskResource(*d.acquireTaskResource(2));
    d.releaseTaskResource(2);

    d.acquireTaskResource(1)->doTask("Task12");
    printTaskResource(*d.acquireTaskResource(1));
    d.releaseTaskResource(1);
}
#endif