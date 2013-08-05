//
// FILE:        Tween.h
// LICENSE:     The MIT license
// PURPOUSE:    Interpolate between values.
// AUTHORS:     Alberto Alonso <rydencillo@gmail.com>
//

#pragma once

#include "FastDelegate.h"
#include <functional>

namespace Engine
{
    enum TweenType
    {
        LINEAR,
    };

    template <class T>
    class Tween final
    {
        typedef FastDelegate<void (const T&)> DelegateType;
        typedef FastDelegate<void (void)> FinalizationHandler;

    public:
        Tween ()
        {
        }

        Tween ( TweenType type, const T& initialValue, const T& targetValue, int time, const DelegateType& del )
        {
            create ( type, initialValue, targetValue, time, del );
        }

        Tween ( TweenType type, const T& initialValue, const T& targetValue, int time, const typename DelegateType::LambdaType& lambda )
        {
            create ( type, initialValue, targetValue, time, DelegateType(lambda) );
        }

        ~Tween ()
        {
        }

        void create ( TweenType type, const T& initialValue, const T& targetValue, int time, const typename DelegateType::LambdaType& lambda )
        {
            return create ( type, initialValue, targetValue, time, DelegateType(lambda) );
        }

        void create ( TweenType type, const T& initialValue, const T& targetValue, int time, const DelegateType& del )
        {
            mInitialValue = initialValue;
            mTargetValue = targetValue;
            mTime = time;
            mElapsed = 0;
            mDelegate = del;
            mFinalizationHandler.clear();
            mFinished = false;

            switch ( type )
            {
                default:
                case LINEAR:
                    mFunction = [] ( float v ) { return v; };
                    break;
            }
        }

        void update ( int deltaTime )
        {
            if ( !mFinished )
            {
                mElapsed += deltaTime;
                float t = clamp(0.0f, (float)mElapsed / mTime, 1.0f);
                mDelegate(lerp(mInitialValue, mTargetValue, mFunction(t)));
                if ( t == 1.0f )
                {
                    mFinished = true;
                    if ( mFinalizationHandler )
                        mFinalizationHandler ();
                }
            }
        }

        void setFinalizationHandler ( const FinalizationHandler& handler )
        {
            mFinalizationHandler = handler;
        }

        void setFinalizationHandler ( const typename FinalizationHandler::LambdaType& lambda )
        {
            setFinalizationHandler ( FinalizationHandler(lambda) );
        }

        bool hasFinished () const
        {
            return mFinished;
        }

    private:
        T                   mInitialValue;
        T                   mTargetValue;
        T*                  mValuePointer;
        int                 mElapsed;
        int                 mTime;
        DelegateType        mDelegate;
        FinalizationHandler mFinalizationHandler;
        std::function<float (float)> mFunction;
        bool                mFinished;
    };
}
