// In this file, we declare the X-Macro for the list of reactions to 
//   be simulated.  
// Each reaction must have a declared reaction rate function in 
//   model_impl.h
// For example, to declare three reactions named "one", "two", and "three", 
// of which "three" is a delayed reaction, use the syntax below.
//
//  REACTION(one)
//  REACTION(two)
//  DELAY_REACTION(three)

#ifndef DELAY_REACTION
#define DELAY_REACTION REACTION
#define UNDO_DELAY_REACTION_DEF
#endif
REACTION(A0_syn)
REACTION(A1_syn)

REACTION(A0A1A2_assoc)
REACTION(A1A2A3_assoc)
REACTION(A2A3A4_assoc)
REACTION(A3A4A5_assoc)
REACTION(A4A5A6_assoc)
REACTION(A5A6A7_assoc)
REACTION(A6A7A8_assoc)
REACTION(A7A8A9_assoc)
REACTION(A8A9A10_assoc)
REACTION(A9A10A11_assoc)
REACTION(A10A11A12_assoc)
REACTION(A11A12A13_assoc)
REACTION(A12A13A14_assoc)
REACTION(A13A14A15_assoc)
REACTION(A14A15A16_assoc)
REACTION(A15A16A17_assoc)
REACTION(A16A17A18_assoc)
REACTION(A17A18A19_assoc)
REACTION(A18A19A20_assoc)
#ifdef UNDO_DELAY_REACTION_DEF
#undef DELAY_REACTION 
#undef UNDO_DELAY_REACTION_DEF
#endif
