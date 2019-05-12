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

STATIC_VAR int num_deltas_make_lemonaide = 3;
STATIC_VAR int deltas_make_lemonaide[] = {-2,-3,1};
STATIC_VAR specie_id delta_ids_make_lemonaide[] = {lemon,sugar,lemonaide};

STATIC_VAR int num_deltas_make_lemon = 1;
STATIC_VAR int deltas_make_lemon[] = {1};
STATIC_VAR specie_id delta_ids_make_lemon[] = {lemon};

STATIC_VAR int num_deltas_make_sugar = 1;
STATIC_VAR int deltas_make_sugar[] = {1};
STATIC_VAR specie_id delta_ids_make_sugar[] = {sugar};

STATIC_VAR int num_deltas_customer_purchase = 2;
STATIC_VAR int deltas_customer_purchase[] = {-1,2};
STATIC_VAR specie_id delta_ids_customer_purchase[] = {lemonaide,money};

STATIC_VAR int num_deltas_buy_lemons = 2;
STATIC_VAR int deltas_buy_lemons[] = {-3,2};
STATIC_VAR specie_id delta_ids_buy_lemons[] = {money,lemon};

STATIC_VAR int num_deltas_buy_sugar = 2;
STATIC_VAR int deltas_buy_sugar[] = {-2,25};
STATIC_VAR specie_id delta_ids_buy_sugar[] = {money,sugar};

STATIC_VAR int num_deltas_make_quality = 2;
STATIC_VAR int deltas_make_quality[] = {-4,1};
STATIC_VAR specie_id delta_ids_make_quality[] = {lemonaide, good_lemonaide};

STATIC_VAR int num_deltas_quality_to_satisfaction = 3;
STATIC_VAR int deltas_quality_to_satisfaction[] = {-2,-1,1};
STATIC_VAR specie_id delta_ids_quality_to_satisfaction[] = {good_lemonaide, lemonaide, customer_satisfaction};

STATIC_VAR int num_deltas_satisfaction_to_tips = 2;
STATIC_VAR int deltas_satisfaction_to_tips[] = {-1,4};
STATIC_VAR specie_id delta_ids_satisfaction_to_tips[] = {customer_satisfaction, money};