// In this file, we declare the X-Macro for the list of reactions to
//   be simulated.
// Each reaction must have a declared reaction rate function in
//   model_impl.h
// For example, to declare three reactions named "one", "two", and "three",
// use the syntax below
//#define LIST_OF_SPECIES
//  SPECIE(specie_one)
//  SPECIE(two)
//  SPECIE(three)


#ifndef CRITICAL_SPECIE
#define CRITICAL_SPECIE SPECIE
#define UNDO_CRITICAL_SPECIE_DEF
#endif
CRITICAL_SPECIE(lemon)
CRITICAL_SPECIE(sugar)
SPECIE(lemonaide)
SPECIE(money)
SPECIE(good_lemonaide)
SPECIE(customer_satisfaction)
#ifdef UNDO_CRITICAL_SPECIE_DEF
#undef CRITICAL_SPECIE
#undef UNDO_CRITICAL_SPECIE_DEF
#endif
