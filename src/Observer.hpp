#ifndef Observer_hpp
#define Observer_hpp

// Interface for Observer pattern.
template <typename Event>
class Observer
{
public:
    Observer() {};
    virtual void update(Event e) = 0;
};
#endif /* Observer_hpp */
