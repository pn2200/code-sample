#ifndef EventBus_hpp
#define EventBus_hpp

#include <algorithm>
#include <cassert>
#include <mutex>
#include <vector>
#include "docEvent.hpp"
#include "Observer.hpp"

// EventBus implementation
template <typename Event, typename ObserverType = Observer<Event>>
class EventBus
{
public:
    EventBus() {};

    void attach(ObserverType* observer)
    {
        assert(observer);

        std::lock_guard<std::mutex> lock(observer_mutex);
        observers.push_back(observer);
    };

    void detach(ObserverType* observer)
    {
        assert(observer);

        std::lock_guard<std::mutex> lock(observer_mutex);
        auto obs = std::find(observers.begin(), observers.end(), observer);
        if (obs != observers.end())
        {
            observers.erase(obs);
        }
    };

    void notify(Event e)
    {
        for (auto& obs : observers)
        {
            if (obs != nullptr)
            {
                obs->update(e);
            }
        }
    };

private:
    std::mutex observer_mutex;
    std::vector<ObserverType*> observers;
};

#endif /* EventBus_hpp */
