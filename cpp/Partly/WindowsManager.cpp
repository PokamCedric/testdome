#include <iostream>
#include <string> // https://app.testdome.com/files/resources/12362/d1b04a55-3797-44ab-8489-28f20b1fc0b2.png
#include <list>
#include <algorithm>

class WindowManager
{
public:
    void open(const std::string windowName)
    {
        std::list<std::string>::iterator search = std::find(windows.begin(), windows.end(), windowName);

        if(search == windows.end())
            windows.push_back(windowName);
    }

    void close(const std::string windowName)
    {
        windows.remove(windowName);
    }

    std::string getTopWindow()
    {
        return windows.back();
    }

private:
    std::list<std::string> windows;
};

#ifndef RunTests
int main()
{
    WindowManager wm;
    wm.open("Calculator");
    wm.open("Browser");
    wm.open("Player");
    wm.close("Browser");
    std::cout << wm.getTopWindow();
}
#endif