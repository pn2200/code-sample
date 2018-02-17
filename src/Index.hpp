#ifndef Index_hpp
#define Index_hpp

#include "EventBus.hpp"
#include "Indexer.hpp"
#include "Observer.hpp"
#include "Storage.hpp"
#include "docEvent.hpp"
#include <map>
#include <mutex>
#include <set>
#include <string>
#include <vector>


class Index : public EventBus<docEvent>, public Observer<docEvent>
{
public:
    Index() {};
    Index(Storage* fileStore, Indexer* indexer);
    // Return collection of filenames that contain word.
    std::vector<std::string> Query(const std::string& word);
    // Update index on Indexed event, remove words and file from index on Removed event.
    void update(docEvent e);

private:
    std::mutex index_mutex;
    std::map<std::string, std::set<std::string>> index;
};
#endif /* Index_hpp */
