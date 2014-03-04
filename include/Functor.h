#ifndef FUNCTOR_H
#define FUNCTOR_H


class BasicFunctor {
public:
    virtual void notify(/* can be an Event object as an argument */) = 0;
};

template <class T> 
class Functor : public BasicFunctor {
  private:
    void (T::*callback)();   // pointer to member function
    T* observer;             // pointer to object

  public:
    Functor(T *_observer, void(T::*_callback)())
    { 
        observer = _observer;  callback = _callback; 
    };

    virtual void notify()
    { 
        (*observer.*callback)();
    };
};


#endif // FUNCTOR_H
