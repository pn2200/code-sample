#ifndef Cmd_hpp
#define Cmd_hpp

#include <vector>
#include <string>
#include "Storage.hpp"
#include "Index.hpp"
#include "Indexer.hpp"

// Respond to command line instructions.
class Cmd
{
public:
    Cmd();
    ~Cmd();

    // End program.
    void Quit();
    // Add file named filename to storage.
    bool Add(const std::string& filename);
    // Remove file named filename.
    void Remove(const std::string& filename);
    // Query all documents for word, returning filenames containing word in documents.
    bool Query(const std::string& word, std::vector<std::string>& documents);

    bool IsRunning();
private:
    bool running;
    Storage* fileStore;
    Indexer* indexer;
    Index* index;
};

#endif /* Cmd_hpp */
