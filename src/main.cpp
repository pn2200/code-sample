#include <iostream>
#include <string>
#include <vector>
#include "Cmd.hpp"
#include "Storage.hpp"
#include "Indexer.hpp"
#include "Index.hpp"

int main(int argc, const char * argv[])
{
    // add a.txt
    // query Hello
    // remove a.txt
    // quit
    // default
    Cmd cliProcessor;

    while (cliProcessor.IsRunning())
    {
        std::string commandLine;
        std::getline(std::cin, commandLine);

        // Split command line
        std::string command;
        std::string target;
        auto pos = commandLine.find(" ");
        if (pos != std::string::npos)
        {
            command = commandLine.substr(0, pos);
            target = commandLine.substr(pos + 1, commandLine.size());
            if (command == "add")
            {
                cliProcessor.Add(target);
            }
            else if (command == "remove")
            {
                cliProcessor.Remove(target);
            }
            else if (command == "query")
            {
                std::vector<std::string> documents;
                if (cliProcessor.Query(target, documents))
                {
                    for (const auto& d : documents)
                    {
                        std::cout << d << std::endl;
                    }
                }
                else
                {
                    std::cout << "No documents found" << std::endl;
                }
            }
        }
        else if (commandLine == "quit")
        {
            cliProcessor.Quit();
        }
        else if (commandLine.empty())
        {
            // Continue if command line is empty
        }
        else
        {
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}
