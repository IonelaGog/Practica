#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <cstddef>
#include <functional>
#include <map>

#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"

class EventManager
{
  public:
    void subscribe(EventType type, THandler handler);
    void fire(EventType type, EventPayload payload);

  private:
    std::function<void(const EventPayload&)> THandler;
    map<EventType, Vector<THandler>> m_handlers;
};

#include "EventManager.tpp"

#endif //EVENTMANAGER_HPP