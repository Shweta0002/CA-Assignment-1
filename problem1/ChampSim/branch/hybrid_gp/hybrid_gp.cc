#include <map>
#include "msl/fwcounter.h"
#include "ooo_cpu.h"
#include "../gshare/gshare.h"
#include "../perceptron/perceptron_hb.h"


constexpr std::size_t BIMODAL_TABLE_SIZE = 4096;
constexpr std::size_t BIMODAL_PRIME = 4093;
// constexpr std::size_t COUNTER_BITS = 2;

std::map<O3_CPU*, std::array<champsim::msl::fwcounter<COUNTER_BITS>, BIMODAL_TABLE_SIZE>> bimodal_table;

auto pPred = 1;
auto gPred = 1;
void O3_CPU::initialize_branch_predictor() {}

uint8_t O3_CPU::predict_branch(uint64_t ip)
{

  auto hash = ip % ::BIMODAL_PRIME;
  auto value = ::bimodal_table[this][hash];

  if (value.value() >= (value.maximum / 2)) {
    gPred = gshare_predict_branch(ip, this);
    return gPred;
  } else {
    pPred = perceptron_predict_branch(ip, this);
    return pPred;
  }
} 

void O3_CPU::last_branch_result(uint64_t ip, uint64_t branch_target, uint8_t taken, uint8_t branch_type)
{
	auto hash = ip % ::BIMODAL_PRIME;
	if (taken == pPred && taken != gPred) {
		::bimodal_table[this][hash] -= 1;
	} else if (taken != pPred && taken == gPred) {
		::bimodal_table[this][hash] += 1;
	}
	
	gshare_last_branch_result(ip, branch_target, taken, branch_type ,this);
	perceptron_last_branch_result(ip, branch_target, taken, branch_type ,this);
}

 