//
// FILE:        Observable.h
// LICENSE:     The MIT license
// PURPOUSE:    Base class for observable objects.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "FastDelegate.h"
#include <set>

namespace Engine
{
    template<typename... Params>
    class Observable
    {
    public:
        typedef FastDelegate<void (Params...)> Delegate;

    public:
        Observable () : mChanged(false) {}

        void addObserver ( const Delegate& del )
        {
            mDelegates.insert ( del );
        }
        void removeObserver ( const Delegate& del )
        {
            mDelegates.erase ( del );
        }

    protected:
        void notifyObservers ( Params... p )
        {
            if ( mChanged )
            {
                for ( auto& del : mDelegates )
                    del ( p... );
                mChanged = false;
            }
        }
        void setChanged ( const bool changed )
        {
            mChanged = changed;
        }

    private:
        std::set<Delegate>  mDelegates;
        bool                mChanged;
    };
}
