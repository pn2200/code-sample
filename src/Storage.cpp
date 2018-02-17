#include "Storage.hpp"

void Storage::Add(const std::string& filename)
{
    {
        std::lock_guard<std::mutex> lock(filenames_mutex);
        filenames.push_back(filename);
    }
    docEvent e(filename, eventType::Added);
    notify(e);
}


void Storage::Remove(const std::string& filename)
{
    bool removed = false;
    {
        std::lock_guard<std::mutex> lock(filenames_mutex);
        auto f = std::find(filenames.begin(), filenames.end(), filename);
        if (f != filenames.end())
        {
            filenames.erase(f);
            removed = true;
        }
    }

    if (removed)
    {
        docEvent e(filename, eventType::Removed);
        notify(e);
    }
}


// For debugging
std::ostream& operator<< (std::ostream& o, const Storage& s)
{
    for (const auto& f : s.filenames)
    {
        o << f;
    }
    return o;
}
