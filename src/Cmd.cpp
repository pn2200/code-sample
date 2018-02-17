#include <fstream>
#include <iostream>
#include <vector>
#include "Cmd.hpp"


Cmd::Cmd() :
    running(true)
{
    fileStore = new Storage();
    indexer = new Indexer(fileStore);
    index = new Index(fileStore, indexer);
}

Cmd::~Cmd()
{
    delete index;
    index = nullptr;
    delete indexer;
    indexer = nullptr;
    delete fileStore;
    fileStore = nullptr;
}

void Cmd::Quit()
{
    running = false;
}

bool Cmd::Add(const std::string& filename)
{
    std::ifstream f(filename);
    if (f.is_open())
    {
        fileStore->Add(filename);
        std::cout << "File added successfully" << std::endl;
        return true;
    }
    else
    {
        std::cout << "File not found" << std::endl;
        return false;
    }
}

void Cmd::Remove(const std::string& filename)
{
    fileStore->Remove(filename);
    std::cout << "File removed successfully" << std::endl;
}

bool Cmd::Query(const std::string &word, std::vector<std::string> &documents)
{
    documents = index->Query(word);

    return !documents.empty();
}

bool Cmd::IsRunning()
{
    return running;
}
