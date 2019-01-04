// Copyright 2018 H-AXE
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <memory>
#include <vector>
#include <string>

namespace axe {
namespace simulation {

enum resource { cpu = 1, memory, network, disk };

class Task {
public:
  Task() {}

private:
  int resource_;
  int duration_;
  std::vector<std::shared_ptr<Task>> precedences_;
  std::vector<std::shared_ptr<std::string>> locality_;
};

} // namespace simulation
} // namespace axe
