#include "doctor_data.h"
namespace heaven {
Vessel::Vessel(std::string name, int generation,
               star_map::System current_system)
    : name{std::move(name)}, generation{generation},
      current_system{current_system}, busters{0} {}
auto Vessel::replicate(std::string name) const -> Vessel {
  return Vessel{std::move(name), this->generation + 1, current_system};
}
auto Vessel::make_buster() -> void { ++busters; }
auto Vessel::shoot_buster() -> bool {
  return busters > 0 ? --busters, true : false;
}
auto get_older_bob(const Vessel &a, const Vessel &b) -> std::string {
  return a.generation < b.generation ? a.name : b.name;
}
auto in_the_same_system(const Vessel &a, const Vessel &b) -> bool {
  return a.current_system == b.current_system;
}
} // namespace heaven
