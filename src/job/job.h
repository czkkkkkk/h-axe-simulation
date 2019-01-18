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

#include "glog/logging.h"
#include "nlohmann/json.hpp"
#include "subgraph.h"
#include <iostream>
#include <vector>

namespace axe {
namespace simulation {

using nlohmann::json;

class Job {
public:
  Job() = default;

  inline const auto &GetSubGraphs() const { return subgraphs_; }
  inline int GetJobId() const { return job_id_; }
  inline int GetUserId() const { return user_id_; }
  inline double GetSubmissionTime() const { return submission_time_; }
  inline void SetWorkerId(int subgraph_id, int worker_id) {
    subgraphs_.at(subgraph_id).SetWorkerId(worker_id);
  }

  friend void from_json(const json &j, Job &job) {
    j.at("jobid").get_to(job.job_id_);
    j.at("userid").get_to(job.user_id_);
    j.at("submissiontime").get_to(job.submission_time_);
    auto pos = j.find("subgraph");
    if (pos != j.end()) {
      pos->get_to(job.subgraphs_);
    }
  }

  // for debug
  void Print() {
    DLOG(INFO) << "user id : " << user_id_;
    DLOG(INFO) << "job id : " << job_id_;
    DLOG(INFO) << "submission time : " << submission_time_;
    for (auto &sg : subgraphs_) {
      sg.Print();
    }
  }

private:
  std::vector<SubGraph> subgraphs_;
  int job_id_;
  int user_id_;
  double submission_time_;
};

} // namespace simulation
} // namespace axe
