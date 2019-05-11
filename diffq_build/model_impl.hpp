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
RATETYPE reaction<A0_syn>::active_rate(const Ctxt& c) {
    return c.getRate(A0_syn)  * (c.getCritVal(rcrit_A0) - (c.getCon(A0))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A1_syn>::active_rate(const Ctxt& c) {
    return c.getRate(A1_syn)  * (c.getCritVal(rcrit_A1) - (c.getCon(A1))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A0A1A2_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A0A1A2_assoc)  * (c.getCritVal(rcrit_A2) - (c.getCon(A0)) - (c.getCon(A1))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A1A2A3_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A1A2A3_assoc)  * (c.getCritVal(rcrit_A3) - (c.getCon(A1)) - (c.getCon(A2))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A2A3A4_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A2A3A4_assoc)  * (c.getCritVal(rcrit_A4) - (c.getCon(A2)) - (c.getCon(A3))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A3A4A5_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A3A4A5_assoc)  * (c.getCritVal(rcrit_A5) - (c.getCon(A3)) - (c.getCon(A4))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A4A5A6_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A4A5A6_assoc)  * (c.getCritVal(rcrit_A6) - (c.getCon(A4)) - (c.getCon(A5))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A5A6A7_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A5A6A7_assoc)  * (c.getCritVal(rcrit_A7) - (c.getCon(A5)) - (c.getCon(A6))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A6A7A8_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A6A7A8_assoc)  * (c.getCritVal(rcrit_A8) - (c.getCon(A6)) - (c.getCon(A7))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A7A8A9_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A7A8A9_assoc)  * (c.getCritVal(rcrit_A9) - (c.getCon(A7)) - (c.getCon(A8))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A8A9A10_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A8A9A10_assoc)  * (c.getCritVal(rcrit_A10) - (c.getCon(A8)) - (c.getCon(A9))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A9A10A11_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A9A10A11_assoc)  * (c.getCritVal(rcrit_A11) - (c.getCon(A9)) - (c.getCon(A10))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A10A11A12_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A10A11A12_assoc)  * (c.getCritVal(rcrit_A12) - (c.getCon(A10)) - (c.getCon(A11))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A11A12A13_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A11A12A13_assoc)  * (c.getCritVal(rcrit_A13) - (c.getCon(A11)) - (c.getCon(A12))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A12A13A14_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A12A13A14_assoc)  * (c.getCritVal(rcrit_A14) - (c.getCon(A12)) - (c.getCon(A13))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A13A14A15_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A13A14A15_assoc)  * (c.getCritVal(rcrit_A15) - (c.getCon(A13)) - (c.getCon(A14))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A14A15A16_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A14A15A16_assoc)  * (c.getCritVal(rcrit_A16) - (c.getCon(A14)) - (c.getCon(A15))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A15A16A17_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A15A16A17_assoc)  * (c.getCritVal(rcrit_A17) - (c.getCon(A15)) - (c.getCon(A16))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A16A17A18_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A16A17A18_assoc)  * (c.getCritVal(rcrit_A18) - (c.getCon(A16)) - (c.getCon(A17))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A17A18A19_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A17A18A19_assoc)  * (c.getCritVal(rcrit_A19) - (c.getCon(A17)) - (c.getCon(A18))) ;
}

template<>
template<class Ctxt>
RATETYPE reaction<A18A19A20_assoc>::active_rate(const Ctxt& c) {
    return c.getRate(A18A19A20_assoc)  * (c.getCritVal(rcrit_A20) - (c.getCon(A18)) - (c.getCon(A19))) ;
}


#endif // MODEL_IMPL_H
