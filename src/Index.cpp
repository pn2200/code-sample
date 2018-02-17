#include <cassert>
#include "Index.hpp"

Index::Index(Storage* fileStore, Indexer* indexer)
{
    assert(fileStore);
    assert(indexer);

    fileStore->attach(this);
    indexer->attach(this);
}

void Index::update(docEvent e)
{
    // Remove file and words.
    if (e.t == eventType::Removed)
    {
        std::lock_guard<std::mutex> lock(index_mutex);
        if (index.find(e.filename) != index.end())
        {
            index.erase(e.filename);
        }
    }
    // Add new words and files to index.
    else if (e.t == eventType::Indexed)
    {
        std::lock_guard<std::mutex> lock(index_mutex);
        if (index.find(e.filename) == index.end())
        {
            index.emplace(e.filename, std::set<std::string>(e.words.begin(), e.words.end()));
        }
    }
}


std::vector<std::string> Index::Query(const std::string& word)
{
    std::vector<std::string> filenames;
    std::lock_guard<std::mutex> lock(index_mutex);
    for (const auto& f : index)
    {
        if (f.second.find(word) != f.second.end())
        {
            filenames.push_back(f.first);
        }
    }

    return filenames;
}
