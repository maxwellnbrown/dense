#include <cmath>
#include "simulation.hpp"
#include "rates.hpp"
#include "context.hpp"
#include "model_impl.hpp"

#include <iostream>


using namespace std;
//declare reaction inits here
#define REACTION(name) \
  template<> \
  reaction< name >::reaction() : \
    num_inputs(num_inputs_##name), num_outputs(num_outputs_##name), \
    in_counts(in_counts_##name), inputs(inputs_##name), \
    out_counts(out_counts_##name), outputs(outputs_##name), \
    num_factors(num_factors_##name), factors(factors_##name){}
#include "reactions_list.hpp"
#undef REACTION

//A quick test case to make sure all reaction rates are defined by link time
void simulation::test_sim() {
  Context c(*this, cells_total);

  double sum_rates = 0.0;
#define REACTION(name) sum_rates += _model.reaction_##name.active_rate(c);
#include "reactions_list.hpp"
#undef REACTION
  std::cout << "If you're seeing this, simulation.cpp compiles correctly:" 
            << sum_rates << std::endl;
}

void set_test_data(){
    
}

void simulation::execute(){
    //concentration cl;
    //Rates rates;
    int steps_elapsed = steps_split; // Used to determine when to split a column of cells
    //update_rates(rs, active_start); // Update the active rates based on the base rates, perturbations, and gradients
    
    //Context<double> contexts[]= {};
    //int j;
    //vector<int> baby_j;
    //bool past_induction = false; // Whether we've passed the point of induction of knockouts or overexpression
    //bool past_recovery = false; // Whether we've recovered from the knockouts or overexpression
    //for (j = time_start; j < time_end; j++) {
        
    /*
    for (int i=0; i< NUM_SPECIES;i++){
        _time_prev[i]= WRAP(_baby_j[i]-1, _rates._delay_size[i]);
    }
     */
        //int time_prev = WRAP(baby_j - 1, max_delay_size); // Time is cyclical, so time_prev may not be baby_j - 1
    
    //where to keep the birth and parent information
    //copy_records(_contexts, _baby_j, _time_prev); // Copy each cell's birth and parent so the records are accessible at every time step
        
        
    // Iterate through each extant cell or context
    for (int k = 0; k < cells_total; k++) {
        if (width_current == width_total || k % width_total <= active_start) { // Compute only existing (i.e. already grown)cells
                // Calculate the cell indices at the start of each mRNA and protein's dela
            int old_cells_mrna[NUM_SPECIES];
            int old_cells_protein[NUM_SPECIES]; // birth and parents info are kept elsewhere now
            calculate_delay_indices(_baby_cl, _baby_j, _j, k, _rates, old_cells_mrna, old_cells_protein);
                
            // Perform biological calculations
            #define REACTION(name);
            #include "reactions_list.hpp"
            #undef REACTION
        }
    }
    // Check to make sure the numbers are still valid
    if (any_less_than_0(_baby_cl, _baby_j) || concentrations_too_high(_baby_cl, _baby_j, max_con_thresh)) {
        //return false;
        //printf "Concentration too high or below zero. Exiting."
        exit(0);
    }
    
    // Update the active record data and split counter
    steps_elapsed++;
    //baby_cl.active_start_record[baby_j] = active_start;
    //baby_cl.active_end_record[baby_j] = active_end;
    
    // Copy from the simulating cl to the analysis cl
    if (_j % big_gran == 0) {
        baby_to_cl(_baby_cl, _cl,  _j / big_gran, _baby_j);
    }
        
    //}
    
    // Copy the last time step from the simulating cl to the analysis cl and mark where the simulating cl left off time-wise
    baby_to_cl(_baby_cl,_cl,_j,_baby_j);
    //time_baby = baby_j;
    //return true;

}



void simulation::baby_to_cl(baby_cl& baby_cl, Concentration_level& cl, int time, int* baby_times){
    int baby_time = 0;
    for (int i = 0; i <= NUM_SPECIES; i++) {
        baby_time = baby_times[i];
        for (int k = 0; k < cells_total; k++) {
            cl[i][time][k] = baby_cl[i][baby_time][k];
        }
    }
    //cl.active_start_record[time] = baby_cl.active_start_record[baby_time];
    //cl.active_end_record[time] = baby_cl.active_end_record[baby_time];


}

/*
void simulation::copy_records (vector<Context> contexts, vector<int> time, vector<int> time_prev) {
    for (int k = 0; k < cells_total; k++) {
        cl.cons[BIRTH][time][k] = cl.cons[BIRTH][time_prev][k];
        cl.cons[PARENT][time][k] = cl.cons[PARENT][time_prev][k];
    }
}*/

bool simulation::any_less_than_0 (baby_cl& baby_cl, int* times) {
    for (int i = 0; i <= NUM_SPECIES; i++) {
        int time = times[i];
        if (baby_cl[i][time][0] < 0) { // This checks only the first cell
            return true;
        }
    }
    return false;
}

bool simulation::concentrations_too_high (baby_cl& baby_cl, int* times, double max_con_thresh) {
    if (max_con_thresh != INFINITY) {
        for (int i = 0; i <= NUM_SPECIES; i++) {
            int time = times[i];
            if (baby_cl[i][time][0] > max_con_thresh) { // This checks only the first cell
                return true;
            }
        }
    }
    return false;
}

void simulation::calculate_delay_indices (baby_cl& baby_cl, int* baby_time, int time, int cell_index, Rates& rs, int old_cells_mrna[], int old_cells_protein[]) {
    //if (section == SEC_POST) { // Cells in posterior simulations do not split so the indices never change
    for (int l = 0; l < NUM_SPECIES; l++) {
        old_cells_mrna[l] = cell_index;
        old_cells_protein[l] = cell_index;
    }
    /*} else { // Cells in anterior simulations split so with long enough delays the cell must look to its parent for values, causing its effective index to change over time
        for (int l = 0; l < NUM_INDICES; l++) {
            old_cells_mrna[IMH1 + l] = index_with_splits(sd, cl, baby_time, time, cell_index, active_rates[RDELAYMH1 + l][cell_index]);
            old_cells_protein[IPH1 + l] = index_with_splits(sd, cl, baby_time, time, cell_index, active_rates[RDELAYPH1 + l][cell_index]);
        }
    }*/
    
}

void simulation::initialize(){
    _j=0;
    cells_total = 200;
    width_total = 50;
    NEIGHBORS_2D = 6;
    
    int _baby_j[NUM_SPECIES];
    _baby_cl.initialize();
    _cl.initialize(5,0,cells_total,0);
    /*
    _parameter_set._delay_sets = {7.012622,14.984612,8.023912,14.704954,
                                  1.243684,0.425859,0.409653,10.049570};
    _parameter_set._rates_base[NUM_REACTIONS] = {30.012607,51.696917,38.245038,30.602979,
                                  
                                  0.499898,0.100750,0.244993,0.479945,
                                  
                                  54.038194,44.558513,23.450357,51.855638,
                                  
                                  0.119014,0.266534,0.445092,0.497927,
                                  
                                  0.025518,0.018589,0.026202,0.013235,
                                  
                                  0.151772,0.244074,0.223924,0.264807,
                                  
                                  0.224610,0.489840,0.486618,0.483102};
    
    _model.factors_perturb[] = [];
    _model._using_gradients = true;
    _model.factors_gradient[][] =;
    _model._has_gradient[] = [];
    */
    //_rates.update_rates();
}
    
    
void simulation::calc_neighbor_2d(){
    for (int i = 0; i < cells_total; i++) {
        if (i % 2 == 0) {																		// All even column cells
            _neighbors[i][0] = (i - width_total + cells_total) % cells_total;			// Top
            _neighbors[i][1] = (i - width_total + 1 + cells_total) % cells_total;		// Top-right
            _neighbors[i][2] = (i + 1) % cells_total;											// Bottom-right
            _neighbors[i][3] = (i + width_total) % cells_total;								// Bottom
            if (i % width_total == 0) {														// Left edge
                _neighbors[i][4] = i + width_total - 1;										// Bottom-left
                _neighbors[i][5] = (i - 1 + cells_total) % cells_total;						// Top-left
            } else {																			// Not a left edge
                _neighbors[i][4] = i - 1;															// Bottom-left
                _neighbors[i][5] = (i - width_total - 1 + cells_total) % cells_total;	// Top-left
            }
        } else {																				// All odd column cells
            _neighbors[i][0] = (i - width_total + cells_total) % cells_total;			// Top
            if (i % width_total == width_total - 1) {											// Right edge
                _neighbors[i][1] = i - width_total + 1;										// Top-right
                _neighbors[i][2] = (i + 1) % cells_total;										// Bottom-right
            } else {																			// Not a right edge
                _neighbors[i][1] = i + 1;															// Top-right
                _neighbors[i][2] = (i + width_total + 1 + cells_total) % cells_total;	// Nottom-right
            }																					// All odd column cells
            _neighbors[i][3] = (i + width_total) % cells_total;								// Bottom
            _neighbors[i][4] = (i + width_total - 1) % cells_total;							// Bottom-left
            _neighbors[i][5] = (i - 1 + cells_total) % cells_total;							// Top-left
        }
    }
}


void simulation::find_related_reactions(){
    
}
