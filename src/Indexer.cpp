#include <cassert>
#include <chrono>
#include <fstream>
#include <thread>
#include "docEvent.hpp"
#include "Indexer.hpp"
#include "stringutility.hpp"


Indexer::Indexer(Storage* fileStore_) :
    fileStore(fileStore_)
{
    assert(fileStore_);
    fileStore->attach(this);
}


// If there are any files, read the file, split out each word.
// Notify all listeners of Indexed event, mapping filename to words in file.
void Indexer::Read()
{
    std::lock_guard<std::mutex> lock(filenames_mutex);
    if (!filenames.empty())
    {
        auto filename = filenames.front();
        filenames.pop();
        std::vector<std::string> words;
        std::ifstream f(filename);
        std::string line;

        while (std::getline(f, line))
        {
            // Split the line into words and store somehow
            split(line, ' ', words);
        }

        docEvent e(filename, eventType::Indexed, std::list<std::string>(words.begin(), words.end()));
        notify(e);
    }
}


void Indexer::update(docEvent e)
{
    if (e.t == eventType::Added)
    {
        std::lock_guard<std::mutex> lock(filenames_mutex);
        filenames.push(e.filename);
    }

    auto indexerThread = std::thread(&Indexer::Read, this);
    indexerThread.join();
}

