#ifndef Indexer_hpp
#define Indexer_hpp

#include <atomic>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include "EventBus.hpp"
#include "Storage.hpp"

class Indexer : public EventBus<docEvent>, public Observer<docEvent>
{
public:
    Indexer(Storage* fileStore_);
    // Update collection of files to be indexed, on Added event.
    void update(docEvent e);

private:
    std::mutex filenames_mutex;
    std::queue<std::string> filenames;
    Storage* fileStore;

    // Index any files and notify any listeners when indexing is complete
    void Read();
};

#endif /* Indexer_hpp */
