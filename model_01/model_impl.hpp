// In this header file, define your model!
// This includes functions to describe each reaction.
// Make sure that you've first completed reaction_list.h and specie_list.h
#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H
#include "core/reaction.hpp"
#include "core/specie.hpp"
#include "core/model.hpp"
#include "sim/base.hpp"
//#include "context.hpp"
#include <cstddef>

/*

Define all of your reaction rate functions in `model_impl.hpp`.
For example, if you enumerated a reaction `R_ONE`, you should declare a
   function like this:

 RATETYPE reaction<R_ONE>::active_rate(const Ctxt& c) { return 6.0; }


Or, for a more interesting reaction rate, you might do something like:


 RATETYPE reaction<R_TWO>::active_rate(const Ctxt& c) {
   return c.getRate(R_TWO) * c.getCon(SPECIE_ONE) * c.neighbors.calculateNeighborAvg(SPECIE_TWO);
 }

Refer to the Context API (Section ) for instructions on how to get delays
   and critical values for more complex reaction rate functions.

*/

template<>
template<class Ctxt>
RATETYPE reaction<M12_3_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M12_3_ASSOCIATION) * c.getCon(ONE) * c.getCon(TWO);
}


template<>
template<class Ctxt>
RATETYPE reaction<M31_24_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M31_24_ASSOCIATION) * c.getCon(THREE) * c.getCon(ONE);
}

template<>
template<class Ctxt>
RATETYPE reaction<M24_15_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M24_15_ASSOCIATION) * c.getCon(TWO) * c.getCon(FOUR);
}

template<>
template<class Ctxt>
RATETYPE reaction<M65_28_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M65_28_ASSOCIATION) * c.getCon(SIX) * c.getCon(FIVE);
}

template<>
template<class Ctxt>
RATETYPE reaction<M23_7_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M23_7_ASSOCIATION) * c.getCon(TWO) * c.getCon(THREE);
}

template<>
template<class Ctxt>
RATETYPE reaction<M7_3_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M7_3_ASSOCIATION) * c.getCon(SEVEN) * c.getCon(THREE);
}

template<>
template<class Ctxt>
RATETYPE reaction<M89_1011_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M89_1011_ASSOCIATION) * c.getCon(EIGHT) * c.getCon(NINE);
}

template<>
template<class Ctxt>
RATETYPE reaction<M1012_13_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M1012_13_ASSOCIATION) * c.getCon(TEN) * c.getCon(TWELVE);
}

template<>
template<class Ctxt>
RATETYPE reaction<M137_12_ASSOCIATION>::active_rate(const Ctxt& c) {
    return c.getRate(M137_12_ASSOCIATION) * c.getCon(THIRTEEN) * c.getCon(SEVEN);
}

template<>
template<class Ctxt>
RATETYPE reaction<ONE_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(ONE_SYNTHESIS) * (c.getCritVal(rcrit_ONE) - c.getCon(ONE));
}

template<>
template<class Ctxt>
RATETYPE reaction<TWO_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(TWO_SYNTHESIS) * c.getCon(ONE);
}

template<>
template<class Ctxt>
RATETYPE reaction<THREE_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(THREE_SYNTHESIS) * c.getCon(TWO);
}

template<>
template<class Ctxt>
RATETYPE reaction<FOUR_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(FOUR_SYNTHESIS) * c.getCon(THREE);
}

template<>
template<class Ctxt>
RATETYPE reaction<FIVE_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(FIVE_SYNTHESIS) * c.getCon(FOUR);
}

template<>
template<class Ctxt>
RATETYPE reaction<SIX_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(SIX_SYNTHESIS) * c.getCon(FIVE);
}

template<>
template<class Ctxt>
RATETYPE reaction<SEVEN_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(SEVEN_SYNTHESIS) * c.getCon(SIX);
}

template<>
template<class Ctxt>
RATETYPE reaction<EIGHT_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(EIGHT_SYNTHESIS) * c.getCon(SEVEN);
}

template<>
template<class Ctxt>
RATETYPE reaction<NINE_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(NINE_SYNTHESIS) * c.getCon(EIGHT);
}

template<>
template<class Ctxt>
RATETYPE reaction<TEN_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(TEN_SYNTHESIS) * c.getCon(NINE);
}

template<>
template<class Ctxt>
RATETYPE reaction<ELEVEN_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(ELEVEN_SYNTHESIS) * c.getCon(TEN);
}

template<>
template<class Ctxt>
RATETYPE reaction<TWELVE_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(TWELVE_SYNTHESIS) * c.getCon(ELEVEN);
}

template<>
template<class Ctxt>
RATETYPE reaction<THIRTEEN_SYNTHESIS>::active_rate(const Ctxt& c) {
    return c.getRate(THIRTEEN_SYNTHESIS) * c.getCon(TWELVE);
}

template<>
template<class Ctxt>
RATETYPE reaction<ONE_DEGRADATION>::active_rate(const Ctxt& c) {
    return c.getRate(ONE_DEGRADATION) * c.getCon(ONE);
}

template<>
template<class Ctxt>
RATETYPE reaction<TWO_DEGRADATION>::active_rate(const Ctxt& c) {
    return c.getRate(TWO_DEGRADATION) * c.getCon(TWO);
}

template<>
template<class Ctxt>
RATETYPE reaction<SIX_DEGRADATION>::active_rate(const Ctxt& c) {
    return c.getRate(SIX_DEGRADATION) * c.getCon(SIX);
}

template<>
template<class Ctxt>
RATETYPE reaction<FIVE_DEGRADATION>::active_rate(const Ctxt& c) {
    return c.getRate(FIVE_DEGRADATION) * c.getCon(FIVE);
}

template<>
template<class Ctxt>
RATETYPE reaction<NINE_DEGRADATION>::active_rate(const Ctxt& c) {
    return c.getRate(NINE_DEGRADATION) * c.getCon(NINE);
}

template<>
template<class Ctxt>
RATETYPE reaction<TEN_DEGRADATION>::active_rate(const Ctxt& c) {
    return c.getRate(TEN_DEGRADATION) * c.getCon(TEN);
}
#endif // MODEL_IMPL_H
