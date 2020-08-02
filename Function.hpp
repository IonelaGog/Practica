#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <memory>
#include <utility>

template <typename TSignature>
class Function;

template <typename TReturn, typename... TArgs>
class Function<TReturn(TArgs...)>
{
public:
    Function() = default;

    template <typename TCallable>
    Function(TCallable&& callable)
        : m_callable(std::make_unique<Callable<TCallable>>(std::forward<TCallable>(callable)))
    {
    }

    template <typename TCallable>
    Function& operator=(TCallable&& callable)
    {
        m_callable = std::make_unique<Callable<TCallable>>(std::forward<TCallable>(callable));
    }

    TReturn operator()(TArgs... args) { return m_callable->invoke(std::forward<TArgs>(args)...); }

private: // Types
    class ICallable
    {
    public:
        virtual TReturn invoke(TArgs... args) = 0;
        virtual ~ICallable(){};
    };

    template <typename TFunction>
    class Callable : public ICallable
    {
    public:
        Callable(const TFunction& function)
            : m_function(function)
        {
        }
        Callable(TFunction&& function)
            : m_function(std::move(function))
        {
        }

        TReturn invoke(TArgs... args) override { return m_function(std::forward<TArgs>(args)...); }

    private:
        TFunction m_function;
    };

private:
    std::unique_ptr<ICallable> m_callable;
};

#endif // FUNCTIONAL_HPP