// Copyright 2025 Reazon Holdings, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>

#include <pluginlib/class_loader.hpp>

#include "hardware_interface/system_interface.hpp"

static constexpr const char* kPluginName =
    "openarm_mujoco_hardware/MujocoHardware";

TEST(TestLoadMujocoOpenarmHardware, can_load_plugin) {
  pluginlib::ClassLoader<hardware_interface::SystemInterface> loader(
      "openarm_mujoco_hardware", "hardware_interface::SystemInterface");
  std::shared_ptr<hardware_interface::SystemInterface> instance;

  ASSERT_NO_THROW(instance = loader.createSharedInstance(kPluginName));
  EXPECT_NE(instance, nullptr);
}
