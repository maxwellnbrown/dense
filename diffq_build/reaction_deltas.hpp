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
STATIC_VAR int num_deltas_A0_syn = 1;
STATIC_VAR int deltas_A0_syn[] = {1};
STATIC_VAR specie_id delta_ids_A0_syn[] = {A0};

STATIC_VAR int num_deltas_A1_syn = 1;
STATIC_VAR int deltas_A1_syn[] = {1};
STATIC_VAR specie_id delta_ids_A1_syn[] = {A1};

STATIC_VAR int num_deltas_A0A1A2_assoc = 3;
STATIC_VAR int deltas_A0A1A2_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A0A1A2_assoc[] = {A0, A1, A2};

STATIC_VAR int num_deltas_A1A2A3_assoc = 3;
STATIC_VAR int deltas_A1A2A3_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A1A2A3_assoc[] = {A1, A2, A3};

STATIC_VAR int num_deltas_A2A3A4_assoc = 3;
STATIC_VAR int deltas_A2A3A4_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A2A3A4_assoc[] = {A2, A3, A4};

STATIC_VAR int num_deltas_A3A4A5_assoc = 3;
STATIC_VAR int deltas_A3A4A5_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A3A4A5_assoc[] = {A3, A4, A5};

STATIC_VAR int num_deltas_A4A5A6_assoc = 3;
STATIC_VAR int deltas_A4A5A6_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A4A5A6_assoc[] = {A4, A5, A6};

STATIC_VAR int num_deltas_A5A6A7_assoc = 3;
STATIC_VAR int deltas_A5A6A7_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A5A6A7_assoc[] = {A5, A6, A7};

STATIC_VAR int num_deltas_A6A7A8_assoc = 3;
STATIC_VAR int deltas_A6A7A8_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A6A7A8_assoc[] = {A6, A7, A8};

STATIC_VAR int num_deltas_A7A8A9_assoc = 3;
STATIC_VAR int deltas_A7A8A9_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A7A8A9_assoc[] = {A7, A8, A9};

STATIC_VAR int num_deltas_A8A9A10_assoc = 3;
STATIC_VAR int deltas_A8A9A10_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A8A9A10_assoc[] = {A8, A9, A10};

STATIC_VAR int num_deltas_A9A10A11_assoc = 3;
STATIC_VAR int deltas_A9A10A11_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A9A10A11_assoc[] = {A9, A10, A11};

STATIC_VAR int num_deltas_A10A11A12_assoc = 3;
STATIC_VAR int deltas_A10A11A12_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A10A11A12_assoc[] = {A10, A11, A12};

STATIC_VAR int num_deltas_A11A12A13_assoc = 3;
STATIC_VAR int deltas_A11A12A13_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A11A12A13_assoc[] = {A11, A12, A13};

STATIC_VAR int num_deltas_A12A13A14_assoc = 3;
STATIC_VAR int deltas_A12A13A14_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A12A13A14_assoc[] = {A12, A13, A14};

STATIC_VAR int num_deltas_A13A14A15_assoc = 3;
STATIC_VAR int deltas_A13A14A15_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A13A14A15_assoc[] = {A13, A14, A15};

STATIC_VAR int num_deltas_A14A15A16_assoc = 3;
STATIC_VAR int deltas_A14A15A16_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A14A15A16_assoc[] = {A14, A15, A16};

STATIC_VAR int num_deltas_A15A16A17_assoc = 3;
STATIC_VAR int deltas_A15A16A17_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A15A16A17_assoc[] = {A15, A16, A17};

STATIC_VAR int num_deltas_A16A17A18_assoc = 3;
STATIC_VAR int deltas_A16A17A18_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A16A17A18_assoc[] = {A16, A17, A18};

STATIC_VAR int num_deltas_A17A18A19_assoc = 3;
STATIC_VAR int deltas_A17A18A19_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A17A18A19_assoc[] = {A17, A18, A19};

STATIC_VAR int num_deltas_A18A19A20_assoc = 3;
STATIC_VAR int deltas_A18A19A20_assoc[] = {-1, -1, 1};
STATIC_VAR specie_id delta_ids_A18A19A20_assoc[] = {A18, A19, A20};
