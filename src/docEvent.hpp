#ifndef docAddedEvent_h
#define docAddedEvent_h

#include <list>
#include <string>

enum class eventType
{
    Added,
    Removed,
    Indexed
};

class docEvent
{
public:
    docEvent(const std::string& filename_, eventType t_, std::list<std::string> words_ = std::list<std::string>()) :
    filename(filename_),
    t(t_),
    words(words_)
    { }

    std::string filename;
    eventType t;
    std::list<std::string> words;
};

#endif /* docAddedEvent_h */
