#include "utility/common_utils.hpp"
#include "core/reaction.hpp"

#include <cstddef>

/*

Define each reaction's reactants and products in reaction_deltas.hpp.
Say a reaction enumerated as R_ONE has the following chemical formula:

                           2A + B --> C

The proper way to define that reaction's state change vector is as follows:

STATIC_VAR int num_deltas_R_ONE = 3;
STATIC_VAR int deltas_R_ONE[] = {-2, -1, 1};
STATIC_VAR specie_id delta_ids_R_ONE[] = {A, B, C};

*/

STATIC_VAR int num_deltas_M12_3_ASSOCIATION = 3;
STATIC_VAR int deltas_M12_3_ASSOCIATION[] = {-1,-1,1};
STATIC_VAR specie_id delta_ids_M12_3_ASSOCIATION[] = {ONE, TWO, THREE};

STATIC_VAR int num_deltas_M31_24_ASSOCIATION = 4;
STATIC_VAR int deltas_M31_24_ASSOCIATION[] = {-1,-1,1,1};
STATIC_VAR specie_id delta_ids_M31_24_ASSOCIATION[] = {THREE, ONE, TWO, FOUR};

STATIC_VAR int num_deltas_M24_15_ASSOCIATION = 4;
STATIC_VAR int deltas_M24_15_ASSOCIATION[] = {-1,-1,2,1};
STATIC_VAR specie_id delta_ids_M24_15_ASSOCIATION[] = {TWO, FOUR, ONE, FIVE};

STATIC_VAR int num_deltas_M65_28_ASSOCIATION = 4;
STATIC_VAR int deltas_M65_28_ASSOCIATION[] = {-1,-1,1,1};
STATIC_VAR specie_id delta_ids_M65_28_ASSOCIATION[] = {SIX, FIVE, TWO, EIGHT};

STATIC_VAR int num_deltas_M23_7_ASSOCIATION = 3;
STATIC_VAR int deltas_M23_7_ASSOCIATION[] = {-3,-1,2};
STATIC_VAR specie_id delta_ids_M23_7_ASSOCIATION[] = {TWO, THREE, SEVEN};

STATIC_VAR int num_deltas_M7_3_ASSOCIATION = 2;
STATIC_VAR int deltas_M7_3_ASSOCIATION[] = {-1,1};
STATIC_VAR specie_id delta_ids_M7_3_ASSOCIATION[] = {SEVEN, THREE};

STATIC_VAR int num_deltas_M89_1011_ASSOCIATION = 4;
STATIC_VAR int deltas_M89_1011_ASSOCIATION[] = {-1,-1,1,1};
STATIC_VAR specie_id delta_ids_M89_1011_ASSOCIATION[] = {EIGHT, NINE, TEN, ELEVEN};

STATIC_VAR int num_deltas_M1012_13_ASSOCIATION = 3;
STATIC_VAR int deltas_M1012_13_ASSOCIATION[] = {-1,-1,1};
STATIC_VAR specie_id delta_ids_M1012_13_ASSOCIATION[] = {TEN, TWELVE, THIRTEEN};

STATIC_VAR int num_deltas_M137_12_ASSOCIATION = 4;
STATIC_VAR int deltas_M137_12_ASSOCIATION[] = {-1,-2,2,1};
STATIC_VAR specie_id delta_ids_M137_12_ASSOCIATION[] = {THIRTEEN, SEVEN, ONE, TWO};

STATIC_VAR int num_deltas_ONE_SYNTHESIS = 1;
STATIC_VAR int deltas_ONE_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_ONE_SYNTHESIS[] = {ONE};

STATIC_VAR int num_deltas_TWO_SYNTHESIS = 1;
STATIC_VAR int deltas_TWO_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_TWO_SYNTHESIS[] = {TWO};

STATIC_VAR int num_deltas_THREE_SYNTHESIS = 1;
STATIC_VAR int deltas_THREE_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_THREE_SYNTHESIS[] = {THREE};

STATIC_VAR int num_deltas_FOUR_SYNTHESIS = 1;
STATIC_VAR int deltas_FOUR_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_FOUR_SYNTHESIS[] = {FOUR};

STATIC_VAR int num_deltas_FIVE_SYNTHESIS = 1;
STATIC_VAR int deltas_FIVE_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_FIVE_SYNTHESIS[] = {FIVE};

STATIC_VAR int num_deltas_SIX_SYNTHESIS = 1;
STATIC_VAR int deltas_SIX_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_SIX_SYNTHESIS[] = {SIX};

STATIC_VAR int num_deltas_SEVEN_SYNTHESIS = 1;
STATIC_VAR int deltas_SEVEN_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_SEVEN_SYNTHESIS[] = {SEVEN};

STATIC_VAR int num_deltas_EIGHT_SYNTHESIS = 1;
STATIC_VAR int deltas_EIGHT_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_EIGHT_SYNTHESIS[] = {EIGHT};

STATIC_VAR int num_deltas_NINE_SYNTHESIS = 1;
STATIC_VAR int deltas_NINE_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_NINE_SYNTHESIS[] = {NINE};

STATIC_VAR int num_deltas_TEN_SYNTHESIS = 1;
STATIC_VAR int deltas_TEN_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_TEN_SYNTHESIS[] = {TEN};

STATIC_VAR int num_deltas_ELEVEN_SYNTHESIS = 1;
STATIC_VAR int deltas_ELEVEN_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_ELEVEN_SYNTHESIS[] = {ELEVEN};

STATIC_VAR int num_deltas_TWELVE_SYNTHESIS = 1;
STATIC_VAR int deltas_TWELVE_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_TWELVE_SYNTHESIS[] = {TWELVE};

STATIC_VAR int num_deltas_THIRTEEN_SYNTHESIS = 1;
STATIC_VAR int deltas_THIRTEEN_SYNTHESIS[] = {1};
STATIC_VAR specie_id delta_ids_THIRTEEN_SYNTHESIS[] = {THIRTEEN};

STATIC_VAR int num_deltas_ONE_DEGRADATION = 1;
STATIC_VAR int deltas_ONE_DEGRADATION[] = {-1};
STATIC_VAR specie_id delta_ids_ONE_DEGRADATION[] = {ONE};

STATIC_VAR int num_deltas_TWO_DEGRADATION = 1;
STATIC_VAR int deltas_TWO_DEGRADATION[] = {-1};
STATIC_VAR specie_id delta_ids_TWO_DEGRADATION[] = {TWO};

STATIC_VAR int num_deltas_FIVE_DEGRADATION = 1;
STATIC_VAR int deltas_FIVE_DEGRADATION[] = {-1};
STATIC_VAR specie_id delta_ids_FIVE_DEGRADATION[] = {FIVE};

STATIC_VAR int num_deltas_SIX_DEGRADATION = 1;
STATIC_VAR int deltas_SIX_DEGRADATION[] = {-1};
STATIC_VAR specie_id delta_ids_SIX_DEGRADATION[] = {SIX};

STATIC_VAR int num_deltas_NINE_DEGRADATION = 1;
STATIC_VAR int deltas_NINE_DEGRADATION[] = {-1};
STATIC_VAR specie_id delta_ids_NINE_DEGRADATION[] = {NINE};

STATIC_VAR int num_deltas_TEN_DEGRADATION = 1;
STATIC_VAR int deltas_TEN_DEGRADATION[] = {-1};
STATIC_VAR specie_id delta_ids_TEN_DEGRADATION[] = {TEN};

