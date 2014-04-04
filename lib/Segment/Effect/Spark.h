/*
 * Spark.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef SPARK_H_
#define SPARK_H_

#include "Generic.h"

class Effect_Spark: public Effect_Generic {
        /* properties */
    protected:
        unsigned int position;
        CRGB         last_color;

        /* methods */
    public:
        Effect_Spark(T_EffectConfig config);
    protected:
        void _preStep();
        void _postStep();
};

#endif /* SPARK_H_ */
