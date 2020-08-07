#include "EventManager.hpp"
#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"

#include <functional>
#include <map>

template <typename TEventType, typename THanlder>
void EventManager<TEventType, THandler>::subscribe(TEventType eventType, THandler handler)
{
    //add the handler int he handler map
    if (!m_handlers.contains(eventType))
    {
        m_handlers[eventType] = {};
    }

    m_handlers[eventType].push_back(handler);
}

template <typename TEventType, typename THanlder>
void EventManager<TEventType, THandler>::fire(TEventType eventType, EventPayload payload)
{
    for (auto& handler : m_handlers[eventType])
    {
        handler(payload);
    }
}