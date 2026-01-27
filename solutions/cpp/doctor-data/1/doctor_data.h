#pragma once
#include <string>
namespace star_map {
enum class System {
  BetaHydri,
  Sol,
  EpsilonEridani,
  AlphaCentauri,
  DeltaEridani,
  Omicron2Eridani,
};
}
namespace heaven {
class Vessel {
public:
  Vessel(std::string name, int generation,
         star_map::System current_system = star_map::System::Sol);
  auto replicate(std::string name) const -> Vessel;
  auto make_buster() -> void;
  auto shoot_buster() -> bool;
  std::string name;
  int generation;
  star_map::System current_system;
  int busters;
};
auto get_older_bob(const Vessel &a, const Vessel &b) -> std::string;
auto in_the_same_system(const Vessel &a, const Vessel &b) -> bool;
} // namespace heaven
