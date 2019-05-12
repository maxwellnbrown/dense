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

REACTION(M12_3_ASSOCIATION)
REACTION(M31_24_ASSOCIATION)
REACTION(M24_15_ASSOCIATION)
REACTION(M65_28_ASSOCIATION)
REACTION(M23_7_ASSOCIATION)
REACTION(M7_3_ASSOCIATION)
REACTION(M89_1011_ASSOCIATION)
REACTION(M1012_13_ASSOCIATION)
REACTION(M137_12_ASSOCIATION)

REACTION(ONE_SYNTHESIS)
REACTION(TWO_SYNTHESIS)
REACTION(THREE_SYNTHESIS)
REACTION(FOUR_SYNTHESIS)
REACTION(FIVE_SYNTHESIS)
REACTION(SIX_SYNTHESIS)
REACTION(SEVEN_SYNTHESIS)
REACTION(EIGHT_SYNTHESIS)
REACTION(NINE_SYNTHESIS)
REACTION(TEN_SYNTHESIS)
REACTION(ELEVEN_SYNTHESIS)
REACTION(TWELVE_SYNTHESIS)
REACTION(THIRTEEN_SYNTHESIS)
    
REACTION(ONE_DEGRADATION)
REACTION(TWO_DEGRADATION)
REACTION(FIVE_DEGRADATION)
REACTION(SIX_DEGRADATION)
REACTION(NINE_DEGRADATION)
REACTION(TEN_DEGRADATION)



#ifdef UNDO_DELAY_REACTION_DEF
#undef DELAY_REACTION 
#undef UNDO_DELAY_REACTION_DEF
#endif


