#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <cstddef>
#include <functional>
#include <map>

#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"

template <typename TEventType, typename THandler>
class EventManager
{
  public:
    void subscribe(TEventType type, THandler handler);
    void fire(TEventType type, EventPayload payload);

  private:
    std::function<void(const EventPayload&)> THandler;
    std::map<TEventType, Vector<THandler>> m_handlers;
};

#include "EventManager.tpp"

#endif //EVENTMANAGER_HPP