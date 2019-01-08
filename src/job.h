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

#include "nlohmann/json.hpp"
#include "task.h"

#include <vector>

namespace axe {
namespace simulation {

using nlohmann::json;

class Job {
public:
  Job() = default;

  inline const auto &GetTasks() const { return tasks_; }
  inline const auto &GetId() const { return id_; }
  inline const auto &GetSubmissionTime() const { return submission_time_; }

  friend void from_json(const json &j, Job &job) {
    j.at("id").get_to(job.id_);
    j.at("submissiontime").get_to(job.submission_time_);
    auto pos = j.find("tasks");
    if (pos != j.end()) {
      pos->get_to(job.tasks_);
    }
  }

private:
  std::vector<Task> tasks_;
  int id_;
  double submission_time_;
};

} // namespace simulation
} // namespace axe
