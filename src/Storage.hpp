#ifndef Storage_hpp
#define Storage_hpp
#include <string>
#include <vector>
#include "EventBus.hpp"
#include "docEvent.hpp"

class Storage : public EventBus<docEvent>
{
public:
    Storage() {};
    // Add filename to storage, and notify any listeners that a file has been added.
    void Add(const std::string& filename);

    // Remove filename from storage, and notify any listeners that a file has been removed.
    void Remove(const std::string& filename);

    friend std::ostream& operator<< (std::ostream& o, const Storage& s);

private:
    std::mutex filenames_mutex;
    std::vector<std::string> filenames;
};


#endif /* Storage_hpp */
