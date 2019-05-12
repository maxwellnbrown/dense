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
RATETYPE reaction<make_lemonaide>::active_rate(const Ctxt& c) {
    return c.getRate(make_lemonaide) * c.getCon(lemon)*c.getCon(sugar);
}

template<>
template<class Ctxt>
RATETYPE reaction<make_lemon>::active_rate(const Ctxt& c) {
    return (c.getRate(make_lemon) * (c.getCon(lemon) - (c.getCon(lemon) *c.getCritVal(rcrit_lemon))));
}

template<>
template<class Ctxt>
RATETYPE reaction<make_sugar>::active_rate(const Ctxt& c) {
    return (c.getRate(make_sugar) * (c.getCon(sugar) - c.getCritVal(rcrit_sugar)));
}

template<>
template<class Ctxt>
RATETYPE reaction<customer_purchase>::active_rate(const Ctxt& c) {
    return c.getRate(customer_purchase);
}

template<>
template<class Ctxt>
RATETYPE reaction<buy_lemons>::active_rate(const Ctxt& c) {
    return c.getRate(buy_lemons);
}

template<>
template<class Ctxt>
Real reaction<buy_sugar>::active_rate (const Ctxt& c) {
    return c.getRate(buy_sugar);
}


template<>
template<class Ctxt>
Real reaction<make_quality>::active_rate (const Ctxt& c) {
    return c.getRate(make_quality)*c.getCon(lemon)*c.getCon(sugar);
}

template<>
template<class Ctxt>
Real reaction<quality_to_satisfaction>::active_rate (const Ctxt& c) {
    return c.getRate(quality_to_satisfaction);
}


template<>
template<class Ctxt>
Real reaction<satisfaction_to_tips>::active_rate (const Ctxt& c) {
    return c.getRate(satisfaction_to_tips);
}
#endif // MODEL_IMPL_H
